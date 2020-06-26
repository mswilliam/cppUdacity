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

read -r -p "Enter the summary: " summary

read -r -p "Enter the details_description: " details_description 

echo "/*!             " > ${header_file_name}
echo " *" >> ${header_file_name}
echo " *  \file       "${header_file_name} >> ${header_file_name}
echo " *" >> ${header_file_name}
echo " *  \brief      "Goal: ${summary} >> ${header_file_name}
echo " *" >> ${header_file_name}
echo " *  \details    "${details_description} >> ${header_file_name}
echo " *" >> ${header_file_name}
echo " *  \author     "${author_name} >> ${header_file_name}
echo " *" >> ${header_file_name}
echo " *  \version    "1.0 >> ${header_file_name}
echo " *" >> ${header_file_name}
echo " *  \date       "$(date) >> ${header_file_name}
echo " *  \copyright  "GNU Public License. >> ${header_file_name}
echo " *" >> ${header_file_name}
echo " *" >> ${header_file_name}
echo " *" >> ${header_file_name}
echo " **/" >> ${header_file_name}



vim ${header_file_name}
