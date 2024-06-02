#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

void dfs(int64_t index, std::vector<int8_t>& peaks, std::vector<std::vector<int64_t>>& graph, int64_t prev) {
    if (prev == 1) {
        peaks[index] = -1;
    } else {
        peaks[index] = 1;
    }
    for (auto neigh : graph[index]) {
        if (peaks[neigh] == 0)  {
            dfs(neigh, peaks, graph, peaks[index]);
        } else if (peaks[neigh] != -1 * peaks[index]) {
            peaks[0] = 1;
        } else {
            continue;
        }
    }

}

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N, M, first, second;
        input >> N >> M;
        std::vector<int8_t> peaks(N + 1, 0);
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>({}));
        for (int64_t i = 0; i < M; ++i) {
            input >> first >> second;
            graph[second].push_back(first);
            graph[first].push_back(second);
        }
        for (int64_t i = 1; i < N + 1; ++i) {
            if (peaks[i] == 0) {
                dfs(i, peaks, graph, 0);
                if (peaks[0] == 1) {
                    std::cout << "NO" << std::endl;
                    break;
                }
            }
        }
        if (peaks[0] == 0) {
            std::cout << "YES" << std::endl;
        }
    }
}
