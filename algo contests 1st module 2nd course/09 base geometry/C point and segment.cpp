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
    double x1,x2,y1,y2,a,b,c,x_p,y_p;
    input >> x_p >> y_p >> x1 >> y1 >> x2 >> y2;
    a = y1 - y2;
    b = x2 - x1;
    c = (x1 * (y2 - y1)) - (y1 * (x2 - x1));


    if ((x_p*a) + (y_p*b) + c == 0) {
        if (x2 >= x1) {
            if ((y2 >= y1) && (x_p >= x1) && (y_p >= y1) && (x_p <= x2) && (y_p <= y2)) {
                std::cout << "YES";
            } else if ((y2 <= y1) && (x_p >= x1) && (y_p <= y1) && (x_p <= x2) && (y_p >= y2)) {
                std::cout << "YES";
            } else {
                std::cout << "NO";
            }
        } else {
            if ((y2 >= y1) && (x_p <= x1) && (y_p >= y1) && (x_p >= x2) && (y_p <= y2)) {
                std::cout << "YES";
            } else if ((y2 <= y1) && (x_p <= x1) && (y_p <= y1) && (x_p >= x2) && (y_p >= y2)) {
                std::cout << "YES";
            } else {
                std::cout << "NO";
            }
        }
    } else {
        std::cout << "NO";
    }
}

