//
// Created by Влад on 19/03/2023.
//
#include "ADT_dynamicArray.h"
#include "iostream"
#include <cstdlib>
#include "ctime"
#include "random"

//1)	Заполнение структуры данных значениями (с клавиатуры);
//Предусловие. n – число заполняемых элементов, 0 < n < N, A– массив с переменной верхней границей.
//Постусловие. Заполненный массив A из n элементов. Нет возвращаемого значения.
void ADT_dynamicArray::make(ADT_dynamicArray& x) {
    std::cout << "Enter " << x.n << " numbers" << '\n';
    for (int i = 0; i < x.n; i++)
        std::cin >> x.A[i];
}

//2)	Заполнение структуры данных значениями (случайными числами);
//Предусловие. n – число заполняемых элементов, 0 < n < N, A– массив с переменной верхней границей.
//Постусловие. Заполненный массив A из n элементов. Нет возвращаемого значения.
void ADT_dynamicArray::makerand(ADT_dynamicArray &x) {
    srand((unsigned)time(nullptr));
    for (int i = 0; i < x.n; i++)
        x.A[i] = rand() % 100;
}

//3)	Вывод структуры в консоль;
//Предусловие. n>0, A – выводимый массив
//Постусловие. Вывод значений массива. Нет возвращаемого значения.
void ADT_dynamicArray::print(ADT_dynamicArray x) {
    std::cout << "Array of " << x.n << " numbers: ";
    for (int i = 0; i < x.n; i++)
        std::cout << x.A[i] << ' ';
    std::cout << '\n';
}

//4)	Удаление элемента в заданной позиции;
//Предусловие. Заполненный массив A из n элементов. Целочисленное значение 0 <= index <  n.
void ADT_dynamicArray::deleteElem(ADT_dynamicArray &x, unsigned int index) {
    for (int i = index; i < x.n - 1; ++i){
        x.A[i] = x.A[i + 1];
    }
    x.A = (typeitem*) realloc((typeitem*)x.A, (x.n - 1) * sizeof (typeitem));
    x.n--;
}

//5)	Вставка элемента в заданную позицию.
//Предусловие. Заполненный массив A из n элементов. n < N-1. 0 <= index < n – позиция для вставки.
// value – значение для вставки.
//Постусловие. Массив A из n+1 элементов с новым элементом. Нет возвращаемого значения.
int ADT_dynamicArray::insert(ADT_dynamicArray &x, unsigned int index, int value) {
    if ((index <= x.n)) {
        if ((x.A = (typeitem*) realloc((typeitem*)x.A, (x.n + 1) * sizeof (typeitem))) != NULL) {
            for (int i = x.n; i > index; --i){
                x.A[i] = x.A[i - 1];
            }
            x.A[index] = value;
            x.n++;
            return 0;
        }
    }
    return -1;
}

//1)	Проверка, имеет ли число более двух целых положительных делителей
//Предусловие. a – исходное число типа int.
//Постусловие. Результат – возвращаемое булево значение, true – если число a имеет больше двух простых делителей,
// false – если число a является простым.
bool ADT_dynamicArray::isTwoDivisors(unsigned int a) {
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
void ADT_dynamicArray::makeNewArr(ADT_dynamicArray &x, ADT_dynamicArray &y) {
    for (unsigned int i = 0; i < x.n; ++i) {
        if (isTwoDivisors(x.A[i])) {
            insert(y, y.n, x.A[i]);
        }
    }
}
