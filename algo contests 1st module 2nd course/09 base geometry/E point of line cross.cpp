#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <cstdint>
#include <map>
const double EPS = 1e-9;
////////////////////////////////////////////////////////////////////////////////////
bool in(double x1,double y1,double x2,double y2,double x_p, double y_p) {
    if (x2 >= x1) {
        if ((y2 >= y1) && (x_p >= x1) && (y_p >= y1) && (x_p <= x2) && (y_p <= y2)) {
            return true;
        } else if ((y2 <= y1) && (x_p >= x1) && (y_p <= y1) && (x_p <= x2) && (y_p >= y2)) {
            return true;
        } else {
            return false;
        }
    } else {
        if ((y2 >= y1) && (x_p <= x1) && (y_p >= y1) && (x_p >= x2) && (y_p <= y2)) {
            return true;
        } else if ((y2 <= y1) && (x_p <= x1) && (y_p <= y1) && (x_p >= x2) && (y_p >= y2)) {
            return true;
        } else {
            return false;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////

int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    double x1,x2,y1,y2,x3,y3,x4,y4,a1,b1,c1,a2,b2,c2;
    input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    a1 = y1 - y2;
    b1 = x2 - x1;
    c1 = (x1 * (y2 - y1)) - (y1 * (x2 - x1));

    a2 = y3 - y4;
    b2 = x4 - x3;
    c2 = (x3 * (y4 - y3)) - (y3 * (x4 - x3));

    if (((a1*b2) - (a2*b1)) == 0) {
        if (((c1*b2) - (c2*b1)) != 0) {
            std::cout << 0;
        } else {
            std::cout << 2;
        }
    } else {
        double x_p = (-(c1*b2) + (c2*b1)) / ((a1*b2) - (a2*b1));
        double y_p = (-(a1*c2) + (a2*c1)) / ((a1*b2) - (a2*b1));
        std::cout << 1 << " " <<  x_p << " " << y_p;

    }

//    if ((x_p*a) + (y_p*b) + c < EPS) {
//        in(x1,y1,x2,y2,x_p,y_p);
//    } else {
//        std::cout << "NO";
//    }
}

