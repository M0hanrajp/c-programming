/* Caesar Ciphers are one of the most basic forms of encryption. It consists 
 * of a message and a key, and it shifts the letters of the message for the value of the key.
Read more about it here: https://en.wikipedia.org/wiki/Caesar_cipher
Your task
Your task is to create a function encryptor that takes 2 arguments - key and message - and returns the encrypted message.

Make sure to only shift letters, and be sure to keep the cases of the letters the same. 
All punctuation, numbers, spaces, and so on should remain the same.

Also be aware of keys greater than 26 and less than -26. There's only 26 letters in the alphabet!
Examples
A message 'Caesar Cipher' and a key of 1 returns 'Dbftbs Djqifs'.

A message 'Caesar Cipher' and a key of -1 returns 'Bzdrzq Bhogdq'. */
char *encryptor (char *str_out, const char *str_in, int key) {
  char *sa = str_out;
 while(*str_in) {
  int tempa = 0, tempb = 0, tempc = 0, tempd = 0;
  *str_out = *str_in;
  if(*str_out >= 'A' && *str_out <= 'Z') {
    if(*str_out + key > 'Z') {
      tempc = *str_out + key - 26;
      while(tempc > 'Z')
        tempc -= 26;
      *str_out = tempc;
    } else if(*str_out + key < 'A') {
      tempd = *str_out + key + 26;
      while(tempd < 'A')
        tempd += 26;
      *str_out = tempd;
    } else {*str_out = *str_out + key;}
  }
  if(*str_out >= 'a' && *str_out <= 'z') {
    if(*str_out + key > 'z') {
      tempa = *str_out + key - 26;
      while(tempa > 'z')
        tempa -= 26;
      *str_out = tempa;
    } else if(*str_out + key < 'a') {
      tempb = *str_out + key + 26;
      while(tempb < 'a')
        tempb += 26;
      *str_out = tempb;
    } else {*str_out = *str_out + key;}
  }
  str_out++;str_in++;
  }
  *str_out = '\0';
	return sa;
}
