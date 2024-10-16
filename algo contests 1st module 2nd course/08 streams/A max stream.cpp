#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <cstdint>
#include <map>
////////////////////////////////////////////////////////////////////////////////////

struct Node{
    int to;
    int value;
    int stream = 0;
    Node(int v1,int value1) {
        to = v1;
        value = value1;
    }
};

void print(std::vector<int>& v){
    for (auto x : v) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}


int dfs(std::vector<std::vector<int>>& graph,std::vector<Node>& con,std::vector<int>& used, int min_on_way, int now,int to,int time) {
    if (now == to){
        return min_on_way;
    }
    used[now] = time;
    int value;
    for (auto x : graph[now]) {
        if ((used[con[x].to] != time) && (con[x].value - con[x].stream!= 0)) {
            min_on_way = std::min(min_on_way, - con[x].stream + con[x].value);
            value = dfs(graph,con,used,min_on_way, con[x].to, to,time);
            if (value != 0) {
                con[x].stream += value;
                con[x ^ 1].stream -= value;
                return value;
            }
        }
    }
    return 0;
}

void search(std::vector<std::vector<int>>& graph,std::vector<Node>& con,std::vector<int>& used, int min_on_way, int now,int to,int time){
    while (dfs(graph,con,used,min_on_way,now,to,time) != 0) {
        ++time;
    }
    int answer = 0;
    for (int x : graph[1]) {
        answer += con[x].stream;
    }
    std::cout << answer;
}

////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int v,e,from,to,value,answer = 0, min_on_way,s,f;
    input >> v >> e;
    std::vector<std::vector<int>> graph(v + 1 , std::vector<int>{});
    std::vector<Node> con;
    std::vector<int> used(v + 1);
    for (int i = 0; i < e; ++i) {
        input >> from >> to >> value;
        con.emplace_back(to, value);
        graph[from].push_back(con.size() - 1);
        con.emplace_back(from, 0);
        graph[to].push_back(con.size() - 1);
    }
    int time = 1;
    search(graph,con,used,1000000000,1,v,time);

}

