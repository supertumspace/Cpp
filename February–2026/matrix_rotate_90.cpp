#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
            for (int j = 0; j < n; j++) {
                ss >> matrix[i][j];
            }
        }
    int **matrix2 = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix2[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        int copy_n = n;
        for (int j = 0; j < n; j++) {
            --copy_n;
            matrix2[i][j] = matrix[copy_n][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
        delete[] matrix2[i];
    }
    delete[] matrix;
    delete[] matrix2;
    return 0;
}
