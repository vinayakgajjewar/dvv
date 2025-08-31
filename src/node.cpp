#include "../include/node.hpp"

std::vector<std::pair<std::string, dvv>> node::get(const std::string &k) {
    return store[k];
}

void node::put(const std::string &k, const std::string &v, const dvv &ctx) {
    for (auto &sibling: store[k]) {
        auto sibling_dvv = sibling.second;
        if (dvv_leq(sibling_dvv, ctx)) {

            /*
             * TODO
             * I don't think this is correct. What if it' a dot?
             */
            sibling.second[id][0]++;
            sibling.first = v;
        } else {
            /*
             * TODO
             * How to handle this case?
             */
        }
    }
}