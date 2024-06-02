#include <iostream>

#include <fstream>
#include <vector>

#include <cstdint>



void dfs(int64_t& index, std::vector<int64_t>& peaks,std::vector< std::vector<int64_t>>& graph, std::vector<int64_t>& answer) {
    peaks[index] = 1;

    for (auto neigh : graph[index]) {
        if (peaks[neigh] == 0) {
            dfs(neigh,peaks,graph, answer);
        } else if (peaks[neigh] == 1) {
            peaks[0] = 15;
            break;
        }
    }
    answer.push_back(index);
    peaks[index] = 2;
}

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N,M,first,second;
        input >> N >> M;
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>{});
        std::vector<int64_t> peaks(N + 1, 0);


        for (int64_t i = 0; i < M; ++i) {
            input >> first >> second;
            graph[first].push_back(second);

        }

        std::vector<int64_t> answer{};
        for (int64_t i = 1; i < N + 1; ++i) {
            if (peaks[i] == 0) {
                dfs(i, peaks, graph,answer);
            }
        }

        if (peaks[0] == 15) {
            std::cout << -1 << std::endl;
        } else {
            for (int64_t i = N - 1; i >= 0; --i) {
                std::cout << answer[i] << " ";
            }
        }

    }
}