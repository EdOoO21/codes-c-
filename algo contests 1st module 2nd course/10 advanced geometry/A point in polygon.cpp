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

long double inf = std::numeric_limits<long double>::max();
struct Point {
    long double x;
    long double y;
};

const double EPS = 1e-9;
////////////////////////////////////////////////////////////////////////////////////
bool in(long double x1,long double y1,long double x2,long double y2,long double x_p, long double y_p) {
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

int checker(long double x1, long double y1, long double x2, long double y2 , long double x3, long double y3, long double x4, long double y4) {
    long double a1 = y1 - y2;
    long double b1 = x2 - x1;
    long double c1 = (x1 * (y2 - y1)) - (y1 * (x2 - x1));

    long double a2 = y3 - y4;
    long double b2 = x4 - x3;
    long double c2 = (x3 * (y4 - y3)) - (y3 * (x4 - x3));

    if (((a1*b2) - (a2*b1)) == 0) {
        if (((c1*b2) - (c2*b1)) != 0) {
            return false;
        } else {
            if ((std::min(x3,x4) <= x1) && (x1<= std::max(x3,x4))) {
                return true;
            } else {
                return false;
            }
        }
    } else {
        long double x_p = (-(c1*b2) + (c2*b1)) / ((a1*b2) - (a2*b1));
        long double y_p = (-(a1*c2) + (a2*c1)) / ((a1*b2) - (a2*b1));
        if ((in(x1,y1,x2,y2,x_p,y_p)) && (in(x3,y3,x4,y4,x_p,y_p))) {
            return true;
        } else {
            return false;
        }

    }
}

bool on_way(long double x1, long double y1, long double x2, long double y2, long double x_p, long double y_p) {
    long double a = y1 - y2;
    long double b = x2 - x1;
    long double c = (x1 * (y2 - y1)) - (y1 * (x2 - x1));


    if ((x_p*a) + (y_p*b) + c == 0) {
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
    } else {
        return false;
    }
}

int main() {
    std::ifstream input("point.in");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algo/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    long double x,y;
    input >> n >> x >> y;
    auto main = Point(x,y);
    std::vector<Point> line(n);
    for (int i = 0; i < n; ++i) {
        input >> line[i].x >> line[i].y;
    }
    int now;
    int ans = 0;
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        now = (i + 1) % n;
        if (on_way(line[i].x,line[i].y, line[now].x, line[now].y, main.x, main.y) || ((main.x == line[i].x) && (main.y == line[i].y))) {
            ok = true;
            break;
        }
        if (checker(line[i].x,line[i].y, line[now].x, line[now].y, main.x, main.y, 100000 , main.y - 1)) {
            ++ans;
        }
    }
    if ((ans % 2 == 1) || ok) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

}
