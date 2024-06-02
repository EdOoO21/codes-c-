#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <queue>

int64_t inf = std::numeric_limits<int64_t>::max();

void dijkstra(std::priority_queue<std::vector<int64_t>, std::vector<std::vector<int64_t>>, std::greater<>>& queue,std::vector<int64_t>& distance,std::vector<std::vector<std::vector<int64_t>>>& graph){
    while (!queue.empty()) {
        for (auto i : graph[queue.top()[1]]) {
            if (i[0] != queue.top()[1]) {
                if ((distance[i[0]] > (i[2] - (distance[queue.top()[1]] % i[1]) + i[1] + distance[queue.top()[1]])) && ((distance[queue.top()[1]] % i[1]) != 0)) {
                    distance[i[0]] = (i[2] - (distance[queue.top()[1]] % i[1]) + i[1] + distance[queue.top()[1]]);
                    queue.push({distance[i[0]],i[0]});
                } else if ((distance[i[0]] > (i[2] + distance[queue.top()[1]])) && ((distance[queue.top()[1]] % i[1]) == 0)) {
                    distance[i[0]] = (i[2] + distance[queue.top()[1]]);
                    queue.push({distance[i[0]],i[0]});
                }
            }
        }
        queue.pop();
    }
}

int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    if (input.is_open()) {
        int64_t N,M,AMP,first,second,third,fourth;
        input >> N >> M;

        std::vector<std::vector<std::vector<int64_t>>> graph(N + 1, std::vector<std::vector<int64_t>>{});
        for (int i = 0; i < M; ++i) {
            input >> first >> second >> third >> fourth;
            graph[first].push_back({second,third,fourth});
        }
        input >> AMP;
        std::vector<int64_t> peaks(AMP,0);
        for (int i = 0; i < AMP; ++i) {
            input >> peaks[i];
        }

        std::priority_queue<std::vector<int64_t>, std::vector<std::vector<int64_t>>, std::greater<>> queue;
        std::vector<int64_t> distance(N + 1, inf);
        bool not_ok = false;
        int64_t prev = 0;
        for (int i = 0; i < AMP - 1; ++i) {
            distance[peaks[i]] = prev;
            queue.push({prev, peaks[i]});
            dijkstra(queue,distance,graph);
            if (distance[peaks[i + 1]] == inf) {
                not_ok = true;
                break;
            } else {
                prev = distance[peaks[i + 1]];
                distance = std::vector<int64_t>(N + 1, inf);
            }
        }
        if (not_ok) {
            std::cout << -1;
        } else {
            std::cout << prev;
        }
    }
}
