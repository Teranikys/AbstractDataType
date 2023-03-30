//
// Created by Влад on 19/03/2023.
//

#ifndef DSA_2_ADT_DYNAMICARRAY_H
#define DSA_2_ADT_DYNAMICARRAY_H

#include "malloc.h"

typedef unsigned int typeitem;

struct ADT_dynamicArray {
    //Определение данных АТД задачи
    unsigned int n = 0;
    typeitem* A = nullptr;
    explicit ADT_dynamicArray(int n1){
        n = n1;
        A = (typeitem*) malloc(n * sizeof(typeitem));
    };

    //Заполнение множества с клавиатуры
    static void make(ADT_dynamicArray &x);
    //1)	Заполнение структуры данных значениями (случайными числами)
    static void makerand(ADT_dynamicArray &x);
    //Вывод множества
    static void print(ADT_dynamicArray x);
    //Удаление элемента по индексу
    static void deleteElem(ADT_dynamicArray &x, unsigned int index);
    //Вставка элемента по индексу
    static int insert(ADT_dynamicArray &x, unsigned int index, int value);
    //Проверка, имеет ли число более двух целых положительных делителей
    static bool isTwoDivisors(unsigned int a);
    //Создание нового массива из чисел исходного, которые имеют более двух целых положительных делителей.
    static void makeNewArr(ADT_dynamicArray &x, ADT_dynamicArray &y);
};

#endif //DSA_2_ADT_DYNAMICARRAY_H
