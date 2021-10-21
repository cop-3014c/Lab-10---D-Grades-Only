/** Test cases for functions defined in grades.h
@file grades_test.cpp
@author YOUR NAME HERE
*/
// TODO: Fill in your name above.

#include "grades.h"
#include <gtest/gtest.h>
using namespace std;

class GradesTest : public ::testing::Test {
 protected:
  // TODO: Change these values to write your test case.
  int grades[MAX_S][MAX_HW] = {0};
  int n_students = 0;
  int n_hws = 0;
  int expected_averages[MAX_S] = {0};
  int expected_top_students[MAX_S] = {0};
  int expected_hw_stats[MAX_HW][4] = {0};
  // Don't change anything below this line.
};

TEST_F(GradesTest, StudentAverageTest) {
  for (int i = 0; i < n_students; i++) {
    EXPECT_EQ(student_average(grades, n_students, n_hws, i),
              expected_averages[i])
        << "Where i = " << i;
  }
}

TEST_F(GradesTest, TopScoreStudentTest) {
  int top_score_id = top_score_student(grades, n_students, n_hws);

  bool in_list = false;
  for (int i = 0; i < n_students && (i == 0 || expected_top_students[i - 1] <
                                                   expected_top_students[i]);
       i++) {
    if (top_score_id == expected_top_students[i]) in_list = true;
  }
  if (!in_list)
    FAIL() << "top_score_student(grades, " << n_students << ", " << n_hws
           << ") had value " << top_score_id
           << " which was not in expected_top_students";
}

TEST_F(GradesTest, HwStatsTest) {
  int min, max, med, avg;
  for (int i = 0; i < n_hws; i++) {
    min = -1;
    max = -1;
    med = -1;
    avg = -1;
    hw_stats(grades, n_students, n_hws, i, min, max, med, avg);
    if (min != expected_hw_stats[i][0] || max != expected_hw_stats[i][1] ||
        med != expected_hw_stats[i][2] || avg != expected_hw_stats[i][3]) {
      ADD_FAILURE() << "      Expected: hw_stats(grades, " << n_students << ", "
                    << n_hws << ", " << i
                    << ", min, max, med, avg)\n      Which is: min = " << min
                    << ", max = " << max << ", med = " << med
                    << ", avg = " << avg << "\n"
                    << "To be equal to: expected_hw_stats[" << i << "]\n";
    }
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return 0;
}
