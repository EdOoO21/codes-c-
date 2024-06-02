#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

////////////////////////////////////////////////////////////////////////////////////
int inf = std::numeric_limits<int>::max();

////////////////////////////////////////////////////////////////////////////////////
int to(int a, int i) {
  int ans = 1;
  while (i > 1) {
    if (i % 2 == 1) {
      ans = ans * a;
    }
    a = a * a;
    i /= 2;
  }
  a = a * ans;
  return a;
}

int count(int num, int n) {
  int i = 1, ans = 0;

  while (to(num,i) <= n) {
    ans += n / to(num,i);
    ++i;
  }
  return ans;
}

int main() {
  std::ifstream input("input.txt");
  int n,k;
  input >> n >> k;
  std::unordered_map<int, int> nfac;
  std::unordered_map<int, int> kk;

  int i = 2;
  while (i * i <= k) {
    if (k % i == 0) {
      ++kk[i];
      k /= i;
    } else {
      i++;
    }
  }
  if (k != 1) {
    kk[k] += 1;
  }


  for (auto a : kk) {
    nfac[a.first] = count(a.first, n);
  }
  int ans = inf;

  for (auto a : nfac) {
    ans = std::min(ans, a.second / kk[a.first]);
  }
  std::cout << ans;
}
