/* If we were to set up a Tic-Tac-Toe game, we would want to know whether the 
 * board's current state is solved, wouldn't we? Our goal is to create a function 
 * that will check that for us!
Assume that the board comes in the form of a 3x3 array, where the value is 0 if a 
spot is empty, 1 if it is an "X", or 2 if it is an "O", like so:

[[0, 0, 1],
 [0, 1, 2],
 [2, 1, 0]]
We want our function to return:

-1 if the board is not yet finished AND no one has won yet (there are empty spots),
1 if "X" won,
2 if "O" won,
0 if it's a cat's game (i.e. a draw). */
enum game_state { NOT_FINISHED = -1, DRAW = 0, X_WON = 1, O_WON = 2 };

enum square { EMPTY = 0, X = 1, O = 2 };

enum game_state check_game_state (const enum square board[3][3]) {
  if(board[0][0] == X && board[0][1] == X && board[0][2] == X){return X_WON;}
  if(board[1][0] == X && board[1][1] == X && board[1][2] == X){return X_WON;}
  if(board[2][0] == X && board[2][1] == X && board[2][2] == X){return X_WON;}
  if(board[0][0] == X && board[1][0] == X && board[2][0] == X){return X_WON;}
  if(board[0][1] == X && board[1][1] == X && board[2][1] == X){return X_WON;}
  if(board[0][2] == X && board[1][2] == X && board[2][2] == X){return X_WON;}
  if(board[0][0] == X && board[1][1] == X && board[2][2] == X){return X_WON;}
  if(board[0][2] == X && board[1][1] == X && board[2][0] == X){return X_WON;}
  if(board[0][0] == O && board[0][1] == O && board[0][2] == O){return O_WON;}
  if(board[1][0] == O && board[1][1] == O && board[1][2] == O){return O_WON;}
  if(board[2][0] == O && board[2][1] == O && board[2][2] == O){return O_WON;}
  if(board[0][0] == O && board[1][0] == O && board[2][0] == O){return O_WON;}
  if(board[0][1] == O && board[1][1] == O && board[2][1] == O){return O_WON;}
  if(board[0][2] == O && board[1][2] == O && board[2][2] == O){return O_WON;}
  if(board[0][0] == O && board[1][1] == O && board[2][2] == O){return O_WON;}
  if(board[0][2] == O && board[1][1] == O && board[2][0] == O){return O_WON;}
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++)
      if(board[i][j] == EMPTY){return NOT_FINISHED;}
  }
  return DRAW;
}
