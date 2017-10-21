#include <iostream>
#include "include/Garbage.h"
#include "include/PaperGarbage.h"
#include "include/PlasticGarbage.h"
#include "include/DustbinContentError.h"
#include "include/Dustbin.h"
#include "include/Dustbin9000.h"

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

    std::cout << "metal: " << std::endl;
    std::unique_ptr<MetalGarbage> m(new MetalGarbage("some metal garbage", 1));
    std::cout << m->getName() << std::endl;

    std::cout << "bottle cap: " << std::endl;
    std::unique_ptr<BottleCap> bc(new BottleCap("some bottle cap", 1, "pink"));
    std::cout << bc->getName() << std::endl;

    Dustbin dustbin("red");
    Dustbin9000 d9k("yellow");

    d9k.printStatus();
    d9k.throwOutGarbage(std::move(g));
    d9k.printStatus();
    d9k.throwOutPaperGarbage(std::move(p));
    d9k.printStatus();
    d9k.throwOutPlasticGarbage(std::move(pl));
    d9k.printStatus();

    d9k.throwOutMetalGarbage(std::move(m));
    d9k.printStatus();
    d9k.throwOutBottleCap(std::move(bc));
    d9k.printStatus();

    return 0;
}