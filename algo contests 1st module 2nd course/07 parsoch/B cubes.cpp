#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>

#include <vector>
#include <cstdint>
#include <set>
#include <stack>
////////////////////////////////////////////////////////////////////////////////////
bool dfs(std::vector<std::set<int>>& graph, std::vector<bool>& used,  std::vector<int>& pairs,int v){
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

    int amo;
    input >> amo;

    std::string word,slovo;
    input >> word;

    std::vector<std::set<int>> graph(26, std::set<int>{});
    std::vector<bool> used;
    std::vector<int> pairs(amo + 1, -1);

    for (int i = 1; i < amo + 1; ++i) {
        input >> slovo;
        for (auto x : slovo) {
            graph[x - 65].insert(i);
        }
    }



    for (auto x : word) {
        used = std::vector<bool>(26,false);
        dfs(graph, used,pairs,x - 65);
    }

    std::vector<std::stack<int>> ans(26,std::stack<int>{});

    for (int x = 1; x < pairs.size(); ++x) {
        if (pairs[x] != -1) {
            ans[pairs[x]].push(x);
        }
    }
    std::vector<int> ans1{};

    for (auto x : word) {
        if (!ans[x - 65].empty()) {
            ans1.push_back(ans[x - 65].top());
            ans[x - 65].pop();
        } else {
            ans[0].push(-1);
            break;
        }
    }

    if ((!ans[0].empty()) && (ans[0].top() == -1)) {
        std::cout << "NO";
    } else {
        std::cout << "YES" << std::endl;
        for (auto x : ans1) {
            std::cout << x << " ";
        }
    }
}

