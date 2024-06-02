#include <iostream>
#include <unordered_map>
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
        int64_t N, start, end,first,second,M;
        input >> N >> M;
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>{});
        std::vector<std::vector<int64_t>> distance(M + 1, std::vector<int64_t>{});
        std::vector<std::vector<int64_t>> peaks(N + 1,{M + 1, M + 1});
        std::vector<int64_t> rebra;
        for (int i = 0; i < M; ++i) {
            input >> first >> second;
            graph[first].push_back(second);
            graph[second].push_back(first);
            rebra.push_back((10000000*first)+second);
        }

        input >> start >> end;
        distance[0].push_back(start);
        peaks[start][0] = 0;
        int minv = M + 1;
        for (int i = 0; i <= M; ++i) {
            for (auto x : distance[i]) {
                for (auto y : graph[x]) {
                    if (peaks[y][0] > i + 1) {
                        peaks[y][0] = i + 1;
                        distance[i + 1].push_back(y);
                        if (y == end) {
                            if ((minv == M + 1) || (minv > i + 1)) {
                                minv = i + 1;
                            }
                        }
                    }
                }
            }
            if (minv != M + 1) {
                break;
            }
        }
        distance = std::vector<std::vector<int64_t>>(M + 1, std::vector<int64_t>{});
        distance[0].push_back(end);
        peaks[end][1] = 0;
        minv = M + 1;
        for (int i = 0; i <= M; ++i) {
            for (auto x : distance[i]) {
                for (auto y : graph[x]) {
                    if (peaks[y][1] > i + 1) {

                        peaks[y][1] = i + 1;
                        distance[i + 1].push_back(y);
                        if (y == start) {
                            if ((minv == M + 1) || (minv > i + 1)) {
                                minv = i + 1;
                            }
                        }
                    }
                }
            }
            if (minv != M + 1) {
                break;
            }
        }
        int64_t answer = 0;
        for (auto x : rebra) {
            if (minv - 1 == ((peaks[(x / 10000000)][1] + peaks[x - ((x / 10000000)*10000000)][0])) ||
            ((peaks[(x / 10000000)][0] + peaks[x - ((x / 10000000)*10000000)][1])) == minv - 1) {
                answer += 1;
            }
        }
        std::cout << M - answer;


    }
}