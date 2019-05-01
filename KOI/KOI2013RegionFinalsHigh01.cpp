#include <iostream>
#include <queue>

using namespace std;
int garden[1000][1000];

typedef pair<int, int> cubicle;

// 인접한 4개의 토마토를 얻기 위해 사용한다.
const int moveGaro[] = { -1, 1, 0, 0 };
const int moveSero[] = { 0, 0, 1, -1 };

// 마지막에 unripetomato가 0이 아니라면
// 모든 토마토가 익는 것이 불가능한 경우.
int unripetomato = 0;

// 시간의 흐름을 기록하는 int daypast.
int daypast = 1;

int main() {
    int garo, sero;
    cin >> garo >> sero;

    // 방금 막 익어버린 토마토들의 위치를 cubicle로 저장하는 Queue.
    queue<cubicle> q;

    // 값 입력하기
    for(int j = 0; j < sero; j++) {
        for(int i = 0; i < garo; i++) {
            cin >> garden[i][j];

            // 남은 토마토의 개수를 센다.
            if(garden[i][j] == 0)
                unripetomato++;

            // 익은 토마토의 위치를 Queue에 넣는다.
            if(garden[i][j] == 1)
                q.push(cubicle(i, j));
        }
    }

    // Queue가 비어있지 않다면 계속 실행한다.
    while (!q.empty()) {

        // 가장 앞의 토마토를 current라는 이름의 pair<int, int>로 가져온다.
        cubicle current = q.front();

        // 현재 익은 토마토의 위치 i, j 값을 임시로 저장한다.
        int ci = current.first;
        int cj = current.second;

        for(int x = 0; x < 4; x++) {

            // 상하좌우의 인접한 토마토들
            int ni = ci + moveGaro[x];
            int nj = cj + moveSero[x];

            // 만약 인접해 있던 토마토가 정원 밖으로 넘어간다면 무시
            if(ni < 0 || ni >= garo || nj < 0 || nj >= sero)
                continue;

            // 그렇지 않은데다가 안 익은 토마토라면 익은 토마토로 변경.
            // 이 때 토마토의 값 안에는 현재 날짜를 넣어둠.
            else if (garden[ni][nj] == 0) {
                garden[ni][nj] = garden[ci][cj] + 1;

                // 안 익은 토마토 개수 1 줄이기
                unripetomato--;

                // 만약 이 날짜가 daypast에서 하루 지난 날짜라면 값 대체
                if (daypast < garden[ni][nj])
                    daypast = garden[ni][nj];

                // 마지막으로 익은 토마토를 Queue에 등록하기
                q.push(cubicle(ni, nj));
            }
        }

        // 이미 주변을 익힌 토마토는 고려하지 않아도 됨.
        q.pop();
    }

    // 하루가 지났을 때 새로 익은 토마토의 값은 2였다.
    // 때문에 daypast - 1이 *지난 날짜 수*인 것이다.
    if (unripetomato == 0)
        cout << daypast - 1 << endl;
    else
        cout << -1 << endl;

    return 0;
}