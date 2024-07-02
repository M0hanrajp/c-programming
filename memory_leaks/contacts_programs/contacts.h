#ifndef CONTACTS_H
#define CONTACTS_H

void initialize_contact_list();
void add_contact(const char *name, const char *phone);
void view_contacts();

#endif // CONTACTS_H
/*
* This code is a preprocessor directive commonly found at the beginning of a C or C++ header file. 
* Let's break it down:

1. `#ifndef`: This is a preprocessor directive that stands for "if not defined". 
    It checks whether a certain macro has not been defined yet.

2. `CONTACTS_H`: `CONTACTS_H` is typically a macro representing the name of the header file.
    It's common practice to use an all-uppercase name for macros to distinguish them from regular code.

3. `#define CONTACTS_H`: This line defines the macro `CONTACTS_H` if it hasn't been defined already. 
    Essentially, it assigns a value to the macro, in this case, the name of the header file.

4. `#endif`: This marks the end of the conditional block started by `#ifndef`. 
If the macro `CONTACTS_H` was not defined, the code between `#ifndef` and `#endif` will be included in the compilation.

   The purpose of these directives is to prevent multiple inclusions of the same header file in a translation unit.
   If a header file is included multiple times in a source file or in multiple source files, it could lead to issues
   like redefinition of symbols. 
   By using `#ifndef`, the header file contents are only included once in each translation unit.
*/
