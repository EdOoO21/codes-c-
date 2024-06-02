#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
//

int main() {
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ifstream input("input.txt");
    if (input.is_open()){
        int N;
        char value;
        input >> N;

        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int,int> distance;
        int num;
        std::vector<std::vector<int>> way_len(1,std::vector<int>{});

        for (int i = N; i > 0; --i) {
            for (int j = 1; j < N + 1; ++j){
                for (int k = 1; k < N + 1; ++k) {
                    input >> value;
                    if ((value == '.') || (value == 'S'))  {
                        num = (i * 1000000) + (j * 1000) + k;
                        graph[num];
                        distance[num] = 30 + (6 * (N * N * N));

                        if (value == 'S') {
                            distance[num] = 0;
                            way_len[0].push_back(num);
                        }

                        if ((j != 1) && (graph.find((i * 1000000) + ((j - 1) * 1000) + k) != graph.end())) {
                            graph[num].push_back((i * 1000000) + ((j - 1) * 1000) + k);
                            graph[(i * 1000000) + ((j - 1) * 1000) + k].push_back(num);
                        }
                        if ((k != 1) && (graph.find((i * 1000000) + (j * 1000) + (k - 1)) != graph.end())) {
                            graph[num].push_back((i * 1000000) + (j * 1000) + (k - 1));
                            graph[(i * 1000000) + (j * 1000) + (k - 1)].push_back(num);
                        }
                        if ((i != N) && (graph.find((((i + 1) * 1000000) + (j * 1000) + k)) != graph.end())) {
                            graph[num].push_back(((i + 1) * 1000000) + (j * 1000) + k);
                            graph[((i + 1) * 1000000) + (j * 1000) + k].push_back(num);
                        }

                    }
                }
            }
        }


        bool flag = false;
        int answer = 0;
        if (N == 1) {
            std::cout << 0;
        } else {
            for (int x = 0; true; x++) {

                way_len.emplace_back();
                for (auto y: way_len[x]) {
                    for (auto z: graph[y]) {
                        if (distance[z] > x + 1) {
                            distance[z] = x + 1;
                            way_len[x + 1].push_back(z);
                            if ((z / 1000000) == N) {
                                answer = x + 1;
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }

            if (way_len[0][0] / 1000000 == N) {
                std::cout << 0;
            } else {
                std::cout << answer;
            }
        }
    }
}
