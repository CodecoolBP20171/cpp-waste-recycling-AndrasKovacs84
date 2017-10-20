//
// Created by András on 2017. 10. 19..
//

#include "../include/PaperGarbage.h"


void PaperGarbage::squeeze() {
    this->isSqueezed = true;
}

bool PaperGarbage::getIsSqueezed() const {
    return isSqueezed;
}

PaperGarbage::PaperGarbage(const std::string &name, size_t weight, bool isSqueezed) : Garbage(name, weight),
                                                                                      isSqueezed(isSqueezed) {}


