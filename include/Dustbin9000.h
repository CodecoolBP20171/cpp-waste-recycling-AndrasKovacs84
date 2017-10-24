//
// Created by András on 2017. 10. 20..
//

#ifndef CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBIN9000_H
#define CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBIN9000_H


#include "Dustbin.h"
#include "MetalGarbage.h"
#include "BottleCap.h"

class Dustbin9000 : public Dustbin {
public:
    Dustbin9000(const std::string &color);
    void throwOutMetalGarbage(std::unique_ptr<MetalGarbage>);
    void throwOutBottleCap(std::unique_ptr<BottleCap>);
    virtual void emptyContents();
    const std::vector<std::unique_ptr<MetalGarbage>> &getMetalContent() const;
    const std::vector<std::unique_ptr<BottleCap>> &getBottleCapContent() const;

private:
    std::vector<std::unique_ptr<MetalGarbage>> metalContent;
    std::vector<std::unique_ptr<BottleCap>> bottleCapContent;

};


#endif //CPP_WASTE_RECYCLING_ANDRASKOVACS84_DUSTBIN9000_H
