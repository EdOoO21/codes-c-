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
  for (int64_t i = 0; i < n; i++) {
    input >> sparse_table[0][i];
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


  int64_t amount, l, r, ans;
  ans = 0;
  input >> amount;
  for (int64_t i = 0; i < amount; i++) {
    input >> l >> r;
    a = numbers[r - l + 1];
    ans += std::min(sparse_table[a][r - (1 << a) + 1] , sparse_table[a][l]);
  }
  std::cout << ans;
}