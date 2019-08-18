%saytens.m 
%Erich Kroneberger

function saytens(x)
    switch x;
        case 0
            fprintf('')
        case 1 
            fprintf('')
        case 2
            fprintf('twenty ')
        case 3 
            fprintf('thirty ')
        case 4
            fprintf('fourty ')
        case 5
            fprintf('fifty ')
        case 6
            fprintf('sixty ')
        case 7
            fprintf('seventy ')
        case 8
            fprintf('eighty ')
        case 9
            fprintf('nintey ')
        otherwise
            fprintf('error ')
    end