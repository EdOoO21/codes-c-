#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>

#include <vector>
#include <cstdint>

////////////////////////////////////////////////////////////////////////////////////
bool dfs(std::vector<std::vector<int>>& graph, std::vector<bool>& used,  std::vector<int>& pairs,int v){
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (auto p : graph[v]) {
        if ((pairs[p] == -1) || (dfs(graph,used,pairs,pairs[p]))) {
            pairs[p] = v;
            return true;
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");

    int a,b;
    input >> a >> b;
    std::vector<std::vector<int>> graph(a + 1,std::vector<int>{});
    std::vector<bool> used;
    std::vector<int> pairs(b + 1, -1);
    std::vector<int> renew(a + 1, -1);
    int now;

    for (int i = 1; i < a + 1; ++i) {
        input >> now;
        while (now != 0) {
            graph[i].push_back(now);
            input >> now;
        }
    }

    for (int i = 1; i < a + 1; ++i) {
        used = std::vector<bool>(a + 1,false);
        dfs(graph, used,pairs,i);
    }

    int amount = 0;
    for (int i = 1; i < b + 1; ++i) {
        if (pairs[i] != -1) {
            renew[pairs[i]] = i;
            ++amount;
        }
    }

    std::cout << amount << std::endl;

    for (int i = 1; i < a + 1; ++i) {
        if (renew[i] != -1) {
            std::cout << i << " " << renew[i] << std::endl;
        }
    }

}

