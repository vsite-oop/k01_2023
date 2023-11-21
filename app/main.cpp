#include "app.h"
#include<iostream>


int main()
{
   std::cout << "Enter the size of the first array: ";
    int a;
    std::cin >> a;

    std::cout << "Enter the values of the first array: ";
    int* arr = new int[a];
    for (int i = 0; i < a; ++i) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the size of the second array: ";
    int b;
    std::cin >> b;

    std::cout << "Enter the values of the second array: ";
    int* div = new int[b];
    for (int i = 0; i < b; ++i) {
        std::cin >> div[i];
    }

    int result = divisible_count(arr, a, div, b);

  
    std::cout << "Number of elements divisible by at least one element in the second array: " << result << std::endl;

   
    delete[] arr;
    delete[] div;


    std::string hand;
    std::cin >> hand;
    int value = cards_value(hand);

    std::cout << "Hand value: " << value << std::endl;

    int poly;
    std::cin >> poly;
    polyline p1(poly);

    return 0;
}

