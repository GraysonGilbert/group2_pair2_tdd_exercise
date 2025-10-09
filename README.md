# C++ Test Driven Development Exercise: PID Controller Implementation
![CICD Workflow status](https://github.com/GraysonGilbert/group2_pair2_tdd_exercise/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/GraysonGilbert/group2_pair2_tdd_exercise/graph/badge.svg?token=9BMMT6K9FG)](https://codecov.io/gh/GraysonGilbert/group2_pair2_tdd_exercise) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

## Part 1 Roles:
Driver: Grayson Gilbert  
Navigator: Siddhant Deshmukh  

## Part 2 Roles:
Driver: Tirth Sadaria  
Navigator: Aakash Dammala

## Part 2 Implementation Summary:

### Design Review Discussion
The design provided by Pair 1 (Grayson Gilbert & Siddhant Deshmukh) was well-structured with:
- Clear class interface with public `compute()` method
- Private helper methods for modular calculation of P, I, and D components
- Appropriate use of member variables to track state (integral_error, previous_error)
- Comprehensive test suite covering all edge cases

### Implementation Approach
Following TDD principles, we implemented the PID controller in logical commits:

1. **Implemented helper methods** - Created the three component calculation methods (proportional, integral, derivative)
2. **Completed compute method** - Integrated all components with error calculation and output clamping
3. **Added input validation** - Implemented dt parameter validation to prevent division by zero

### Key Implementation Details
- **Proportional component**: `kp * error`
- **Integral component**: Accumulates error over time using `integral_error += error * dt`, returns `ki * integral_error`
- **Derivative component**: Calculates rate of change `kd * (error - previous_error) / dt`
- **Output clamping**: Ensures output stays within [min, max] bounds
- **Input validation**: Throws `std::invalid_argument` for non-positive dt values
- **Default bounds**: Changed from [0.0, 10.0] to [-100.0, 100.0] to accommodate negative control outputs

### Test Results
All 8 unit tests pass successfully:
- ✅ Proportional controller test
- ✅ Integral controller test  
- ✅ Derivative controller test
- ✅ Full PID controller test
- ✅ Zero dt validation test
- ✅ Negative dt validation test
- ✅ Upper bound clamping test
- ✅ Lower bound clamping test

### Code Quality
- **Cppcheck**: No issues found (output in `cppcheck_output.txt`)
- **Code coverage**: Available via CodeCov badge above
- **Documentation**: All methods documented with Doxygen-style comments

### Additional Tests Recommended
Based on our review, we recommend adding:
- [ ] Test for integral windup prevention
- [ ] Test for setpoint changes during operation
- [ ] Test for large dt values
- [ ] Performance test for control loop timing

### TODO Items
- Consider adding anti-windup mechanism for integral component
- Add reset() method to clear integral and derivative state
- Consider making min/max bounds mutable for runtime adjustment

## Standard install via command-line:
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
```
## Building for code coverage:

```bash
# if you don't have gcovr or lcov installed, do:
  sudo apt-get install gcovr lcov
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
# Now, do a clean compile, run unit test, and generate the covereage report
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

This generates a index.html page in the build/test_coverage sub-directory that can be viewed locally in a web browser.
```

You can also get code coverage report for the pid_controller_example target, instead of unit test. Repeat the previous 2 steps but with the *app_coverage* target:

``` bash
# Now, do another clean compile, run pid_controller_example, and generate its covereage report
  cmake --build build/ --clean-first --target all app_coverage
# open a web browser to browse the test coverage report
  open build/app_coverage/index.html

This generates a index.html page in the build/app_coverage sub-directory that can be viewed locally in a web browser.
```
