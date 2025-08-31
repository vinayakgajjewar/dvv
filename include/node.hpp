#ifndef INCLUDE_NODE_HPP
#define INCLUDE_NODE_HPP

#include "dvv.hpp"

#include <string>

class node {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, dvv>>> store;
    std::string id;
public:

    /*
     * Initialize a new replica node with a given ID.
     */
    node(const std::string &);

    /*
     * Return all the concurrent values that this replica node stores for the
     * given key.
     */
    std::vector<std::pair<std::string, dvv>> get(const std::string &);

    void put(const std::string &, const std::string &, const dvv &);
};

#endif