# C++ Test Driven Development Exercise: PID Controller Implementation
![CICD Workflow status](https://github.com/GraysonGilbert/group2_pair2_tdd_exercise/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/GraysonGilbert/group2_pair2_tdd_exercise/graph/badge.svg?token=9BMMT6K9FG)](https://codecov.io/gh/GraysonGilbert/group2_pair2_tdd_exercise) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


## Standard install via command-line
```bash
# Download the code:
  git clone https://github.com/GraysonGilbert/group2_pair2_tdd_exercise
  cd group2_pair2_tdd_exercise
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/shell-app
# Run tests:
  cd build/; ctest; cd -
  # or if you have newer cmake
  ctest --test-dir build/
# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/

