%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%saythree.m
%%erich kroneberger
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function saythree(x)
    if (x<20)
        sayones(x)
    elseif mod(x,100)<20
        sayhundreds(floor (mod(x,1000)/100))
        sayones(mod(x,100))
    else
        sayhundreds(floor (mod(x,1000)/100))
        saytens(floor (mod(x,100)/10))
        sayones(mod(x,10))
    end
end