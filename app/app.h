#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include<numbers>

void divisible_count(int* n, int x, int* n2, int y);

inline uint16_t operator""_us(unsigned long long int broj)
{
	return static_cast<uint16_t>(broj);
}

class course {
public:
	virtual std::string title() = 0;
	virtual uint16_t students() = 0;
	virtual uint16_t year() = 0;
	virtual ~course() = default;
};

std::unique_ptr<course> course_factory(int predmet = 0, int godina = 0, int br_studenata = 0);

class oop : public course {
	uint16_t st;
	uint16_t godina;
public:
	oop(int g, int br_studenata);
	std::string title() override;
	uint16_t students() override;
	uint16_t year() override;
};
class nwp : public course {
	uint16_t st;
	uint16_t godina;
public:
	nwp(int g, int br_studenata);
	std::string title() override;
	uint16_t students() override;
	uint16_t year() override;
};
int cards_value(const std::string& s);

struct vertex {
	int x, y;
};

class polyline {
	int duljina;
	vertex* niz;
	int indeks = 0;
public:
	polyline(int size);
	void add(const vertex& v);
	double length();
	polyline(const polyline& other);
	~polyline();
};