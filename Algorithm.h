//
// Created by Jose Diaz on 5/7/21.
//

#ifndef ALGORITHMTEST_ALGORITHM_H
#define ALGORITHMTEST_ALGORITHM_H

#include "Cart.h"

struct Algorithm{
    Algorithm();
    virtual ~Algorithm();

    bool firstFit(int number, std::vector<Cart*> carts);
    bool firstFitDecreasing(int number, std::vector<Cart*> carts);
    bool bestFit(int number, std::vector<Cart*> carts);
};


#endif //ALGORITHMTEST_ALGORITHM_H
