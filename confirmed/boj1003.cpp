#include <iostream>
using namespace std;
int main(){
    int trial;
    std::cin>>trial;
    int map[42][2];
    int mademap = 1;

    map[0][0] = 1; map[0][1] = 0;
    map[1][0] = 0; map[1][1] = 1;

    for(int a = 2; a < 42; a++) {
        map[a][0] = map[a-1][0] + map[a-2][0];
        map[a][1] = map[a-1][1] + map[a-2][1];
    }

    while(trial>0) {
        int x; std::cin>>x;
        std::cout<<map[x][0]<<" "<<map[x][1]<<endl;
        trial--;
    }
    return 0;
}