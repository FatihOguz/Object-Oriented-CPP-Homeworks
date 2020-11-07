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

using namespace std;


void test(vector <Classroom> classrooms,int classrooms_size,vector <Course> courses ,int courses_size,vector <Lecturer> lecturers,int lecturer_size,Administrator administrator);

#endif