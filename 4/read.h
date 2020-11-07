#ifndef READ_H
#define READ_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "classroom.h"
#include "administrator.h"
#include "lecturer.h"
#include "student.h"

using namespace std;
using namespace Administratort;
using namespace Lecturert;
using namespace Classroomss;
using namespace Studentt;

void read_courses_and_classrooms(int& num1,int& num2);
void read_lecturers(int& num1);
void read_students(int & student_size);

#endif