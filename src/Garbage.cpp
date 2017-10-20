//
// Created by András on 2017. 10. 19..
//

#include "../include/Garbage.h"

const std::string &Garbage::getName() const {
    return name;
}

Garbage::Garbage(const std::string &name, size_t weight) : name(name), weight(weight) {}

size_t Garbage::getWeight() const {
    return weight;
}
