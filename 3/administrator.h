#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "course.h"
#include "classroom.h"
#include "lecturer.h"

using namespace std;
class Administrator
{
public:
	/*									GETTER FUNCTIONS (INLINE) 									*/
	int  get_pid()											{ return pid;}
	int get_password()										{ return password;}
	/*									SETTER FUNCTIONS (INLINE)									*/
	void set_pid(int pid_value)								{ pid = pid_value;}
	void set_password(int password_value)					{ password = password_value;}
	/*										OTHER FUNCTIONS											*/
	Classroom arrangeClassroom(vector <Classroom> classrooms,int classrooms_size,vector <Course> courses,int courses_size,Classroom crm, Course crs);
	Course arrangeTimeTable(vector<Course> courses , int courses_id);
private:
	int pid; /* personal id of lecturer */
	int password;
};


#endif