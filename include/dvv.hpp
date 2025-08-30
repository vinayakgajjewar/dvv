#ifndef INCLUDE_DVV_HPP
#define INCLUDE_DVV_HPP

#include <string>
#include <unordered_map>
#include <vector>

using dvv = std::unordered_map<std::string, std::vector<int>>;

std::vector<dvv> dvv_sync(const std::vector<dvv> &, const std::vector<dvv> &);

dvv dvv_update(const std::vector<dvv> &, const std::vector<dvv> &, const std::string &);

void dvv_print(const dvv &);

#endif