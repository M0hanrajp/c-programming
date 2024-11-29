/* Write a function to convert a name into initials. This kata strictly 
takes two words with one space in between them.

The output should be two capital letters with a dot separating them.

It should look like this:

Sam Harris => S.H

patrick feeney => P.F */
char *get_initials (const char *full_name, char initials[4])
{
  // write to initials
  // First word initial at index[0] of initials
  if(full_name[0] >= 65 && full_name[0] <= 90)
    initials[0] = full_name[0];
  else
    initials[0] = full_name[0] - 32;
  for(int index = 0; full_name[index] != '\0'; index++) {
    //'.' character & Second word initial at index[1] & index[2]
    if(full_name[index] == 32) {
      initials[1] = '.';
      if(full_name[index + 1] >= 65 && full_name[index + 1] <= 90)
        initials[2] = full_name[index + 1];
      else
        initials[2] = full_name[index + 1] - 32;
      break;
    }
  }
  initials[3] = '\0';
  return initials; // return it
}

 //    do_test("Sam Harris", "S.H");
 //    do_test("Patrick Feenan", "P.F");
 //    do_test("Evan Cole", "E.C");
 //    do_test("P Favuzzi", "P.F");
 //    do_test("David Mendieta", "D.M");
 //    do_test("george clooney", "G.C");
 //    do_test("marky mark", "M.M");
 //    do_test("eliza doolittle", "E.D");
 //    do_test("reese witherspoon", "R.W");
