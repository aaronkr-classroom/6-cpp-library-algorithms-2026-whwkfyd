#pragma once

#ifndef GUARD_grade.h
#define GUARD_grade_h

#include <vector>
#include <list>
#include "Student_info.h"

using std::vector;
using std::list;

double grade(double, double, const vector<double>&);
double grade(double, double, double);
double grade(const Student_info&);

bool fgrade(const Student_info&);
bool pgrade(const Student_info&);
bool did_all_hw(const Student_info&);

vector<Student_info> extract_fails(vector < Student_info>&);
list<Student_info> extract_fails(list < Student_info>&);


#endif 

