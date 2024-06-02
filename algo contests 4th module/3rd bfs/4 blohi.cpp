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
#include <limits>

int64_t inf = std::numeric_limits<int64_t>::max();

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N, M, S, T, Q, first, second;
        input >> N >> M >> S >> T >> Q;
        std::vector<std::vector<int64_t>> peaks{};
        std::vector<std::vector<int64_t>> table(N + 1, std::vector<int64_t>(M + 1, inf));
        for (int i = 0; i < Q; ++i) {
            input >> first >> second;
            peaks.push_back({first,second});
        }
        table[S][T] = 0;
        std::vector<std::vector<std::vector<int64_t>>> distance(1, std::vector<std::vector<int64_t>>(1,{S,T}));
        for (int i = 0; !distance[i].empty(); ++i) {
            distance.emplace_back();
            for (auto x : distance[i]) {
                if ((((x[0] + 2) < N + 1) && ((x[1] + 1) < M + 1)) && (i + 1 < table[x[0] + 2][x[1] + 1])) {
                    distance[i + 1].push_back({x[0] + 2,x[1] + 1});
                    table[x[0] + 2][x[1] + 1] = i + 1;
                }
                if ((((x[0] + 2) < N + 1) && ((x[1] - 1) > 0)) && (i + 1 < table[x[0] + 2][x[1] - 1])) {
                    distance[i + 1].push_back({x[0] + 2,x[1] - 1});
                    table[x[0] + 2][x[1] - 1] = i + 1;
                }
                if ((((x[0] - 2) > 0) && ((x[1] + 1) < M + 1)) && (i + 1 < table[x[0] - 2][x[1] + 1])) {
                    distance[i + 1].push_back({x[0] - 2,x[1] + 1});
                    table[x[0] - 2][x[1] + 1] = i + 1;
                }
                if ((((x[0] - 2) > 0) && ((x[1] - 1) > 0)) && (i + 1 < table[x[0] - 2][x[1] - 1])) {
                    distance[i + 1].push_back({x[0] - 2,x[1] - 1});
                    table[x[0] - 2][x[1] - 1] = i + 1;
                }



                if ((((x[0] + 1) < N + 1) && ((x[1] + 2) < M + 1)) && (i + 1 < table[x[0] + 1][x[1] + 2])) {
                    distance[i + 1].push_back({x[0] + 1,x[1] + 2});
                    table[x[0] + 1][x[1] + 2] = i + 1;
                }
                if ((((x[0] + 1) < N + 1) && ((x[1] - 2) > 0)) && (i + 1 < table[x[0] + 1][x[1] - 2])) {
                    distance[i + 1].push_back({x[0] + 1,x[1] - 2});
                    table[x[0] + 1][x[1] - 2] = i + 1;
                }
                if ((((x[0] - 1) > 0) && ((x[1] + 2) < M + 1)) && (i + 1 < table[x[0] - 1][x[1] + 2])) {
                    distance[i + 1].push_back({x[0] - 1,x[1] + 2});
                    table[x[0] - 1][x[1] + 2] = i + 1;
                }
                if ((((x[0] - 1) > 0) && ((x[1] - 2) > 0)) && (i + 1 < table[x[0] - 1][x[1] - 2])) {
                    distance[i + 1].push_back({x[0] - 1,x[1] - 2});
                    table[x[0] - 1][x[1] - 2] = i + 1;
                }

            }
        }
        int answer = 0;
        bool ok = false;
        for (auto x : peaks) {
            if (table[x[0]][x[1]] != inf) {
                answer += table[x[0]][x[1]];
            } else {
                ok = true;
                break;
            }
        }

        if (ok) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << answer << std::endl;
        }

    }
}
