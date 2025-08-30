#include <iostream>

#include "include/dvv.hpp"

int main() {
    dvv d1 = {{"r", {4}}};
    dvv d2 = {{"r", {3, 5}}};
    if (dvv_leq(d1, d2)) {
        std::cout << "d1 <= d2" << std::endl;
    } else if (dvv_leq(d2, d1)) {
        std::cout << "d2 <= d1" << std::endl;
    } else {
        std::cout << "d1 || d2" << std::endl;
    }
}