#!/bin/bash

./device_gt02 --imei=123456789012345 --intv=1 > 123456789012345.txt &
sleep 2
./device_gt02 --imei=123456789012340 --intv=1 > 123456789012340.txt &
sleep 2
./device_gt02 --imei=123456789012341 --intv=1 > 123456789012341.txt &
sleep 2
./device_gt02 --imei=123456789012342 --intv=1 > 123456789012342.txt &
sleep 2
./device_gt02 --imei=123456789012343 --intv=1 > 123456789012343.txt &
sleep 2
./device_gt02 --imei=123456789012344 --intv=1 > 123456789012344.txt &
sleep 2
./device_gt02 --imei=123456789012346 --intv=1 > 123456789012346.txt &
sleep 2
./device_gt02 --imei=123456789012347 --intv=1 > 123456789012347.txt &
sleep 2
./device_gt02 --imei=123456789012348 --intv=1 > 123456789012348.txt &
sleep 2
./device_gt02 --imei=123456789012349 --intv=1 > 123456789012349.txt &
sleep 2

./ldd_admin --cmd=reg --imei=123456789012340
./ldd_admin --cmd=reg --imei=123456789012341
./ldd_admin --cmd=reg --imei=123456789012342
./ldd_admin --cmd=reg --imei=123456789012343
./ldd_admin --cmd=reg --imei=123456789012344
./ldd_admin --cmd=reg --imei=123456789012346
./ldd_admin --cmd=reg --imei=123456789012345
./ldd_admin --cmd=reg --imei=123456789012347
./ldd_admin --cmd=reg --imei=123456789012348
./ldd_admin --cmd=reg --imei=123456789012349
