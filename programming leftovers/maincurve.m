%This m-file reads a set of grades, and asks the user for
%an average that is desired, and then calls a user defined function 
%"curve.m" that adjusts the individual grades to match the requested
%average.  This program uses global variables to allow access to the
%variables "GRADES" and "NEWGRADES" without transferring them through the
%function argument, or by a return variable.

clear
clc
global GRADES NEWGRADES;% the grade arrays are global variables
GRADES = [72 91 89 65 76 63 54 78 34];
fprintf('\nAverage without curve = %6.1f\n\n',mean(GRADES));
newave = input('What would you like the new average to be ?');
curve(newave);
fprintf('\nold grade   new grade\n');
fprintf('%7.1f %10.1f\n',[GRADES;NEWGRADES]);
