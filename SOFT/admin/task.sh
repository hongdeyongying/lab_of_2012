#!/bin/bash

source ~/.bash_profile

date +"%Y-%m-%d %H:%M:%S" >> /home/release/workspace/SETUP/lab_of_2012/SOFT/UGW/log/task.log
/home/release/workspace/SETUP/lab_of_2012/SOFT/UGW/bin/MyBPML_exe /home/release/workspace/SETUP/lab_of_2012/SOFT/UGW/cnf/task/mysql_stat_yesterday.xml >>/home/release/workspace/SETUP/lab_of_2012/SOFT/UGW/log/task.log
