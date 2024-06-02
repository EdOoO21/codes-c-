#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

void dfs(int64_t index, std::vector<int8_t>& peaks, std::vector<std::vector<int64_t>>& graph, bool& flag, std::vector<int64_t>& cycle, int64_t& prev, int64_t& osnova) {
    peaks[index] = 1;
    for (auto neigh : graph[index]) {
        if (!flag) {
            if (peaks[neigh] == 0) {
                dfs(neigh, peaks, graph, flag, cycle, index, osnova);
            } else if ((peaks[neigh] == 1) && (prev != neigh)) {
                flag = true;
                osnova = neigh;
                break;
            }
        } else {
            break;
        }
    }
    if (flag && (!cycle.empty()) && (cycle[cycle.size() - 1] != osnova)) {
        cycle.push_back(index);
    } else if (flag && (cycle.empty())) {
        cycle.push_back(index);
    }
    peaks[index] = 2;
}

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N, first;
        input >> N;
        std::vector<int8_t> peaks(N + 1, 0);
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>{});
        std::vector<int64_t> cycle{};
        std::int64_t prev = 0;
        bool flag = false;

        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < N + 1; ++j) {
                input >> first;
                if (first == 1) {
                    graph[i].push_back(j);
                }
            }
        }
        int64_t osnova = 0;
        for (int i = 1; i < N + 1; ++i) {
            if (!flag) {
                if (peaks[i] == 0) {
                    dfs(i, peaks, graph, flag, cycle, prev, osnova);
                }
            } else {
                break;
            }
        }

        if (!cycle.empty()) {
            std::cout << "YES" << std::endl << cycle.size() << std::endl;
            for (auto x : cycle) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }

    }
}
