/*********************************************
 *                                           *
 *  This program calculates the              *
 *  factorization in prime numbers of a      *
 *  number entered by the user.              *
 *                                           *
 *                                           *
 *  Copyright Maria Valentina Carlucci 2013  *
 *                                           *
 *********************************************/

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    
    unsigned long int input_num;
    clock_t time;
    
    // contains the prime numbers
    unsigned int prim[1000000];
    
    // counts how much times the number is divisible by the given prime number
    unsigned int count[1000000];
    for (int i = 0; i < 1000000; i++) {
        count[i] = 0;
    }
    
    // input
    cout << "Enter your number: ";
    cin >> input_num;

    // routine initialization
    unsigned long int new_num = input_num;
    int i = 0;
    prim[i] = 2;

    // routine
    time = clock();
    while(1) {
        
        // checks if and how much times a prime number is divisor
        while (1) {
            if (new_num % prim[i] == 0) {
                count[i]++;
                new_num = new_num/prim[i];
            } else break;
        }

        // checks if we can end
        if (new_num == 1) {
            break;
        }
        
        // finds the next prime number
        unsigned int test_prim = prim[i] + 1;
        while (1) {
            int nonprime_flag = 0;
            for (int j = 0; j <= i && prim[j] <= test_prim/2; j++) {
                if (test_prim % prim[j] == 0) {
                    nonprime_flag = 1;
                    break;
                }
            }
            if (nonprime_flag == 0) {
                i++;
                prim[i] = test_prim;
                break;
            } else {
                test_prim++;
            }
            
        }
    }
    time = clock() - time;
    
    // output
    if (new_num == input_num) {
        cout << "Your number is prime." << endl;
    } else {
        cout << "Your number can be factorized as: ";
        for (int j = 0; j < i; j++) {
            if (count[j] != 0) {
                cout << prim[j] << "^" << count[j] << " x ";
            }
        }
        cout << prim[i] << "^" << count[i] << endl;
    }
    cout << "Time needed for the calculation: " << ((float)time)/CLOCKS_PER_SEC << " seconds." << endl;
    
    // end
    return 0;
}
