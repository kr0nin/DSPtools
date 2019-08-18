%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% wordform.m
%% main program for proj4
%% Erich Kroneberger
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% prompt user for number input
num = input('Please enter a number:');
% init variables
ones = mod(num,10);
tens = floor(mod(num,100)/10);
hund = floor(mod(num,1000)/100);
thou = floor(mod(num,(10^4))/10^3);
mil = floor(mod(num,(10^7))/(10^6));
bil = floor(mod(num,(10^10))/(10^9));

% operation thru teens only
if (num < 20)
    sayones(num)

%operation thru hundreds teens
elseif mod (num,100) < 20
    sayhundreds(hund)
    sayones(mod(num,100))

else
% print full numbers
    sayhundreds(hund)
    saytens(tens)
    sayones(ones)

end