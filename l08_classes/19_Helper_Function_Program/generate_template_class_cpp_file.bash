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

read -r -p "Enter the class name: " class_name
header_file_name=class_name

read -r -p "Enter the namespace name: " namespace_name

header_file_pattern=$(echo ${header_file_name}|sed -e 's/[[:upper:]]/_&/g')
header_file_pattern=$(echo ${header_file_pattern}|sed -e 's/^_//g')

header_file_name=$(echo ${header_file_pattern}|sed -e 's/\(.*\)/\L\1/g')
absolute_path_header_file_name="$(pwd)/${header_file_name}.h"
absolute_path_source_file_name="$(pwd)/${header_file_name}.cpp"

header_file_pattern=$(echo ${header_file_pattern}|sed -e 's/\(.*\)/\U\1/g')
header_file_pattern=$(echo ${header_file_pattern}|sed -e 's/.*/__&_/g')

read -r -p "Enter your full name: " author_name

read -r -p "Enter the summary: " summary

read -r -p "Enter the details_description: " details_description 

echo "/*!             " > ${absolute_path_header_file_name}
echo "/*!             " > ${absolute_path_source_file_name}

echo " *" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_source_file_name}

echo " *  \file       "${header_file_name}.h >> ${absolute_path_header_file_name}
echo " *  \file       "${header_file_name}.cpp >> ${absolute_path_source_file_name}

echo " *" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_source_file_name}

echo " *  \brief      "Goal: ${summary} >> ${absolute_path_header_file_name}
echo " *  \brief      "Goal: ${summary} >> ${absolute_path_source_file_name}

echo " *" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_source_file_name}

echo " *  \details    "${details_description} >> ${absolute_path_header_file_name}
echo " *  \details    "${details_description} >> ${absolute_path_source_file_name}

echo " *" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_source_file_name}

echo " *  \author     "${author_name} >> ${absolute_path_header_file_name}
echo " *  \author     "${author_name} >> ${absolute_path_source_file_name}

echo " *" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_source_file_name}

echo " *  \version    "1.0 >> ${absolute_path_header_file_name}
echo " *  \version    "1.0 >> ${absolute_path_source_file_name}

echo " *" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_source_file_name}

echo " *  \date       "$(date) >> ${absolute_path_header_file_name}
echo " *  \date       "$(date) >> ${absolute_path_source_file_name}

echo " *  \copyright  "GNU Public License. >> ${absolute_path_header_file_name}
echo " *  \copyright  "GNU Public License. >> ${absolute_path_source_file_name}

echo " *" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_source_file_name}

echo " *" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_source_file_name}

echo " *" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_source_file_name}


echo " **/" >> ${absolute_path_header_file_name}
echo " **/" >> ${absolute_path_source_file_name}

echo >> ${absolute_path_header_file_name}
echo >> ${absolute_path_source_file_name}

echo "#ifndef" ${header_file_pattern} >> ${absolute_path_header_file_name}
echo "#define" ${header_file_pattern} >> ${absolute_path_header_file_name}

echo >> ${absolute_path_header_file_name}

echo namespace ${namespace_name} { >> ${absolute_path_header_file_name}
echo namespace ${namespace_name} { >> ${absolute_path_source_file_name}

echo //  \namaspace ${namespace_name} >> ${absolute_path_header_file_name}
echo //  \namaspace ${namespace_name} >> ${absolute_path_source_file_name}

echo >> ${absolute_path_header_file_name}
echo >> ${absolute_path_source_file_name}

echo "/* A class" ${class_name} "class*/" >> ${absolute_path_header_file_name}
echo class ${class_name} "{" >> ${absolute_path_header_file_name}

echo >> ${absolute_path_header_file_name}
echo >> ${absolute_path_source_file_name}

echo " public:" >> ${absolute_path_header_file_name}
echo "  "${class_name} "();" >> ${absolute_path_header_file_name}
echo "  ~"${class_name}"();" >> ${absolute_path_header_file_name}

echo >> ${absolute_path_header_file_name}
echo "  //Forbid the copy operations" >> ${absolute_path_header_file_name}
echo "  "${class_name} "(const" ${class_name} "&) = delete;" >> ${absolute_path_header_file_name}
echo "  "${class_name} "& operator= (const" ${class_name} "&) = delete;" >> ${absolute_path_header_file_name}

echo >> ${absolute_path_header_file_name}

echo "  //Forbid the move operations" >> ${absolute_path_header_file_name}
echo "  "${class_name} "("${class_name}"&&) = delete;" >> ${absolute_path_header_file_name}
echo "  "${class_name}"& operator= ("${class_name}"&&) = delete;" >> ${absolute_path_header_file_name}

echo >> ${absolute_path_header_file_name}
echo >> ${absolute_path_source_file_name}


echo "};" >> ${absolute_path_header_file_name}

echo >> ${absolute_path_header_file_name}

echo "/*! \\class" ${class_name}.h >> ${absolute_path_header_file_name}
echo " * \brief This is" ${class_name} "class" >> ${absolute_path_header_file_name}
echo " *" >> ${absolute_path_header_file_name}
echo " * Some details about the class" >> ${absolute_path_header_file_name}
echo " */" >> ${absolute_path_header_file_name}

echo >> ${absolute_path_header_file_name}
echo >> ${absolute_path_source_file_name}

echo ${class_name}::${class_name} "(){}" >> ${absolute_path_source_file_name}
echo ~${class_name}::${class_name} "(){}" >> ${absolute_path_source_file_name}

echo >> ${absolute_path_source_file_name}
echo }  // namespace ${namespace_name}  >> ${absolute_path_header_file_name}
echo }  // namespace ${namespace_name}  >> ${absolute_path_source_file_name}

echo "#endif //" ${header_file_pattern} >> ${absolute_path_header_file_name}

echo >>vim ${absolute_path_header_file_name}
