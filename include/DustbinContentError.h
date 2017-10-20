//
// Created by András on 2017. 10. 19..
//

#ifndef CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBINCONTENTERROR_H
#define CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBINCONTENTERROR_H

#include <exception>

class DustbinContentError: public std::exception {

public:
    const char* what();
};


#endif //CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBINCONTENTERROR_H
