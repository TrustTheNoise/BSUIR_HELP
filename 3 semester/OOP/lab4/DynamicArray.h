#pragma once
#include<vector>

template <typename T>
class DynamicArray {
private:
    std::vector<T> array;

public:

    void initializeArray(T value) { array.push_back(value); };
  /*  void viewArray();
    void delElem();
    void performOperation();*/
};

