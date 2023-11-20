#include "app.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <memory>

//1
void divisible_count(int* arr, int arr_size, int* div, int div_size) {
    for (int i = 0; i < arr_size; ++i) {
        int count = 0;
        for (int j = 0; j < div_size; ++j) {
            if (arr[i] % div[j] == 0) {
                count++;
            }
        }
        arr[i] = count;
    }
}

//2
class dynamic_course : public course {
public:
    dynamic_course(std::string name, int year, int students)
        : course_name(std::move(name)), course_year(year), course_students(students) {}

    std::string title() const override { return course_name; }
    uint16_t students() const override { return course_students; }
    uint16_t year() const override { return course_year; }

private:
    std::string course_name;
    uint16_t course_year;
    uint16_t course_students;
};

std::unique_ptr<course> course_factory(const std::string& name, int year, int students) {
    return std::make_unique<dynamic_course>(name, year, students);
}

//3
int card_value(char card) {
    if (isdigit(card)) {
        return (card - '0');
    }
    else {
        switch (toupper(card)) {
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 1;
        }
    }
}

int cards_value(const std::string& cards) {
    int total_value = 0;
    for (char card : cards) {
        int value = card_value(card);
        if (value != -1) {
            total_value += value;
        }
    }
    return total_value;
}

//4
polyline::polyline(size_t size) : vertices(size) {}

void polyline::add(const vertex& v) {
    vertices.push_back(v);
}

double polyline::length() const {
    double total_length = 0.0;
    for (size_t i = 1; i < vertices.size(); ++i) {
        double dx = vertices[i].x - vertices[i - 1].x;
        double dy = vertices[i].y - vertices[i - 1].y;
        total_length += std::hypot(dx, dy);
    }
    return total_length;
}




