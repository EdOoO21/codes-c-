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
#include <set>

struct Point {
    long double x;
    long double y;
};
////////////////////////////////////////////////////////////////////////////////////

int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algo/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    long double x, y;
    input >> x >> y;

    Point ld{};
    Point rd{};
    Point rw{};
    Point lw{};

    input >> ld.x >> ld.y;
    input >> rd.x >> rd.y;
    input >> rw.x >> rw.y;
    input >> lw.x >> lw.y;

    long double a = 1 - ((rd.x - ld.x)/ x);
    long double b = -((lw.x - ld.x)/ y);
    long double c = -((rd.y - ld.y)/ x);
    long double d = 1 - ((lw.y - ld.y)/ y);

    std::cout << std::fixed << std::setprecision(4) << \
    ((ld.x * d) - (b * ld.y)) / ((a * d) - (b * c)) \
    << " " << ((ld.y * a) - (c * ld.x)) / ((a * d) - (b * c));

}
