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
        int64_t N,S,T,AMD,first,second,third,fourth;
        input >> N >> S >> T >> AMD;

        std::vector<std::vector<std::vector<int64_t>>> graph(N + 1, std::vector<std::vector<int64_t>>{});
        for (int i = 0; i < AMD; ++i) {
            input >> first >> second >> third >> fourth;
            graph[first].push_back({third,second,fourth});
        }
        std::priority_queue<std::vector<int64_t>, std::vector<std::vector<int64_t>>, std::greater<>> queue;
        std::vector<int64_t> distance(N + 1, inf);
        distance[S] = 0;
        queue.push({0,S});
        while (!queue.empty()) {
            for (auto i : graph[queue.top()[1]]) {
                if ((i[0] != queue.top()[1]) && (distance[queue.top()[1]] <= i[1])) {
                    if (distance[i[0]] > (i[2])) {
                        distance[i[0]] = i[2];
                        queue.push({distance[i[0]],i[0]});
                    }
                }
            }
            queue.pop();
        }

        if (distance[T] == inf) {
            std::cout << -1;
        } else {
            std::cout << distance[T];
        }
    }
}
