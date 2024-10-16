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
//asdadadadadaw
////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string ans,s;
    std::map<int,std::string> map;
    std::map<std::string,int> existance;
    for (int i = 0; i < 128; ++i) {
        s = char(i);
        map[i] = s;
        existance[s] = i;
    }
    int pointer = 0,p = 128;
    int now,prev = 0;
    int k;
    input >> k;
    while (pointer < k) {
        input >> now;
        if (map.find(now) == map.end()) {
            map[p] = map[prev] + map[prev][0];
            existance[map[prev] + map[prev][0]] = p;
            ++p;
        }
        s = map[now][0];
        ans += map[now];
        if (pointer != 0) {
            if (existance.find(map[prev] + s) == existance.end()) {
                map[p] = map[prev] + s;
                existance[map[prev] + s] = p;
                ++p;
            }
        }
        prev = now;
        ++pointer;
    }
    std::cout << ans;
}

