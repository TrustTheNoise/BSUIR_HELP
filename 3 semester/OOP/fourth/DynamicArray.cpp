#include "DynamicArray.h"
#include <iostream>
using namespace std;

template<class T>
void DynamicArray<T>::viewArray()
{
    for(int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " | ";
    }
    std::cout << "\n";
}

template<class T>
void DynamicArray<T>::delElem() {
    array.pop();
}

template<class T>
void DynamicArray<T>::performOperation()
{
    for(int i = 0; i < array.size; i++) {
        array[i] = array.size - i + array[i];
    }
}