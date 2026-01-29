#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    string total_s;
    string s;
    while (cin >> s && s != "0") {
        total_s += s + " ";
    }
    int cap = 1;
    int size = 0;
    int *arr = new int[cap];
    int n;
    stringstream ss(total_s);
    while (ss >> n) {
        if (size == cap) {
            cap *= 2;
            int *new_arr = new int[cap];
            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
            }
            delete [] arr;
            arr = new_arr;
        }
        arr[size++] = n;
    }
    int *start = arr;
    int *end = arr + (size - 1);
    for (int i = 0; i < size; i++) {
        if (start == end) {
            cout << *start << " ";
        } else {
            cout << *start + *end << " ";
        }
        ++start;
        --end;
    }
    delete [] arr;
    return 0;
}
