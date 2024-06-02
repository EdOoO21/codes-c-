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

int count(std::unordered_map<int, int>& number) {
  int ans = 1;
  for (auto a : number) {
    ans *= to(a.first, a.second);
  }
  return ans;
}

int main() {
  std::ifstream input("input.txt");
  int n;
  input >> n;
  std::unordered_map<int, int> map;
  std::unordered_map<int, int> number;

  int i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      ++map[i];
      number[i] = 1;
      n /= i;
    } else {
      i++;
    }
  }
  if (n != 1) {
    map[n] += 1;
    number[n] = 1;
  }

  int num = count(number);
  for (auto a : map) {
    i = 2;
    while (a.second > number[a.first] * num) {
      number[a.first] = i;
      num *= a.first;
      i++;
    }
  }
  std::cout << num << std::endl;
}
