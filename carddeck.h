#include <string>
#include <cstdlib>
#include <vector>

#define SPADE "\u2660"
#define CLUB "\u2663"
#define HEART "\u2665"
#define DIAMOND "\u2666"

enum Suits{
    Spade=1,
    Club,
    Heart,
    Diamond
};
enum CardValue{
    One = 1,
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
struct Card{
    CardValue value;
    Suits suit;
    Card(CardValue value, Suits suit){
        this->value = value;
        this->suit = suit;
    }
    std::string ToString(){
        std::string output = "";
        if(value <= 10){
            output += std::to_string(value);
        }
        else{
            switch (value){
                case Jack:
                    output += "J";
                    break;
                case Queen:
                    output += "Q";
                    break;
                case King:
                    output += "K";
                    break;
                default:
                    break;
            }
        }
        switch(suit){
            case Spade:
                output += SPADE;
                break;
            case Diamond:
                output += DIAMOND;
                break;
            case Club:
                output += CLUB;
                break;
            case Heart:
                output += HEART;
                break;
            default:
                break;
        }
        return output;
    }
};
class CardDeck{
    std::vector<Card> deck;
    std::vector<Card> dealt; // the discarded cards
    public:
    void RemakeDeck(){
        deck = std::vector<Card>();
        dealt = std::vector<Card>();
        for(int card = 1; card <= 13; ++card){
            for(int suit = 1; suit <= 4; ++suit){
                deck.emplace_back((CardValue)card, (Suits)suit);
            }
        }
    }
    bool DealCard(Card* card){
        size_t cards = deck.size();
        if(cards == 0){
            return false;
        }
        int random = rand() % (int)cards;
        Card randCard = new Card(deck.at(random));

        deck.erase(deck.begin() + random);
        dealt.push_back(randCard);

        card = randCard;
        return true;
    } // deals a random card, adds it to the discard pile
    int GetNCards(int n, std::vector<Card>* cards){
        int i = 0;
        bool leaveEarly = false;
        while(i < n && !leaveEarly){
            Card card;
            if(!DealCard(&card)) leaveEarly = true;
            cards->push_back(card);
        }
    } // deals n random card, add them to the discard pile
    static Card RandomCard(){
        int suit = rand() % 4 + 1;
        int card = rand() % 13 + 1;
        return Card((CardValue)card, (Suits)suit);
    }

};