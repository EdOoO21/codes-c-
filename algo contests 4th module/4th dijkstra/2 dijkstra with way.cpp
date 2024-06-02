#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <unordered_map>

int64_t inf = std::numeric_limits<int64_t>::max();

int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    if (input.is_open()) {
        int64_t N,S,F;
        input >> N >> S >> F;
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>(N + 1,0));
        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < N + 1; ++j) {
                input >> graph[i][j];
            }
        }
        std::vector<std::vector<int64_t>> distance(N + 1, std::vector<int64_t>{0,inf,0});
        distance[S][1] = 0;
        distance[S][2] = -1;
        int64_t minv;
        int peaks = 0;
        while (true) {
            minv = inf;
            for (int i = 1; i < N + 1; ++i) {
                if (distance[i][0] == 0) {
                    if (minv == inf) {
                        minv = i;
                    } else {
                        minv = distance[minv][1] > distance[i][1] ? i : minv;
                    }
                }
            }
            if (minv == inf) {
                break;
            } else {
                peaks += 1;
                if (peaks == N + 1) {
                    break;
                }
            }
            distance[minv][0] = 1;

            for (int i = 1; i < N + 1; ++i) {
                if ((i != minv) && (graph[minv][i] != -1)) {
                    if (distance[i][1] > distance[minv][1] + graph[minv][i]) {
                        distance[i][1] = distance[minv][1] + graph[minv][i];
                        distance[i][2] = minv;
                    }
                }
            }
        }
        if (distance[F][1] != inf) {
            int i = F;
            std::vector<int64_t> answer{};
            while (i != -1) {
                answer.push_back(i);
                i = distance[i][2];
            }
            for (int j = answer.size() - 1; j >= 0; --j) {
                std::cout << answer[j] << " ";
            }
        } else {
            std::cout << -1;
        }
    }
}
