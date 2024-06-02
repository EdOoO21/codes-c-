#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>

int64_t inf = std::numeric_limits<int64_t>::max();

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N, M, S, T, first, second;
        input >> N >> M;
        std::vector<std::vector<int64_t>> peaks(N + 1, std::vector<int64_t>{});
        std::vector<std::vector<int64_t>> graph(M + 1, std::vector<int64_t>{});
        std::vector<bool> lines(M + 1, false);
        for (int i = 0; i < M; ++i) {
            input >> first;
            for (int j = 0; j < first; ++j) {
                input >> second;
                peaks[second].push_back(i + 1);
                for (auto x : peaks[second]) {
                    if ((x != i + 1) && (std::find(graph[x].begin(),graph[x].end(),i + 1) == graph[x].end())) {
                        graph[x].push_back(i + 1);
                        graph[i + 1].push_back(x);
                    }
                }

            }
        }
        input >> S >> T;
        for (auto x : peaks[T]) {
            lines[x] = true;
        }
        std::vector<std::vector<int64_t>> distance{{}};
        std::vector<int64_t> way_len;
        int64_t minv = inf;
        bool not_ok = false;
        for (auto x : peaks[S]) {
            way_len = std::vector<int64_t>(M + 1,inf);
            way_len[x] = 0;
            distance.clear();
            distance.push_back({x});
            if (lines[x]) {
                not_ok = true;
                break;
            }
            for (int i = 0; !distance[i].empty(); ++i) {
                distance.emplace_back();
                for (auto y : distance[i]) {
                    for (auto z : graph[y]) {
                        if (way_len[z] > i + 1) {
                            way_len[z] = i + 1;
                            distance[i + 1].push_back(z);
                            if (lines[z]) {
                                minv = minv > i + 1 ? i + 1 : minv;
                            }
                        }

                    }
                    if (not_ok) {
                        break;
                    }
                }
                if (not_ok) {
                    break;
                }
            }
            if (not_ok) {
                break;
            }
        }
        if (not_ok || (M == 1)) {
            std::cout << 0;
        } else if (minv == inf) {
            std::cout << -1;
        } else {
            std::cout << minv;
        }
    }
}
