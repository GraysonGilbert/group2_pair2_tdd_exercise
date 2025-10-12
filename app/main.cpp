/**
 * @file main.cpp
 * @author Grayson Gilbert (ggilbert@umd.edu) - Part 1 (Driver)
 * @author Siddhant Deshmukh (iamsid@umd.edu @umd.edu) - Part 1 (Navigator)
 * @author Tirth Sadaria (tsadaria@umd.edu) - Part 2  (Driver)
 * @author Aakash Dammala (asd@umd.edu) - Part 2 (Navigator)
 * @brief Example implementation for the PIDController class
 * @version 0.2
 * @date 2025-10-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>

#include "pid_controller.hpp"


int main() {
  std::cout << "\nStarting PID Controller Example:\n\n";

  // Modify the following values to change the PID controller reponse
  double kp{0.1};
  double ki{0.1};
  double kd{0.1};
  double dt{0.1};

  double set_point{5.0};
  double measured_value{0.0};

  // PID Control output
  double output{};

  std::cout << "Kp Value: " << kp << '\n';
  std::cout << "Ki Value: " << ki << '\n';
  std::cout << "Kd Value: " << kd << '\n';
  std::cout << "dt Value: " << dt << '\n';

  PIDController pid_controller(kp, ki, kd, dt);

  output = pid_controller.compute(set_point, measured_value);

  std::cout << "\nPID Control output value: " << output << "\n\n";

  return 0;
}
