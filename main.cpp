#include <iostream>
#include "ADS_dynamicArray.h"

int main() {
    int n, f, elem, index, k, flag = -1;
    std::cout << "Enter the size of the array\n";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Invalid array size\n";
        return -1;
    }

    ADS_dynamicArray A(n);
    ADS_dynamicArray B(n);

    std::cout << "Enter 1 if you want to fill in the array manually\n";
    std::cout << "Enter 2 if you want to fill in the array with random numbers\n";

    std::cin >> f;
    switch (f) {
        case 1:
            ADS_dynamicArray::make(A);
            break;
        case 2:
            ADS_dynamicArray::makerand(A);
            break;
        default:
            std::cout << "Invalid input\n";
            return -1;
    }

    while (flag != 0) {
        std::cout << "Enter:\n1 to fill in the array\n";
        std::cout << "2 to show the array\n";
        std::cout << "3 to create an array of numbers with more than 2 non-negative divisors\n";
        std::cout << "4 to insert a new element\n";
        std::cout << "0 to shut down the program\n";
        std::cin >> flag;
        switch (flag) {
            case 1:
                std::cout << "Enter the size of the array\n";
                std::cin >> n;
                if (n <= 0) {
                    std::cout << "Invalid array size\n";
                    return -1;
                }
                A = ADS_dynamicArray(n);

                std::cout << "Enter 1 if you want to fill in the array manually\n";
                std::cout << "Enter 2 if you want to fill in the array with random numbers\n";

                std::cin >> f;
                switch (f) {
                    case 1:
                        ADS_dynamicArray::make(A);
                        break;
                    case 2:
                        ADS_dynamicArray::makerand(A);
                    default:
                        std::cout << "Invalid input\n";
                        return -1;
                }
                break;
            case 2:
                if (A.n > 0) {
                    ADS_dynamicArray::print(A);
                } else {
                    std::cout << "The array is empty. First fill in the array\n";
                }
                break;
            case 3:
                if (A.n > 0) {
                    B = ADS_dynamicArray(0);
                    ADS_dynamicArray::makeNewArr(A, B);
                    std::cout << "Array of non-prime numbers: ";
                    ADS_dynamicArray::print(B);
                    B.A.clear();
                } else {
                    std::cout << "The array is empty. First fill in the array\n";
                }
                break;
            case 4:
                if (A.n > 0) {
                    std::cout << "Enter the new element\n";
                    std::cin >> elem;
                    std::cout << "Enter the position of new element (enumeration starts from 0)\n";
                    std::cin >> index;
                    ADS_dynamicArray::insert(A, index, elem);
                } else {
                    std::cout << "The array is empty. First fill in the array\n";
                }
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid input\n";
        }
    }
    A.A.clear();
    return 0;
}
