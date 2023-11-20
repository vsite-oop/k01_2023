#include "app.h"

void divisible_count(int arr[], int size, int div[], int div_size) {
	for (int i = 0;i < size;i++) {
		int count = 0;
		for (int j = 0;j < div_size;j++) {
			if (arr[i] % div[j] == 0) {
				count++;
			}
		}
		arr[i] = count;
	}
}

int cards_value(const std::string& hand) {
	int value = 0;

	for (char card : hand) {
		switch (card)
		{
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
		case 'A':
			value += 1;
			break;
		case '1':
			return -1;
		default:
			if (isdigit(card)) {
				value += (card-'0');
			}
			else {
				return -1;
			}
		}
	}
	return value;
}

class oop_course : public course {
	int year_;
	int students_;
public:
	oop_course(int year, int students) : year_(year), students_(students) {}

	std::string title() const override {
		return "oop";
	}

	uint16_t students() const override {
		return static_cast<uint16_t>(students_);
	}

	uint16_t year() const override {
		return static_cast<uint16_t>(year_);
		}
};

class nwp_course : public course {
	int year_;
	int students_;
public:
	nwp_course(int year, int students) :year_(year), students_(students) {}

	std::string title() const override {
		return "nwp";
	}

	uint16_t students() const override {
		return static_cast<uint16_t>(students_);
	}

	uint16_t year() const override {
		return static_cast<uint16_t>(year_);
	}
};

	std::unique_ptr<course> course_factory(int id, int year, int students) {
		if (id == 1) {
			return std::make_unique<oop_course>(year, students);
		}
		else if (id == 2) {
			return std::make_unique<nwp_course>(year, students);
		}
		else {
			return nullptr;
		}
	}

	vertex::vertex(int x, int y) : x(x), y(y) {}

	polyline::polyline(int capacity) : size(0), capacity(capacity) {
		vertices = new vertex[capacity]();
	}

	polyline::~polyline() {
		delete[] vertices;
	}

	void polyline::add(const vertex& v) {
		if (size < capacity) {
			vertices[size++] = v;
		}
	}

	double polyline::length() const {
		double totalLength = 0.0;

		for (int i = 0; i < size-1; ++i) {
			double dx = vertices[i + 1].x - vertices[i].x;
			double dy = vertices[i + 1].y - vertices[i].y;
			totalLength += std::sqrt(dx * dx + dy * dy);
		}

		return totalLength;
	}