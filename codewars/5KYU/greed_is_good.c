/* Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it, is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point
A single die can only be counted once in each roll. For example, a given "5" can only count as part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)
  {
    const int dice[5] = {5, 5, 5, 3, 3};
    cr_assert_eq(score(dice), 500);
  } 
  {
    const int dice[5] = {1, 1, 1, 1, 3};
    cr_assert_eq(score(dice), 1100);
In some languages, it is possible to mutate the input to the function. This is something that you should never do. If you mutate the input, you will not be able to pass all the tests. */
int score(const int dice[5]) {
  int throw_1 = 0, throw_2 = 0, throw_3 = 0, 
      throw_4 = 0, throw_5 = 0, throw_6 = 0;
  int result = 0;
  for(int i = 0; i < 5; i++) {
    switch(dice[i]) {
        case 1: throw_1++; break;
        case 2: throw_2++; break;
        case 3: throw_3++; break;
        case 4: throw_4++; break;
        case 5: throw_5++; break;
        case 6: throw_6++; break;
       default: break;
    }
  }
  if(throw_1 >= 3){result += 1000; throw_1 -= 3;}
  if(throw_5 >= 3){result +=  500; throw_5 -= 3;}
  result += throw_2 >= 3 ?  200 : 0;
  result += throw_3 >= 3 ?  300 : 0;
  result += throw_4 >= 3 ?  400 : 0;
  result += throw_6 >= 3 ?  600 : 0;
  result += throw_1 >= 1 && throw_1 <= 2 ? throw_1 * 100 : 0;
  result += throw_5 >= 1 && throw_5 <= 2 ? throw_5 *  50 : 0;
  return result;
}
