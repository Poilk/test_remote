//
// Created by 文欣 on 2022/5/9.
//

#ifndef CPP_FILES_ALGORITHM_TEMPLATE_COMMON_H_
#define CPP_FILES_ALGORITHM_TEMPLATE_COMMON_H_

#include <cstdio>
#include <algorithm>

template<typename T>
void chose_max(T &a,  const T b){
  a = std::max(a, b);
}
template<typename T>
void chose_min(T &a,  const T b){
  a = std::min(a, b);
}

#endif //CPP_FILES_ALGORITHM_TEMPLATE_COMMON_H_
