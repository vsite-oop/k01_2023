#include "app.h"

uint16_t operator "" _us(unsigned long long d) {
    return d;
}


void divisible_count(int* arr, int arrCount, int* div, int divCount) {
    for (int i = 0; i < arrCount; i++) {
        int count = 0;
        for (int j = 0; j < divCount; j++) {
            if (arr[i] % div[j] == 0)
            {
                count++;
            }
        }
        arr[i] = count;
    }
}



// course oop
std::string oop::title() const {
    return "oop";
}
uint16_t oop::students() const {
    return 16_us;
}
uint16_t oop::year() const {
    return 2023_us;
}

// course nwp
std::string nwp::title() const {
    return "nwp";
}
uint16_t nwp::students() const {
    return 10_us;
}
uint16_t nwp::year() const {
    return 2024_us;
}



std::unique_ptr<course> course_factory(int courseId) {
    return nullptr;
}

std::unique_ptr<course> course_factory(int courseId, int year, int stud) {
    switch (courseId)
    {
    case 1:        
        return std::make_unique<oop>();
    case 2:
        return std::make_unique<nwp>();
    default:
        return nullptr;
    }
}


// cards

int cards_value(std::string inString) {

    if (inString == "")
    {
        return 0;
    }

    card cards[]{ {'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13} };
    int sum = 0;
    int elementFound = 0;    
    
    for (auto symbol : inString)
    {
        for (auto card : cards)
        {
            if (symbol == card.color)
            {
                sum += card.value;
                elementFound++;
            }
        }
    }

    if (inString.length() != elementFound)
    {
        return -1;
    }

    return sum;
}


// polyline

polyline::polyline(uint32_t lCount) : _lineCount(lCount), _lines(new vertex[_lineCount]) { };

polyline::polyline(const polyline& other) : _lineCount(other._lineCount), _lines(new vertex[_lineCount]) {
    for (uint32_t i = 0; i < other._lineCount; i++)
    {
        _lines[i] = other._lines[i];
    }
};

polyline::~polyline() {
    delete[] _lines;
}

void polyline::add(vertex v) {
    _lines[_currentCount] = v;
    _currentCount++;
}

double polyline::length() {
    double sum = 0;
    for (uint32_t i = 0; i < _lineCount - 1; i++) {
        sum += sqrt(pow((_lines[i + 1].x - _lines[i].x), 2) + pow((_lines[i + 1].y - _lines[i].y), 2));
    }
    return sum;
}