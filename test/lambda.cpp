//
// Created by 文欣 on 2022/5/10.
//
#include <algorithm>

int main(int argc, char *argv[]) {
  const int maxn = 10;
  int a[maxn][maxn];
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      a[i][j] = std::max(i, j);
    }
  }
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      printf("%d ", a[i][j]);
    }
    puts("");
  }
  int dst_i, dst_j;
  auto get_ref = [&]() -> int & { return a[dst_i][dst_j]; };
  for (int i = 0; i < maxn; i++) {
    dst_i = i;
    for (int j = 0; j < maxn; j++) {
      dst_j = j;
      get_ref() = std::min(i, j);
    }
  }
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      printf("%d ", a[i][j]);
    }
    puts("");
  }
  auto get_max = [](int x, int y) {return std::max(x, y);};
  std::function<int(int,int)> fun_max = get_max;
  return 0;
}