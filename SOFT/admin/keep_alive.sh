#!/bin/bash

source ~/.bash_profile

date >> /home/release/workspace/SETUP/lab_of_2012/SOFT/UGW/log/alive.log
/home/release/workspace/SETUP/lab_of_2012/SOFT/UGW/bin/MyBPML_exe /home/release/workspace/SETUP/lab_of_2012/SOFT/UGW/cnf/task/keep_mysql_active.xml >>/home/release/workspace/SETUP/lab_of_2012/SOFT/UGW/log/alive.log
