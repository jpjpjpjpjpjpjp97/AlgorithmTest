//
// Created by Jose Diaz on 5/7/21.
//

#include "Algorithm.h"
#include <algorithm>

Algorithm::Algorithm() {}
Algorithm::~Algorithm() {}

bool Algorithm::firstFit(int number, std::vector<Cart*> carts) {
    bool placed = false;

    // Now call first fit
    // Place item
    for (int i = 0; i < carts.size(); i++) {
        //  Find the first cart that can accommodate number
        if (carts[i]->sumNumbers() + number <= carts[i]->getMaxNumber()) {
            carts[i]->addNumber(number);
            placed = true;
            return placed;
        }
    }
    return placed;
}

bool Algorithm::firstFitDecreasing(int number, std::vector<Cart*> carts) {
    // Vector to sort numbers
    std::vector<int> allNumbers;
    allNumbers.push_back(number);

    // Put all numbers in the vector
    for (int i = 0; i < carts.size(); i++) {
        for (int j = carts[i]->getNumbers().size()-1; j >= 0; j--) {
            allNumbers.push_back(carts[i]->getNumbers()[j]);
            carts[i]->removeNumber();
        }
    }

    // Sort vector
    std::sort(allNumbers.begin(), allNumbers.end());

    // Now call first fit
    // Place items from vector one by one in the carts
    for (int i = 0; i < carts.size(); i++) {
        //  Find the first cart that can accommodate number
        for (int j = allNumbers.size()-1; j >= 0; j--) {
            if (carts[i]->sumNumbers() + allNumbers[j] <= carts[i]->getMaxNumber()) {
                carts[i]->addNumber(allNumbers[j]);
                allNumbers.erase(allNumbers.begin()+j);
            }
        }
    }

    //  If a cart could accommodate number
    if(allNumbers.empty()){
        return true;
    }
    else{

        return false;
    }
}

bool Algorithm::bestFit(int number, std::vector<Cart*> carts) {
    bool placed = false;
    int bestCart = 0;
    int bestDifference = carts[0]->getMaxNumber() - carts[0]->sumNumbers();

    // Now call best fit
    // Place item
    for (int i = 0; i < carts.size(); i++) {
        //  Find the cart with the tightest spot that can accomodate the number
        if (carts[i]->sumNumbers() + number <= carts[i]->getMaxNumber() and carts[i]->calculateDifference() <= bestDifference) {
            bestCart = i;
            bestDifference = carts[i]->calculateDifference();
            placed = true;
        }
    }

    // If a place for the number is found, place it there.
    if (placed){
        carts[bestCart]->addNumber(number);
    }

    return placed;
}