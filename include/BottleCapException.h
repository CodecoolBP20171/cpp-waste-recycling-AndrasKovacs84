//
// Created by András on 2017. 10. 20..
//

#ifndef CPP_WASTE_RECYCLING_ANDRASKOVACS84_BOTTLECAPEXCEPTION_H
#define CPP_WASTE_RECYCLING_ANDRASKOVACS84_BOTTLECAPEXCEPTION_H


#include <exception>

class BottleCapException : public std::exception{

public:
    const char* what();
};


#endif //CPP_WASTE_RECYCLING_ANDRASKOVACS84_BOTTLECAPEXCEPTION_H
