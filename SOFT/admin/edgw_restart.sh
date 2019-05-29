#!/bin/bash

pwd_cur=`pwd`

killall -15  edgw
sleep 1
killall -9 edgw



echo "goto $SOFT/DGW/EDGW/bin; exec edgw ; back $pwd_cur"

cd $SOFT/DGW/EDGW/bin

./edgw &

cd $pwd_cur

