#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include<iterator>
#include <cctype>

namespace ko1 {
	void divisible_count(int ar[], int arlen, int div[], int divlen);

	uint16_t operator ""_us(unsigned long long x);

	class course {
	protected:
		uint16_t st=0;
		uint16_t y=0;
	public:
		virtual std::string title() const= 0;
		virtual uint16_t students() const= 0;
		virtual uint16_t year() const= 0;
	};

	class oop : public course {
		std::string name = "oop";
	public:
		oop(uint16_t year, uint16_t student);
		std::string title() const override;
		uint16_t students() const override;
		uint16_t year() const override;
	};

	class nwp :public course {
		std::string name = "nwp";
	public:
		nwp(uint16_t year, uint16_t student);
		std::string title() const override;
		uint16_t students() const override;
		uint16_t year() const override;
	};

	std::unique_ptr<course> course_factory(int selection, uint16_t y=0, uint16_t s=0);

	int cards_value(std::string s);

	struct vertex { int x, y; };

	class polyline {
		int n; 
		vertex* v;
	public:
		polyline(int n);
		double length();
		void add(const vertex& pt);
	};
}
