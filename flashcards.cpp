/*********************************************
 *                                           *
 *  This program implements a deck of cards  *
 *  to learn words in Italian. If you give   *
 *  the correct answer, the card is          *
 *  discarded, otherwise it goes to the end  *
 *  of the deck.                             *
 *                                           *
 *  The code is optimized, but it allows     *
 *  a maximum number of attempts of SIZE.    *
 *  For more generality, uncomment the       *
 *  commented lines and comment the ones     *
 *  ending with //; however, this will imply *
 *  a physical copy of data that could       *
 *  be laborious.                            *
 *                                           *
 *                                           *
 *  Copyright Maria Valentina Carlucci 2013  *
 *                                           *
 *********************************************/



#include <iostream>
#include <string>
using namespace std;

struct single_card {
    string question;
    string answer;
};

class flash_card {
    
    single_card* card_list;
    int max;
    
    public:
    
    int ind;
    string ans;
    int flag;

    flash_card(single_card list[], int i) {
        card_list = list;
        max = i - 1;
        ind = 0;
    }
    
    void take_card();
    void check_ans();
   
};

void flash_card::take_card() {
    cout << "New card. The English word is: " << card_list[ind].question << endl;
    cout << "Write the translation in Italian: ";
    cin >> ans;
}

void flash_card::check_ans() {
    if (ans == card_list[ind].answer && ind < max) {
        cout << "Correct!" << endl;
        ind++;
        flag = 0;
    } else if (ans == card_list[ind].answer && ind == max) {
        cout << "Correct!" << endl;
        cout << "Congratulations, you have completed the deck!" << endl;
        flag = 1;
    } else {
        cout << "Wrong!" << endl;
//        single_card temp = card_list[ind];
//        for (int i = ind; i < max; i++) { card_list[i] = card_list[i+1]; }
//        card_list[max] = temp;
        card_list[max + 1] = card_list[ind]; //
        card_list = card_list + 1; //
        flag = 0;
    }
}



int main () {
    
    const int SIZE = 1000; //
//    const int SIZE = 5;
        
    single_card mylist[SIZE] = {
        {"cat","gatto"},
        {"love","amore"},
        {"star","stella"},
        {"travel","viaggio"},
        {"tree","albero"},
    };
    
    flash_card mydeck(mylist, 5);
    
    do {
        
        mydeck.take_card();
        mydeck.check_ans();        
    
    } while (mydeck.flag == 0);
        
    return 0;
}


