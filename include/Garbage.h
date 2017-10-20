//
// Created by András on 2017. 10. 19..
//

#ifndef CPP_WASTE_RECYCLING_ANDRASKOVACS84_GARBAGE_H
#define CPP_WASTE_RECYCLING_ANDRASKOVACS84_GARBAGE_H

#include <iostream>

class Garbage {
public:
    Garbage(const std::string &name, size_t weight);

    size_t getWeight() const;

    const std::string &getName() const;

private:
    std::string name;
    size_t weight;
};


#endif //CPP_WASTE_RECYCLING_ANDRASKOVACS84_GARBAGE_H
