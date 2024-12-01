/* You will need a rental car in order for you to get around in your vacation. 
 * The manager of the car rental makes you some good offers.
 * Every day you rent the car costs $40. If you rent the car for 7 or more days, 
 * you get $50 off your total. Alternatively, if you rent the car for 3 or more 
 * days, you get $20 off your total.
Write a code that gives out the total amount for different days(d). */
unsigned rental_car_cost(unsigned d) {
  unsigned cost = d * 40;
  d > 6 ? (cost -= 50) : d > 2 ? (cost -= 20) : (cost = cost * 1u);
  return cost;
}
