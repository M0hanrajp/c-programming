### Notes

- The screen and keyboard together are called console.
- Formatted funcitons allow the input read from keyboard or the output displayed on the VDU
  to be formatted as per the requirements.
![Image](https://github.com/user-attachments/assets/a5c5081b-2a19-4984-bd66-1b783e74fd1f)

- Understanding how argc and argv work https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean
```bash
int main (int argc, char *argv[])
In the above declaration, the type of the second parameter named argv is actually a char**.
That is, argv is a pointer to a pointer to a char. This is because a char* [] decays to a char** due to type decay.
For example, the below given declarations are equivalent:

int main (int argc, char *argv[]); //first declaration
int main (int argc, char **argv);  //RE-DECLARATION. Equivalent to the above declaration
In other words, argv is a pointer that points to the first element of an array with elements of type char*.
Moreover, each elements argv[i] of the array(with elements of type char*) itself point to a character which is the start
of a null terminated character string. That is, each element argv[i] points to the first element of an array with elements
of type char(and not const char). A diagram is given for illustration purposes:
```
![Image](https://github.com/user-attachments/assets/62b4d033-aef5-4095-8ac7-525878a3c3e5)
- We can read a character, `ch = fgetc(stdin)`, here `stdin` (read from keyboard), `stdout`(console/monitor), `stderror`(console/monitor).



#### Format specifiers

Symbol/ Notation | Format Specifier Name | Description | Data type | Range | Size
-- | -- | -- | -- | -- | --
%d or %i | Decimal integer | Signed integer in base 10 | int | -2147483648 to 2147483647 | 4 bytes
%f | Float | Floating point number with six digits of precision | float | 1.2E-38 to 3.4E+38 | 4 bytes
%Lf | Long double | Floating point number with extended precision | long double | 3.4E-4932 to 1.1E+4932 | 10 or 16 bytes
%c | Character | Single character | char | -128 to 127 | 1 byte
%s | String | String of characters | char[] | - | -
%p | Pointer | Address in memory | void * | - | 4 or 8 bytes
%Id | Long integer | Signed long integer | signed long | -2147483648 to 2147483647 | 4 bytes
%lu | Unsigned Long | Unsigned long integer | unsigned long | 0 to 4294967295 | 4 bytes
%lld | Long Long | Signed long long integer | long long | -9223372036854775808 to 9223372036854775807 | 8 bytes
%llu | Unsigned Long Long | Unsigned long long integer | unsigned long long | 0 to 18446744073709551615 | 8 bytes
%x | Hexadecimal | Unsigned integer in base 16 | unsigned int | 0 to 4294967295 | 4 bytes
%E | Scientific notation | Floating point number in scientific notation | double | 2.2E-308 to 1.8E+308 | 8 bytes
%o | Octal | Unsigned integer in base 8 | unsigned int | 0 to 4294967295 | 4 bytes
%u | Unsigned Decimal | Unsigned integer in base 10 | unsigned int | 0 to 4294967295 | 4 bytes
%hd | Short | Short signed integer | short | -32768 to 32767 | 2 bytes
%m | Error message | Error message corresponding to the error number in the argument | int | - | -
%n | Output assignment | Stores the number of characters written so far into the pointer argument | int * | - | -
%hu | Unsigned Short | Short unsigned integer | unsigned short | 0 to 65535 | 2 bytes
%zu | size_t | prints sizeof(data) regardless of architecture | unsigned int | 
%%  | NA | prints %

### Escape sequences

Escape Sequence | Name | Description
-- | -- | --
\a | Alarm or Beep | It is used to generate a bell sound in the C program.
\b | Backspace | It is used to move the cursor one place backward.
\f | Form Feed | It is used to move the cursor to the start of the next logical page.
\n | New Line | It moves the cursor to the start of the next line.
\r | Carriage Return | It moves the cursor to the start of the current line.
\t | Horizontal Tab | It inserts some whitespace to the left of the cursor and moves the cursor accordingly.
\v | Vertical Tab | It is used to insert vertical space.
\\ | Backlash | Use to insert backslash character.
\’ | Single Quote | It is used to display a single quotation mark.
\” | Double Quote | It is used to display double quotation marks.
\? | Question Mark | It is used to display a question mark.
\ooo | Octal Number | It is used to represent an octal number.
\xhh | Hexadecimal Number | It represents the hexadecimal number.
\0 | NULL | It represents the NULL character.

