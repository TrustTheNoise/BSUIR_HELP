#include <iostream>
#include <vector>

// 24. Вычислить определитель матрицы.

using namespace std;

void printMatrix(const vector<vector<double>>&);
double determinant(const vector<vector<double>>&);
int check();

int main() {
    int n;
    cout << "Input size of matrix (NxN): \n>";
    n = check();

    vector<vector<double>> matrix(n, vector<double>(n));

    cout << "Input elements of matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ">";
            cin >> matrix[i][j];
        }
    }

    cout << "Your matrix:\n";
    printMatrix(matrix);

    double det = determinant(matrix);
    cout << "Determinant of matrix: " << det << endl;

    return 0;
}

int check() {
    int a = 0;
    while (true) {
        while ((std::cin >> a, getchar()) != '\n') {
            std::cout << "Incorrect input!\n>";
            rewind(stdin);
        }
        if (a <= 0) {
            std::cout << "Incorrect size of array!\n>";
        }
        else {
            break;
        }
    }
    return a;
}

void printMatrix(const vector<vector<double>>& matrix) {
    int size_of_matrix = matrix.size();
    for (int i = 0; i < size_of_matrix; i++) {
        for (int j = 0; j < size_of_matrix; j++) {
            cout << matrix[i][j] << " | ";
        }
        cout << endl;
    }
}

double determinant(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    if (n == 1) {
        return matrix[0][0];
    }

    double det = 0;
    vector<vector<double>> submatrix(n - 1, vector<double>(n - 1));

    for (int i = 0; i < n; i++) {
        int subi = 0;
        for (int j = 1; j < n; j++) {
            int subj = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                submatrix[subi][subj] = matrix[j][k];
                subj++;
            }
            subi++;
        }
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(submatrix);
    }

    return det;
}