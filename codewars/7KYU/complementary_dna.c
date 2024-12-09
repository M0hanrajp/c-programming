/* In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". 
 * Your function receives one side of the DNA (string, except for Haskell); you need 
 * to return the other complementary side. DNA strand is never empty or there is no 
 * DNA at all (again, except for Haskell). 
 * "ATTGC" --> "TAACG"
"GTAT" --> "CATA"
 * */
#include <stdlib.h>
#include <string.h>
char *dna_strand(const char *dna) {
  char* cdna = (char *)malloc((strlen(dna) + 1) * sizeof(char));
  int i = 0;
  for(; dna[i] != '\0'; i++) {
    switch(dna[i]) {
        case 'T':
          cdna[i] = 'A';
          break;
        case 'A':
          cdna[i] = 'T';
          break;
        case 'C':
          cdna[i] = 'G';
          break;
        case 'G':
          cdna[i] = 'C';
          break;
        default:
          break;
    }
  }
  cdna[i] = '\0';
  return cdna;
}
