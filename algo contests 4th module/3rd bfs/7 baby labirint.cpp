#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <unordered_map>

int64_t inf = std::numeric_limits<int64_t>::max();

int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    if (input.is_open()) {
        int64_t N, M;
        input >> N >> M;
        std::unordered_map<int64_t,int64_t> ways;
        std::vector<std::vector<int64_t>> l(N, std::vector<int64_t>(M,0));
        std::vector<int64_t > finish{};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M ; ++j) {
                input >> l[i][j];
                ways[(100000 * i) + j] = inf;
                if (l[i][j] == 2) {
                    finish.push_back((100000 * i) + j);
                }
            }
        }
        ways[0] = 0;
        int k;
        std::unordered_map<int64_t , std::vector<int64_t>> peaks;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (i > 0) {
                    k = i - 1;
                    while (true) {
                        if (l[k][j] == 2) {
                            peaks[(100000 * i) + j].push_back((100000 * k) + j);
                            break;
                        }
                        if (l[k][j] == 1) {
                            if (i != k + 1) {
                                peaks[(100000 * i) + j].push_back((100000 * (k + 1)) + j);
                            }
                            break;
                        }
                        if (k == 0) {
                            peaks[(100000 * i) + j].push_back(j);
                            break;
                        }
                        --k;
                    }
                }
                if (j > 0) {
                    k = j - 1;
                    while (true) {
                        if (l[i][k] == 2) {
                            peaks[(100000 * i) + j].push_back((100000 * i) + k);
                            break;
                        }
                        if (l[i][k] == 1) {
                            if (j != k + 1) {
                                peaks[(100000 * i) + j].push_back((100000 * i) + k + 1);
                            }
                            break;
                        }
                        if (k == 0) {
                            peaks[(100000 * i) + j].push_back(100000*i);
                            break;
                        }
                        --k;
                    }
                }
                if (i < N - 1) {
                    k = i + 1;
                    while (true) {
                        if (l[k][j] == 2) {
                            peaks[(100000 * i) + j].push_back((100000 * k) + j);
                            break;
                        }
                        if (l[k][j] == 1) {
                            if (i != k - 1) {
                                peaks[(100000 * i) + j].push_back((100000 * (k - 1)) + j);
                            }
                            break;
                        }
                        if (k == N - 1) {
                            peaks[(100000 * i) + j].push_back((100000 * k) + j);
                            break;
                        }
                        ++k;
                    }
                }
                if (j < M - 1) {
                    k = j + 1;
                    while (true) {
                        if (l[i][k] == 2) {
                            peaks[(100000 * i) + j].push_back((100000 * i) + k);
                            break;
                        }
                        if (l[i][k] == 1) {
                            if (j != k - 1) {
                                peaks[(100000 * i) + j].push_back((100000 * i) + k - 1);
                            }
                            break;
                        }
                        if (k == M - 1) {
                            peaks[(100000 * i) + j].push_back((100000 * i) + k);
                            break;
                        }
                        ++k;
                    }
                }

            }
        }

        std::vector<std::vector<int64_t>> distance(1,std::vector<int64_t>{0});
        int64_t answer = -1;
        for (int i = 0; !distance.empty(); ++i) {
            distance.emplace_back();
            for (auto x : distance[i]) {
                for (auto y : peaks[x]) {
                    if (ways[y] > i + 1) {
                        distance[i + 1].push_back(y);
                        ways[y] = i + 1;
                        if (std::find(finish.begin(),finish.end(),y) != finish.end()) {
                            answer = i + 1;
                            break;
                        }
                    }
                }
                if (answer != -1) {
                    break;
                }
            }
            if (answer != -1) {
                break;
            }
        }
        std::cout << answer;

    }
}
