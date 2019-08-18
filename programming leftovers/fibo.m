%%%%%%%%%%%%%%%%%%%%%%%%%%%
% fibonacci number
% Erich Kroneberger CS122 
% hw problem #6
%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all

F = zeros(n);


%set value
f = input ('enter number= ');

while (i<=n);
    
    f(i) = f(i-1)+f(n-2);
    % accumulate sums?
    f = (f-1) + (f-2);
    
end

fprintf('the Fibonacci number for %d= %d'\n , f,n);