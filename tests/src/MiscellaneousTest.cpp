/**************************************************************************
 *
 * UtilsTest.cpp
 *
 *    Miscellaneous test
 *
 * Copyright 2018 Intelbras
 *
 **************************************************************************/

#include "CppUTest/TestHarness.h"
extern "C" {
  #include "utils.h"
}
 
TEST_GROUP(Utils) {

  void setup() {
    
  }

  void teardown() {
    
  }

};
 
TEST(Utils, Millisleep) {
  CHECK_EQUAL(0,  u_msleep(100));
  CHECK_EQUAL(0,  u_msleep(0));
  CHECK_EQUAL(-1, u_msleep(-1));
  CHECK_EQUAL(0, u_msleep(5000));
}
