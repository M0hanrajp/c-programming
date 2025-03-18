// the aim of this program is to redirect the contents of stdout to file ASCII in fdir
#include <stdio.h>
int main(void) {
    for(int i = 0; i < 128; i++)
        fprintf(stdout, "DEC:: %3d = CHAR:: %c\n", i, i);
    return 0;
}
/* 
$ ./a.out > fdir/ASCII
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/console_ip_op$ cat fdir/ASCII
DEC::   0 = CHAR::
DEC::   1 = CHAR::
DEC::   2 = CHAR::
DEC::   3 = CHAR::
DEC::   4 = CHAR::
DEC::   5 = CHAR::
DEC::   6 = CHAR::
DEC::   7 = CHAR::
DEC::   8 = CHAR::
DEC::   9 = CHAR::
DEC::  10 = CHAR::

DEC::  11 = CHAR::

DEC::  12 = CHAR::

DEC::  13 = CHAR::
DEC::  14 = CHAR::
DEC::  15 = CHAR::
DEC::  16 = CHAR::
DEC::  17 = CHAR::
DEC::  18 = CHAR::
DEC::  19 = CHAR::
DEC::  20 = CHAR::
DEC::  21 = CHAR::
DEC::  22 = CHAR::
DEC::  23 = CHAR::
DEC::  24 = CHAR::
DEC::  25 = CHAR::
DEC::  26 = CHAR:: ␦
DEC::  27 = CHAR::

EC::  28 = CHAR::
DEC::  29 = CHAR::
DEC::  30 = CHAR::
DEC::  31 = CHAR::
DEC::  32 = CHAR::
DEC::  33 = CHAR:: !
DEC::  34 = CHAR:: "
DEC::  35 = CHAR:: #
DEC::  36 = CHAR:: $
DEC::  37 = CHAR:: %
DEC::  38 = CHAR:: &
DEC::  39 = CHAR:: '
DEC::  40 = CHAR:: (
DEC::  41 = CHAR:: )
DEC::  42 = CHAR:: *
DEC::  43 = CHAR:: +
DEC::  44 = CHAR:: ,
DEC::  45 = CHAR:: -
DEC::  46 = CHAR:: .
DEC::  47 = CHAR:: /
DEC::  48 = CHAR:: 0
DEC::  49 = CHAR:: 1
DEC::  50 = CHAR:: 2
DEC::  51 = CHAR:: 3
DEC::  52 = CHAR:: 4
DEC::  53 = CHAR:: 5
DEC::  54 = CHAR:: 6
DEC::  55 = CHAR:: 7
DEC::  56 = CHAR:: 8
DEC::  57 = CHAR:: 9
DEC::  58 = CHAR:: :
DEC::  59 = CHAR:: ;
DEC::  60 = CHAR:: <
DEC::  61 = CHAR:: =
DEC::  62 = CHAR:: >
DEC::  63 = CHAR:: ?
DEC::  64 = CHAR:: @
DEC::  65 = CHAR:: A
DEC::  66 = CHAR:: B
DEC::  67 = CHAR:: C
DEC::  68 = CHAR:: D
DEC::  69 = CHAR:: E
DEC::  70 = CHAR:: F
DEC::  71 = CHAR:: G
DEC::  72 = CHAR:: H
DEC::  73 = CHAR:: I
DEC::  74 = CHAR:: J
DEC::  75 = CHAR:: K
DEC::  76 = CHAR:: L
DEC::  77 = CHAR:: M
DEC::  78 = CHAR:: N
DEC::  79 = CHAR:: O
DEC::  80 = CHAR:: P
DEC::  81 = CHAR:: Q
DEC::  82 = CHAR:: R
DEC::  83 = CHAR:: S
DEC::  84 = CHAR:: T
DEC::  85 = CHAR:: U
DEC::  86 = CHAR:: V
DEC::  87 = CHAR:: W
DEC::  88 = CHAR:: X
DEC::  89 = CHAR:: Y
DEC::  90 = CHAR:: Z
DEC::  91 = CHAR:: [
DEC::  92 = CHAR:: \
DEC::  93 = CHAR:: ]
DEC::  94 = CHAR:: ^
DEC::  95 = CHAR:: _
DEC::  96 = CHAR:: `
DEC::  97 = CHAR:: a
DEC::  98 = CHAR:: b
DEC::  99 = CHAR:: c
DEC:: 100 = CHAR:: d
DEC:: 101 = CHAR:: e
DEC:: 102 = CHAR:: f
DEC:: 103 = CHAR:: g
DEC:: 104 = CHAR:: h
DEC:: 105 = CHAR:: i
DEC:: 106 = CHAR:: j
DEC:: 107 = CHAR:: k
DEC:: 108 = CHAR:: l
DEC:: 109 = CHAR:: m
DEC:: 110 = CHAR:: n
DEC:: 111 = CHAR:: o
DEC:: 112 = CHAR:: p
DEC:: 113 = CHAR:: q
DEC:: 114 = CHAR:: r
DEC:: 115 = CHAR:: s
DEC:: 116 = CHAR:: t
DEC:: 117 = CHAR:: u
DEC:: 118 = CHAR:: v
DEC:: 119 = CHAR:: w
DEC:: 120 = CHAR:: x
DEC:: 121 = CHAR:: y
DEC:: 122 = CHAR:: z
DEC:: 123 = CHAR:: {
DEC:: 124 = CHAR:: |
DEC:: 125 = CHAR:: }
DEC:: 126 = CHAR:: ~
DEC:: 127 = CHAR::
 */
