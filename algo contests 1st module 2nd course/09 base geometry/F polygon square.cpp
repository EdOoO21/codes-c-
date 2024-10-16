#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <cstdint>
#include <map>
#include <iomanip>

struct Point {
    int x;
    int y;
};

int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algo/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    double ans = 0,x,y;
    input >> n;
    std::vector<Point> figure(n,Point());

    for (int i = 0; i < n; ++i) {
        input >> x >> y;
        figure[i].x = x;
        figure[i].y = y;
    }

    int now;
    for (int i = 0; i < n; ++i) {
        now = (i + 1) % n;
        ans += figure[i].x * figure[now].y;
        ans -= figure[now].x * figure[i].y;
    }


    std::cout << std::fixed << std::setprecision(5) << std::abs(ans) / 2 << std::endl;

}
