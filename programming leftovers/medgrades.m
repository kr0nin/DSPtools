%% medgrades.m                Erich Kroneberger
%% find the average of cs122 class midterm test
%% 

clc;
clear;

load ('grades.txt')

sum = 0;
n = length (grades);

for i = 1:n;

    sum = sum+grades (i);

end    

gavg = (sum/n);

fprintf('average grades= %f\n', gavg)