#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

    //Variables

    srand(time(NULL));

    int dCard = rand() % 13 + 1;
    int hidCard = rand() % 13 + 1;

    int card1 = rand() % 13 + 1;
    int card2 = rand() % 13 + 1;
    int pCard = card1 + card2;

    char choice;

    //Bulk of the Game

    cout << "You drew " << card1 << " and " << card2 << ". Your total is now " << pCard << "." << endl;

    cout << "Dealer: " << dCard << endl;
    cout << "Player: " << pCard << endl;
    cout << "The Dealer has a card face down.\nHit (h) or Stand (s)?" << endl;
    cin >> choice;

    if (pCard > 21) {
        cout << "Player Busts! Dealer wins!" << endl;
    }
    if (pCard == 21) {
        cout << "Player hits 21! Player wins!" << endl;
    }

    while (pCard < 21 && choice=='h') {
        pCard += rand() % 13 + 1;
        cout << "Dealer: " << dCard << endl;
        cout << "Player: " << pCard << endl;
        
        //Game End Condition
        if (pCard > 21) {
             cout << "Player Busts! Dealer wins!" << endl;
             break;
        }
        
        if (pCard == 21) {
            cout << "Player hits 21! Player wins!";
            break;
            
        }
        
        //Repeat until Player stands
        cout << "Hit (h) or Stand (s)?" << endl;
        cin >> choice;
    }

    //Stand Branch

    if (pCard < 21 && choice == 's') {

        //Dealer hits until 17 or greater
        cout << "Dealer reveals their card. It was " << hidCard << "." << endl;
        dCard += hidCard;
        cout << "Dealer's card total is now " << dCard << "." << endl;
        while (dCard < 17) {
            cout << "Dealer Hits." << endl;
            dCard += rand() % 13 + 1;
            cout << "Dealer's card total is now " << dCard << "." << endl;
        }

        //End Game
        cout << "Dealer: " << dCard << endl;
        cout << "Player: " << pCard << endl;
        if (dCard > 21) {
            cout << "Dealer Busts! Player wins!" << endl;
        }
        if (dCard < pCard) {
            cout << "Player's hand is larger! Dealer wins!";
        }
        if (dCard == 21){
            cout << "Dealer's hits 21! Dealer wins!";
        }
        if (dCard > pCard && dCard < 21) {
            cout << "Dealer's hand is greater! Dealer wins!";
        }
        if (dCard == pCard) {
            cout << "The hands are equal! It's a tie!";
        }
    }


    return 0;
}