//
// Created by 文欣 on 2022/6/12.
//

#ifndef CPP_FILES_SRC_BIN_TEXT_TEMPLATE_T_H_
#define CPP_FILES_SRC_BIN_TEXT_TEMPLATE_T_H_

#include <memory>
#include <vector>

template <typename T>
class S;

class PD;
class TPD{
 public:
  PD* pd;
  int x;
  int y;
};


class Example{
 public:
  //static double reate = 6.5;
  static const int vecSize = 20;
  static std::vector<double> vec(vecSize);
};

#endif //CPP_FILES_SRC_BIN_TEXT_TEMPLATE_T_H_
