#include <iostream>
#include "app.h"
#include <numbers>
#include <vector>

int main() {
    //1
    int arr_size, div_size;

    std::cout << "Enter the size of arr: ";
    std::cin >> arr_size;

    int* arr = new int[arr_size];

    std::cout << "Enter elements for arr: ";
    for (int i = 0; i < arr_size; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the size of div: ";
    std::cin >> div_size;

    int* div = new int[div_size];

    std::cout << "Enter elements for div: ";
    for (int i = 0; i < div_size; ++i) {
        std::cin >> div[i];
    }

    divisible_count(arr, arr_size, div, div_size);

    //2
    std::string course_name;
    int year, students;

    std::cout << "Enter the course name: ";
    std::cin >> course_name;

    std::cout << "Enter the year: ";
    std::cin >> year;

    std::cout << "Enter the number of students: ";
    std::cin >> students;

    auto c = course_factory(course_name, year, students);

    //3
    std::string input_card;

    std::cout << "Enter a card value: ";
    std::cin >> input_card;

    int value = cards_value(input_card);

    if (value != -1) {
        std::cout << "The value of card " << input_card << value << std::endl;
    }
    //4
    std::size_t num_vertices;
    std::cout << "Enter the number of vertices for the polyline: ";
    std::cin >> num_vertices;

    std::vector<vertex> coordinates;
    std::cout << "Enter the coordinates for each vertex:" << std::endl;
    for (std::size_t i = 0; i < num_vertices; ++i) {
        double x, y;
        std::cout << "Vertex " << i + 1 << " - x: ";
        std::cin >> x;
        std::cout << "Vertex " << i + 1 << " - y: ";
        std::cin >> y;
        coordinates.push_back({ x, y });
    }

    polyline p(num_vertices);
    for (const auto& v : coordinates) {
        p.add(v);
    }

    std::cout << "The length of the polyline is: " << p.length() << std::endl;
}

