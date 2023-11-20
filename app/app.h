#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <numbers>

void divisible_count(int arr_to_divide[], int size_of_first, int dividers[], int size_of_second);

uint16_t operator ""_us(unsigned long long num);

class course {
public:
	virtual std::string title() const = 0;
	virtual uint16_t students() const = 0;
	virtual uint16_t year() const = 0;
	virtual ~course() = default;
};

class real_course : public course {
    int _id;
    uint16_t _year = 0;
    uint16_t _students = 0;
    std::string _title = 0;
public:
    real_course(int id, uint16_t year, uint16_t students, const std::string& title);
    std::string title() const override;
    uint16_t students() const override;
    uint16_t year() const override;
};

std::unique_ptr<course> course_factory(int id, uint16_t year = 0, uint16_t students = 0);

int cards_value(const std::string& s);

struct vertex { int x, y; };

double distance(const vertex& v1, const vertex& v2);

class polyline {
    int _num;
    vertex* v;
public:
    polyline(int num);
    polyline(const polyline& other);
    ~polyline();
    void add(const vertex& v);
    double length() const;
};

