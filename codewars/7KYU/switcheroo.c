/* Given a string made up of letters a, b, and/or c, switch the position of letters 
 * a and b (change a to b and vice versa). Leave any incidence of c untouched.
Example:
'acb' --> 'bca'
'aabacbaa' --> 'bbabcabb' */
char *switcheroo (char *string) {
  char *p = string;
  while(*string) {
    if(*string == 'a'){*string = 'b'; string++; continue;}
    if(*string == 'b'){*string = 'a'; string++; continue;}
    string++; 
  }
	return p;
}
