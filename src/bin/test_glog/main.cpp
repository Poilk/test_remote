//
// Created by poilk on 2022/6/28.
//
#include <glog/logging.h>

int main(int argc, char *argv[]){
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = true;

  LOG(FATAL) << "Found " << "fuck2 " << " cookies";
  return 0;
}
