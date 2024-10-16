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


//
//void dfs(int index, std::vector<Node>& trie,int& num,std::string line,std::string& ans) {
//    for (auto [lett, neigh] : trie[index].map) {
//        if ((ans.empty()) && (num == 0)) {
//            ans = line;
//            break;
//        } else if (num == 0) {
//            break;
//        }
//        if (num - trie[neigh].amount_term <= 0) {
//            if (trie[neigh].term && !trie[neigh].map.empty()) {
//                --num;
//                dfs(neigh, trie, num, line + lett, ans);
//            } else if (!trie[neigh].term && !trie[neigh].map.empty()) {
//                dfs(neigh, trie, num, line + lett, ans);
//            } else if (trie[neigh].term && trie[neigh].map.empty()) {
//                --num;
//            }
//        } else {
//            num -= trie[neigh].amount_term;
//            continue;
//        }
//
//        if ((ans.empty()) && (num == 0)) {
//            if (trie[neigh].term && trie[neigh].map.empty()) {
//                line += lett;
//            }
//            ans = line;
//            break;
//        } else if (num == 0) {
//            break;
//        }
//
//    }
//
//
//}



////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string num;
    input >> num;
    int size = ceil(log2(num.size() + 1));
    for (int i = size; ; ++i) {
        if (i == ceil(log2(num.size() + 1 + i))) {
            size = i;
            break;
        }
    }
    std::vector<char> line(size + num.size() + 1,'0');
    std::vector<int> pows(size,1);
    line[1] = 'a';
    for (int i = 1; i < size; ++i) {
        pows[i] = pows[i-1] * 2;
        line[pows[i]] = 'a';
    }
    int pointer = 0;
    for (int i = 1; i < size + num.size() + 1; ++i) {
        if (line[i] != 'a') {
            line[i] = num[pointer];
            ++pointer;
        }
    }
    int sum = 0,prev;
    for (auto i : pows) {
        pointer = i;
        sum = 0;
        prev = 1;
        while (pointer <= size + num.size()) {
            while (((pointer / i) == prev) && (pointer <= size + num.size())) {
                if (line[pointer] != 'a') {
                    sum += line[pointer] - '0';
                }
                ++pointer;
            }
            pointer += i;
            prev = pointer / i;
        }
        if (sum % 2 == 0) {
            line[i] = '0';
        } else {
            line[i] = '1';
        }
    }

    for (int i = 1; i < line.size(); ++i) {
        std::cout << line[i];
    }













}

