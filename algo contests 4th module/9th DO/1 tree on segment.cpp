#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

void sumsearch(std::vector<int64_t> &tree, int64_t &l, int64_t &r, int64_t & ans, int64_t index, int64_t nowl,int64_t nowr) {
  if ((nowl >= l) && (nowr <= r)) {
    ans += tree[index];
  } else {
    if ((nowl <= r && l <= nowl) || (nowr >= l && nowr <= r) || (nowl <= l && nowr >= r)){
        sumsearch(tree, l, r, ans, 2*index, nowl, nowl + ((nowr - nowl) / 2));
        sumsearch(tree, l, r, ans, (2*index) + 1, nowr - ((nowr - nowl) / 2), nowr);
    }
  }
}


int main() {
  std::ifstream input ("input.txt");
  int64_t n;
  input >> n;
  int64_t a,b;
	b = pow(2,ceil(log2(n)));
  a = 2*b;
  std::vector<int64_t> tree(a,0);
  std::vector<int64_t> line(n,0);
  for (int64_t i = 0; i < n; i++) {
    input >> line[i];
  }

  for (int64_t i = b; i < a; i++) {
    if (i - b >= n) {
      tree[i] = 0;
    } else {
      tree[i] = line[i - b];
    }
  }
  for (int64_t i = b - 1; i > 0; i--) {
    tree[i] = tree[2 * i] + tree[(2 * i) + 1];
  }
  int64_t m;
  input >> m;
  int64_t type,l,r;
  for (int64_t i = 0; i < m; i++) {
    input >> type >> l >> r;
    if (type == 2) {
      tree[b + l] = r;
      for (int64_t i = b - 1; i > 0; i--) {
        tree[i] = tree[2 * i] + tree[(2 * i) + 1];
      }
    } else {
      int64_t ans = 0;
      sumsearch(tree, l, r, ans, 1, 0, b - 1);
      std::cout << ans << std::endl;
    }
  }

}