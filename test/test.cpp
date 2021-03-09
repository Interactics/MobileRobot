#include "../include/unit/unit.h"
#include <iostream>

using namespace UNIT;

int main(){
    Position test{0, 0, 0, 0,0, 3.14};

    std::cout << test.euler[YAW] << std::endl;

}