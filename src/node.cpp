#include "../include/node.hpp"

node::node(const std::string &id) {
    this->id = id;
}

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
             * If the client's context doesn't descend our local DVV, we have to
             * store the value as a sibling.
             */
            store[k].push_back(std::make_pair(v, dvv_sync()));
        }
    }
}