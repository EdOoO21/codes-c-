#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>


int64_t inf = std::numeric_limits<int64_t>::max();


int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    if (input.is_open()) {
        int64_t N,S,F,K,first,second,third,fourth;
        input >> N >> S >> F >> K;
        std::vector<std::vector<int64_t>> graph(K + 1,std::vector<int64_t>{});
        for (int i = 1; i <= K; ++i) {
            input >> first >> second >> third >> fourth;
            graph[i] = {first,third,second,fourth};
        }

        std::vector<int64_t> distance(N + 1,inf);
        distance[S] = 0;
        int64_t ans = inf;
        for (int i = 1; i <= K + 3; ++i) {
            for (int j = 1; j <= K; ++j) {
                if ((distance[graph[j][0]] <= graph[j][2]) && (distance[graph[j][1]] > graph[j][3])) {
                    distance[graph[j][1]] = graph[j][3];
                }
            }
        }

        std::cout << distance[F];
    }
}
