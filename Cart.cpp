//
// Created by Jose Diaz on 5/7/21.
//

#include "Cart.h"

Cart::Cart(int maxNumber, const std::vector<int> &numbers) : max_number(maxNumber), numbers(numbers) {}

Cart::~Cart() {

}

int Cart::getMaxNumber() const {
    return max_number;
}

void Cart::setMaxNumber(int maxNumber) {
    max_number = maxNumber;
}

std::vector<int> Cart::getNumbers() const{
    return numbers;
}

void Cart::setNumbers(const std::vector<int> &numbers) {
    Cart::numbers = numbers;
}

int Cart::sumNumbers() {
    int total;
    for (int i = 0; i < numbers.size(); i++) {
        total+=numbers[i];
    }
    return total;
}

int Cart::calculateDifference() {
    return max_number - this->sumNumbers();
}

void  Cart::addNumber(int number){
    numbers.push_back(number);
}

void  Cart::removeNumber() {
    numbers.pop_back();
}

void  Cart::removeAllNumbers() {
    numbers.clear();
}

std::ostream &operator<<(std::ostream &os, const Cart &cart) {
    os << "Max_number: " << cart.max_number << " | Numbers: ";
    for (int i = 0; i < cart.numbers.size(); i++) { os << cart.numbers[i] << " ";};
    return os;
}

