#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int **matrix = new int *[a];
    for (int i = 0; i < a; i++) {
        matrix[i] = new int[b];
    }
    int num = 1;
    for (int j = 0; j < b; j++) {
        for (int i = 0, copy_j = j; i <= j && i < a; i++, num++, copy_j--) {
            matrix[i][copy_j] = num;
        }
    }
    for (int i = 1, j = b - 1; i < a; i++) {
        for (int copy_i = i, copy_j = j; copy_i < a && copy_j >= 0; copy_i++, copy_j--, num++) {
            matrix[copy_i][copy_j] = num;
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < a; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
