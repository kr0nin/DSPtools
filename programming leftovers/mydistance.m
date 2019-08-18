(* ::Package:: *)

%%%%%%%%%%%%%%
% calc the distance of two points
%%%%%%%%%%%%%%
x1 = input ('Please input the value of x1:');
y1 = input ('Please input the value of y1:');
x2 = input ('Please input the value of x2:');
y2 = input ('Please input the value of y2:');

dist = sqrt ((x1-x2)^2+(y1-y2)^2);

fprintf ('the distance between point (% d,% d) and (% d,% d) is % f',x1,y1,x2,y2,dist);
