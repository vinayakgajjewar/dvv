#ifndef INCLUDE_DVV_HPP
#define INCLUDE_DVV_HPP

namespace dvv {
    typedef struct {
        std::string value;
        std::unordered_map<std::string, int> vv;
        std::tuple<std::string, int> dot;
    } dvv;

    void sync();

    void update();
}

#endif