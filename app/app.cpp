#include "app.h"

//Ne znam smijem li includati u kolokvij, ali mi je javljalo grešku
#include <numbers>

void divisible_count(int prvi_arr[], int size1, int div_arr[], int size2) {
	for (int i = 0; i < size1; i++) {
		int count = 0;
		for (int j = 0; j < size2; j++) {
			if (prvi_arr[i] % div_arr[j] == 0) {
				count++;
			}
		}
		prvi_arr[i] = count;
	}
}

uint16_t operator "" _us(unsigned long long n_us) {
	return n_us;
}

course_mold::course_mold(uint16_t year, uint16_t n_students, const std::string& title)	: _year(year), _n_students(n_students), _title(title) {}

std::string course_mold::title() const {
	return _title;
}

uint16_t course_mold::students() const {
	return _n_students;
}

uint16_t course_mold::year() const {
	return _year;
}

std::unique_ptr<course> course_factory(int for_case, uint16_t year, uint16_t n_students) {
	switch (for_case)
	{
	case 1:
		return std::make_unique<course_mold>(year, n_students, "oop");
	case 2:
		return std::make_unique<course_mold>(year, n_students, "nwp");
	default:
		return nullptr;
	}
}

int cards_value(const std::string& cards) {
	if (cards.empty()) {
		return 0;
	}
	int suma = 0;
	for (char card : cards) {
		if (isdigit(card)){
			if(card == '1') return -1;
			else {
				suma += int(card) - '0';
			}
		}
		else if (card == 'A') { suma += 1; }
		else if (card == 'T') { suma += 10; }
		else if (card == 'J') { suma += 11; }
		else if (card == 'Q') { suma += 12; }
		else if (card == 'K') { suma += 13; }
		else { return -1; }
	}
	return suma;

	/*std::string all_cards[13] = {
		{"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
		{"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"T", 10},
		{"J", 11}, {"Q", 12}, {"K", 13}
	};*/

	
}

double distance(const vertex& verta, const vertex& vertb) {
	int dx = vertb.x - verta.x, dy = vertb.y - verta.y;
	return sqrt(dx * dx + dy * dy);
}


polyline::polyline(int n) : verteces(new vertex[n]), _num(0) {}

polyline::polyline(const polyline& other) : verteces(new vertex[other._num]), _num(other._num) {
	for (int i = 0; i < _num; ++i)
		verteces[i] = other.verteces[i];
}
polyline::~polyline() {
	delete[] verteces;
}

void polyline::add(const vertex& verta) {
	verteces[_num++] = verta;
}
double polyline::length() const {
	double len = 0;
	for (int i = 0; i < _num - 1; i++)
		len += distance(verteces[i], verteces[i + 1]);
	return len;
}