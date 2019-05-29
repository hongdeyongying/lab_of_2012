#!/bin/bash

source ~/.bash_profile

date +"%Y-%m-%d %H:%M:%S" >> /home/release/SOFT/UGW/log/task.log
/home/release/SOFT/UGW/bin/MyBPML_exe /home/release/SOFT/UGW/cnf/task/mysql_stat_yesterday.xml >>/home/release/SOFT/UGW/log/task.log
