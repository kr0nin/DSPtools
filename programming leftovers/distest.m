%%%%%distest.m
x1 = input ('Please input the value of x1:');
y1 = input ('Please input the value of y1:');
x2 = input ('Please input the value of x2:');
y2 = input ('Please input the value of y2:');

d = mydist(x1,y1,x2,y2);
fprintf('the distance between the points is %g\n', d);