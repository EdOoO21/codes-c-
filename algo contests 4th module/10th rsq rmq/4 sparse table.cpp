#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

int64_t inf = std::numeric_limits<int64_t>::max();

int main() {


  int64_t n, m;
  std::cin >> n >> m;
  if (n == 1) {
    int64_t a;
    std::cin >> a;
    std::cout << 1 << " " << 1 << " " << a << std::endl;
    return 0;
  }
  std::vector<int64_t> numbers(n + 1);
  int64_t a = 2;
  int64_t counter = 0;
  for (int64_t i = 1; i <= n; i++) {
    if (i == a) {
      a *= 2;
      counter += 1;
    }
    numbers[i] = counter;
  }
  std::vector<std::vector<int64_t>> sparse_table(numbers[n] + 1, std::vector<int64_t>(n,inf));


  std::cin >> sparse_table[0][0];
  for (int64_t i = 1; i < n; i++) {
    sparse_table[0][i] = (((23*sparse_table[0][i-1]) + 21563) % 16714589);
  }
  int64_t num;
  for (int64_t i = 1; i <= numbers[n]; i++) {
    num = 1 << (i - 1);
    for (int64_t j = 0; j + num < n; j++) {
      if (sparse_table[i - 1][j + num] != inf) {
      sparse_table[i][j] = std::min(sparse_table[i - 1][j], sparse_table[i - 1][j + num]);

      } else {
        break;
      }
    }
  }

  int64_t l, r,u,v,ans;
  std::cin >> u >> v;

  for (int64_t i = 1; i <= m; i++) {
    if (i == 1){
      l = std::min(u - 1,v - 1);
      r = std::max(u - 1,v - 1);
      a = numbers[r - l + 1];
      ans = std::min(sparse_table[a][r - (1 << a) + 1] , sparse_table[a][l]);

    } else {
      u = ((((17 * u) + 751 + ans + (2*(i-1))) % n) + 1);
      v = ((((13 * v) + 593 + ans + (5*(i-1))) % n) + 1);
      l = std::min(u - 1,v - 1);
      r = std::max(u - 1,v - 1);
      a = numbers[r - l + 1];
      ans = std::min(sparse_table[a][r - (1 << a) + 1] , sparse_table[a][l]);
    }
  }
  std::cout << u << ' ' << v << ' ' << ans;
}