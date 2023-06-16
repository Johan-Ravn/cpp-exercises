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

class Deck {
    public:
        Deck(int num_decks) {
            for (int i = 0; i < num_decks; i++) {
                add_deck();
            }
            shuffle_deck();
        }

        Card get_card() {
            int deck_size = deck.size();
            random_device rd;
            mt19937 generator(rd());
            uniform_int_distribution<int> distribution(0, deck_size);
            int random_number = distribution(generator);
            return pop_card(random_number);
        }

    private:
        vector<Card> deck;

        Card pop_card(int index) {
            if (index < 0 || index >= deck.size()) {
                return Card();
            }
            Card temp = deck[index];
            deck.erase(deck.begin() + index);
            return temp;
        }

        void add_deck() {
            for (Suit currentSuit = Heart; currentSuit <= Spade; currentSuit = static_cast<Suit>(currentSuit + 1)) {
                for (Rank currentRank = Ace; currentRank <= King; currentRank = static_cast<Rank>(currentRank + 1)) {
                    Card card;
                    card.rank = currentRank;
                    card.suit = currentSuit;
                    deck.push_back(card);
                }
            }
        }

        void shuffle_deck() {
            random_device rd;
            mt19937 generator(rd());
            shuffle(deck.begin(), deck.end(), generator);
        }        
};

int card_points(int sum, int rank) {
    if (rank == Ace) {
        return 11;
    }

    if (rank > Ten) {
        return 10;
    }
    return rank + 1;
}

class Hand {
    public:
        Hand(Deck *&deck) : ptrDeck(deck){
            for (int i = 0; i < 2; i++) {
                draw_card();
            }
        };

        int get_sum() {
            int sum = 0;
            int ace = 0;
            for (Card card : hand) {
                sum += card_points(sum, card.rank);
                if (card.rank == Ace) {
                    ace++;
                }
            }
            // Takes into account ace 11/1
            while (sum > 21 && ace > 0) {
                ace--;
                sum -= 10;
            }
            return sum;
        }

        vector<Card> get_hand() {
            return hand;
        }

        void draw_card() {
            hand.push_back(ptrDeck->get_card());
        }

    private:
        vector<Card> hand;
        Deck *ptrDeck;
};

class BlackJack {
    public:
        BlackJack(int num_decks) {

        }
    private:
};

int main() {
    Deck deck(1);
    Deck *ptrDeck = &deck;
    Hand player_hand(ptrDeck);
    vector<Card> hand = player_hand.get_hand();
    cout << "Sum: " << player_hand.get_sum() << endl;
    for (Card card : hand) {
        cout << "Suit: " << get_suit_string(card.suit) << " Rank: " << get_rank_string(card.rank) << endl;
    }
    return 0;
}
