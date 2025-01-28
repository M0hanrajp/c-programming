/* Task
Write a function that accepts fight string consists of only small letters 
and return who wins the fight. When the left side wins return Left side wins!, 
when the right side wins return Right side wins!, in other case return Let's fight again!.
The left side letters and their power:
 w - 4
 p - 3
 b - 2
 s - 1
The right side letters and their power:
 m - 4
 q - 3
 d - 2
 z - 1
The other letters don't have power and are only victims.
Example
AlphabetWar("z");        //=> Right side wins!
AlphabetWar("zdqmwpbs"); //=> Let's fight again!
AlphabetWar("zzzzs");    //=> Right side wins!
AlphabetWar("wwwwwwz");  //=> Left side wins! */
char *alphabet_war(const char *fight) {
  unsigned rw = 0, lw = 0;
  for(unsigned i = 0; fight[i] != '\0'; i++) {
    switch(fight[i]) {
        case 'w' : lw += 4; break;
        case 'p' : lw += 3; break;
        case 'b' : lw += 2; break;
        case 's' : lw += 1; break;
        case 'm' : rw += 4; break;
        case 'q' : rw += 3; break;
        case 'd' : rw += 2; break;
        case 'z' : rw += 1; break;
        default  : break;
    }
  }
  return rw > lw ? "Right side wins!" : rw < lw ? "Left side wins!" : "Let's fight again!";
}
