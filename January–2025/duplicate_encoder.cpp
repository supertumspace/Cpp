#include <string>
using namespace std;
string duplicate_encoder(const string& word){
  int length = word.length();
  char *arr = new char[length];
  for (int i = 0; i < length; ++i) {
    arr[i] = word[i];
    }
  string answer = "";
  for (int i = 0; i <length; ++i) {
    bool does_already_appear = false;
    for (int j = 0; j < length; ++j) {
      if  ((arr[i] == arr[j] && i != j) || ((arr[i] - arr[j] == 32) && (arr[i] >= 65 && arr[i] <= 122) && (arr[j] >= 65 && arr[j] <= 122)) || ((arr[j] - arr[i] == 32) && (arr[i] >=65

&& arr[i] <= 122) && (arr[j] >= 65 && arr[j] <= 122))) {
        does_already_appear = true;
        break;
        }
      }
    if (does_already_appear) {
      answer += ")";
      } else {
      answer += "(";
      }
    }
  delete[] arr;
  return answer;
}
