/*
 * Keypoint: Only count circles with exclusively covered planetary systems.
 * Do not count commonly covered planetary systems.
 * Lesson: I forgot "endl."
*/

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
bool inside(int x, int y, int px, int py, int r) {
    int dx = abs(px-x);
    int dy = abs(py-y);
    return (sqrt(dx*dx+dy*dy) < r);
}
int main(){
    int trial;
    int x1, y1, x2, y2;
    int planets;
    int loop;
    int px, py, r;
    int mustCross;
    std::cin>>trial;
    std::vector<int> answers(trial);
    while(trial>0) {
        mustCross = 0;
        std::cin>>x1>>y1>>x2>>y2;
        std::cin>>planets;
        for(loop = 0; loop < planets; loop++) {
            std::cin>>px>>py>>r;
            if(inside(x1, y1, px, py, r) ^ inside(x2, y2, px, py, r)) {
                mustCross++;
            }
        }
        answers[trial-1] = mustCross;
        trial--;
    }
    for(int c = answers.size()-1; c >= 0; c--) {
        std::cout<<answers[c]<<endl;
    }
    return 0;
}