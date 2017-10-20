//
// Created by András on 2017. 10. 19..
//

#ifndef CPP_WASTE_RECYCLING_ANDRASKOVACS84_PAPERGARBAGE_H
#define CPP_WASTE_RECYCLING_ANDRASKOVACS84_PAPERGARBAGE_H

#include <iostream>
#include "Garbage.h"

class PaperGarbage: public Garbage{

public:
    PaperGarbage(const std::string &name, size_t weight, bool isSqueezed);

    bool getIsSqueezed() const;

    void squeeze();

private:
    bool isSqueezed;

};


#endif //CPP_WASTE_RECYCLING_ANDRASKOVACS84_PAPERGARBAGE_H
