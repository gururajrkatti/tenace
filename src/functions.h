#ifndef FUNCTIONS_H
#define FUNCTIONS_H

char *rank_string (rank r);
char rank_char (rank r);
int parse_suit(char c);
int parse_card(char *tok);
int parse_bid(char *tok);
rank parse_rank_char (char c);
GString *card_string (card c);
GString *bid_string (card c);
char *seat_string (seat s);
GString *hand_string (board *b, seat h);
//GString *gib_string (hand *h);
char *contract_string(int level, suit trumps, seat declarer, int doubled);
seat seat_mod(seat s);
char *overtricks (int i);
int score (int level, suit s, int doubled, int vuln, int tricks);
char *score_string(int level, suit trumps, seat declarer, int doubled, int vuln, int tricks, seat lead);

extern int pos_score_for;

#endif