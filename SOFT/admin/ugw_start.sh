#!/bin/bash


#sudo  /usr/sbin/nginx -c /etc/nginx/nginx.conf 

#service mysql start

CONNSTR=${SOFT}UGW/bin/sock.unix.8080
INNER_CONNSTR=${SOFT}UGW/bin/sock.unix.8081

#SOFT=/home/release/SOFT/

echo "cgi-fcgi -start -connect ${CONNSTR} ${SOFT}UGW/bin/ugw  10"
#pwd_cur=`pwd`
#cd ${SOFT}/UGW/bin
cgi-fcgi -start -connect ${CONNSTR} ${SOFT}UGW/bin/ugw  10

cgi-fcgi -start -connect ${INNER_CONNSTR} ${SOFT}INNER_UGW/bin/inner_ugw  10
#cd $pwd_cur
