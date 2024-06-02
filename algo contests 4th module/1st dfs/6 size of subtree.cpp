#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>


void dfs(int64_t index, std::vector<int64_t>& peaks, std::vector<std::vector<int64_t>>& graph) {
    peaks[index] = 1;
    int64_t sum = 0;
    for (auto neigh : graph[index]) {
        if (peaks[neigh] == 0) {
            dfs(neigh,peaks,graph);
            sum += peaks[neigh];
        }
    }
    peaks[index] = sum + 1;
}

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N, first, second;
        input >> N;
        std::vector<int64_t> peaks(N + 1, 0);
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>{});
        for (int i = 0; i < N; ++i) {
            input >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }
        peaks[1] = N;
        dfs(1, peaks, graph);

        for (auto x : peaks) {
            if (x != 0) {
                std::cout << x << " ";
            }
        }
    }
}