cd build/ || exit
ctest --progress
lcov -c -d . -o main_coverage.info
lcov --remove main_coverage.info '/usr/*' --output-file main_coverage.info
lcov --remove main_coverage.info /*/test/* --output-file main_coverage.info
lcov --remove main_coverage.info /*/app/* --output-file main_coverage.info
genhtml main_coverage.info --output-directory ../Coverage