%This is an m-file that is a user-defined function, which
%adjust a set of grades such that they fit a user provided average.  This
%function exchanges information with the calling program through the global
%variables "GRADES" and "NEWGRADES", so there is no separate return variable
%required in the function.

function curve(newav)
global GRADES NEWGRADES;
avgrd=mean(GRADES);
NEWGRADES=(newav/avgrd)*GRADES;