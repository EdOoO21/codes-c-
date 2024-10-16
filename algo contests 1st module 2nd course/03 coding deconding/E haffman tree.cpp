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
    int r;
    int l;
    int parent;
    bool left;
         //
    std::string word;
    Node () {
        l = -1;
        r = -1;
        parent = -1;
        left = false;
        word = "";
    }
};




////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::vector<Node> tree{Node()};
    int k, now;
    input >> k;
    std::string word;
    std::vector<std::string> ans;
    tree[0].parent = -12;
    for (int _ = 0; _ < k; ++_) {
        input >> word;
        now = 0;
        ans.clear();
        tree.clear();
        tree.emplace_back();
        for (int x = 0; x < word.size(); ++x) {
            if (word[x] == 'D') {
                if (tree[now].l == -1) {
                    tree.emplace_back();
                    tree[now].l = tree.size() - 1;
                    tree[tree.size() - 1].parent = now;
                    tree[tree.size() - 1].word = tree[now].word + '0';
                    now = tree.size() - 1;
                    tree[now].left = true;


                } else {
                    tree.emplace_back();
                    tree[now].r = tree.size() - 1;
                    tree[tree.size() - 1].parent = now;
                    tree[tree.size() - 1].word = tree[now].word + '1';
                    now = tree.size() - 1;
                }
                if (word[x + 1] == 'U') {
                    ans.push_back(tree[now].word);
                }
            } else {
                while ((now != -12) && !tree[now].left) {
                    now = tree[now].parent;
                }

                now = tree[now].parent;

                tree.emplace_back();
                tree[now].r = tree.size() - 1;
                tree[tree.size() - 1].parent = now;
                tree[tree.size() - 1].word = tree[now].word + '1';
                now = tree.size() - 1;


                if ((x == word.size() - 1)|| (word[x + 1] == 'U')) {
                    ans.push_back(tree[now].word);
                }
            }
        }
        std::cout << ans.size() << std::endl;
        for (auto y : ans) {
            std::cout << y << std::endl;
        }
    }

}

