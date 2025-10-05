/**
 * @file pid_controller.cpp
 * @author Grayson Gilbert (ggilbert@umd.edu)
 * @brief PIDController class function definitions
 * @version 0.1
 * @date 2025-10-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <pid_controller.hpp>

// Construct a PID Controller
PIDController::PIDController(const double kp, const double ki, const double kd, const double dt, const double min, const double max)
    : kp_(kp), ki_(ki), kd_(kd), dt_(dt), min_(min), max_(max), previous_error_(0.0), integral_error_(0.0) {}


// Compute the PID control output value
double PIDController::compute(double set_point, double measured_value){

    // Current stub implementation

    return 0; // Return value will be changed when function is implemented
}

