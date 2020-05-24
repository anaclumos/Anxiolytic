#include <iostream>
using namespace std;

int *reverse(int start, int last, int all[]) {
  start -= 1;
  last -= 1;
  for (int t = 0; t < (last - start + 1) / 2; t++) {
    int temp = all[start + t];
    all[start + t] = all[last - t];
    all[last - t] = temp;
  }
  return all;
}

int main() {
  int deck[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  for (int t = 0; t < 10; t++) {
    int s, l;
    cin >> s >> l;
    reverse(s, l, deck);
  }

  for (int t = 0; t < 20; t++) cout << deck[t] << " ";
  cout << endl;
}