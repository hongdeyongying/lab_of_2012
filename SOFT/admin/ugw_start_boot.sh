#!/bin/bash


#sudo  /usr/sbin/nginx -c /etc/nginx/nginx.conf 

service mysql start

CONNSTR=127.0.0.1:8080
INNER_CONNSTR=127.0.0.1:8081

SOFT=/home/release/SOFT/

echo "${SOFT}fcgi/bin/cgi-fcgi -start -connect ${CONNSTR} ${SOFT}UGW/bin/ugw  10"
pwd_cur=`pwd`
cd ${SOFT}/UGW/bin
${SOFT}fcgi/bin/cgi-fcgi -start -connect ${CONNSTR} ${SOFT}UGW/bin/ugw  10

echo "${SOFT}fcgi/bin/cgi-fcgi -start -connect ${INNER_CONNSTR} ${SOFT}INNER_UGW/bin/inner_ugw  10"
cd ${SOFT}/INNER_UGW/bin
${SOFT}fcgi/bin/cgi-fcgi -start -connect ${INNER_CONNSTR} ${SOFT}INNER_UGW/bin/inner_ugw  10
cd $pwd_cur
