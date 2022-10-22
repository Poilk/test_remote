//
// Created by 文欣 on 2022/5/9.
//

#include "binary_indexed_tree.h"
#include <vector>


template<typename Data, int N>

// test
int main(int argc, char *argv[]){
  using namespace std;
  BinaryIndexedTree<int, 2010> bit_tree;
  std::vector<std::pair<int, int>> arr{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  std::vector<std::vector<int>> ans(arr.size());
  std::sort(arr.begin(), arr.end());
  int count = 0;
  for(int i = 0; i < arr.size(); i++){
    if(i && arr[i].first == arr[i-1].first){
      ++count;
    } else{
      count = 0;
    }
    int find_empty = arr[i].second - count;
    int l = 1, len = arr.size() + 1;
    while(len){
      int half = len >> 1;
      int cur = l + half;
      int count_1 = bit_tree.query(cur);
      if(cur - count_1 <= find_empty){
        l = l + half + 1;
        len = len - half - 1;
      } else{
        len = half;
      }
    }
    ans[l-1] = {arr[i].first, arr[i].second};
    bit_tree.update(l, 1);
  }
  return 0;
}