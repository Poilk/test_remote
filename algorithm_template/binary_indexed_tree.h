//
// Created by 文欣 on 2022/5/9.
//

#ifndef CPP_FILES_ALGORITHM_TEMPLATE_BINARY_INDEXED_TREE_H_
#define CPP_FILES_ALGORITHM_TEMPLATE_BINARY_INDEXED_TREE_H_

#include <cstdio>
#include <array>

template<typename Data, int N>
class BinaryIndexedTree{
 public:
  int lowbit(int x) {return x & -x;}
  Data query(int idx){
    Data res = 0;
    for(;idx; idx -= lowbit(idx)){
      //update res
    }
    return res;
  }
  void update(int idx, Data value){
    for(;idx < N;idx += lowbit(idx)){
      //update v
    }
  }
 private:
  std::array<Data, N> v{};
};

#endif //CPP_FILES_ALGORITHM_TEMPLATE_BINARY_INDEXED_TREE_H_
