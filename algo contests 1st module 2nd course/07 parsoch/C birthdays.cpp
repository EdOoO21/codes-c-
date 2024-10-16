#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>

#include <vector>
#include <cstdint>
#include <map>
#include <set>
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

void search(std::vector<std::vector<int>>& graph, std::vector<bool>& b,std::vector<bool>& g, std::vector<int>& pairs,int v) {
    b[v] = true;
    for (auto neigh : graph[v]) {
        if (!g[neigh] && (pairs[neigh] != -1)) {
            g[neigh] = true;
            search(graph,b,g,pairs,pairs[neigh]);
        }
    }
}


void vertex_find(std::vector<std::vector<int>>& graph, std::vector<int>& pairs, std::vector<int>& renew,int girls) {
    std::vector<bool> b(graph.size(), false);
    std::vector<bool> g(girls, false);

    for (int i = 1; i < graph.size() ; ++i) {
        if (renew[i] == -1) {
            search(graph,b,g,pairs,i);
        }
    }

    int boy = 0, girl = 0;
    for (int i = 1; i < graph.size(); ++i) {
        if (b[i]) {
            ++boy;
        }
    }
    for (int i = 1; i < girls; ++i) {
        if (!g[i]) {
            ++girl;
        }
    }
    std::cout << boy + girl << std::endl;
    std::cout << boy << " " << girl << std::endl;

    for (int i = 1; i < graph.size(); ++i) {
        if (b[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    for (int i = 1; i < girls; ++i) {
        if (!g[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}


////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    int k;
    input >> k;
    for (int i1 = 0; i1 < k; ++i1) {
        int a, b;
        input >> a >> b;

        int now;

        std::vector<std::vector<int>> g(a + 1, std::vector<int>{});
        std::vector<bool> checker;

        for (int i = 1; i < a + 1; ++i) {
            checker = std::vector<bool>(b + 1,false);
            input >> now;
            while (now != 0) {
                checker[now] = true;
                input >> now;
            }
            for (int j = 1; j < b + 1; ++j) {
                if (!checker[j]) {
                    g[i].push_back(j);
                }
            }

        }

        std::vector<bool> used;
        std::vector<int> pairs(b + 1, -1);
        std::vector<int> renew(a + 1, -1);

        for (int i = 1; i < a + 1; ++i) {
            used = std::vector<bool>(a + 1, false);
            dfs(g, used, pairs, i);
        }

        for (int i = 1; i < b + 1; ++i) {
            if (pairs[i] != -1) {
                renew[pairs[i]] = i;
            }
        }


        vertex_find(g,pairs,renew,b + 1);

    }
}

