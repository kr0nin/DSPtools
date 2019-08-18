(* ::Package:: *)

%  Script file: funxy.m
%
%  Purpose: 
%    This program solves the function f (x,y) for a 
%    user-specified x and y, where f (x,y) is defined as:
%                 _
%                |
%                | x + y             x >= 0 and y >= 0
%                | x + y**2          x >= 0 and y < 0
%       f (x,y) = | x**2 + y          x < 0  and y >= 0
%                | x**2 + y**2       x < 0  and y < 0

%
% Define variables:
%   x     -- First independent variable
%   y     -- Second independent variable
%   fun   -- Resulting function

% Prompt the user for the values x and y
x = input ('Enter the x coefficient: ');
y = input ('Enter the y coefficient: ');
 
% Calculate the function f (x,y) based upon 
% the signs of x and y.
if x >= 0
   if y >= 0
      fun = x + y;
   else
      fun = x + x^2;
   end
else
   if y >= 0
      fun = x^2 + y;
   else
      fun = x^2 + y^2;
   end
end

% Write the value of the function.
disp (['The value of the function is ' num2str (fun)]);



