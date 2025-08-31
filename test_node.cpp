#include <iostream>

#include "include/node.hpp"

int main() {
    auto r1 = node("r1");

    r1.put("k", "v1", {});

    auto get_result = r1.get("k");
    std::cout << get_result.size() << std::endl;
    assert(get_result.size() == 1);

    r1.put("k", "v2", {});
}