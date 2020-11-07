#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "course.h"
#include "classroom.h"
#include "lecturer.h"
#include "administrator.h"
#include "student.h"


using namespace std;
using namespace Administratort;
using namespace Lecturert;
using namespace Classroomss;

using namespace Studentt;

void test(Classroom classrooms[],int classrooms_size,Course courses[] ,int courses_size,Lecturer lecturers[],int lecturer_size,Administrator administrator,Student StudentPtr[],int student_size);

#endif