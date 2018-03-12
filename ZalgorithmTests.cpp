#include "Zalgorithm.h"
#include "gtest/gtest.h"

#include <string>

using testing::Test;

// Testing MatchLength calculation when no matches occur
TEST(MatchLengthTest, NoMatchTest) {
  // TODO: Implement this
  std::string String_to_test = " nomatch";  // start at index 1

  // indexes for begining of the string and the position of the string to be matched
  short start_pt = 1;
  short present_pt = 3;

  EXPECT_EQ(MatchLength(String_to_test, start_pt, present_pt), 0);
}

// Testing MatchLength calculation when geginning of string matches
TEST(MatchLengthTest, BeginningStringMatch) {
  // TODO: Implement this
  std::string String_to_test = " testtest$"; // start at index 1

  // indexes for begining of the string and the position of the string to be matched
  short start_pt = 1;
  short present_pt = 5;

  EXPECT_EQ(MatchLength(String_to_test, start_pt, present_pt), 4);
}

// Testing MatchLength calculation when middle of the string matches
TEST(MatchLengthTest, MidStringMatch) {
  // TODO: Implement this

  std::string String_to_test = " testingting$"; // start at index 1

  // indexes for begining of the string and the position of the string to be matched
  short start_pt = 4;
  short present_pt = 8;

  EXPECT_EQ(MatchLength(String_to_test, start_pt, present_pt), 4);
}

// Testing MatchLength calculation when match stops at end of string
TEST(MatchLengthTest, EndOfStringMatch) {
  // TODO: Implement this

  std::string String_to_test = " teststringteststring"; // start at index 1

  // indexes for begining of the string and the position of the string to be matched
  short start_pt = 1;
  short present_pt = 11;

  EXPECT_EQ(MatchLength(String_to_test, start_pt, present_pt), 10);
}

// Testing Zalgorithm calculation with string S = " aabcaabxaaz", p.7 Gusfield
TEST(ZalgorithmTest, GusfieldExamplePageSeven) {
  // TODO: Implement this. Check only values given in the text

  std::string String_to_test = " aabcaabxaaz"; // start at index 1


  std::vector<int> Zval;

  // Run the ZAlgorithm on the given string
  Zalgorithm(String_to_test, &Zval);
  // Expected output values
  int output_expt[] = {0, 0, 1, 0, 0, 3, 1, 0, 0, 2, 1, 0};
  int index = 0;
  // check if each value in Zval is as expected
  while(index < Zval.size()){
    EXPECT_EQ(Zval[index], output_expt[index]);
    index++;
  }
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

