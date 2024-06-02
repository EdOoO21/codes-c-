#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <queue>

#define DEF long long



void dijkstra(std::priority_queue<std::vector<DEF>, std::vector<std::vector<DEF>>, std::greater<>>& queue,std::vector<DEF>& distance,std::vector<std::vector<std::vector<DEF>>>& graph,DEF m){
    while (!queue.empty()) {
        for (auto i : graph[queue.top()[1]]) {
            if (m <= i[2]) {
                if (distance[i[0]] > distance[queue.top()[1]] + i[1]) {
                    distance[i[0]] = distance[queue.top()[1]] + i[1];
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
        DEF N,M,first,second,third,fourth;
    	int64_t inf = 1000000000000000000;
        input >> N >> M;
        std::vector<std::vector<std::vector<DEF>>> graph(N + 1, std::vector<std::vector<DEF>>{});
        for (int i = 0; i < M; ++i) {
            input >> first >> second >> third >> fourth;
            graph[first].push_back({second,third,fourth - 3000000});
        }
        std::priority_queue<std::vector<DEF>, std::vector<std::vector<DEF>>, std::greater<>> queue;
        std::vector<DEF> distance(N + 1, inf);
        DEF l,r,ans;
        l = 0;
        r = 10000000001;
        for (int i = 0; i < 100; ++i) {
            DEF m = (l + r) / 2;
            distance = std::vector<DEF>(N + 1,inf);
            distance[1] = 0;
            queue.push({0,1});
            dijkstra(queue,distance,graph,m*100);
            if (distance[N] > 1440) {
                r = m;
            } else {
                l = m;
                ans = m;
            }
        }

        if (ans >= 10000000) {
            std::cout << 10000000;
        } else {
            std::cout << ans;
        }


    }
}
