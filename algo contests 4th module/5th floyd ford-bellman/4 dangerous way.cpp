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
        int64_t N,M,first,second,S,F;
        double third;
        input >> N >> M >> S >> F;
        std::vector<std::vector<double>> graph(N + 1, std::vector<double>(N + 1 , 1));
        for (int i = 1; i < M + 1; ++i) {
            input >> first >> second >> third;
            graph[first][second] = third / 100;
            graph[second][first] = third / 100;
        }

        for (int k = 1; k < N + 1; ++k) {
            for (int from = 1; from < N + 1; ++from) {
                for (int to = 1; to < N + 1; ++to) {
                    graph[from][to] = ((graph[from][k] + graph[k][to]) - (graph[from][k] * graph[k][to])) < graph[from][to] ? ((graph[from][k] + graph[k][to]) - (graph[from][k] * graph[k][to])) : graph[from][to];
                }
            }
        }
        std::cout << graph[S][F];
    }
}
