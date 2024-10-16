#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>

#include <vector>
#include <cstdint>

////////////////////////////////////////////////////////////////////////////////////

struct Node{
    int prev;
    int weight;
    int top;
    Node(int prev1,int weight1, int top1) {
        prev = prev1;
        weight = weight1;
        top = top1;
    }
};


////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::vector<Node> tree{Node(-1,0,0)};
    int k, number, mass;
    input >> k;
    for (int i = 0; i < k; ++i) {
        input >> number >> mass;
        if (mass != 0) {
            tree.emplace_back(number,mass + tree[number].weight,mass);
        } else {
            tree.emplace_back(tree[tree[number].prev]);
        }
    }
    int64_t ans = 0;
    for (auto x : tree) {
        ans += x.weight;
    }
    std::cout << ans;
}

