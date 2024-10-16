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
    long double xb,yb;
};

bool comp(Point& first, Point& second) {
    long double one = atan2(first.y - first.yb, first.x - first.xb);
    long double sec = atan2(second.y - second.yb, second.x - second.xb);
    if (std::abs(one - sec) < 1e-9) {
        long double del1 = std::sqrt(std::pow(first.y - first.yb,2) + std::pow(first.x - first.xb,2));
        long double del2 =  std::sqrt(std::pow(second.y - second.yb,2) + std::pow(second.x - second.xb,2));
        return del1 < del2;
    }
    return one < sec;
}


void square(std::vector<Point>& figure) {
    long double ans = 0;

    int now;
    int size = figure.size();
    for (int i = 0; i < size; ++i) {
        now = (i + 1) % size;
        ans += figure[i].x * figure[now].y;
        ans -= figure[now].x * figure[i].y;
    }


    std::cout << std::fixed << std::setprecision(5) << std::abs(ans) / 2 << std::endl;

}

void perimetr(std::vector<Point>& figure) {
    long double ans = 0;
    int now;
    int size = figure.size();
    if (size == 2) {
        ans += std::sqrt(std::pow(figure[0].x - figure[1].x, 2) + std::pow(figure[0].y - figure[1].y, 2));
    } else {
        for (int i = 0; i < size; ++i) {
            now = (i + 1) % size;
            ans += std::sqrt(std::pow(figure[i].x - figure[now].x, 2) + std::pow(figure[i].y - figure[now].y, 2));
        }
    }
    std::cout << std::fixed << std::setprecision(5) << ans  << std::endl;
}

bool angle (Point& fir, Point& sec, Point& thir) {
    long double v1x = sec.x - fir.x, v1y = sec.y - fir.y;
    long double v2x = thir.x - sec.x,v2y = thir.y - sec.y;
    return ((v1x * v2y) - (v1y * v2x)) > 0;
}


int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algo/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n,from,to;
    long double minx = inf,miny = inf;
    input >> n;
    std::vector<Point> line;
    std::set<std::string> sets;
    int before;
    for (int i = 0; i < n; ++i) {
        input >> from >> to;
        before = sets.size();
        sets.insert(std::to_string(from) + ' ' + std::to_string(to));
        if (sets.size() != before) {
            if (miny > to) {
                minx = from;
                miny = to;
            }
            if ((miny == to) && (minx < from)) {
                minx = from;
                miny = to;
            }
            line.emplace_back(from, to);
        }
    }

    for (int i = 0; i < line.size(); ++i) {
        line[i].xb = minx;
        line[i].yb = miny;
    }

    std::sort(line.begin(), line.end(), comp);

    if (line.size() == 1) {
        std::cout << std::fixed << std::setprecision(5) << 0 << std::endl << 0 << std::endl;
    } else if (line.size() == 2) {
        std::cout << std::fixed << std::setprecision(5) << std::sqrt(std::pow(line[0].x - line[1].x, 2) + std::pow(line[0].y - line[1].y,2)) << std::endl << 0 << std::endl;
    } else {

        std::vector<Point> ans{line[0], line[1]};
        Point a;
        for (int i = 2; i < line.size(); ++i) {
            ans.push_back(line[i]);
            while ((ans.size() >= 3) && (angle(ans[ans.size() - 1], ans[ans.size() - 2], ans[ans.size() - 3]))) {
                a = ans[ans.size() - 1];
                ans.pop_back();
                ans.pop_back();
                ans.push_back(a);
            }
        }
        perimetr(ans);
        square(ans);
    }
}
