#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

void divisible_count(int*, size_t, const int*, size_t);

inline unsigned short operator "" _us(unsigned long long int n) {
    return n;
}

class course {
public:
    virtual std::string title() const = 0;
    virtual uint16_t students() const = 0;
    virtual uint16_t year() const = 0;
    virtual ~course() = default;
};
std::unique_ptr<course> course_factory(int id, uint32_t year = 0, uint32_t students = 0);

int cards_value(const std::string&);

struct vertex { int x, y; };

class polyline {
    uint32_t n;
    vertex* p;
public:
    polyline(uint32_t n);
    polyline(const polyline&);
    ~polyline();
    void add(const vertex&);
    double length() const;
};

