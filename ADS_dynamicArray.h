//
// Created by Влад on 19/03/2023.
//

#ifndef DSA_2_ADS_DYNAMICARRAY_H
#define DSA_2_ADS_DYNAMICARRAY_H

#include "vector"

const unsigned int N = 100;
typedef unsigned int typeitem;

struct ADS_dynamicArray {
    //Определение данных АТД задачи
    std::vector<typeitem> A;
    unsigned int n = 0;
    explicit ADS_dynamicArray(int size) {
        n = size;
        A.resize(size);
    }
    //Заполнение множества с клавиатуры
    static void make(ADS_dynamicArray &x);
    //1)	Заполнение структуры данных значениями (случайными числами)
    static void makerand(ADS_dynamicArray &x);
    //Вывод множества
    static void print(ADS_dynamicArray x);
    //Удаление элемента по индексу
    static void deleteElem(ADS_dynamicArray &x, unsigned int index);
    //Вставка элемента по индексу
    static void insert(ADS_dynamicArray &x, unsigned int index, int value);
    //Проверка, имеет ли число более двух целых положительных делителей
    static bool isTwoDivisors(unsigned int a);
    //Создание нового массива из чисел исходного, которые имеют более двух целых положительных делителей.
    static void makeNewArr(ADS_dynamicArray &x, ADS_dynamicArray &y);
};

#endif //DSA_2_ADS_DYNAMICARRAY_H
