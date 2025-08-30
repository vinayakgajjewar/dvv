#include <unordered_set>

#include "../include/dvv.hpp"

/*
 * TODO
 *
 * Private helper functions should be static?
 */

std::vector<std::string> dvv_ids(const dvv &a) {
    std::vector<std::string> ids;
    for (const auto &[id, counters]: a) {
        ids.push_back(id);
    }
    return ids;
}

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

int dvv_ceil(const dvv &d, const std::string &id) {
    auto max = 0;
    for (const auto &[d_id, d_counters]: d) {
        if (d_id == id) max = d_counters[d_counters.size() - 1];
    }
    return max;
}

int dvv_ceil(const std::vector<dvv> &dvvs, const std::string &id) {
    auto max = 0;
    for (const auto &d: dvvs) {
        max = std::max(max, dvv_ceil(d, id));
    }
    return max;
}

std::vector<dvv> dvv_sync(const std::vector<dvv> &a, const std::vector<dvv> &b) {
    std::vector<dvv> concurrent;
    auto a_ids = dvv_ids(a);
    auto b_ids = dvv_ids(b);
    std::unordered_set<std::string> ids(a_ids.begin(), a_ids.end());
    ids.insert(b_ids.begin(), b_ids.end());
    for (const auto &id: ids) {
        // TODO
    }
}

std::vector<dvv> dvv_update() {

}