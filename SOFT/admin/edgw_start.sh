#!/bin/bash

pwd_cur=`pwd`


echo "goto $SOFT/DGW/EDGW/bin; exec edgw ; back $pwd_cur"

cd $SOFT/DGW/EDGW/bin

./edgw &

cd $pwd_cur

