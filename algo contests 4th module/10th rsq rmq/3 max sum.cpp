#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

int64_t inf = std::numeric_limits<int64_t>::max();

int main() {

  std::ifstream input ("input.txt");
  int64_t n;
  input >> n;
  std::vector<int64_t> numbers(n + 1, 0);
  for (int64_t i = 1; i <= n; i++) {
    input >> numbers[i];
  }
  std::vector<int64_t> dp(n + 1, 0);
  for (int64_t i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + numbers[i];
  }


  int64_t ans = -inf;
  int64_t min_sum = dp[0];
  for (int64_t i = 1; i <= n; i++) {
    ans = std::max(ans, dp[i] - min_sum);
    min_sum = std::min(dp[i],min_sum);
  }
  std::cout << ans;
}