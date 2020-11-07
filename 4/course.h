#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>


using namespace std;
struct Dates
{
	int pzt[12];		/* 0. day */
	int sal[12];		/* 1. day */
	int car[12];		/* 2. day */
	int per[12];		/* 3. day */
	int cum[12];		/* 4. day */
};
struct Course
{
	int pid;
	int id;
	string name;
	int code;
	int credit;
	int totalHours;
	Dates lecturerDates;
	string sDate1;
	string sDate2;
	int sHourStart1;
	int sHourStart2;
	int sHourFinish1;
	int sHourFinish2;
	int timetable=0;
	string field;
	int isMandatory;
	int lec;
	string classroomNo;
};

#endif