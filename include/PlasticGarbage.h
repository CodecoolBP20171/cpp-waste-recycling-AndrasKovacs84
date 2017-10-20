//
// Created by András on 2017. 10. 19..
//

#ifndef CPP_WASTE_RECYCLING_ANDRASKOVACS84_PLASTICGARBAGE_H
#define CPP_WASTE_RECYCLING_ANDRASKOVACS84_PLASTICGARBAGE_H


#include "Garbage.h"

class PlasticGarbage : public Garbage {
public:
    PlasticGarbage(const std::string &name, int weight, bool isClean);

    bool getIsClean() const;
    void clean();

private:
    bool isClean;
};


#endif //CPP_WASTE_RECYCLING_ANDRASKOVACS84_PLASTICGARBAGE_H
