#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

enum Suit {
    Heart,
    Diamond,
    Club,
    Spade
};

enum Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

string get_suit_string(Suit suit) {
    switch (suit) {
        case Heart: return "Heart";
        case Diamond: return "Diamond";
        case Club: return "Club";
        case Spade: return "Spade";
        default: return "Unknown";
    }
}

string get_rank_string(Rank rank) {
    switch (rank) {
        case Ace: return "Ace";
        case Two: return "2";
        case Three: return "3";
        case Four: return "4";
        case Five: return "5";
        case Six: return "6";
        case Seven: return "7";
        case Eight: return "8";
        case Nine: return "9";
        case Ten: return "10";
        case Jack: return "Jack";
        case Queen: return "Queen";
        case King: return "King";
        default: return "Unknown";
    }
}


struct Card {
    Rank rank;
    Suit suit;
};

int card_points(int sum, int rank) {
    if (rank == Ace) return 11;
    if (rank > Ten) return 10;
    return rank + 1;
}

class Deck {
    public:
        Deck(int numDecks) {
            for (int i = 0; i < numDecks; i++) {
                add_deck();
            }
        }

        Card drawCard() {}
        void printDeck() {
            for (Card current : deck) {
                cout << "Rank: " << get_rank_string(current.rank) << " Suit: " << get_suit_string(current.suit) << endl;
            }
        }

    private:
        vector<Card> deck;
        void add_deck() {
            for (int i = 0; i < 13; i++) {
                for (int j = 0; j < 4; j++) {
                    Card temp_card;
                    temp_card.rank = Rank(i);
                    temp_card.suit = Suit(j);
                    deck.push_back(temp_card);
                }
            }
        }
};

class Player{
    public:
        Player() {

        };

        void drawCard() {

        }

    private:
};

class BlackJack{
    public:
        BlackJack(int pBalanceAmtCents, int pDecksNum, int pPlayersNum) : deck(Deck(pDecksNum)) {
            balanceAmountCents = pBalanceAmtCents;
            decksNum = pDecksNum;
            playerNum = pPlayersNum;
        };

        void checkDeck() {
            deck.printDeck();
        }

    private:
        int balanceAmountCents; // 100 cents = 1 dollar
        int decksNum;
        int playerNum;
        Deck deck;
};


int main() {
    BlackJack game(100, 1, 2);
    game.checkDeck();

    return 0;
}
