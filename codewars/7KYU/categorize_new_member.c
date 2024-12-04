/* The Western Suburbs Croquet Club has two categories of membership, Senior and Open. 
 * They would like your help with an application form that will tell prospective members 
 * which category they will be placed. To be a senior, a member must be at least 55 years
 * old and have a handicap greater than 7. In this croquet club, handicaps range from -2 
 * to +26; the better the player the lower the handicap. */
// input =  [[18, 20], [45, 2], [61, 12], [37, 6], [21, 21], [78, 9]]
// output = ["Open", "Open", "Senior", "Open", "Open", "Senior"]
#include <stddef.h>
enum membership {OPEN = 1, SENIOR = 2};
void open_or_senior (size_t n, const int members[n][2], enum membership memberships[n]) {
  for(size_t i = 0; i < n; i++) {
    members[i][0] >= 55 && members[i][1] > 7 ? (memberships[i] = SENIOR) : (memberships[i] = OPEN);
  }
}
