//
// Created by Jose Diaz on 5/7/21.
//

#ifndef ALGORITHMTEST_CART_H
#define ALGORITHMTEST_CART_H

#include "vector"
#include <ostream>
#include "iostream"

class Cart {

private:
    int max_number;
    std::vector <int> numbers;
public:
    Cart(int maxNumber, const std::vector<int> &numbers);

    virtual ~Cart();

    int getMaxNumber() const;
    void setMaxNumber(int maxNumber);

    std::vector<int> getNumbers() const;
    void setNumbers(const std::vector<int> &numbers);

    int sumNumbers();
    void addNumber(int number);
    void removeNumber();
    void removeAllNumbers();
    int calculateDifference();

    friend std::ostream &operator<<(std::ostream &os, const Cart &cart);

public:
};


#endif //ALGORITHMTEST_CART_H
