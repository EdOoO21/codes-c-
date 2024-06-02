#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>

int64_t inf = std::numeric_limits<int64_t>::max();

int64_t wt(int64_t a,int64_t b) {
    return (((179*a) + (719*b)) % 1000) - 500;
}

int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    if (input.is_open()) {
        int64_t N;
        input >> N;
        std::vector<int64_t> distance(13001,inf);
        distance[1] = 0;
        bool not_ok;
        for (int i = 1; i < 13000; ++i) {
            not_ok = true;
            for (int j = i + 1; ((13000 + 1 > j)  && (j > i)); ++j) {
                if (wt(i,j) + distance[i] < distance[j]) {
                    distance[j] = wt(i,j) + distance[i];
                    not_ok = false;
                }
            }
            if (not_ok) {
                break;
            }
        }
        std::cout << distance[N];
    }
}
