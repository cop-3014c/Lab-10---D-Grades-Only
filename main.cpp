/** Driver for gradebook program. Do not alter this file.
@file main.cpp
@author Hong Tai Wei
*/

#include <ios>
#include <iostream>
#include <limits>
#include "grades.h"
using namespace std;

/**
@brief Main function for gradebook program

Prompts user for number of students and hws, then prompts for inputs 1 row at a
time. Prints out student averages and top scoring student.

@return Exit code 0
*/
int main() {
  int grades[MAX_S][MAX_HW];
  int students, hws;

  do {
    cout << "Enter the number of students (1-20):" << endl;
    cin >> students;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (students < 1 || students > 20);

  do {
    cout << "Enter the number of homework assignments (1-20):" << endl;
    cin >> hws;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (hws < 1 || hws > 20);

  for (int i = 0; i < students; i++) {
    cout << "Enter the grades for Student " << i
         << ", separated by spaces:" << endl;
    for (int j = 0; j < hws; j++) {
      cin >> grades[i][j];
    }
  }

  for (int i = 0; i < students; i++) {
    cout << "Student " << i
         << "'s average grade is: " << student_average(grades, students, hws, i)
         << endl;
  }

  cout << "The student with the highest average grade is Student "
       << top_score_student(grades, students, hws) << endl;

  return 0;
}
