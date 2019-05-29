#!/bin/bash

source ~/.bash_profile

date >> /home/release/SOFT/UGW/log/alive.log
/home/release/SOFT/UGW/bin/MyBPML_exe /home/release/SOFT/UGW/cnf/task/keep_mysql_active.xml >>/home/release/SOFT/UGW/log/alive.log
