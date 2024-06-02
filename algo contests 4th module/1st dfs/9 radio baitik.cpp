#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point {
    int x;
    int y;
};

double distance(const Point& a, const Point& b) {
    return pow(a.x - b.x,2) + pow(a.y - b.y,2);
}

void dfs(int& index, std::vector<int64_t>& colors,std::vector<Point>& points, bool& flag, int& prev, int& mid) {
    if (prev == 0) {
        colors[index] = 2;
    } else {
        colors[index] = 3 - colors[prev];
    }
    for (int i = 1; i < points.size(); ++i) {
        if ((i != index) && (distance(points[i], points[index]) < mid)) {
            if (colors[index] == colors[i]) {
                flag = false;
                break;
            } else if (colors[i] == 0) {
                dfs(i,colors,points,flag,index,mid);
            }
        } if (!flag) {
            break;
        }
    }
}



int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        std::vector<int64_t> potential_answer;
        int64_t N;
        int a2, b2;
        input >> N;
        std::vector<Point> points(N + 1);
        for (int i = 1; i < N + 1; ++i) {
            input >> a2 >> b2;
            points[i].x = a2;
            points[i].y = b2;
        }
        int left = 0;
        int right = 1024 * 1024 * (pow(20,4) + 1);
        int mid;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            bool flag = true;
            std::vector<int64_t> colors(N + 1, 0);
            int prev = 0;
            for (int i = 1; i < N + 1; ++i) {
                if (colors[i] == 0) {
                    colors[i] = 1;
                    dfs(i, colors, points,flag,prev,mid);
                    if (!flag) {
                        break;
                    }
                }
            }
            if (!flag) {
                right = mid;
                if (mid < 2) {
                    std::cout << std::endl;
                }
            } else {
                left = mid;
                potential_answer = colors;
            }
        }


        std::cout << std::setprecision(25) << sqrt(left) / 2 << std::endl;
        for (int i = 1; i < N + 1; ++i) {
            std::cout << potential_answer[i] << " ";
        }
        std::cout << std::endl;
    }
}
