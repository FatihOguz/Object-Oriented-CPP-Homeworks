#ifndef LECTURER_H
#define LECTURER_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "course.h"
#include "classroom.h"

using namespace std;

using namespace Classroomss;

namespace Lecturert
{

	class Lecturer
	{
	public:
		Lecturer();
		~Lecturer();
		Lecturer(Lecturer& other);
		Lecturer& operator=(Lecturer& other);
		/* 										GETTER FUNCTIONS (INLINE)							*/
		string get_name()										{ return name;}
		string get_surname()									{ return surname;}
		int get_personal_id()									{ return personal_id;}
		string get_title()										{ return title;}
		string get_proffesions0()								{ return proffesions0;}
		string get_proffesions1()								{ return proffesions1;}
		string get_proffesions2()								{ return proffesions2;}
		string get_proffesions3()								{ return proffesions3;}
		vector <Course> get_LectureCourses()					{ return LectureCourses;}

		/* 									SETTER FUNCTIONS (INLINE)								*/
		void set_name(string name_value)						{ name = name_value; }
		void set_surname(string surname_value)					{ surname = surname_value;}
		void set_personal_id(int personal_id_value)				{ personal_id = personal_id_value;}
		void set_title(string title_value)						{ title = title_value;}
		void set_proffesions0(string proffesions_value)			{ proffesions0= proffesions_value ;}
		void set_proffesions1(string proffesions_value)			{ proffesions1= proffesions_value ;}
		void set_proffesions2(string proffesions_value)			{ proffesions2= proffesions_value ;}
		void set_proffesions3(string proffesions_value)			{ proffesions3= proffesions_value ;}

		
		/* 										OTHER FUNCTIONS										*/

		Course proposeCourse(Course courses[],Course temp,int courses_size);		
		Course  assignCourse(Course courses[] ,Course temp,int courses_size);
		void assignCourse(Course temp);
		vector <Course> LectureCourses;
	private:
		string name;
		string surname;
		int personal_id;
		string title;
		string proffesions0;
		string proffesions1;
		string proffesions2;
		string proffesions3;
		
	};
	static vector <Course> courses;
	void initialized_courses_and_classrooms(Course courses[],int courses_size,Classroom classrooms[],int classrooms_size);
	void initialized_lecturer(Lecturer lecturers[],int lecturer_size);
	int min(int arr[],int size);
	
}


#endif

