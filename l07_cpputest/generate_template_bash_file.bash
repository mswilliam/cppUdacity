#!/bin/bash

##############################
# Author: MANGOUA SOFACK William
# Date: 23/06/2020
# Description: File script template generator
# Modification : 23/06/2020
##############################
clear
echo
read -r -p "Enter the script file name: " script_name
script_name="$(pwd)/${script_name}.bash"

read -r -p "Enter your full name: " author_name

read -r -p "Enter the description: " description

#echo "#!/bin/bash" > ${script_name}
echo
echo "############################################################" >> ${script_name}
echo "#" >> ${script_name}
echo "# Author:" ${author_name} >> ${script_name}
echo "#" >> ${script_name}
echo "# Date Created:" $(date) >> ${script_name}
echo "#" >> ${script_name}
echo "# Description:" $description >> ${script_name}
echo "#" >> ${script_name}
echo "# Date Modified:" $(date) >> ${script_name}
echo "############################################################" >> ${script_name}

echo
chmod a+x ${script_name}

vim ${script_name}

