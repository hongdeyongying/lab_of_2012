#!/bin/bash


CONNSTR=127.0.0.1:8080
INNER_CONNSTR=127.0.0.1:8081


echo "${SOFT}fcgi/bin/cgi-fcgi -start -connect ${CONNSTR} ${SOFT}UGW/bin/ugw  1"
pwd_cur=`pwd`
cd ${SOFT}/UGW/bin
${SOFT}fcgi/bin/cgi-fcgi -start -connect ${CONNSTR} ${SOFT}UGW/bin/ugw  1
cd $pwd_cur


echo "${SOFT}fcgi/bin/cgi-fcgi -start -connect ${INNER_CONNSTR} ${SOFT}INNER_UGW/bin/inner_ugw  1"
pwd_cur=`pwd`
cd ${SOFT}/INNER_UGW/bin
${SOFT}fcgi/bin/cgi-fcgi -start -connect ${INNER_CONNSTR} ${SOFT}INNER_UGW/bin/inner_ugw  1
cd $pwd_cur
