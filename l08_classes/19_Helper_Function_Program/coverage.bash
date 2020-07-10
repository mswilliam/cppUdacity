############################################################
#
# Author: MANGOUA SOFACK William
#
# Date Created: Wed Jun 24 02:53:23 CEST 2020
#
# Description: This srcipt perform the coverage test
#
# Date Modified: Wed Jun 24 02:53:23 CEST 2020
############################################################

clear
echo
component_dir="$(pwd)/components"
build_dir="$(pwd)/build/components"

for component in $(ls ${component_dir})
do
  for test_file_cpp in $(ls ${component_dir}/${component}/src)
  do
    test_file=${test_file_cpp%.cpp}
    gcov_dir=${build_dir}/${component}/src/
    gcov_in_file=${component_dir}/${component}/src/${test_file_cpp}
    gcov_data_file=${build_dir}/${component}/src/${test_file}
    gcov_objet_file=${build_dir}/${component}/src/${test_file}.o

  
    gcov --object-directory ${gcov_dir}  ${gcov_in_file} ${gcov_data_file} --object-file ${gcov_objet_file} ${gcov_data_file}

    mv ${test_file}*.gcov ${build_dir}/${component}/src/
    rm -rf *.gcov
  done
done

echo
