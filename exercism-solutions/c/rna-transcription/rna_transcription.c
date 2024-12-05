#include "rna_transcription.h"
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna) {
   unsigned long len = strlen(dna);
   char *rrna = (char *)calloc((len + 1), sizeof(char));
   if(len > 0) {
      for(int i = 0; dna[i] != '\0'; i++) {
         switch(dna[i]) {
            case 'G':
               rrna[i] = 'C';
               break;
            case 'C':
               rrna[i] = 'G';
               break;
            case 'T':
               rrna[i] = 'A';
               break;
            case 'A':
               rrna[i] = 'U';
         }
      }
   }
   rrna[len] = '\0';
   return rrna;
}
