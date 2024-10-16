#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <array>
#include <algorithm>
////////////////////////////////////////////////////////////////////////////////////
struct Node {
    bool term;//
    int map[26]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};//
    int go[26] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};//
    int suf; //
    int term_pointer;//
    std::string ans; //
    int word;
    Node () {
        suf = -1;
        term = false;
        term_pointer = -1;
        ans = "";
        word = 0;
    }
};




////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::vector<Node> trie;
    std::string slovo;
    input >> slovo;
    int k;
    int now;
    std::vector<int> order{};
    std::string word;
    input >> k;
    trie.emplace_back();
    for (int i = 0; i < k; ++i) {
        now = 0;
        input >> word;
        for (auto lett : word) {
            if (trie[now].map[lett - 'a'] == -1) {
                trie.emplace_back();
                trie[now].map[lett - 'a'] = trie.size() - 1;
                trie[trie.size() - 1].word = 1 + trie[now].word ;
                // trie[trie.size() - 1].parent = now;
            }
            now = trie[now].map[lett - 'a'];
        }
        order.push_back(now);
        trie[now].term = 1;
    }

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
                if (trie[trie[child].suf].term) {
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




    now = 0;
    for (int i = 0; i < slovo.size(); ++i) {
        now = trie[now].go[slovo[i] - 'a']; // !!!!!!!!!!
        if ((now != -1) && (now != 0)) {
            if (trie[now].term) {
                if (trie[now].ans.empty()) {
                    trie[now].ans += std::to_string(i + 2 - trie[now].word);
                } else {
                    trie[now].ans += " " + std::to_string(i + 2 - trie[now].word);
                }
            }
            curr = now;
            while ((trie[curr].term_pointer > 0)) {
                curr = trie[curr].term_pointer;
                if (trie[curr].ans.empty()) {
                    trie[curr].ans += std::to_string(i + 2- trie[curr].word);
                } else {
                    trie[curr].ans += " " + std::to_string(i + 2 - trie[curr].word);
                }
            }
        } else {
            now = 0;
        }
    }



    for (auto x : order) {
        if (!trie[x].ans.empty()) {
            std::cout << std::count(trie[x].ans.begin(), trie[x].ans.end(), ' ') + 1 << " " << trie[x].ans;
        } else {
            std::cout << 0;
        }
        std::cout << std::endl;
    }


}

