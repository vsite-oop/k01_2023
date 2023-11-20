#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include<vector>

int divisible_count(int* arr, int a, int* div, int b) {}


int cards_value(std::string cards) {}

struct vertex
{
    double x, y;
};

class polyline
{
public:
    explicit polyline(size_t capacity);
    void add(const vertex& v);
    double length() const;

private:
    static double distance(const vertex& v1, const vertex& v2);

    std::vector<vertex> points;
    size_t size;
};

