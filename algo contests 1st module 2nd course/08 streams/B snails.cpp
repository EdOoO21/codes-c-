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
    bool flag;
    Node(int v1,int value1, bool flag1) {
        to = v1;
        value = value1;
        flag = flag1;
    }
};

void print(std::vector<int>& v,int val){
    for (auto x : v) {
        std::cout << x << ' ';
        if (x == val) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}


int dfs(std::vector<std::vector<int>>& graph,std::vector<Node>& con,std::vector<int>& used, int min_on_way, int now,int to,int time,std::vector<int>& ans,bool controller) {
    if (now == to){
        return min_on_way;
    }
    used[now] = time;
    int value;
    for (auto x : graph[now]) {
        if ((used[con[x].to] != time) && (con[x].value - con[x].stream != 0) && (!controller || (controller && con[x].flag))) {
            ans.push_back(con[x].to);
            min_on_way = std::min(min_on_way, - con[x].stream + con[x].value);
            value = dfs(graph,con,used,min_on_way, con[x].to, to,time,ans,controller);
            if (value != 0) {
                if (!controller) {
                    con[x].stream += value;
                    con[x ^ 1].stream -= value;
                } else {
                    con[x].stream = con[x].value;
                }
                return value;
            } else {
                ans.pop_back();
            }
        }
    }
    return 0;
}

void search(std::vector<std::vector<int>>& graph,std::vector<Node>& con,std::vector<int>& used, int min_on_way, int now,int to,int time){
    std::vector<int> ans{now};
    while (dfs(graph,con,used,min_on_way,now,to,time,ans,false) != 0) {
        ++time;
    }
    int answer = 0;
    for (int x : graph[now]) {
        answer += con[x].stream;
    }
    if (answer < 2) {
        std::cout << "NO";
    } else {
        std::cout << "YES" << std::endl;
        std::swap(now,to);
        ans = {now};
        used = std::vector<int>(graph.size(),0);
        time = 1;
        dfs(graph,con,used,min_on_way,now,to,time,ans,true);
        ++time;
        ans.push_back(now);
        dfs(graph,con,used,min_on_way,now,to,time,ans,true);
        std::reverse(ans.begin(),ans.end());
        print(ans,now);

    }

}

////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int v,e,from,to,value,answer = 0, min_on_way,s,f;
    input >> v >> e >> s >> f;
    std::vector<std::vector<int>> graph(v + 1 , std::vector<int>{});
    std::vector<Node> con;
    std::vector<int> used(v + 1);
    for (int i = 0; i < e; ++i) {
        input >> from >> to;
        if (from != to) {
            con.emplace_back(to, 1, false);
            graph[from].push_back(con.size() - 1);
            con.emplace_back(from, 0, true);
            graph[to].push_back(con.size() - 1);
        }
    }
    int time = 1;
    search(graph,con,used,1000000000,s,f,time);

}

