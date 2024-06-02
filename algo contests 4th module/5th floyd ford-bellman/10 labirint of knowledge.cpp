#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>

int64_t inf = std::numeric_limits<int64_t>::max();

bool can_finish(std::vector<std::vector<int64_t>>& graph, std::vector<std::vector<bool>>& used,int64_t node, int64_t target);

int main() {
//    std::ifstream input ("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ifstream input ("input.txt");
    if (input.is_open()) {
        int64_t N, M, first, second, third;
        input >> N >> M;
        std::vector<std::vector<bool>> used(N + 1, std::vector<bool>(2, false));
        std::vector<std::vector<int64_t>> graph(N + 1);
        std::vector<std::vector<int64_t>> rebra(M,std::vector<int64_t> {0,0,0});
        std::vector<int64_t> distance(N + 1, -inf);
        distance[1] = 0;
        bool ok;
        for (int i = 0; i < M; ++i) {
            input >> first >> second >> third;
            rebra[i] = {first, second, third};
            graph[first].push_back(second);
        }
        can_finish(graph, used, 1, N);
        for (int k = 0; k <= N; ++k) {
            ok = false;
            for (int i = 0; i < M; i++) {
                if ((distance[rebra[i][0]] != -inf) && (distance[rebra[i][1]] < distance[rebra[i][0]] + rebra[i][2])) {
                    distance[rebra[i][1]] = distance[rebra[i][0]] + rebra[i][2];
                    if (used[rebra[i][1]][1]) {
                        ok = true;
                    }
                }
            }
        }
        if (ok) {
            std::cout << ":)" << std::endl;
        } else if (distance[N] == -inf) {
            std::cout << ":(" << std::endl;
        } else {
            std::cout << distance[N] << std::endl;
        }
    }
}


bool can_finish(std::vector<std::vector<int64_t>>& graph, std::vector<std::vector<bool>>& used,int64_t node, int64_t target) {
    if (used[node][0]) {
        return used[node][1];
    }
    used[node][0] = true;
    if (node == target) {
        return used[node][1] = true;
    }
    used[node][1] = false;
    for (auto i : graph[node]) {
        used[node][1] = (can_finish(graph, used,i, target) | used[node][1]);
    }
    return used[node][1];
}
