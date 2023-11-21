#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cmath>

//1
void divisible_count(int* arr, int arr_size, int* div, int div_size);

//2
class course {
public:
    virtual std::string title() const = 0;
    virtual uint16_t students() const = 0;
    virtual uint16_t year() const = 0;
    virtual ~course() = default;
};

std::unique_ptr<course> course_factory(const std::string& name, int year, int students);

//3
int cards_value(const std::string& cards);
//4
struct vertex {
    double x;
    double y;
};

class polyline {
public:
    polyline(size_t size);
    void add(const vertex& v);
    double length() const;

private:
    std::vector<vertex> vertices;
};





