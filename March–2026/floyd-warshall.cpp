#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int INF = 1e9;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0 && i != j) {
                matrix[i][j] = INF;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] != INF && matrix[k][j] != INF) {
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }
    int MAX = matrix[0][0];
    int i_max = 0;
    int j_max = 0;
    int zero_marker = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INF || n == 1) {
                    zero_marker = 1;
                }
            if (matrix[i][j] != INF && matrix[i][j] > MAX) {
                MAX = matrix[i][j];
                i_max = i;
                j_max = j;
            }
        }
    }
    if (zero_marker == 1) {
        cout << 0 << " " << 0 << " " << 0;
    } else {
        cout << i_max + 1 << " " << j_max + 1 << " " << MAX;
    }
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
