//
// Created by András on 2017. 10. 19..
//

#include "../include/Dustbin.h"
#include "../include/DustbinContentError.h"
#include "../include/DustbinIsFull.h"

Dustbin::Dustbin(const std::string &color) : color(color) {}

void Dustbin::setColor(const std::string &color) {
    Dustbin::color = color;
}

void Dustbin::throwOutGarbage(std::unique_ptr<Garbage> houseWaste) {
    if(currentWeight + houseWaste->getWeight() < MAX_WEIGHT && currentGarbageAmount < MAX_GARBAGE_AMOUNT){
        std::cout << houseWaste->getWeight() << std::endl;
        currentWeight += houseWaste->getWeight();
        currentGarbageAmount += 1;
        houseWasteContent.push_back(std::move(houseWaste));
    } else {
        throw DustbinIsFull();
    }
}

void Dustbin::throwOutPaperGarbage(std::unique_ptr<PaperGarbage> paperGarbage) {
    if(paperGarbage->getIsSqueezed()) {
        if(currentWeight + paperGarbage->getWeight() < MAX_WEIGHT && currentGarbageAmount < MAX_GARBAGE_AMOUNT){
            currentWeight += paperGarbage->getWeight();
            currentGarbageAmount += 1;
            paperContent.push_back(std::move(paperGarbage));
        } else {
            throw DustbinIsFull();
        }
    } else {
        throw DustbinContentError();
    }
}

void Dustbin::throwOutPlasticGarbage(std::unique_ptr<PlasticGarbage> plasticGarbage) {
    if(plasticGarbage->getIsClean()) {
        if(currentWeight + plasticGarbage->getWeight() < MAX_WEIGHT && currentGarbageAmount < MAX_GARBAGE_AMOUNT){
            currentWeight += plasticGarbage->getWeight();
            currentGarbageAmount += 1;
            plasticContent.push_back(std::move(plasticGarbage));
        } else {
            throw DustbinIsFull();
        }
    } else {
        throw DustbinContentError();
    }
}

void Dustbin::emptyContents() {
    houseWasteContent.empty();
    paperContent.empty();
    plasticContent.empty();
    currentGarbageAmount = 0;
    currentWeight = 0;
}

void Dustbin::printStatus() {
    std::cout << "\nDustbin status: \n";
    std::cout << "weight: " << currentWeight << std::endl;
    std::cout << "garbage amount: " << currentGarbageAmount << std::endl;
    std::cout << "Paper contents: ";
    for (auto& paper: paperContent) {
        std::cout << paper->getName() << " ";
    }
    std::cout << std::endl;
    std::cout << "Plastic contents: ";
    for (auto& plastic: plasticContent) {
        std::cout << plastic->getName() << " ";
    }
    std::cout << std::endl;
}
