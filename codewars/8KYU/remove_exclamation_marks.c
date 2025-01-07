/* Write function RemoveExclamationMarks which removes all exclamation marks from a given string. */
// Write resulting string into buffer pointed by str_out
void remove_exclamation_marks(const char *str_in, char *str_out) {
  while(*str_in != '\0') {
    if(*str_in != '!') {*str_out = *str_in;str_out++;}str_in++;
  }
  *str_out = '\0';
}
