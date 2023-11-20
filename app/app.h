#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

uint16_t operator "" _us(unsigned long long d);

void divisible_count(int* arr, int arrCount, int* div, int divCount); 

class course {

public:
    virtual std::string title() const = 0;
    virtual uint16_t students() const = 0;
    virtual uint16_t year() const = 0;
    virtual ~course() = default;
};

class oop : public course {
public:
    std::string title() const override;
    uint16_t students() const override;
    uint16_t year() const override;
};

class nwp : public course {
public:
    std::string title() const override;
    uint16_t students() const override;
    uint16_t year() const override;
};

std::unique_ptr<course> course_factory(int courseId);
std::unique_ptr<course> course_factory(int courseId, int year, int stud);


struct card {
    char color;
    int value;
};

int cards_value(std::string c);


struct vertex {
    int x = 0;
    int y = 0;
    
    vertex() { };
    vertex(int x, int y) : x(x), y(y) { };
};

class polyline {
    uint32_t _lineCount = 0;
    uint32_t _currentCount = 0;
    vertex* _lines;

public:
    polyline(uint32_t lCount);
    polyline(const polyline& other);
    ~polyline();

    void add(vertex v);

    double length();
};

