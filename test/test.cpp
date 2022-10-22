//
// Created by poilk on 2022/10/12.
//
#include <stdio.h>

int main(int argc, char *argv[]){
  char buf[1000];
  int x = 123456;
  int ret = sprintf(buf, "%uu", x);
  printf("\"%s\", ret %d, %d\n", buf, ret, x);
  printf("%d\n", -1 % 2);
  return 0;
}