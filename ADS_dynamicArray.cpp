//
// Created by Влад on 19/03/2023.
//
#include "ADS_dynamicArray.h"
#include "iostream"
#include <cstdlib>
#include "ctime"
#include "random"

//1)	Заполнение структуры данных значениями (с клавиатуры);
//Предусловие. n – число заполняемых элементов, 0 < n < N, A– массив с переменной верхней границей.
//Постусловие. Заполненный массив A из n элементов. Нет возвращаемого значения.
void ADS_dynamicArray::make(ADS_dynamicArray& x) {
    std::cout << "Enter " << x.n << " numbers" << '\n';
    for (int i = 0; i < x.n; i++)
        std::cin >> x.A[i];
}

//2)	Заполнение структуры данных значениями (случайными числами);
//Предусловие. n – число заполняемых элементов, 0 < n < N, A– массив с переменной верхней границей.
//Постусловие. Заполненный массив A из n элементов. Нет возвращаемого значения.
void ADS_dynamicArray::makerand(ADS_dynamicArray &x) {
    srand((unsigned)time(nullptr));
    for (int i = 0; i < x.n; i++)
        x.A[i] = rand() % 100;
}

//3)	Вывод структуры в консоль;
//Предусловие. n>0, A – выводимый массив
//Постусловие. Вывод значений массива. Нет возвращаемого значения.
void ADS_dynamicArray::print(ADS_dynamicArray x) {
    std::cout << "Array of " << x.n << " numbers: ";
    for (int i = 0; i < x.n; i++)
        std::cout << x.A[i] << ' ';
    std::cout << '\n';
}

//4)	Удаление элемента в заданной позиции;
//Предусловие. Заполненный массив A из n элементов. Целочисленное значение 0 <= index <  n.
void ADS_dynamicArray::deleteElem(ADS_dynamicArray &x, unsigned int index) {
    x.A.erase(x.A.cbegin() + index);
    x.n--;
}

//5)	Вставка элемента в заданную позицию.
//Предусловие. Заполненный массив A из n элементов. n < N-1. 0 <= index < n – позиция для вставки.
// value – значение для вставки.
//Постусловие. Массив A из n+1 элементов с новым элементом. Нет возвращаемого значения.
void ADS_dynamicArray::insert(ADS_dynamicArray &x, unsigned int index, int value) {
    if (index <= x.n) {
        x.A.push_back(0);
        x.A.insert(x.A.cbegin() + index, value);
        x.n++;
    }
}

//1)	Проверка, имеет ли число более двух целых положительных делителей
//Предусловие. a – исходное число типа int.
//Постусловие. Результат – возвращаемое булево значение, true – если число a имеет больше двух простых делителей,
// false – если число a является простым.
bool ADS_dynamicArray::isTwoDivisors(unsigned int a) {
    for (int i = 2; i < trunc(sqrt(a) + 1); ++i) {
        if (a % i == 0) {
            return true;
        }
    }
    return false;
}

//2)	Создание нового массива из чисел исходного, которые имеют более двух целых положительных делителей.
//Предусловие. Заполненный массив A из n элементов. Целочисленное значение 0 <= index <  n.
//Постусловие. Массив A из чисел исходного, которые имеют более двух целых положительных делителей.
void ADS_dynamicArray::makeNewArr(ADS_dynamicArray &x, ADS_dynamicArray &y) {
    for (auto elem : x.A) {
        if (isTwoDivisors(elem)) {
            y.A.push_back(elem);
        }
    }
    y.n = y.A.size();
}
