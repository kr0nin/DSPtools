
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Script file: proj3.m
%  Author: Erich Kroneberger
%
% Purpose:
%     this program can convert a military time (1440) into a 
%     conventional 12-hour time (2:40pm).
%
% Define variables:
%     miltime     --user defined military time
%     hours       --miltime hours
%     minutes     --minutes
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Prompt the user for military time
miltime = input ('Enter military time: ');

% convert for just hours...
hours = floor(miltime/100);

% and just minutes...
minutes = ((miltime/100)-(fix (miltime/100)))*100;

if      miltime > 2359; %this is to limit the input to military time.
        
        fprintf ('invalid format, military time is between 0000 and 2400')
        
elseif  minutes > 59; %also to limit. tis is for minutes.
        
        fprintf ('invalid format, minutes are between 00 and 59')

elseif  miltime < 100; %this is in the hour of midnight.
        hours = 12;
        minutes = ((miltime/100)-(fix (miltime/100)))*100;

        fprintf ('The standard time for %d is %d:%02g am \n'...
                  ,miltime, hours, minutes);

elseif  hours== 12; % this is for noon.
        
        fprintf ('The standard time for %d is %d:%02g pm \n'...
                  ,miltime, hours, minutes);

elseif  hours > 12; %this is anything in the pm.
        hours = hours-12;
        
        fprintf ('The standard time for %d is %d:%02g pm \n'...
                  ,miltime, hours, minutes);
        
else    %this is any other am times.
        fprintf ('The standard time for %d is %d:%02g am \n'...
                  ,miltime, hours, minutes);
end              