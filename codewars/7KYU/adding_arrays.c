// question:Create a function that takes an array of letters, and combines them into words in a sentence.
/*
[
  ['J','L','L','M'],
  ['u','i','i','a'],
  ['s','v','f','n'],
  ['t','e','e','']
] // => "Just Live Life Man"

[ 
  [ 'T', 'M', 'i', 't', 'p', 'o', 't', 'c' ],
  [ 'h', 'i', 's', 'h', 'o', 'f', 'h', 'e' ],
  [ 'e', 't', '', 'e', 'w', '', 'e', 'l' ],
  [ '', 'o', '', '', 'e', '', '', 'l' ],
  [ '', 'c', '', '', 'r', '', '', '' ],
  [ '', 'h', '', '', 'h', '', '', '' ],
  [ '', 'o', '', '', 'o', '', '', '' ],
  [ '', 'n', '', '', 'u', '', '', '' ],
  [ '', 'd', '', '', 's', '', '', '' ],
  [ '', 'r', '', '', 'e', '', '', '' ],
  [ '', 'i', '', '', '', '', '', '' ],
  [ '', 'a', '', '', '', '', '', '' ]
] // => "The Mitochondria is the powerhouse of the cell"
*/
char *array_adder (int rows, int cols,
    const char matrix[rows][cols],
    char string[cols * (rows + 1) + 1])
{
    int index = 0;
    for(int i = 0; i < cols; i++) {
      for(int j = 0; j < rows; j++) {
        if(matrix[j][i] == '\0')
          break;
        string[index++] = matrix[j][i];
      }
      string[index++] = ' ';
    }
    string[index - 1] = '\0';
    return string;
}
