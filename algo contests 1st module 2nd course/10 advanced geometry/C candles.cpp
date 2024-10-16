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

int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algo/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int64_t n, m, r,a,b,c;
    input >> n >> m >> r;
    std::vector<Point> line(n);
    for (int i = 0; i < n; ++i) {
        input >> line[i].x >> line[i].y;
    }
    std::vector<std::string> svechki(n, "");
    for (int i = 0; i < m; ++i) {
        input >> a >> b >> c;
        for (int j = 0; j < n; ++j) {
            svechki[j] += std::to_string((1 == (0 < ((a*line[j].x) + (b*line[j].y) + c))));
        }
    }
    std::set<std::string> check(svechki.begin(),svechki.end());
    if (check.size() != svechki.size()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
