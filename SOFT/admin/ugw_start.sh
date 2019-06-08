#!/bin/bash


#sudo  /usr/sbin/nginx -c /etc/nginx/nginx.conf 

#service mysql start

export NGINX_TMP=/home/release/workspace/SETUP/docker_lab_2012/nginx/data/tmp

#CONNSTR=${NGINX_TMP}/sock.unix.8080
CONNSTR=10.116.207.174:8080
#INNER_CONNSTR=${NGINX_TMP}/sock.unix.8081
INNER_CONNSTR=10.116.207.174:8081

#SOFT=/home/release/SOFT/

echo "cgi-fcgi -start -connect ${CONNSTR} ${SOFT}UGW/bin/ugw  10"
pwd_cur=`pwd`
cd ${SOFT}/UGW/bin
cgi-fcgi -start -connect ${CONNSTR} ${SOFT}UGW/bin/ugw  10

echo "cgi-fcgi -start -connect ${INNER_CONNSTR} ${SOFT}INNER_UGW/bin/inner_ugw  10"
cgi-fcgi -start -connect ${INNER_CONNSTR} ${SOFT}INNER_UGW/bin/inner_ugw  10
cd $pwd_cur
