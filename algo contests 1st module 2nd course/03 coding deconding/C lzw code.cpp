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

////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string s;
    std::map<std::string,int> map;
    for (int i = 0; i < 128; ++i) {
        s = char(i);
        map[s] = i;
    }

    std::string string,ch;
    std::getline(input, string);

    int pointer = 0,size = string.size();
    std::vector<int> ans{};
    s = "";
    int start = 128;
    while (pointer != size) {
        ch = string[pointer];
        if (map.find(s + ch) == map.end()) {
            map[s + ch] = start;
            ans.push_back(map[s]);
            ++start;
            s = ch;
        } else {
            s += ch;
        }
        ++pointer;
    }
    ans.push_back(map[s]);
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }

}

