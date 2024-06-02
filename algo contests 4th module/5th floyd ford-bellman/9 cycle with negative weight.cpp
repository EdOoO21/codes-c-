#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>

int64_t inf = std::numeric_limits<int64_t>::max();


int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    if (input.is_open()) {
        int64_t N;
        input >> N;
        std::vector<std::vector<int64_t>> graph(N + 1,std::vector<int64_t>(N + 1, inf));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                input >> graph[i][j];
            }
        }


        std::vector<std::vector<int64_t>> distance(N + 1,{0,0});

        int64_t ans = 0;
        for (int k = 1; k <= N + 1; ++k) {
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= N; ++j) {
                    if (graph[i][j] + distance[i][0] < distance[j][0]) {
                        distance[j][0] = graph[i][j] + distance[i][0];
                        distance[j][1] = i;
                        if (k == N + 1) {
                            ans = i;
                        }
                    }
                }
            }
        }
        if (ans == 0) {
            std::cout << "NO";
        } else {
            int64_t index = 1;
            std::vector<int64_t> answer{ans};
            while (true) {
                ans = distance[ans][1];
                if (std::find(answer.begin(), answer.end(), ans) != answer.end()) {
                    break;
                }
                answer.push_back(ans);
                index++;
            }
            std::vector<int64_t> real_answer{ans};
            for (int i = index - 1; i >= 0; --i) {
                if (answer[i] == ans){
                    real_answer.push_back(answer[i]);
                    break;
                } else {
                    real_answer.push_back(answer[i]);
                }
            }
            std::cout << "YES\n" << real_answer.size() << std::endl;
            for (auto x : real_answer) {
                std::cout << x << " ";
            }
        }

    }
}
