#include "app.h"

void divisible_count(int* arr, size_t n, const int* d, size_t m) {
    for (size_t i{ 0 }; i < n; ++i) {
        auto c{ 0 };
        for (size_t j{ 0 }; j < m; ++j)
            if ((arr[i] % d[j]) == 0)
                ++c;
        arr[i] = c;
    }
}

class course_impl : public course {
    uint16_t y;
    uint16_t s;
public:
    course_impl(uint16_t y, uint16_t s) : y(y), s(s) {}
    uint16_t students() const override { return s; }
    uint16_t year() const override { return y; }
};

class oop : public course_impl {
public:
    oop(uint16_t y, uint16_t s) : course_impl(y, s) {}
    std::string title() const override { return "oop"; }
};

class nwp : public course_impl {
public:
    nwp(uint16_t y, uint16_t s) : course_impl(y, s) {}
    std::string title() const override { return "nwp"; }
};

std::unique_ptr<course> course_factory(int id, uint32_t year, uint32_t students) {
    switch (id) {
    case 1: return std::make_unique<oop>(year, students);
    case 2: return std::make_unique<nwp>(year, students);
    default: return nullptr;
    }
}

int cards_value(const std::string& s) {
    int n{ 0 };
    for (auto c : s) {
        if (c == 'A') ++n;
        else if (c == 'K') n += 13;
        else if (c == 'Q') n += 12;
        else if (c == 'J') n += 11;
        else if (c == 'T') n += 10;
        else if (c >= '2' && c <= '9') n += c - '0';
        else return -1;
    }
    return n;
}

double distance(const vertex& a, const vertex& b) {
    return std::hypot(a.x - b.x, a.y - b.y);
}

polyline::polyline(uint32_t n) : p(new vertex[n]), n(0) {}
polyline::polyline(const polyline& other) : p(new vertex[other.n]), n(other.n) {
    for (uint32_t i = 0; i < n; ++i)
        p[i] = other.p[i];
}
polyline::~polyline() { delete[] p; }
void polyline::add(const vertex& a) { p[n++] = a; }
double polyline::length() const {
    double d{ 0 };
    for (uint32_t i = 0; i < n - 1; ++i)
        d += distance(p[i], p[i + 1]);
    return d;
}
