#pragma once
#include<vector>

using namespace std;

template <typename T>
class DynamicArray {
private:
    vector<T> array;

public:

    void initializeArray(T value) { array.push_back(value); };
    void viewArray();
    void delElem();
    void performOperation();
};
