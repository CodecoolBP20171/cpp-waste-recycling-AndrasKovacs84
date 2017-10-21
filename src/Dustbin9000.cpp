//
// Created by András on 2017. 10. 20..
//

#include "../include/Dustbin9000.h"
#include "../include/DustbinIsFull.h"
#include "../include/BottleCapException.h"

Dustbin9000::Dustbin9000(const std::string &color) : Dustbin(color) {}

void Dustbin9000::throwOutMetalGarbage(std::unique_ptr<MetalGarbage> metalGarbage) {

    if(currentWeight + metalGarbage->getWeight() < MAX_WEIGHT && currentGarbageAmount < MAX_GARBAGE_AMOUNT){

        std::cout << metalGarbage->getWeight() << std::endl;
        currentWeight += metalGarbage->getWeight();
        currentGarbageAmount += 1;
        metalContent.push_back(std::move(metalGarbage));
    } else {
        throw DustbinIsFull();
    }
}

void Dustbin9000::throwOutBottleCap(std::unique_ptr<BottleCap> bottleCap) {

    if(currentWeight + bottleCap->getWeight() < MAX_WEIGHT && currentGarbageAmount < MAX_GARBAGE_AMOUNT){
        if(bottleCap->getColor() == "pink") {
            currentWeight += bottleCap->getWeight();
            currentGarbageAmount += 1;
            bottleCapContent.push_back(std::move(bottleCap));
        } else {
            throw BottleCapException();
        }
    } else {
        throw DustbinIsFull();
    }
}

void Dustbin9000::emptyWithExtraContents() {
    metalContent.clear();
    bottleCapContent.clear();
    emptyContents();

}

const std::vector<std::unique_ptr<MetalGarbage>> &Dustbin9000::getMetalContent() const {
    return metalContent;
}

const std::vector<std::unique_ptr<BottleCap>> &Dustbin9000::getBottleCapContent() const {
    return bottleCapContent;
}
