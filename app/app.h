#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include<cmath>

void divisible_count(int arr[], int size, int div[], int div_size);

int cards_value(const std::string& hand);

class course {
public:
	virtual ~course() = default;
	virtual std::string title() const = 0;
	virtual uint16_t students() const = 0;
	virtual uint16_t year() const = 0;
};

std::unique_ptr<course> course_factory(int id, int year=0000, int students=0);

constexpr uint16_t operator ""_us(unsigned long long value) {
	return static_cast<uint16_t>(value);
}

class vertex {
public:
	int x;
	int y;

	vertex() :x(0.0), y(0.0) {}
	vertex(int x, int y);
};

class polyline {
	vertex* vertices;
	int size;
	int capacity;

public:
	polyline(int capacity);
	~polyline();

	void add(const vertex& v);
	double length() const;
};