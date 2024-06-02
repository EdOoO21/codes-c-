#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

void dfs(int64_t index, std::vector<int8_t>& peaks, std::vector<std::vector<int64_t>>& graph, std::vector<int64_t>& timing) {
    peaks[index] = 1;
    timing.push_back(index);
    for (auto neigh : graph[index]) {
        if (peaks[neigh] == 0)  {
            dfs(neigh, peaks, graph, timing);

        }
    }

}

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N,M,first,second;
        input >> N >> M;
        std::vector<int8_t> peaks(N + 1, 0);
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>({}));
        for (int64_t i = 0; i < M; ++i) {
            input >> first >> second;
            graph[second].push_back(first);
            graph[first].push_back(second);
        }
        //////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////

        std::vector<std::pair<int64_t, std::vector<int64_t>>> answer;
        std::vector<int64_t> timing{};
        for (int64_t index = 1; index < N + 1; index++) {
            if (peaks[index] == 0) {
                timing.clear();
                dfs(index, peaks, graph, timing);
                answer.push_back(std::pair{timing.size(), timing});
            }
        }
        std::cout << answer.size() << std::endl;
        for (auto x : answer) {
            std::cout << x.first << std::endl;
            for (auto b : x.second) {
                std::cout << b << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "kofnwnfowe" << std::endl;
    }
}

