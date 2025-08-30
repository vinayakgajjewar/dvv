#include "../include/dvv.hpp"

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

bool dvv_descends(const std::vector<dvv> &a, const std::vector<dvv> &b) {
}

bool dvv_dominates(const std::vector<dvv> &a, const std::vector<dvv> &b);

std::vector<dvv> dvv_sync(const std::vector<dvv> &a, const std::vector<dvv> &b) {

}

std::vector<dvv> dvv_update() {}