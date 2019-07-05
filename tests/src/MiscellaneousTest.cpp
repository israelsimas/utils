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
  CHECK_EQUAL(0,  msleep(100));
  CHECK_EQUAL(0,  msleep(0));
  CHECK_EQUAL(-1, msleep(-1));
  CHECK_EQUAL(0, msleep(5000));
}
