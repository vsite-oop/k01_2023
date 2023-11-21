#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <numbers>

unsigned short operator"" _us(unsigned long long n);

void divisible_count(int* arr, int nArr, int* div, int nDiv);

class course {
public:
	virtual std::string title() = 0;
	virtual unsigned short students() = 0;
	virtual unsigned short year() = 0;
	virtual ~course() = default;
};

class course_one : public course {
	unsigned short s;
	unsigned short y;
public:
	course_one(unsigned short students, unsigned short year) : s(students), y(year) {}
	std::string title() override { return "oop"; }
	unsigned short students() override { return s; }
	unsigned short year() override { return y; }
};

class course_two : public course {
	unsigned short s;
	unsigned short y;
public:
	course_two(unsigned short students, unsigned short year) : s(students), y(year) {}
	std::string title() override { return "nwp"; }
	unsigned short students() override { return s; }
	unsigned short year() override { return y; }
};

std::unique_ptr<course> course_factory(int course_index);
std::unique_ptr<course> course_factory(int course_index, unsigned short year, unsigned short students);

int cards_value(const std::string cards);

struct vertex {
	int x, y;
	vertex(int x = 0, int y = 0) : x(x), y(y) {}
};

class polyline {
	int members;
	int current_member;
	vertex* ver;
public:
	polyline(int n) : members(n), current_member(0) {}
	void add(const vertex& v);
	double length();
	~polyline() { delete[] ver; }
};