#include <iostream>
#include "Algorithm.h"
#include "Cart.h"
#include "iostream"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main() {

    // Begin::Adding objects
    std::vector<Cart*> carts;
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;

    Cart *cart1 = new Cart(12,v1);
    Cart *cart2 = new Cart(15,v2);
    Cart *cart3 = new Cart(18,v3);
    carts.push_back(cart1);
    carts.push_back(cart2);
    carts.push_back(cart3);
    Algorithm algorithm;
    // End::Adding objects


    srand (time(NULL));
    int number = rand() %10 + 1;

    // Begin::FirstFitDecreasing
    std::cout << "*************************************" << std::endl;
    std::cout << "CALLING FIRST FIT DECREASING" << std::endl;
    std::cout << "Cons:" << std::endl;
    std::cout << "It will always end with the larger numbers that fit in the given containers (can drop a previously made reservation)" << std::endl;
    std::cout << "It is inneficient (several loops)" << std::endl;
    std::cout << "Pros:" << std::endl;
    std::cout << "Very efficient in distribution" << std::endl;

    bool value = true;
    while(value){
        value = algorithm.firstFitDecreasing(number, carts);
        std::cout << "*************************************" << std::endl;
        std::cout << "Entering number: " << number << std::endl;
        for (int i = 0; i < carts.size(); i++) {
            std::cout << "Cart " << i << std::endl;
            std::cout << *carts[i] << std::endl;
        }
        std::cout << "*************************************" << std::endl;
        if(!value){
            std::cout << "Carts are full." << std::endl;
            break;
        }
        number = rand() %10 + 1;
    }
    std::cout << "Final Carts:" << std::endl;
    for (int i = 0; i < carts.size(); i++) {
        std::cout << "Cart " << i << std::endl;
        std::cout << *carts[i] << std::endl;
    }
    // End::FirstFitDecreasing

    // Begin::FirstFit
    std::cout << "*************************************" << std::endl;
    std::cout << "CALLING FIRST FIT" << std::endl;
    std::cout << "Cons:" << std::endl;
    std::cout << "It wont be the most efficient distribution" << std::endl;
    std::cout << "Pros:" << std::endl;
    std::cout << "It will leave reservations in their place (no re-accomodations)" << std::endl;
    std::cout << "Efficient (one loop per added reservation)" << std::endl;

    cart1->removeAllNumbers();
    cart2->removeAllNumbers();
    cart3->removeAllNumbers();

    value = true;
    number = rand() %10 + 1;

    while(value){
        value = algorithm.firstFit(number, carts);
        std::cout << "*************************************" << std::endl;
        std::cout << "Entering number: " << number << std::endl;
        for (int i = 0; i < carts.size(); i++) {
            std::cout << "Cart " << i << std::endl;
            std::cout << *carts[i] << std::endl;
        }
        std::cout << "*************************************" << std::endl;
        if(!value){
            std::cout << "Carts are full, number that couldn't enter: " << number << std::endl;
            break;
        }
        number = rand() %10 + 1;
    }

    std::cout << "Final Carts:" << std::endl;
    for (int i = 0; i < carts.size(); i++) {
        std::cout << "Cart " << i << std::endl;
        std::cout << *carts[i] << std::endl;
    }
    // End::FirstFit

    // Begin::BestFit
    std::cout << "*************************************" << std::endl;
    std::cout << "CALLING BEST FIT" << std::endl;
    std::cout << "Cons:" << std::endl;
    std::cout << "It wont be the most efficient distribution (middle)" << std::endl;
    std::cout << "Pros:" << std::endl;
    std::cout << "It will leave reservations in their place (no re-accomodations)" << std::endl;
    std::cout << "Efficient (one loop per added reservation)" << std::endl;

    cart1->removeAllNumbers();
    cart2->removeAllNumbers();
    cart3->removeAllNumbers();

    value = true;
    number = rand() %10 + 1;

    while(value){
        value = algorithm.bestFit(number, carts);
        std::cout << "*************************************" << std::endl;
        std::cout << "Entering number: " << number << std::endl;
        for (int i = 0; i < carts.size(); i++) {
            std::cout << "Cart " << i << std::endl;
            std::cout << *carts[i] << std::endl;
        }
        std::cout << "*************************************" << std::endl;
        if(!value){
            std::cout << "Carts are full, number that couldn't enter: " << number << std::endl;
            break;
        }
        number = rand() %10 + 1;
    }
    std::cout << "Final Carts:" << std::endl;
    for (int i = 0; i < carts.size(); i++) {
        std::cout << "Cart " << i << std::endl;
        std::cout << *carts[i] << std::endl;
    }
    // End::BestFit

    return 0;
}
