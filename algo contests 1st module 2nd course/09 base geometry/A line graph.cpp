#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <cstdint>
#include <map>
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    double x1,x2,y1,y2,a,b,c;
    input >> x1 >> y1 >> x2 >> y2;
    a = y1 - y2;
    b = x2 - x1;
    c = (x1 * (y2 - y1)) - (y1 * (x2 - x1));
    std::cout << a << " " << b << " " << c << std::endl;
}

