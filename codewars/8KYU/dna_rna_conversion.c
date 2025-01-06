/* Deoxyribonucleic acid, DNA is the primary information storage molecule in biological systems. 
 * It is composed of four nucleic acid bases Guanine ('G'), Cytosine ('C'), Adenine ('A'), and Thymine ('T').
 * Ribonucleic acid, RNA, is the primary messenger molecule in cells. RNA differs slightly from DNA its chemical 
 * structure and contains no Thymine. In RNA Thymine is replaced by another nucleic acid Uracil ('U').

Create a function which translates a given DNA string into RNA.
For example:
"GCAT"  =>  "GCAU"
The input string can be of arbitrary length - in particular, it may be empty. All input is guaranteed to be valid,
i.e. each input string will only ever consist of 'G', 'C', 'A' and/or 'T'. */
#include <stdlib.h>
#include <string.h>
char *dna_to_rna(const char *dna) {
  char *rna_o = (char *)calloc(strlen(dna) + 1, sizeof(char));
  for(int i = 0; dna[i] != '\0'; i++){
    rna_o[i] = dna[i];
    if(dna[i] == 'T')
      rna_o[i] = 'U';
  }
  rna_o[strlen(dna)] = '\0';
  return rna_o;
}
