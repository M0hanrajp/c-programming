/* In this kata, you should calculate the type of triangle with three given sides a, b and c (given in any order).
If each angle is less than 90°, this triangle is acute and the function should return 1.
If one angle is strictly 90°, this triangle is right and the function should return 2.
If one angle is more than 90°, this triangle is obtuse and the function should return 3.
If three sides cannot form a triangle, or one angle is 180° (which turns the triangle into a segment) - the function should return 0.
Three input parameters are sides of given triangle. All input values are non-negative floating point or integer numbers (or both, depending on the language). */
/* (2, 4, 6) ---> return 0 (Not triangle)
(8, 5, 7) ---> return 1 (Acute, angles are approx. 82°, 38° and 60°)
(3, 4, 5) ---> return 2 (Right, angles are approx. 37°, 53° and exactly 90°)
(7, 12, 8) ---> return 3 (Obtuse, angles are approx. 34°, 106° and 40°) */
//  Should return triangle type
//  0 : if triangle cannot be made with given sides
//  1 : acute triangle
//  2 : right triangle
//  3 : obtuse triangle
//  Check for valid triangle
int checkTriangleEquality(int a, int b, int c) {
  return a + b > c ? (b + c > a ? (c + a > b ? 1 : 0) : 0) : 0;
}
//  Get the largest side
int get_hyp(int a, int b, int c) {
  if(a > b && a > c){return a;}
  if(b > a && b > c){return b;}
  if(c > a && c > b){return c;}
  if(a == b || a == c){return a;}
  if(b == a || b == c){return b;}
  if(c == a || c == b){return c;}
  return 0;
}
//  Check triangle type
int triangleType(int a, int b, int c) {
  if((a == b) && (b == c) && (c == a)){return 1;}
  int cc = get_hyp(a, b, c);
  int aa = (cc != a) ? a : (cc != b) ? b : (cc != c) ? c : 0;
  int bb = (cc == a || cc == b) && (aa == b || aa == a) ? c : 
           (cc == b || cc == c) && (aa == c || aa == b) ? a : 
           (cc == c || cc == a) && (aa == a || aa == c) ? b : 0;
  if(checkTriangleEquality(aa, bb, cc)){
    if((cc * cc) <  ((aa * aa) + (bb * bb))){return 1;}
    if((cc * cc) == ((aa * aa) + (bb * bb))){return 2;}
    if((cc * cc) >  ((aa * aa) + (bb * bb))){return 3;}
  }
  return 0;
}
