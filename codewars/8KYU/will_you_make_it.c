/*
 * You were camping with your friends far away from home, but when it's time to go back, 
 * you realize that your fuel is running out and the nearest pump is 50 miles away! You 
 * know that on average, your car runs on about 25 miles per gallon. There are 2 gallons left.
 * Considering these factors, write a function that tells you if it is possible to get to the 
 * pump or not.
 * Function should return true if it is possible and false if not.
 */
#include <stdbool.h>

bool zero_fuel(double distance_to_pump, double mpg, double fuel_left) {
  return (distance_to_pump <= mpg * fuel_left);
}
    // test_zero_fuel(50, 25, 2, true);
    // test_zero_fuel(60, 30, 3, true);
    // test_zero_fuel(70, 25, 1, false);
    // test_zero_fuel(100, 25, 3, false);
