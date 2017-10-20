//
// Created by András on 2017. 10. 19..
//

#include "../include/PlasticGarbage.h"

PlasticGarbage::PlasticGarbage(const std::string &name, int weight, bool isClean) : Garbage(name, weight),
                                                                                    isClean(isClean) {}
void PlasticGarbage::clean() {
    this->isClean = true;
}

bool PlasticGarbage::getIsClean() const {
    return isClean;
}

