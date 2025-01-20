# include <stdio.h>
int main( ) {
    char s[ ] = "No two viruses work similarly" ;
    int i = 0 ;
    while ( s[ i ] != 0 )
    {
        printf ( "%c %c\n", s[ i ], *( s + i ) ) ;
        printf ( "%c %c\n", i[ s ], *( i + s ) ) ;
        i++;
    }
    return 0 ;
}
// It will print each character twice and newline will be inserted
// N N \n [ Iteration 1]
// N N \n
/*:~/c-programming/programming_concepts/strings/snippets$ ./c
N N
N N
o o
o o


t t
t t
w w
w w
o o
o o


v v
v v
i i
i i
r r
r r
u u
u u
s s
s s
e e
e e
s s
s s


w w
w w
o o
o o
r r
r r
k k
k k


s s
s s
i i
i i
m m
m m
i i
i i
l l
l l
a a
a a
r r
r r
l l
l l
y y
y y */
