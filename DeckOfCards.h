#include <string>
#include <vector>
using namespace std;
struct Card
{
	string face;
	string suit;
};

class DeckOfCards
{
public:
							static const int numberOfCards=52;
							static const int faces=13;
							static const int suits=4;
							
							DeckOfCards();
							void shuffle();
							void deal() const;
private:
								vector < Card > deck;
};

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


DeckOfCards::DeckOfCards():deck(numberOfCards)
{
	static string suit[suits]={"Hearts","Diamonds","Clubs","Spades"};
	static string face[faces]={"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine",
	"Ten","Jack","Queen","King"};
	for(int i=0;i<numberOfCards;i++)
	{
		deck[i].face=face[i%faces];
		deck[i].suit=suit[i/faces];
 }
 srand(time(0));
}
void DeckOfCards::shuffle()
{
	for(int i=0;i<numberOfCards;i++)
	{
		int j=rand()%numberOfCards;
		Card temp=deck[i];
		deck[i]=deck[j];
		deck[j]= temp;
	}
}
void DeckOfCards::deal()const
{
	for(int i=0;i<numberOfCards;i++)
	cout<<right<<setw(5)<<deck[i].face<<" of "<<left<<setw(8)<<deck[i].suit<<((i+1)%2?'\t':'\n');
}
