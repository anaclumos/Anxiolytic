#include <iostream>
#include <vector>
using namespace std;

int main() {
  int totalBallNumber;
  cin >> totalBallNumber;

  vector<pair<int, int>> arr[2001];
  // a[사이즈] -> 각 아이템들은 [컬러][번호]를 가진다

  for (int ballID = 0; ballID < totalBallNumber; ballID++) {
    int color, size;
    cin >> color >> size;
    arr[size].push_back(pair<int, int>(color, ballID));
  }

  int smallersSum = 0;
  int answer[totalBallNumber];
  int sumPerColor[totalBallNumber];

  for (int ballID = 0; ballID < totalBallNumber; ballID++) {
    answer[ballID] = 0;
    sumPerColor[ballID] = 0;
  }

  for (int size = 1; size <= 2000; size++) {
    vector<pair<int, int>> v =
        arr[size];  // 사이즈가 size인 모든 공들의 {색, ID}.
    for (int t = 0; t < (int)v.size(); t++) {
      answer[v[t].second] = smallersSum - sumPerColor[v[t].first];
    }
    for (int t = 0; t < (int)v.size(); t++) {
      sumPerColor[v[t].first] += size;
      smallersSum += size;
    }
  }

  for (int ballID = 0; ballID < totalBallNumber; ballID++) {
    cout << answer[ballID] << endl;
  }
  return 0;
}