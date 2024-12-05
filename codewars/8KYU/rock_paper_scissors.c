/* Rock Paper Scissors
Let's play! You have to return which player won! In case of a draw return Draw!.

Examples(Input1, Input2 --> Output):

"scissors", "paper" --> "Player 1 won!"
"scissors", "rock" --> "Player 2 won!"
"paper", "paper" --> "Draw!" */
enum tool {ROCK, PAPER, SCISSORS};
enum outcome {P1_WON, P2_WON, DRAW};
enum outcome rps (enum tool p1, enum tool p2) {
  if(p1 == ROCK) {
    if(p2 == PAPER)
      return P2_WON;
    if(p2 == SCISSORS)
      return P1_WON;
  }
  if(p1 == PAPER) {
    if(p2 == ROCK)
      return P1_WON;
    if(p2 == SCISSORS)
      return P2_WON;
  }
  if(p1 == SCISSORS) {
    if(p2 == ROCK)
      return P2_WON;
    if(p2 == PAPER)
      return P1_WON;
  }
  return DRAW;
}
