#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <iostream>
using namespace std;


Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck()
{}

void Deck::Populate()
{
	Clear();
	for (int s = Card::CLUBS; s <= Card::SPADES; s++)
	{
		for (int r = Card::ACE; r <= Card::KING; r++)
		{
			Add(new Card(static_cast<Card::rank>(r), 
						 static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty())
	{
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else
	{
		cout << "Out of cards. Unable to deal." << endl;
	}
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	cout << endl;
	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		cout << aGenericPlayer.IsBusted() << endl;

		if (aGenericPlayer.IsBusted())
		{
			aGenericPlayer.Bust();
		}
	} 
}