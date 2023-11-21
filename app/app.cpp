#include "app.h"
#include <string>

unsigned short operator"" _us(unsigned long long n) {
	return n;
}

void divisible_count(int* arr, int nArr, int* div, int nDiv) {
	int* result = new int[nArr];
	for (int i = 0; i < nArr; i++) {
		int counter = 0;
		for (int j = 0; j < nDiv; j++) {
			if (arr[i] % div[j] == 0) counter++;
		}
		result[i] = counter;
	}
	for (int i = 0; i < nArr; i++) {
		arr[i] = result[i];
	}
	delete[] result;
}

std::unique_ptr<course> course_factory(int course_index) {
	return course_factory(course_index, 0, 0);
}
std::unique_ptr<course> course_factory(int course_index, unsigned short year, unsigned short students) {
	switch (course_index)
	{
	case 1:
		return std::make_unique<course_one>(students, year);
	case 2:
		return std::make_unique<course_two>(students, year);
	default:
		return nullptr;
	}
}

int cards_value(const std::string cards)
{
	if (cards.size() == 0) return 0;
	int value(0);
	for (std::string::size_type i = 0; i < cards.size(); ++i) {
		switch (cards[i]) {
		case 'A':
			value += 1;
			break;
		case '2':
			value += 2;
			break;
		case '3':
			value += 3;
			break;
		case '4':
			value += 4;
			break;
		case '5':
			value += 5;
			break;
		case '6':
			value += 6;
			break;
		case '7':
			value += 7;
			break;
		case '8':
			value += 8;
			break;
		case '9':
			value += 9;
			break;
		case 'T':
			value += 10;
			break;
		case 'J':
			value += 11;
			break;
		case 'Q':
			value += 12;
			break;
		case 'K':
			value += 13;
			break;
		default:
			return -1;
		}
	}
	return value;
}


void polyline::add(const vertex& v) {
	//ver[current_member] = std::make_unique<vertex>(v);
	ver[current_member] = v;
	current_member++;
}

double polyline::length() {
	double distance(0.);
	for (int i = 1; i < members; i++) {
		distance += sqrt((ver[i - 1].x - ver[i].x) * (ver[i - 1].x - ver[i].x) + (ver[i - 1].y - ver[i].y) * (ver[i - 1].y - ver[i].y));
	}
	return distance;
}