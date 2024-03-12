#pragma once
#include<vector>
#include<iostream>

using namespace std;

template <typename T>
class DynamicArray {
private:
    vector<T> array;

public:

    void initializeArray(T value) { 
        cout << "Where are you want to push your element: 1.Start, 2.End\n>";
        int where;
        cin >> where;
        switch (where) {
        case 1:
            array.insert(array.begin(), value);
            break;
        case 2:
            array.push_back(value);
            break;
        }
    }
    
    void viewArray() {
        for (int i = 0; i < array.size(); i++) {
            cout << array[i] << " | ";
        }
        cout << "\n";
    }
    
    void delElem() {
        array.pop_back();
    }
    
    void performOperation() {
        int size_arr = array.size();
        for (int i = 0; i < array.size(); i++) {
            array[i] = size_arr - i + array[i];
        }
    }
};