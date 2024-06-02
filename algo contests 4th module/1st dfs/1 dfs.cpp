#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

void dfs(size_t index, std::vector<bool>& peaks, std::vector<std::vector<int64_t>>& graph) {
    peaks[index] = true;
    for (auto neigh : graph[index]) {
        if (!peaks[neigh]) {
            dfs(neigh, peaks, graph);

        }
    }

}

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N,M,first,second;
        input >> N >> M;
        std::vector<bool> peaks(N + 1);
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>({}));
        for (int64_t i = 0; i < M; ++i) {
            input >> first >> second;
            graph[second].push_back(first);
            graph[first].push_back(second);
        }
        dfs(1, peaks,graph);
        M = 0;
        for (auto x : peaks) {
            if (x) {
                M++;
            }
        }
        std::cout << M << std::endl;
        for (int i = 0; i < N + 1; ++i) {
            if (peaks[i]) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "kofnwnfowe" << std::endl;
    }
}

