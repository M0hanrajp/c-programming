/* This program tests the life of an evaporator containing a gas.
We know the content of the evaporator (content in ml), the percentage 
of foam or gas lost every day (evap_per_day) and the threshold (threshold) 
in percentage beyond which the evaporator is no longer useful. All numbers 
are strictly positive.

The program reports the nth day (as an integer) on which the evaporator will be out of use.

Example:
evaporator(10, 10, 5) -> 29 */
int evaporator(double content, double evap_per_day, double threshold) {
  int days = 0;
  evap_per_day /= 100.0;threshold /= 100.0;threshold *= content;
  while (content >= threshold) {
    content -= (content * evap_per_day);
    days++;
  }
  return days;
}
