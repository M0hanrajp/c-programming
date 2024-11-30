/* The first century spans from the year 1 up to and including the year 100, the second century 
 * - from the year 101 up to and including the year 200, etc.

Task
Given a year, return the century it is in.

Examples
1705 --> 18
1900 --> 19
1601 --> 17
2000 --> 20
2742 --> 28 */
int centuryFromYear(int year) {
  return year > 100 ? !( year % 100 ) ? year / 100 : year / 100 + 1 : 1 ;
}
/* self written logic :)
 * it says if year is more than 100
 * check if year divided by 100 gives reminder 0
 * if yes then just return the number divided by 100
 * else return number divided by 100 + 1
 * if all condition not satisfied then return 1.
 * follows strict from table in https://en.wikipedia.org/wiki/Century
 */
