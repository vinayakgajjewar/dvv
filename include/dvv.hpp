#ifndef INCLUDE_DVV_HPP
#define INCLUDE_DVV_HPP

#include <string>
#include <unordered_map>
#include <vector>

using dvv = std::unordered_map<std::string, std::vector<int>>;

/*
 * Returns a set of concurrent DVVs that describe the collective causal past of
 * the input DVV sets while discarding obsolete knowledge.
 */
std::vector<dvv> dvv_sync(const std::vector<dvv> &, const std::vector<dvv> &);

dvv dvv_update(const std::vector<dvv> &, const std::vector<dvv> &, const std::string &);

/*
 * Print the contents of a DVV to the console.
 */
void dvv_print(const dvv &);

#endif