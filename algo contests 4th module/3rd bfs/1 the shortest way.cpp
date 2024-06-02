#include <iostream>

#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N, start, end;
        input >> N;
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>(N + 1, 0));
        std::vector<std::vector<int64_t>> distance(N + 1, std::vector<int64_t>{});

        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < N + 1; ++j) {
                input >> graph[i][j];
            }
        }
        input >> start >> end;
        distance[0].push_back(start);
        std::vector<int64_t> answer(N + 1,  ((N*(N-1))/2) + 1);
        answer[start] = 0;
        for (int j = 0; j < N + 1; j++) {
            for (auto y : distance[j]) {
                for (int i = 1; i < N + 1; ++i) {
                    if ((graph[y][i] == 1) && (y != i) && (answer[i] > j + 1)) {
                        answer[i] = j + 1;
                        distance[j + 1].push_back(i);
                    }
                }
            }
        }
        if (answer[end] == ((N*(N-1))/2) + 1) {
            std::cout << -1;
        } else {
            std::cout << answer[end];
        }

    }
}