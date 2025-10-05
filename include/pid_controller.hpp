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
     */
    PIDController(double kp_, double ki_, double kd_, double dt_);

    /**
     * @brief Computes the next PID control output value
     * 
     * @param setpoint - The desired value to be reached
     * @param measured_value - The current measured value of the system
     * @return double - Returns the output control value for the next iteration of the control loop
     */
    double compute(double set_point, double measured_value);

    private:

    double kp_; // Proportional gain value
    double ki_; // Integral gain value
    double kd_; // Derivative gain value
    double dt_; // Loop time interval

    double integral_error_; // Total integral error value
    double previous_error_; // Error value from previous control loop
    
};


#endif //PID_CONTROLLER_HPP_