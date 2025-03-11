// Understanding basic operations of file IP/OP
// Program -> C library functions -> OS -> DISK
// TODO: update with the function return type and how it works.
#include <stdio.h>

int main(void) {
    FILE *fp = NULL;
    /* FILE is of type struct _IO_FILE
     * It has multiple fields, _IO_read_ptr,  _IO_read_end etc
     * here fp is a pointer to a struct object of type FILE
     */
    char  fc = 0;

    fp = fopen("fdir/file.txt", "r");
    /* FILE *fopen( const char *restrict filename, const char *restrict mode ); since C99
     * Opens a filIf successful, returns a pointer to the new file stream. The stream is fully buffered unless filename refers to an interactive device. On error, returns a null pointere indicated by filename and returns a pointer to the file stream associated with that file. 
     * mode is used to determine the file access mode.
     * filename	- file name to associate the file stream to, a string
     * --> It tries to find out the file name in the current directory if proper path is not provided.
     * mode	- null-terminated character string determining file access mode, check below the different modes of file
     *
     * In the above statement, it returns pointer to the stream/address opened file.
     * fopen is able to get all information about the fields that are declared in FILE(struct _IO_FILE).
     * (gdb) whatis fp
     type = FILE *

    (gdb) p *fp
    $14 = {_flags = -72539000, _IO_read_ptr = 0x555555559482 "is is a test file.\n", _IO_read_end = 0x555555559495 "", _IO_read_base = 0x555555559480 "This is a test file.\n",
      _IO_write_base = 0x555555559480 "This is a test file.\n", _IO_write_ptr = 0x555555559480 "This is a test file.\n", _IO_write_end = 0x555555559480 "This is a test file.\n",
      _IO_buf_base = 0x555555559480 "This is a test file.\n", _IO_buf_end = 0x55555555a480 "", _IO_save_base = 0x0, _IO_backup_base = 0x0, _IO_save_end = 0x0, _markers = 0x0,
      _chain = 0x7ffff7fa46a0 <_IO_2_1_stderr_>, _fileno = 3, _flags2 = 0, _old_offset = 0, _cur_column = 0, _vtable_offset = 0 '\000', _shortbuf = "", _lock = 0x555555559380, _offset = -1,
      _codecvt = 0x0, _wide_data = 0x555555559390, _freeres_list = 0x0, _freeres_buf = 0x0, __pad5 = 0, _mode = -1, _unused2 = '\000' <repeats 19 times>}

    (gdb) p fp
    $15 = (FILE *) 0x5555555592a0
     * This function looks for the file then opens it based on the mode
     * it loads the file into a buffer and sets up a pointer to point to that buffer.
     * If successful, returns a pointer to the new file stream. 
     * The stream is fully buffered unless filename refers to an interactive device. 
     * On error, returns a null pointer
     */
    while (1) {
        fc = fgetc(fp);
        /* int fgetc( FILE* stream );
         * 1) Reads the next character from the given input stream.
         * reads a single character from the input stream at the current position 
         * and increases the associated file pointer, if any, so that it points to the next character.
         * stream - to read the character from
         * On success, returns the obtained character as an unsigned char (0-255) converted to an int. 
         * On failure, returns EOF.
         */
        if(fc == EOF) // EOF is defined to be -1
            break;
        printf("%c", fc);
    }
    fclose(fp);
    /* https://en.cppreference.com/w/c/io/fclose
     * int fclose( FILE* stream );
     * Closes the given file stream. Any unwritten buffered data are flushed to the OS. Any unread buffered data are discarded
     * The behavior is undefined if the value of the pointer stream is used after fclose returns.
     * 0 on success, EOF otherwise
     */
    return 0;
}

/*
// file access modes
+--------+----------------+--------------------------------------+-------------------------------------+--------------------------------+
| Mode   | Meaning        | Explanation                          | Action if file already exists       | Action if file does not exist  |
+--------+----------------+--------------------------------------+-------------------------------------+--------------------------------+
| "r"    | read           | Open a file for reading              | Read from start                     | Failure to open                |
| "w"    | write          | Create a file for writing            | Destroy contents                    | Create new                   |
| "a"    | append         | Append to a file                     | Write to end                        | Create new                   |
| "r+"   | read extended  | Open a file for read/write           | Read from start                     | Error                        |
| "w+"   | write extended | Create a file for read/write         | Destroy contents                    | Create new                   |
| "a+"   | append extended| Open a file for read/write           | Write to end                        | Create new                   |
+--------+----------------+--------------------------------------+-------------------------------------+--------------------------------+
*/
