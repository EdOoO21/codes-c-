#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <cstdint>
#include <map>
#include <unordered_map>
////////////////////////////////////////////////////////////////////////////////////
struct Node {
    bool term;
    std::map<char,int> map;
    int amount_term;
};
////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::vector<Node> trie;
    int k;
    int z, num = 0;
    bool ok;
    char lett;
    input >> k;
    trie.emplace_back();
    std::vector<int> syn(k+1,0);
    std::vector<int> place(k+1,-1);
    for (int i = 0; i < k+1; ++i) {
        syn[i] = i;
    }
    for (int l = 1; l <= k; ++l) {
        input >> z >> lett;
        ok = false;
        if (trie.size() > 1) {
            for (auto [way, um]: trie[syn[z - 1]].map) {
                if (lett == way) {
                    syn[l] = um;
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            ++num;
            trie.emplace_back();
            trie[syn[z - 1]].map[lett] = trie.size() - 1;
            syn[l] = trie[syn[z - 1]].map[lett];
        }
        std::cout << num << std::endl;
    }
}




