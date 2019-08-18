%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% proj4.m
%% Erich Kroneberger
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% prompt the user for number input
num = input('please enter a number: ');

% for negatives
if(num<0)
    num = (num*(-1));
    fprintf('negative ')
end

% init variables
hun = mod(num,10^3);
tho = floor(mod(num,10^6)/10^3);
mil = floor(mod(num,10^9)/10^6);
bil = floor(mod(num,10^12)/10^9);

% program breakdown
if(num==0)
    fprintf('zero')
elseif(bil>0)
    saythree(bil)
    fprintf(' billion ')
    saythree(mil)
    fprintf(' million ')
    saythree(tho)
    fprintf(' thousand ')
    saythree(hun)
elseif(mil>0)
    saythree(mil)
    fprintf(' million ')
    saythree(tho)
    fprintf(' thousand ')
    saythree(hun)
elseif(tho>0)
    saythree(tho)
    fprintf(' thousand ')
    saythree(hun)
elseif(hun>0)
    saythree(hun)
else
    fprintf(' error ')
end