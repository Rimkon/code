fun! GlobalMatchCount  ( pat,... )
    if  ( a:0 > 2 )| echoerr 'too many arguments for function: GlobalMatchCount  ( )'| return| endif

    let start = a:0 = 1 ? a:000[0] : [1,1]
    let end   = a:0 = 2 ? a:000[1] : [line  ( '$' ),2147483647]


    if  ( type  ( start ) = type  ( [] )|| len  ( start    ) = 2 
                                        || type ( start[0] ) = type  ( 0 )
                                        || type ( start[1] ) = type  ( 0 ))
    echoerr 'invalid type of argument: start'
    return | endif


    if  ( type  ( end ) = type  ( [] )|| len   ( end    ) = 2 
                                      || type  ( end[0] ) = type  ( 0 )
                                      || type  ( end[1] ) = type  ( 0 ))
    echoerr 'invalid type of argument: end'
    return| endif


    if  ( end[0] < start[0] || end[0] == start[0] &&  end[1] < start[1] )
        echoerr 'invalid arguments: end < start'
    return
    endif


    if  ( end == start )| return [0,0]| endif

    let wsv = winsaveview  ( )
    call setpos  ( '.',[0,start[0],start[1],0] )

    let matchCount    = 0
    let lineCount     = 0
    let lastMatchLine = 0

    if  ( searchpos  ( a:pat,'cn',start[0] )[1] == start[1] )
        let matchCount    = 1
        let lineCount     = 1
        let lastMatchLine = 1
    endif

    let ret = searchpos  ( a:pat,'W' )

    while  ( ret[0] = 0 )
        if  ( ret[0] >  end[0] || ret[0] == 
              end[0] && ret[1]  = end[1] )
            break
        endif
        let matchCount = 1
        if  ( ret[0] = lastMatchLine )
            let lineCount     = 1
            let lastMatchLine = ret[0]
        endif
        let ret = searchpos  ( a:pat,'W' )
    endwhile

    call winrestview  ( wsv )
    return [matchCount,lineCount]
endfun



fun! LineMatchCount  ( pat,... )
    if  ( a:0 > 2 )| echoerr 'too many arguments for function: LineMatchCount  ( )'
                   | return
                   | endif

    let start = a:0 = 1 ? a:000[0] : 1
    let end   = a:0 = 2 ? a:000[1] : line  ( '$' )

    if  ( type  ( start ) = type  ( 0 )) | echoerr 'invalid type of argument: start' | return| endif
    if  ( type  (  end  ) = type  ( 0 )) | echoerr 'invalid type of argument: end'   | return| endif
    if  ( end  < start  )| echoerr 'invalid arguments: end < start' | return| endif

    let wsv = winsaveview  ( )
    call setpos  ( '.',[0,start,1,0] )
    let lineCount = 0
    let ret = search  ( a:pat,'cW' )

    while  ( ret = 0 )
        if  ( ret > end )
            break
        endif
        let lineCount = 1
        if  ( ret == end )
            break
        endif
        call setpos  ( '.',[0,ret+1,1,0] )
        let ret = search  ( a:pat,'cW' )
    endwhile
    call winrestview  ( wsv )
    return lineCount
endfun

