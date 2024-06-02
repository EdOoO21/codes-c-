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
        int64_t N,E,first,second,third,amg, st;
        input >> N >> E >> amg >> st;
        std::vector<int64_t> goroda(amg, 0);
        for (int i = 0; i < amg; ++i) {
            input >> goroda[i];
        }
        std::vector<std::vector<std::vector<int64_t>>> graph(N + 1, std::vector<std::vector<int64_t>>{});
        for (int i = 0; i < E; ++i) {
            input >> first >> second >> third;
            graph[first].push_back({second,third});
            graph[second].push_back({first,third});
        }
        std::priority_queue<std::vector<int64_t>, std::vector<std::vector<int64_t>>, std::greater<>> queue;
        std::vector<std::vector<int64_t>> distance(N + 1, std::vector<int64_t>{0,inf,0});
        distance[st][1] = 0;
        distance[st][2] = -1;
        queue.push({0,st});
        while (!queue.empty()) {

            for (auto i : graph[queue.top()[1]]) {
                if (i[0] != queue.top()[1]) {
                    if (distance[i[0]][1] > (distance[queue.top()[1]][1] + i[1])) {
                        distance[i[0]][1] = distance[queue.top()[1]][1] + i[1];
                        distance[i[0]][2] = queue.top()[1];
                        queue.push({distance[i[0]][1],i[0]});
                    }
                }
            }
            queue.pop();
        }

        for (auto x : goroda) {
            queue.push({distance[x][1],x});
        }
        for (int x = 0; x < amg; x++) {
            std::cout << queue.top()[1] << " " << queue.top()[0] << std::endl;
            queue.pop();
        }
    }
}
