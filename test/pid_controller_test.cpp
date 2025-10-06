/**
 * @file pid_controller_test.cpp
 * @author Grayson Gilbert (ggilbert@umd.edu)
 * @brief Test cases for the PIDController class
 * @version 0.1
 * @date 2025-10-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 
#include <gtest/gtest.h>
#include <stdexcept>
#include "pid_controller.hpp"


// Declaring multiple test scenarios for the PIDController class

/*=========== Pure Proportional Controller Test ===========

Gains: kp = 1.0, ki = 0.0, kd = 0.0
Time interval = 1.0
Set Point = 10.0
Measured Value = 8.0

Solve for Proportional Output:
Proportional Output -> Kp * error
Error -> 10.0 - 8.0 = 2.0

Proportional Output = 1.0 * 2.0 = 2.0

*/
TEST(PIDControllerTest1, ProportionalTest) {
	PIDController controller(1.0, 0.0, 0.0, 1.0);
	double output = controller.compute(10.0, 8.0);
	EXPECT_DOUBLE_EQ(output, 2.0);
}

/*=========== Pure Integrator Test with Two Steps ===========

- The purpose of the two steps in the test is to show that the integral error will accumulate between loops

Gains: kp = 0.0, ki = 1.0, kd = 0.0
Time interval = 1.0
Set Point = 5.0
Measured Value = 0.0
Integral Error = 0.0

=========== Solve for Integral Output of loop 1: ===========

Integral Error -> Integral Error + Error
Error -> 5.0 - 0.0 = 5.0
Integral Output ->  Ki * Integral Error 
Integral Output -> 1.0 * 5.0 = 5.0 

=========== Solve for Integral Output of loop 2: ===========

Integral Error = 5.0
Error -> 5.0 - 0.0 = 5.0
Integral Error -> 5.0 + 5.0 = 10.0
Integral Output -> 1.0 * 10.0 = 10.0
*/

TEST(PIDControllerTest2, IntegralTest) {
	PIDController controller(0.0, 1.0, 0.0, 1.0);
	double first_output = controller.compute(5.0, 0.0);
	EXPECT_DOUBLE_EQ(first_output, 5.0);

	double second_output = controller.compute(5.0, 0.0);
	EXPECT_DOUBLE_EQ(second_output, 10.0);

}

/*===========  Pure Derivative Test with Two Steps ===========

Gains: kp = 0.0, ki = 0.0, kd = 1.0

=========== Solve for Derivative Output of Loop 1: ===========

Time interval = 1.0
Set Point = 10.0
Measured Value = 8.0
Previous Error = 0.0
Error -> 10.0 - 8.0 = 2.0

Derivative Output -> kd * (error - previous error) / dt
Derivative Output = 1.0 * (2.0 - 0.0) / 1.0 = 2.0

=========== Solve for Derivative Output of Loop 2: ===========

Set Point = 10.0
Measured Value = 9.0
Previous Error = 2.0
Error -> 10.0 - 9.0 = 1.0

Derivative Output -> 1.0 * (1.0 - 2.0) / 1 = -1
*/
TEST(PIDControllerTest3, DerivativeTest) {
	PIDController controller(0.0, 0.0, 1.0, 1.0);
	double first_output = controller.compute(10.0, 8.0);
	EXPECT_DOUBLE_EQ(first_output, 2.0);

	double second_output = controller.compute(10.0, 9.0);
	EXPECT_DOUBLE_EQ(second_output, -1.0);
}

/* =========== Mixed PID Test ===========

Gains: kp = 1.0, ki = 0.5, kd = 0.0
Set Point = 4.0
Measured Value = 2.0
Time Interval = 1.0
Integral Error = 0.0
Previous Error = 0.0

Proportional Output -> Kp * error
Integral Error -> Integral Error + Error
Integral Output ->  Ki * Integral Error 
Derivative Output -> kd * (error - previous error) / dt

PID Output -> Proportional Output + Integral Output + Derivative Output

=========== Solving for PID Output of Loop 1: ===========

Error -> 4.0 - 2.0 = 2.0
Proportional Output -> 1.0 * 2.0 = 2.0
Integral Error -> 0.0 + 2.0 = 2.0
Integral Output -> 0.5 * 2.0 = 1.0
Derivative Output -> 0.0 * (2.0 - 0.0) / 1.0 = 0.0

PID Output = 2.0 + 1.0 + 0.0 = 3.0

=========== Solving for PID Output of Loop 2: ===========

Error = 4.0 - 2.0 = 2.0
Proportional Output -> 1.0 * 2.0 = 2.0
Integral Error -> 2.0 + 2.0 = 4.0
Integral Output -> 0.5 * 4.0 = 2.0
Derivative Output -> 0.0 * (2.0 - 2.0) / 1.0 = 0.0

PID Output -> 2.0 + 2.0 + 0.0 = 4.0
*/

TEST(PIDControllerTest4, FullPIDTest) {
	PIDController controller(1.0, 0.5, 0.0, 1.0);
	double first_output = controller.compute(4.0, 2.0);
	EXPECT_DOUBLE_EQ(first_output, 3.0);

	double second_output = controller.compute(4.0, 2.0);
	EXPECT_DOUBLE_EQ(second_output, 4.0);

}


// Test case to avoid operation with zero dt
TEST(PIDControllerTest5, ThrowsOnZeroDt) {
	
	EXPECT_THROW(
		PIDController controller(1.0, 0.5, 2.0, 0.0),
		std::invalid_argument);
}

// Test case to avoid operation with negative dt
TEST(PIDControllerTest6, ThrowsOnNegativeDt) {
	
	EXPECT_THROW(
		PIDController controller(1.0, 0.5, 2.0, -0.1),
		std::invalid_argument);
}

/*=========== Upper Bound Controller Test ===========

Gains: kp = 5.0, ki = 0.0, kd = 0.0
Time interval = 1.0
Set Point = 10.0
Measured Value = 0.0

Solve for Proportional Output:
Proportional Output -> Kp * error
Error -> 10.0 - 0.0 = 10.0

Proportional Output = 5.0 * 10.0 = 50.0

Max Output -> 10.0

Control will be capped at 10.0 due to exceeding upper bound
*/

TEST(PIDControllerTest7, TestUpperBound) {
	PIDController controller(5.0, 0.0, 0.0, 1.0, 0.0, 10.0);
	double output = controller.compute(10, 0.0);
	EXPECT_DOUBLE_EQ(output, 10.0);
}

/*=========== Lower Bound Controller Test ===========

Gains: kp = 5.0, ki = 0.0, kd = 0.0
Time interval = 1.0
Set Point = 0.0
Measured Value = 10.0

Solve for Proportional Output:
Proportional Output -> Kp * error
Error -> 0.0 - 10.0 = -10.0

Proportional Output = 5.0 * -10.0 = -50.0

Min Output -> -10.0

Control will be capped at -10.0 due to exceeding lower bound
*/

TEST(PIDControllerTest8, TestLowerBound) {
	PIDController controller(5.0, 0.0, 0.0, 1.0, -10.0, 10.0);
	double output = controller.compute(0.0, 10.0);
	EXPECT_DOUBLE_EQ(output, -10.0);
}