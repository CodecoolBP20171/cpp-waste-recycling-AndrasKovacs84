//
// Created by András on 2017. 10. 20..
//

#ifndef CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBINISFULL_H
#define CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBINISFULL_H


#include <exception>

class DustbinIsFull: public std::exception {

public:
    const char* what();
};


#endif //CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBINISFULL_H
