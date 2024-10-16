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
struct Node {
    bool term;
    std::map<char,int> map;
    int amount_term;
};

void dfs(int index, std::vector<Node>& trie,int& num,std::string line,std::string& ans) {
    for (auto [lett, neigh] : trie[index].map) {
        if ((ans.empty()) && (num == 0)) {
            ans = line;
            break;
        } else if (num == 0) {
            break;
        }
        if (num - trie[neigh].amount_term <= 0) {
            if (trie[neigh].term && !trie[neigh].map.empty()) {
                --num;
                dfs(neigh, trie, num, line + lett, ans);
            } else if (!trie[neigh].term && !trie[neigh].map.empty()) {
                dfs(neigh, trie, num, line + lett, ans);
            } else if (trie[neigh].term && trie[neigh].map.empty()) {
                --num;
            }
        } else {
            num -= trie[neigh].amount_term;
            continue;
        }

        if ((ans.empty()) && (num == 0)) {
            if (trie[neigh].term && trie[neigh].map.empty()) {
                line += lett;
            }
            ans = line;
            break;
        } else if (num == 0) {
            break;
        }

    }


}



////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::vector<Node> trie;
    int k;
    int z, num,now;
    bool ok;
    std::string word;
    input >> k;
    trie.emplace_back();
    for (int l = 0; l < k; ++l) {
        input >> z;
        if (z == 1) {
            input >> word;
            now = 0;
            for (int i = 0; i < word.size(); ++i) {
                ok = false;
                if (trie.size() > 1) {
                    for (auto [way, _]: trie[now].map) {
                        if (word[i] == way) {
                            ++trie[now].amount_term;
                            now = trie[now].map[way];
                            ok = true;
                            if (i == word.size() - 1) {
                                ++trie[now].amount_term;
                                trie[now].term = true;
                            }
                            break;
                        }
                    }

                }
                if (!ok) {
                    trie.emplace_back();
                    ++trie[now].amount_term;
                    trie[now].map[word[i]] = trie.size() - 1;
                    now = trie[now].map[word[i]];
                    if (i == word.size() - 1) {
                        ++trie[now].amount_term;
                        trie[now].term = true;
                    }
                }
            }

        }
        else {
            input >> num;
            std::string ans;
            dfs(0,trie,num,"",ans);
            std::cout << ans << std::endl;

        }

    }


}

