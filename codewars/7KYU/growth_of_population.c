/* In a small town the population is p0 = 1000 at the beginning of a year. 
 * The population regularly increases by 2 percent per year and moreover 
 * 50 new inhabitants per year come to live in the town. How many years 
 * does the town need to see its population greater than or equal to p = 1200 inhabitants?

At the end of the first year there will be: 
1000 + 1000 * 0.02 + 50 => 1070 inhabitants

At the end of the 2nd year there will be: 
1070 + 1070 * 0.02 + 50 => 1141 inhabitants (** number of inhabitants is an integer **)

At the end of the 3rd year there will be:
1141 + 1141 * 0.02 + 50 => 1213

It will need 3 entire years. */
int nbYear(int p0, double percent, int aug, int p) {
  int y = 0;
  while(p0 < p) {p0 = p0 + (p0 * (percent / 100)) + aug;y++;}
  return y;
}
