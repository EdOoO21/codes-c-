#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

int64_t max_sum = 0;
int64_t sum_index = 0;
void dfs(int64_t index, std::vector<bool>& peaks, std::vector<std::vector<int64_t>>& graph, int64_t sum) {
    peaks[index] = true;
    if (max_sum < sum) {
        max_sum = sum;
        sum_index = index;
    }
    for (auto neigh : graph[index]) {
        if (!peaks[neigh]) {
            dfs(neigh,peaks,graph, sum + 1);
        }
    }
    max_sum = max_sum > sum ? max_sum : sum;
}

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N, first, second;
        input >> N;
        std::vector<bool> peaks(N + 1, false);
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>{});
        for (int i = 0; i < N; ++i) {
            input >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }

        int64_t sum = 0;
        for (int i = 1; i < N + 1; ++i) {
            if (!peaks[i]) {
                dfs(i,peaks,graph, sum);
            }
        }
        peaks = std::vector<bool>(N + 1, false);
        sum = 0;
        dfs(sum_index,peaks, graph, sum);
        std::cout << max_sum << std::endl;
    }
}