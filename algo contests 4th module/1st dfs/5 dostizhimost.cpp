#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>


void dfs(int64_t index, std::vector<int8_t>& peaks, std::vector<std::vector<int64_t>>& graph) {
    peaks[index] = 1;
    for (auto neigh : graph[index]) {
        if (peaks[neigh] == 0) {
            dfs(neigh,peaks,graph);
        }
    }
}

bool Used(int64_t& a, std::vector<int64_t>& array) {
    for (auto x : array) {
        if (x == a) {
            return false;
        }
    }
    return true;
}


int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N, M, first, second;
        input >> N >> M;
        std::vector<int8_t> peaks(N + 1, 0);
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>{});
        for (int i = 0; i < M + 1; ++i) {
            input >> first >> second;
            if ((first != second) && (Used(second,graph[first]))) {
                graph[second].push_back(first);
            }
        }
        peaks[1] = 1;
        dfs(1,peaks,graph);
        for (int i = 1; i < N + 1; ++i) {
            if (peaks[i] == 1) {
                std::cout << i << " ";
            }
        }
    }
}
