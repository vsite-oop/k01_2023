#include "app.h"

namespace ko1 {
	void divisible_count(int ar[], int arlen, int div[], int divlen) {	
		for (int i = 0; i < arlen; i++) {
			int sum = 0;
			for (int j = 0; j < divlen; j++) {
				if (ar[i] % div[j] == 0) { sum++; }
			}
			ar[i] = sum;
		}
	}

	uint16_t operator ""_us(unsigned long long x) {
		return x;
	}
	oop::oop(uint16_t year, uint16_t student){
		y = year; st = student;
	}
	uint16_t oop::students() const {
		return st;
	}
	uint16_t oop::year() const {
		return y;
	}
	std::string oop::title() const {
		return name;
	}
	nwp::nwp(uint16_t year, uint16_t student) {
		y = year; st = student;
	}
	uint16_t nwp::students() const {
		return st;
	}
	uint16_t nwp::year() const {
		return y;
	}
	std::string nwp::title() const {
		return name;
	}


	std::unique_ptr<course> course_factory(int selection, uint16_t y, uint16_t s) {
		switch (selection)
		{
		case 1:
			return std::make_unique<oop>(y, s);
		case 2:
			
			return std::make_unique<nwp>(y,s);
		default:
			return nullptr;
		}
	}

	int cards_value(std::string s) {
		if (s == "") { return 0; }
		int sum = 0;
		for (int i = 0; i <std::size(s); i++) {
			switch (s[i])
			{
				case 'T':
					sum += 10;
					continue;
				case 'J':
					sum += 11;
					continue;
				case 'Q':
					sum += 12;
					continue;

				case 'K':
					sum += 13;
					continue;

				case 'A':
					sum += 1;
					continue;

				case '1':
					return -1;
					if (std::isdigit(s[i])) {
						sum += (s[i])-'0';

					}
					else {
						return -1;
					}
					continue;
			}

		}
		return sum;
	}

	polyline::polyline(int n) : v(new vertex[n]), n(0) {}

	double distance(const vertex& a, const vertex& b) {
		int dx = b.x - a.x, dy = b.y - a.y;
		return sqrt(dx * dx + dy * dy);
	}
	void polyline::add(const vertex& pt) { v[n++] = pt; }
	double polyline::length() {
		double dis=0;
		for (int i = 0; i < n - 1; ++i)
			dis += distance(v[i], v[i + 1]);
		return dis;
	}
}