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
  for test_file_cpp in $(ls ${component_dir}/${component}/tests)
  do
    test_file=${test_file_cpp%.cpp}
    gcov --object-directory ${build_dir}/${component}/tests/ ${component_dir}/${component}/tests/${test_file_cpp} ${build_dir}/${component}/tests/${test_file} --object-file ${build_dir}/${component}/tests/${test_file}.o ${build_dir}/${component}/tests/${test_file}

    mv *.gcov ${build_dir}/${component}/tests/
  done
done

echo
