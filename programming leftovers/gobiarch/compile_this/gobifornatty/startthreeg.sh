#!/bin/bash

function chkroot {
	ROOT_UID=0
	if [ "$UID" -ne "$ROOT_UID" ]; then
		gksudo "./3gup.sh"
		exit 0		
	else 
		enablethreeg
	fi
}

function enablethreeg {
	cat /dev/null > /opt/Qualcomm/QDLService2k/QDLService2kNovatel.txt
	THREEGDEV=`dmesg | grep -i -o -e ttyUSB[0-9] | tail -1`
	/opt/Qualcomm/QDLService2k/QDLService2kNovatel /dev/$THREEGDEV
	BLAR=`cat /opt/Qualcomm/QDLService2k/QDLService2kNovatel.txt | grep failed | tail -1`
	if [[ $BLAR == *failed* ]]; then
		echo "3G Driver" "ERROR: $BLAR"
	else 
		echo "3G Driver" "Successfully completed firmware download" 
	fi
}

chkroot


