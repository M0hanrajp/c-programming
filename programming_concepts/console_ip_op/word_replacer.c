/* This program searches for a particular word.
 * replaces the searched word with the desired word
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void searchWordOffsets(const char *file, const char *sWord, int *sOffset, int *eOffset) {
    FILE *fp = fopen(file, "r");
    char wordBuff[ 15];
    int fc = 0, wordI = 0, res = 1;

    while ((fc = fgetc(fp)) != EOF) {
        if((char)fc != ' ' && (char)fc != '!' && (char)fc != ',' && (char)fc != ';') {
            if(wordI == 0)
                // get the start offset position
                *sOffset = ftell(fp) - 1;
            wordBuff[wordI++] = (char )fc;
        }
        else {
            res = strcmp(sWord, wordBuff);
            if(res == 0)
                // get the end offset position
                *eOffset = ftell(fp);
            memset(wordBuff, 0, sizeof(wordBuff));
            wordI = 0;
        }
        if(!res){ break;}
    }
}

void copyFiles(const char *sFile, const char *tFile) {
    FILE *sf = fopen(sFile, "w");
    FILE *tf = fopen(tFile, "r");
    int fc = 0;
    while ((fc = fgetc(tf)) != EOF) {
        fputc(fc, sf);
    }
    fclose(tf);
    fclose(sf);
}

void searchAndReplaceWord(const char *file, const char *sWord, const char *tWord) {
    int sOffset = 0, eOffset = 0;
    searchWordOffsets(file, sWord, &sOffset, &eOffset);

    FILE *fp = fopen(file, "r");
    FILE *ft = fopen("fdir/tmp", "w");
    int fc = 0;

    // copy till start offset
    while (ftell(fp) < sOffset) {
        fc = fgetc(fp);
        fputc(fc, ft);
    }
    // reset char value & pointer position
    fc = 0; fseek(fp, 0, SEEK_SET);
    // replace the target word
    while (*tWord) {
        fputc(*tWord, ft);
        tWord++;
    }
    // append from end offset till EOF
    fseek(fp, eOffset - 1, SEEK_SET);
    while ((fc = fgetc(fp)) != EOF) {
        fputc(fc, ft);
    }
    fclose(fp);
    fclose(ft);

    // copy contents of tmp to original file
    copyFiles(file, "fdir/tmp");
    remove("fdir/tmp");
}

int main(int argc, char *argv[]) {
    searchAndReplaceWord(argv[1], argv[2], argv[3]);
    return 0;
}

/* Output
// before
$ cat fdir/a.txt
O Captain! my Mr.Keating! our fearful trip is done,
The ship has weather’d every rack, the prize we sought is won,
The port is near, the bells I hear, the people all exulting,
While follow eyes the steady keel, the vessel grim and daring;
                         But O heart! heart! heart!
                            O the bleeding drops of red,
                               Where on the deck my Captain lies,
                                  Fallen cold and dead.

// after replacing the word
$ ./word_replacer fdir/a.txt Mr.Keating Captain
$ cat fdir/a.txt
O Captain! my Captain! our fearful trip is done,
The ship has weather’d every rack, the prize we sought is won,
The port is near, the bells I hear, the people all exulting,
While follow eyes the steady keel, the vessel grim and daring;
                         But O heart! heart! heart!
                            O the bleeding drops of red,
                               Where on the deck my Captain lies,
                                  Fallen cold and dead.
*/
