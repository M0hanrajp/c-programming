/* Complete the function so that it finds the average of the three scores 
 * passed to it and returns the letter value associated with that grade.

Numerical Score	Letter Grade
90 <= score <= 100	'A'
80 <= score < 90	'B'
70 <= score < 80	'C'
60 <= score < 70	'D'
0 <= score < 60	'F'
Tested values are all between 0 and 100. Theres is no need to check for 
negative values or values greater than 100. */
char get_grade(int a, int b, int c) {
  int avg = (a + b + c) / 3;
  static char res = 0;
  if(avg >= 90 && avg <= 100)
    res = 'A';
  if(avg >= 80 && avg < 90)
    res = 'B';
  if(avg >= 70 && avg < 80)
    res = 'C';
  if(avg >= 60 && avg < 70)
    res = 'D';
  if(avg >= 0 && avg < 60)
    res = 'F';
  return res;
}
