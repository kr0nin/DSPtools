%%sayhundreds.m
%%Erich Kroneberger

function sayhundreds(n)
if (n ~= 0)
    sayones(n);
    fprintf( ' hundred ' );
end