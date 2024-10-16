#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <array>
#include <algorithm>
#include <cstdint>

////////////////////////////////////////////////////////////////////////////////////
struct Node {
    int term;//
    int map[26]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};//
    int go[26] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};//
    int suf; //
    int term_pointer;//
     //
    std::string word;
    Node () {
        suf = -1;
        term = 0;
        term_pointer = -1;

        word = "";
    }
};




////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::vector<Node> trie;
    std::vector<bool> mapa = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
    int k;
    std::map<std::string,int> helper;

    int now;
    uint64_t minv = 100000;
    std::vector<std::string> order;
    std::string word;
    input >> k;
    trie.emplace_back();

    // бор
    for (int i = 0; i < k; ++i) {
        now = 0;
        input >> word;
        for (auto lett : word) {
            if (trie[now].map[lett - 'a'] == -1) {
                trie.emplace_back();
                trie[now].map[lett - 'a'] = trie.size() - 1;
                trie[trie.size() - 1].word = trie[now].word + lett;
                // trie[trie.size() - 1].parent = now;
            }
            now = trie[now].map[lett - 'a'];
        }
        order.push_back(word);
        helper[word] = -1;

        mapa[word[word.size() - 1] - 'a'] = true;
        ++trie[now].term;
//        minv = std::min(minv,word.size());
    }



    // постройка ссылок
    trie[0].suf = 0;
    std::queue<int> q;
    q.push(0);

    for (int i = 0; i < 26; ++i) {
        if (trie[0].map[i] != -1) {
            trie[0].go[i] = trie[0].map[i];
            continue;
        } else {
            trie[0].map[i] = 0;
            trie[0].go[i] = 0;
        }
    }

    trie[0].term_pointer = 0;
    int curr,child;



    while (!q.empty()) {
        curr = q.front();
        q.pop();

        for (int c = 0; (c < 26); ++c) {
            child = trie[curr].map[c];

            if ((child == -1) || (trie[curr].suf == -1) || (child == 0)) {
                continue;
            }
            //suff
            trie[child].suf = curr == 0 ? 0 : trie[trie[curr].suf].go[c]; // !!!!!!!!!!!!!!!


            //go
            for (int i = 0; i < 26; ++i) {
                if (trie[child].map[i] != -1) {
                    trie[child].go[i] = trie[child].map[i];
                } else if (trie[child].suf != -1) {
                    trie[child].go[i] = trie[trie[child].suf].go[i];
                } else {
                    trie[child].go[i] = 0;
                }
            }

            //term
            if (trie[child].suf != -1) {
                if (trie[trie[child].suf].term > 0) {
                    trie[child].term_pointer = trie[child].suf;
                } else if (trie[trie[child].suf].term_pointer != -1) {
                    trie[child].term_pointer = trie[trie[child].suf].term_pointer;
                }
            } else {
                std::cout << "хуета на " << curr << " " << child<< std::endl;
            }

            q.push(child);
        }
    }



//поиск
    int ans = 0;

    std::vector<std::string> used{};
    for (auto x : order) {
        used.clear();
        now = 0;
        for (auto y : x) {
            now = trie[now].map[y - 'a'];
            curr = now;
            while ((curr != 0) && (mapa[y - 'a'])) {
                if ((trie[curr].term > 0) && (helper[trie[curr].word] < 1)) {
                    ans += trie[curr].term;
                    helper[trie[curr].word] = 1;
                    used.push_back(trie[curr].word);
                }
                curr = trie[curr].suf;
            }
        }
        for (auto x1 : used) {
            helper[x1] = -1;
        }
        helper[x] = -1;
    }

    std::cout << ans - k;



//вывод


}

