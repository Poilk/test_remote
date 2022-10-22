//
// Created by 文欣 on 2022/5/11.
//

#ifndef CPP_FILES_ALGORITHM_TEMPLATE_UNIONFIND_H_
#define CPP_FILES_ALGORITHM_TEMPLATE_UNIONFIND_H_

#include <array>

template<int N>
class UnionFind{
 public:
  UnionFind(){
    for(int i = 0; i < parent.size(); i++){
      parent[i] = i;
      size[i] = 1;
    }
  };
  int find(int x){
    while(x != parent[x]){
      parent[x] = find(parent[x]);
    }
    return x;
  }
  void merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
      if(size[fx] > size[fy]){
        parent[fy] = fx;
        size[fx] += size[fy];
      } else{
        parent[fx] = fy;
        size[fy] += size[fx];
      }
    }
  }
  std::array<int, N> parent;
  std::array<int, N> size;
};

#endif //CPP_FILES_ALGORITHM_TEMPLATE_UNIONFIND_H_
