#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <queue>

int64_t inf = std::numeric_limits<int64_t>::max();



int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    if (input.is_open()) {
        int64_t N;
        input >> N;
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>(N + 1, 0));
        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < N + 1; ++j) {
                input >> graph[i][j];
            }
        }

        for (int k = 1; k < N + 1; ++k) {
            for (int from = 1; from < N + 1; ++from) {
                for (int to = 1; to < N + 1; ++to) {
                    graph[from][to] = ((graph[from][k] && graph[k][to]) || graph[from][to]);
                }
            }
        }
        bool ok = true;
        for (int i = 1; i < N + 1; ++i) {
            if (graph[i][i] == 1) {
                std::cout << 1;
                ok = false;
                break;
            }
        }
        if (ok) {
            std::cout << 0;
        }

    }
}
