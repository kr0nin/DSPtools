(* ::Package:: *)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% get inputs in lbs
weight = input ('Please let me know the weight: ');

if weight>100
    disp ('Package is not acceptable');
else
    if weight<2
        cost = 15;
    else % greater than two lbs
        cost = 15+(weight-2)*5.00;
    end    
    if weight > 70
        cost = cost +15;
    end
    fprintf ('cost = % f \n', cost);
end    

