#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>>

//Ne znam smijem li includati u kolokvij, ali mi je javljalo grešku
#include <numbers>

void divisible_count(int prvi_arr[], int size1, int div_arr[], int size2);

uint16_t operator "" _us(unsigned long long n_us);

class course {
public:
    virtual std::string title() const = 0;
    virtual uint16_t students() const = 0;
    virtual uint16_t year() const = 0;
    virtual ~course() = default;
};

class course_mold : public course {
private:
    uint16_t _year = 0;
    uint16_t _n_students = 0;
    std::string _title = 0;

public:
    course_mold(uint16_t year, uint16_t n_students, const std::string& title);

    std::string title() const override;

    uint16_t students() const override;

    uint16_t year() const override;

};

std::unique_ptr<course> course_factory(int for_case, uint16_t year = 0, uint16_t n_students = 0);

int cards_value(const std::string&);

//struct vertex {
//    int x;
//    int y;
//};
//
//class polyline {
//    int n;
//    array verteces;
//public:
//    polyline(int n);
//    polyline(const polyline&);
//    ~polyline();
//
//    void add(vertex*);
//    double length() const;
//};

struct vertex { int x, y; };

double distance(const vertex& verta, const vertex& vertb);

class polyline {
    int _num;
    vertex* verteces;
public:
    polyline(int num);
    polyline(const polyline& other);
    ~polyline();
    void add(const vertex& verteces);
    double length() const;
};