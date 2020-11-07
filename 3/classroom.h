#ifndef CLASSROOM_H
#define CLASSROOM_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
struct Date
{
	int pzt[9];		/* 0. day */
	int sal[9];		/* 1. day */
	int car[9];		/* 2. day */
	int per[9];		/* 3. day */
	int cum[9];		/* 4. day */
};
struct Classroom
{
	int id;
	string classNo;
	int capacity;
	int student_in_room;
	Date available;
	int flag=0;
};

#endif