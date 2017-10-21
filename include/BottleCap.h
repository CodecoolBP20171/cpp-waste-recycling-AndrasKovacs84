//
// Created by András on 2017. 10. 20..
//

#ifndef CPP_WASTE_RECYCLING_ANDRASKOVACS84_BOTTLECAP_H
#define CPP_WASTE_RECYCLING_ANDRASKOVACS84_BOTTLECAP_H


#include "Garbage.h"

class BottleCap : public Garbage {
public:
    BottleCap(const std::string &name, size_t weight, const std::string &color);

    const std::string &getColor() const;

private:
    std::string color;
};


#endif //CPP_WASTE_RECYCLING_ANDRASKOVACS84_BOTTLECAP_H
