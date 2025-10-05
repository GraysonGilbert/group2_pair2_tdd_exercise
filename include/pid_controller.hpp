/**
 * @file pid_controller.hpp
 * @author Grayson Gilbert (ggilbert@umd.edu)
 * @brief Header file for PIDController class
 * @version 0.1
 * @date 2025-10-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef PID_CONTROLLER_HPP_
#define PID_CONTROLLER_HPP_


class PIDController {

    public:

    /**
     * @brief Construct a new PIDController object
     * 
     * @param kp_ - Proportional gain
     * @param ki_ - Integral gain
     * @param kd_ - Derivative gain
     * @param dt_ - Loop time interval
     * @param min - Minimum output provided by the controller
     * @param max - Maximum output provided by the controller
     */
    PIDController(const double kp_, const double ki_, const double kd_, const double dt_, const double min_ = 0.0, const double max_ = 10.0);


    /**
     * @brief Computes the next PID control output value
     * 
     * @param setpoint - The desired value to be reached
     * @param measured_value - The current measured value of the system
     * @return double - Returns the output control value for the next iteration of the control loop
     */
    double compute(double set_point, double measured_value);


    private:

    /**
     * @brief Helper function for compute, calculates the proportional component of the control output
     * 
     * @param error - The difference between the set_point and the measured_value
     * @return double - Returns the proportional component of the control output
     */
    double compute_proportional(double error);

    /**
     * @brief Helper function for compute, calculates the integral component of the control output
     * 
     * @param error - The difference between the set_point and the measured_value
     * @return double - Returns the integral component of the control output
     */
    double compute_integral(double error);

    /**
     * @brief Helper function for compute, calculates the derivative component of the control output
     * 
     * @param error - The difference between the set_point and the measured_value
     * @return double - Returns the derivative component of the control output
     */
    double compute_derivative(double error);


    const double kp_; // Proportional gain value
    const double ki_; // Integral gain value
    const double kd_; // Derivative gain value
    const double dt_; // Loop time interval
    const double min_; // Minimum control output
    const double max_; // Maximum control output

    double integral_error_; // Total integral error value
    double previous_error_; // Error value from previous control loop
    
};


#endif //PID_CONTROLLER_HPP_