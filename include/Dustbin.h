//
// Created by András on 2017. 10. 19..
//

#ifndef CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBIN_H
#define CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBIN_H

#include <iostream>
#include "Garbage.h"
#include "PlasticGarbage.h"
#include "PaperGarbage.h"
#include <vector>
#include <memory>

class Dustbin {
public:
    Dustbin(const std::string &color);
    void setColor(const std::string &color);

    void throwOutGarbage(std::unique_ptr<Garbage>);
    void throwOutPaperGarbage(std::unique_ptr<PaperGarbage>);
    void throwOutPlasticGarbage(std::unique_ptr<PlasticGarbage>);
    void emptyContents();
    void printStatus();


protected:
    //Constants
    const size_t MAX_WEIGHT = 50;
    const size_t MAX_GARBAGE_AMOUNT = 5;

    std::string color;

    size_t currentWeight = 0;
    size_t currentGarbageAmount = 0;
    std::vector<std::unique_ptr<PaperGarbage>> paperContent;
    std::vector<std::unique_ptr<PlasticGarbage>> plasticContent;
    std::vector<std::unique_ptr<Garbage>> houseWasteContent;
};


#endif //CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBIN_H
