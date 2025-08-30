#ifndef INCLUDE_DVV_HPP
#define INCLUDE_DVV_HPP

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using dvv = std::unordered_map<std::string, std::vector<int>>;

std::vector<std::string> dvv_ids(const dvv &);

std::vector<std::string> dvv_ids(const std::vector<dvv> &);

bool elem_leq(const std::vector<int> &, const std::vector<int> &);

bool dvv_leq(const dvv &, const dvv &);

bool dvv_descends(const std::vector<dvv> &, const std::vector<dvv> &);

bool dvv_dominates(const std::vector<dvv> &, const std::vector<dvv> &);

/*
 * TODO
 *
 * Everything below this comment is the public facing interface. How do I hide
 * everything else?
 */

std::vector<dvv> dvv_sync(const std::vector<dvv> &, const std::vector<dvv> &);

std::vector<dvv> dvv_update(const std::vector<dvv> &, const std::vector<dvv> &, std::string);

#endif