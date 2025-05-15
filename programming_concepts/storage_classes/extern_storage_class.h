#ifndef EXTERN_HEADER
#define EXTERN_HEADER

extern int a; 
/* Only declaration is allowed, it cannot be initialized to any value
 * it is defined at file-scope, external linakge in extern_definiiton.c that has this header file included
 * the current header file is to make it known that this variable can be referenced to all the files
 * the variable has external linkage, static duration */

extern int b;
/* declaration of int b as extern, external-linkage, static duration.
 * defined in extern_definition.c as uninitialized filescope variable.
 * since it was unitialized, using a printf the value turned out to be 0.
 */

// int a = 1; declaration of a and definition of a in the same header file
/* what happens here ? The following error is observed
   
   $ gcc -g -Wall extern_storage_class.c extern_definition.c
   /usr/bin/ld: /tmp/ccL8flay.o:/...extern_storage_class.h:11: 
   multiple definition of `a'; /tmp/cczGbxJT.o:/...extern_storage_class.h:11: first defined here
   collect2: error: ld returned 1 exit status

* Means if you include this header in multiple files 
* then you will end up with multiple declarations
* also you cannot define an variable inside a block scope
* because that would been it is automatic storage and no linkage
*/

void incrementExternVariable(void);
void printExternVariable(void);
void multiplyExternByTwo(void);
void checkValueofB(void);

#endif
