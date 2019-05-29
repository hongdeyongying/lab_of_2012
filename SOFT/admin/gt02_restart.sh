#!/bin/bash

pwd_cur=`pwd`

killall -9 device_gt02



echo "goto $SOFT/DGW/EDGW/bin; exec device_gt02; back $pwd_cur"

cd $SOFT/DGW/EDGW/bin

./device_gt02 --intval=1 >1.log &

cd $pwd_cur
