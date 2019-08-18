
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Programe Name:
% Author:
% Date:
% Version:
% Inputs: Velocity: 5
% Angle: 5 in degree
% Outputs: plot of .....
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% this is for inputs
v = input ('Please input velocity:');
a = input ('Please input angle:');

g = 9.8;
a1 = (a*pi)/180;

% cal total
total = (2*v*sin (a1))/g;
t = 0:(total/100):total;

x = v.*t.*cos (a1);
y = (v.*t).*sin (a1)-(0.5.*g.*t.^2);

% starting plot
plot (x,y);
title ('This is the project2');
hold on; 
