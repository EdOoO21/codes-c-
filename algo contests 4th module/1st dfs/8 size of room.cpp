#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

int64_t sum = 0;
void dfs(int64_t index, int64_t index2, std::vector<std::vector<int64_t>>& graph) {
    graph[index][index2] = 2;
    sum += 1;
    if (graph[index][index2 + 1] == 1) {
        dfs(index,index2 + 1,graph);
    }
    if (graph[index + 1][index2] == 1) {
        dfs(index + 1,index2,graph);
    }
    if (graph[index][index2 - 1] == 1) {
        dfs(index,index2 - 1,graph);
    }
    if (graph[index - 1][index2] == 1) {
        dfs(index - 1,index2,graph);
    }

}

int main() {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        int64_t N;
        char first;
        input >> N;
        std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>(N + 1, 0));
        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < N + 1; ++j) {
                input >> first;
                if (first == '.') {
                    graph[i][j] = 1;
                }
            }
        }
        int64_t one,two;
        input >> one >> two;
        dfs(one,two,graph);
        std::cout << sum << std::endl;

    }
}