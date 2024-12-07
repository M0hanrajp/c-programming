/* Your task is to convert strings to how they would be written by Jaden Smith. 
 * The strings are actual quotes from Jaden Smith, but they are not capitalized 
 * in the same way he originally typed them.

Example:

Not Jaden-Cased: "How can mirrors be real if our eyes aren't real"
Jaden-Cased:     "How Can Mirrors Be Real If Our Eyes Aren't Real" */
char *to_jaden_case (char *jaden_case, const char *string) {
  int i = 1;
  if(*string == '\0') {
    *jaden_case = '\0';
    return jaden_case;
  }
  string[0] >= 65 && string[0] <= 90 ? (jaden_case[0] = string[0]) : (jaden_case[0] = string[0] - 32);
    while(string[i] != '\0') {
        jaden_case[i] = string[i];
        if(string[i] == ' ') {
            i++;
            if(string[i] >= 65 && string[i] <= 90)
                jaden_case[i] = string[i];
            else
                jaden_case[i] = string[i] - 32;
        }
        i++;
    }
    jaden_case[i] = '\0';
  return jaden_case;
}
