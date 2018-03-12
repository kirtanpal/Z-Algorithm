#include "BoyerMoore.h"
#include "gtest/gtest.h"

using testing::Test;

#include <algorithm>
#include <random>
#include <string>

#define NUM_TEST_CASES 10000
#define RANDOM_STRING_SIZE 100

const std::string Sigma = "abcdefghijklmnopqrstuvwxyz";
// Sanity check for BoyerMoore.
// Does NUM_TEST_CASES times:
//    1) Generate random string T of size RANDOM_STRING_SIZE
//    2) Generate a random substring P of T
//    3) Runs BoyerMoore and checks there is at least one match
// Use <random> & uniform_int_distribution for your random number generation

TEST(BoyerMooreSanityCheck, SubstringmatchesListInRandomString) {
  // TODO: Implement this
  std::default_random_engine randomGenerator;
  std::uniform_int_distribution<int> substring(1, RANDOM_STRING_SIZE);
  std::uniform_int_distribution<int> letters(0, 25);

  std::list<int> matchesList;
  std::string P, T;

  int i=0;

  while(i < NUM_TEST_CASES) {
    T = " ";
    int j = 0;
    while(j < RANDOM_STRING_SIZE) {
      T.push_back('a' + letters(randomGenerator));
      j++;
    }

    int begining = substring(randomGenerator);
    int last = substring(randomGenerator);
    if (begining > last)
    {
      int temp = begining;
      begining = last;
      last = temp;
    }

    P = " ";
    P += T.substr(begining, last);
    BoyerMoore(P, T, Sigma, &matchesList);
    ASSERT_GE(matchesList.size(), 1);
    i++;
  }
}

int main(int argc, char** argv) {
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
