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
        int64_t N,E,first,second,third,S,F;
        input >> N >> E;
        std::vector<std::vector<std::vector<int64_t>>> graph(N + 1, std::vector<std::vector<int64_t>>{});
        for (int i = 0; i < E; ++i) {
            input >> first >> second >> third;
            graph[first].push_back({second,third});
            graph[second].push_back({first,third});
        }
        std::priority_queue<std::vector<int64_t>, std::vector<std::vector<int64_t>>, std::greater<>> queue;
        std::vector<int64_t> distance(N + 1, inf);
        std::vector<bool> used(N + 1, false);
        distance[1] = 0;
        queue.push({0,1});
        while (!queue.empty()) {
            used[queue.top()[1]] = true;
            for (auto i : graph[queue.top()[1]]) {
                    if ((!used[i[0]]) && (distance[i[0]] > (i[1]))) {
                        distance[i[0]] = i[1];
                        queue.push({distance[i[0]],i[0]});

                    }

            }
            queue.pop();
        }
        int64_t ans = 0;
        for (int i = 1; i < N + 1; ++i) {
            ans += distance[i];
        }
        std::cout << ans;
    }
}
