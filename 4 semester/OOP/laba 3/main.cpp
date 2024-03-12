#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // Для isdigit
#include <cstdlib> // Для atoi
#include <filesystem>


using namespace std;

// Функция шифрования Цезаря (Rot8)
char encryptChar(char c) {
    if (isalpha(c)) {
        char base = islower(c) ? 'a' : 'A';
        return (c - base + 8) % 26 + base;
    }
    return c;
}

// Функция для определения суммы всех целых чисел в строке
int sumOfIntegers(const string& str) {
    int sum = 0, i = 0;
    while (i < str.length()) {
        if (isdigit(str[i])) {
            string numStr;
            while (i < str.length() && isdigit(str[i])) {
                numStr += str[i++];
            }
            if (!numStr.empty()) {
                sum += atoi(numStr.c_str());
            }
        }
        i++;
    }
    return sum;
}

int main() {
    system("chcp 1251>0");

    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string line;
    string encryptedLine;
    while (getline(inFile, line)) {
        for (int i = 0; i < line.size(); i++) { 
            encryptedLine += encryptChar(line[i]);
        }
        encryptedLine += '\n';
    }

    outFile << encryptedLine;

    outFile.close();
    inFile.clear();
    inFile.seekg(0, ios::beg);

    string content;
    string word;
    while (inFile >> word) {
        content += word + " ";
    }

    int sum = sumOfIntegers(content);
    cout << "Sum of all integers in the text: " << sum << endl;

    inFile.close();

    return 0;
}