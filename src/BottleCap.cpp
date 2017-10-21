//
// Created by András on 2017. 10. 20..
//

#include "../include/BottleCap.h"

BottleCap::BottleCap(const std::string &name, size_t weight, const std::string &color) : Garbage(name, weight),
                                                                                         color(color) {}

const std::string &BottleCap::getColor() const {
    return color;
}
