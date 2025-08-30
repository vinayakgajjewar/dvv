#include "include/dvv.hpp"

int main() {
    dvv d1 = {{"r", {4}}};
    dvv d2 = {{"r", {3, 5}}};
    dvv_print(d1);
    dvv_print(d2);
    dvv_print(dvv_update({d2}, {d1}, "r"));
}