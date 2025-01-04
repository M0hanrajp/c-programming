/* You get any card as an argument. Your task is to return the suit of this card (in lowercase).

Our deck (is preloaded):

deck = ['2♣','3♣','4♣','5♣','6♣','7♣','8♣','9♣','10♣','J♣','Q♣','K♣','A♣',
        '2♦','3♦','4♦','5♦','6♦','7♦','8♦','9♦','10♦','J♦','Q♦','K♦','A♦',
        '2♥','3♥','4♥','5♥','6♥','7♥','8♥','9♥','10♥','J♥','Q♥','K♥','A♥',
        '2♠','3♠','4♠','5♠','6♠','7♠','8♠','9♠','10♠','J♠','Q♠','K♠','A♠']; */
#include <string.h>
extern const char *const deck[52];

enum CardSuit { CLUBS, DIAMONDS, HEARTS, SPADES };

// The input string 'card' is encoded in UTF-8
enum CardSuit get_suit (const char *card) {
  if(strcmp(&card[strlen(card) - 3], "♣") == 0) return CLUBS;
  if(strcmp(&card[strlen(card) - 3], "♠") == 0) return SPADES; 
  if(strcmp(&card[strlen(card) - 3], "♦") == 0) return DIAMONDS;
  return HEARTS;
}
// Note -3 because of UTF-8
