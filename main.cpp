#include <iostream>
#include "include/Garbage.h"
#include "include/PaperGarbage.h"
#include "include/PlasticGarbage.h"
#include "include/DustbinContentError.h"
#include "include/Dustbin.h"

int main() {
    std::cout << "garbage:" << std::endl;
    std::unique_ptr<Garbage> g(new Garbage("some other garbage", 10));
    std::cout << g->getName() << std::endl;

    std::cout << "paper:" << std::endl;
    std::unique_ptr<PaperGarbage> p(new PaperGarbage("some paper", 10, false));
    std::cout << p->getName() <<  std::endl;
    p->squeeze();

    std::cout << "plastic:" << std::endl;
    std::unique_ptr<PlasticGarbage> pl(new PlasticGarbage("some plastic", 20, false));
    std::cout << pl->getName() << std::endl;
    pl->clean();

    Dustbin dustbin("red");

    dustbin.printStatus();
    dustbin.throwOutGarbage(std::move(g));
    dustbin.printStatus();
    dustbin.throwOutPaperGarbage(std::move(p));
    dustbin.printStatus();
    dustbin.throwOutPlasticGarbage(std::move(pl));
    dustbin.printStatus();
    dustbin.emptyContents();
    dustbin.printStatus();

    return 0;
}