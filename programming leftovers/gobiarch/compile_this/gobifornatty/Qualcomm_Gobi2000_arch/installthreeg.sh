#!/bin/bash

function chkroot {
	ROOT_UID=0
	if [ "$UID" -ne "$ROOT_UID" ]; then
		sudo bash "./installthreeg.sh"
		exit 0		
	else 
		makeandinstall
	fi
}

function makeandinstall {
	cd QCSerial2k
	make
	make install
	cd ../QCUSBNet
	make
	make install
}

chkroot


