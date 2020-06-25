#!/bin/bash

############################################################
#
# Author: MANGOUA SOFACK William
#
# Date Created: Thu Jun 25 11:35:07 CEST 2020
#
# Description: This script generates a .h template file
#
# Date Modified: Thu Jun 25 11:35:07 CEST 2020
############################################################

clear
echo

read -r -p "Enter the file name without the .h extention:" header_file_name

read -r -p "Enter the namespace name:" namespace_name

header_file_pattern=$(echo ${header_file_name}|sed -e 's/[[:upper:]]/_&/g')
header_file_pattern=$(echo ${header_file_pattern}|sed -e 's/^_//g')

header_file_name=$(echo ${header_file_pattern}|sed -e 's/\(.*\)/\L\1/g')
header_file_name="$(pwd)/${header_file_name}.h"

header_file_pattern=$(echo ${header_file_pattern}|sed -e 's/\(.*\)/\U\1/g')
header_file_pattern=$(echo ${header_file_pattern}|sed -e 's/.*/__&__/g')

read -r -p "Enter your full name: " author_name

read -r -p "Enter the description: " description

echo "/*!" > ${header_file_name}
echo " *  \file ${header_file_name}" >> ${header_file_name}






echo header file name: ${header_file_name}
echo header file pattern: ${header_file_pattern}
echo namespace name: ${namespace_name}

