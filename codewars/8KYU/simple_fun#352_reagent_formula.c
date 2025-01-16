/* Now we will confect a reagent. There are eight materials to choose from, numbered 1,2,..., 8 respectively.

We know the rules of confect:
material1 and material2 cannot be selected at the same time
material3 and material4 cannot be selected at the same time
material5 and material6 must be selected at the same time
material7 or  material8 must be selected(at least one, or both)
Task
You are given a integer array formula. Array contains only digits 1-8 that represents material 1-8. Your task is to determine if the formula is valid. Returns true if it's valid, false otherwise.

Example
For formula = [1,3,7], The output should be true.
For formula = [7,1,2,3], The output should be false.
For formula = [1,3,5,7], The output should be false.
For formula = [1,5,6,7,3], The output should be true.
For formula = [5,6,7], The output should be true.
For formula = [5,6,7,8], The output should be true.
For formula = [6,7,8], The output should be false.
For formula = [7,8], The output should be true.

All inputs are valid. Array contains at least 1 digit. Each digit appears at most once.
Happy Coding ^_^ */
#include <stdbool.h>
#include <stddef.h>

bool is_valid(size_t length, const unsigned formula[length]) {
  bool valid = true, flaga = false, flagb = false, flagc = false, ca = true, cb = true, cc = false, cd = false;
  // check single digit arrays
  if(length == 1) {
    if(formula[0] != 7 && formula[0] != 8)
      return false;
  }
  // check if 7 & 8 are present
  if(length > 1) {
    for(size_t i = 0; i < length; i++) {
      if(formula[i] == 7 || formula[i] == 8)
        cd = true;
    }
  }
  // check the conditions mentioned per description and return a value
  for(size_t i = 0; i < length; i++) {
     if(formula[i] == 5 || formula[i] == 6) {
       flagc = true;
       if(formula[i] == 6) {
         for(size_t o = 0; o < length; o++) {
          if(formula[o] == 5) {
            cc = true;
            break;
          }
         }
       }
       if(formula[i] == 5) {
         for(size_t p = 0; p < length; p++) {
          if(formula[p] == 6) {
            cc = true;
            break;
          }
         }        
       }      
     }
     if(formula[i] == 1 || formula[i] == 2) {
       flagb = true;
       if(formula[i] == 1) {
         for(size_t o = 0; o < length; o++) {
          if(formula[o] == 2) {
            cb = false;
            break;
          }
         }
       }
	   if(formula[i] == 2) {
         for(size_t p = 0; p < length; p++) {
          if(formula[p] == 1) {
            cb = false;
            break;
          }
         }        
       }      
     }   
     if(formula[i] == 3 || formula[i] == 4) {
       flaga = true;
       if(formula[i] == 3) {
         for(size_t o = 0; o < length; o++) {
          if(formula[o] == 4) {
            ca = false;
            break;
          }
         }
       }
       if(formula[i] == 4) {
         for(size_t p = 0; p < length; p++) {
          if(formula[p] == 3) {
            ca = false;
            break;
          }
         }        
       }      
     }   
  }
  // check for all possible conditions
  if(flaga) {
    valid = ca;
  }
  if(flagb) {
    valid = cb;
  }
  if(flagc) {
    valid = cc;
  }
  if(flaga && flagb) {
    valid = ca && cb;
  }
  if(flagb && flagc) {
    valid = cb && cc;
  }
  if(flagc && flaga) {
    valid = cc && ca;
  }
  if(flaga && flagb && flagc) {
    valid = (ca && cb) && ( cc && cd );
  }
  return valid;
}
