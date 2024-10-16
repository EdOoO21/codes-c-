#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>

#include <vector>
#include <cstdint>

////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("inexact-matching.in");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string patt;
    std::string task;
    int l = 0;
    int r = 0;
    input >> patt;
    input >> task;
    const int size = patt.size() + task.size() + 1;
    std::vector<int> z(size,-1);
    std::vector<int> zb(size,-1);
    std::string a = patt + "#" + task;
    std::reverse(patt.begin(),patt.end());
    std::reverse(task.begin(),task.end());
    std::string b = patt + "#" + task;
    z[0] = 0;
    zb[0] = 0;
    for (int i = 1; i < size; ++i) {
        z[i] = std::max(std::min(z[i - l], r - i), 0);
        while ((a[z[i]] == a[i + z[i]]) && (i + z[i] < size)) {
            ++z[i];
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }

    }
    l = 0;
    r = 0;
    for (int i = 1; i < size; ++i) {
        zb[i] = std::max(std::min(zb[i - l], r - i), 0);
        while ((b[zb[i]] == b[i + zb[i]]) && (i + zb[i] < size)) {
            ++zb[i];
        }
        if (i + zb[i] > r) {
            r = i + zb[i];
            l = i;
        }
    }
    std::reverse(zb.begin(),zb.end());
    int c = patt.size();
    std::vector<int64_t> ans{};


//
//    for (int i = 0; i < z.size(); ++i) {
//        std::cout << z[i] << " ";
//    }
//    std::cout << std::endl;
//    for (int i = 0; i < z.size(); ++i) {
//        std::cout << zb[i] << " ";
//    }
//    std::cout << std::endl;



    int64_t count = c - 1;
    for (int i = c + 1; count < size - c - 1; ++i) {

        if (z[i] + zb[count] >= c - 1) {
            ans.push_back(i - c);
        }
        ++count;
    }


    std::cout << ans.size() << std::endl;
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << " ";
    }
}

