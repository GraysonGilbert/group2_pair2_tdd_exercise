/**
 * @file pid_controller.cpp
 * @author Grayson Gilbert (ggilbert@umd.edu) - Part 1 (Driver)
 * @author Siddhant Deshmukh (siddhantd@umd.edu) - Part 1 (Navigator)
 * @author Tirth Sadaria (tirths@umd.edu) - Part 2  (Driver)
 * @author Aakash Dammala (aakashd@umd.edu) - Part 2 (Navigator)
 * @brief PIDController class function definitions
 * @version 0.2
 * @date 2025-10-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <pid_controller.hpp>
#include <stdexcept>

// Construct a PID Controller
PIDController::PIDController(const double kp, const double ki, const double kd, const double dt, const double min, const double max)
    : kp_(kp), ki_(ki), kd_(kd), dt_(dt), min_(min), max_(max), previous_error_(0.0), integral_error_(0.0) {
        if (dt <= 0.0) {
            throw std::invalid_argument("dt must be positive");
        }
    }


// Compute the PID control output value
double PIDController::compute(double set_point, double measured_value){

    // Calculate the current error
    double error = set_point - measured_value;
    
    // Calculate PID components
    double proportional = compute_proportional(error);
    double integral = compute_integral(error);
    double derivative = compute_derivative(error);
    
    // Calculate total PID output
    double output = proportional + integral + derivative;
    
    // Clamp output to min/max bounds
    if (output > max_) {
        output = max_;
    } else if (output < min_) {
        output = min_;
    }
    
    return output;
}

// Compute the proportional component of the PID control output
double PIDController::compute_proportional(double error) {
    return kp_ * error;
}

// Compute the integral component of the PID control output
double PIDController::compute_integral(double error) {
    integral_error_ += error * dt_;
    return ki_ * integral_error_;
}

// Compute the derivative component of the PID control output
double PIDController::compute_derivative(double error) {
    double derivative = kd_ * (error - previous_error_) / dt_;
    previous_error_ = error;
    return derivative;
}