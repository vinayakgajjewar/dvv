#include <iostream>
#include <unordered_set>

#include "../include/dvv.hpp"

/*
 * Get the set of node IDs in a given DVV.
 */
std::vector<std::string> dvv_ids(const dvv &a) {
    std::vector<std::string> ids;
    for (const auto &[id, counters]: a) {
        ids.push_back(id);
    }
    return ids;
}

/*
 * Get the set of node IDs in a given DVV set.
 */
std::vector<std::string> dvv_ids(const std::vector<dvv> &v) {
    std::vector<std::string> ids;
    for (const auto &d: v) {
        auto d_ids = dvv_ids(d);
        ids.insert(ids.end(), d_ids.begin(), d_ids.end());
    }
    return ids;
}

bool elem_leq(const std::vector<int> &a, const std::vector<int> &b) {
    auto asz = a.size();
    auto bsz = b.size();
    assert(asz <= 2);
    assert(bsz <= 2);
    if (asz == 1 && bsz == 1) return (a.at(0) <= b.at(0));
    if (asz == 1) return (a.at(0) <= b.at(0) || (b.at(0) == b.at(1) + 1 && a.at(0) == b.at(1)));
    if (bsz == 1) return (a.at(1) <= b.at(0));
    return (a.at(1) <= b.at(0) || (a.at(0) <= b.at(0) && a.at(1) == b.at(1)));
}

bool dvv_leq(const dvv &a, const dvv &b) {
    bool dvv_leq = true;
    for (const auto &[a_id, a_counters]: a) {
        bool id_leq = false;
        for (const auto &[b_id, b_counters]: b) {
            if (a_id != b_id) continue;
            if (elem_leq(a_counters, b_counters)) {
                id_leq = true;
                break;
            }
        }
        if (!id_leq) {
            dvv_leq = false;
            break;
        }
    }
    return dvv_leq;
}

/*
 * Return the max counter value in a DVV for a given identifier.
 *
 * TODO
 * This implementation is inefficient. We can just look up the ID in the DVV.
 */
int dvv_ceil(const dvv &d, const std::string &id) {
    auto max = 0;
    for (const auto &[d_id, d_counters]: d) {
        if (d_id == id) max = d_counters[d_counters.size() - 1];
    }
    return max;
}

/*
 * Get the max counter value in a set of DVVs for a given identifier.
 */
int dvv_ceil(const std::vector<dvv> &dvvs, const std::string &id) {
    auto max = 0;
    for (const auto &d: dvvs) {
        max = std::max(max, dvv_ceil(d, id));
    }
    return max;
}

std::vector<dvv> dvv_sync(const std::vector<dvv> &a, const std::vector<dvv> &b) {
    std::vector<dvv> concurrent;
    for (const dvv &a_dvv: a) {
        for (const dvv &b_dvv: b) {
            if (dvv_leq(a_dvv, b_dvv)) concurrent.push_back(b_dvv);
            if (dvv_leq(b_dvv, a_dvv)) concurrent.push_back(a_dvv);
        }
    }
    return concurrent;
}

dvv dvv_update(const std::vector<dvv> &ctx, const std::vector<dvv> &node_dvvs, const std::string &node_id) {
    dvv updated;
    for (const auto &ctx_id: dvv_ids(ctx)) {
        if (ctx_id == node_id) continue;
        auto new_counter = dvv_ceil(ctx, ctx_id);
        updated[ctx_id] = {new_counter};
    }
    auto s_r = dvv_ceil(node_dvvs, node_id);
    updated[node_id] = {s_r, s_r + 1};
    return updated;
}

void dvv_print(const dvv &d) {
    for (const auto &[id, counters]: d) {
        std::cout << id << std::endl;
        std::cout << "\t";
        for (auto c: counters) {
            std::cout << c << ",";
        }
        std::cout << std::endl;
    }
}