#include "app.h"
#include<iostream>
#include<vector>
#include<numbers>


int divisible_count(int* arr, int a, int* div, int b) {
    
    int brojac = 0;
    for (int i = 0; i < a; ++i) 
    {
        for (int j = 0; j < b; ++j) 
        {
            if (div[j] != 0 && arr[i] % div[j] == 0) 
            {
                brojac += 1;
            }
        }

    }

    return brojac;  

    
    
}

int cards_value(const std::string& cards)
{
    int counter = 0;

    if (cards.empty()) {
        return 0; 
    }

    for (int i = 0; i < cards.size(); ++i)
    {
        if (cards[i] == 'A')
        {
            counter += 1;
        }
        else if (cards[i] == 'K')
        {
            counter += 13;
        }
        else if (cards[i] == 'Q')
        {
            counter += 12;
        }
        else if (cards[i] == 'J')
        {
            counter += 11;
        }
        else if (cards[i] == 'T')
        {
            counter += 10;
        }
        else if (cards[i] >= '2' && cards[i] <= '9')
        {
            counter += cards[i] - '0';
        }
        else
        {
            return -1; 
        }
    }

    return counter;
}

struct vertex
{
    double x, y;
};

class polyline
{
public:
    explicit polyline(size_t capacity) : points(capacity), size(0) {}

    void add(const vertex& v)
    {
        if (size < points.size())
        {
            points[size++] = v;
        }
    }

    double length() const
    {
        double totalLength = 0.0;
        for (size_t i = 0; i < size - 1; ++i)
        {
            totalLength += distance(points[i], points[i + 1]);
        }
        return totalLength;
    }

private:
    static double distance(const vertex& v1, const vertex& v2)
    {
        return std::sqrt(std::pow(v2.x - v1.x, 2) + std::pow(v2.y - v1.y, 2));
    }

    std::vector<vertex> points;
    size_t size;
};


