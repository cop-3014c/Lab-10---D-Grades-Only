/** Header file for grades.cpp. Do not alter this file.
@file grades.h
@author Hong Tai Wei
*/

#ifndef GRADES_H
#define GRADES_H

/// Max number of students allowed in the gradebook.
const int MAX_S = 20;

/// Max number of homework assignments allowed in the gradebook.
const int MAX_HW = 20;

int student_average(const int grades[MAX_S][MAX_HW], int n_students, int n_hws,
                    int student_id);

int top_score_student(const int grades[MAX_S][MAX_HW], int n_students,
                      int n_hws);

#endif  // GRADES_H
