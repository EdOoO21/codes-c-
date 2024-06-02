#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>



int main() {
  std::ifstream input ("input.txt");
  int64_t n;
  input >> n;
  std::vector<int64_t> line(n + 1,0);
  for (int64_t i = 1; i <= n; i++) {
    input >> line[i];
  }
  std::vector<int64_t> dp(n + 1,0);
  for (int64_t i = 1; i <= n; i++) {
    dp[i] = line[i] + dp[i - 1];
  }
  int64_t q, x0;
  input >> q >> x0;
  std::vector<int64_t> subNums(2*q,0);
  subNums[0] = x0;
  for (int64_t i = 1; i < 2*q; i++) {
    subNums[i] = ((11173 * subNums[i - 1]) + 1) % 1000000007;
  }
  int64_t ans = 0;
  int64_t a;
  int64_t b;
  for (int64_t i = 0; i < q; i++) {
    a = std::min(subNums[2*i] % n, subNums[(2*i) + 1] % n);
    b = std::max(subNums[2*i] % n, subNums[(2*i) + 1] % n);
    ans += dp[b + 1] - dp[a];
    ans = ans % 1000000007;
  }
  std::cout << ans;
}