#include "app.h"
#include <numbers>

void divisible_count(int arr_to_divide[], int size_of_first, int dividers[], int size_of_second) {
	for (int i = 0; i < size_of_first; i++) {
		int count_of_dividers = 0;
		for (int j = 0; j < size_of_second; j++) {
			if (arr_to_divide[i] % dividers[j] == 0) {
				count_of_dividers++;
			}
		}
		arr_to_divide[i] = count_of_dividers;
	}
}

uint16_t operator ""_us(unsigned long long num) {
	return num;
}

real_course::real_course(int id, uint16_t year, uint16_t students, const std::string& title)
	: _id(id), _year(year), _students(students), _title(title) {}

std::string real_course::title() const {
	return _title;
}

uint16_t real_course::students() const {
	return _students;
}

uint16_t real_course::year() const {
	return _year;
}

std::unique_ptr<course> course_factory(int id, uint16_t year, uint16_t students) {
	switch (id)
	{
	case 1:
		return std::make_unique<real_course>(id, year, students, "oop");
	case 2:
		return std::make_unique<real_course>(id, year, students, "nwp");
	default:
		return nullptr;
	}
}

int cards_value(const std::string& s) {
	int sum = 0;
	for (char letter : s) {
		if (letter == '1')
			return -1;
		else if (isdigit(letter))
			sum += int(letter) - '0';
		else if (letter == 'A')
			sum++;
		else if (letter == 'T')
			sum += 10;
		else if (letter == 'J')
			sum += 11;
		else if (letter == 'Q')
			sum += 12;
		else if (letter == 'K')
			sum += 13;
		else
			return -1;
	}
	return sum;
}

double distance(const vertex& v1, const vertex& v2) {
	int dx = v2.x - v1.x, dy = v2.y - v1.y;
	return sqrt(dx * dx + dy * dy);
}

polyline::polyline(int n) : v(new vertex[n]), _num(0) {}

polyline::polyline(const polyline& other) : v(new vertex[other._num]), _num(other._num) {
	for (int i = 0; i < _num; ++i)
		v[i] = other.v[i];
}

polyline::~polyline() { 
	delete[] v; 
}

void polyline::add(const vertex& a) { 
	v[_num++] = a; 
}
double polyline::length() const {
	double len= 0;
	for (int i = 0; i < _num - 1; i++)
		len += distance(v[i], v[i + 1]);
	return len;
}




