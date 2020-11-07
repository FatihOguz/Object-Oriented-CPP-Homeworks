#ifndef STUDENT_H
#define STUDENT_H
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
using namespace Administratort;
using namespace Lecturert;
using namespace Classroomss;

namespace Studentt
{



	struct studentOfCourse
	{
		int Mon[24];
		int Tues[24];
		int Wednes[24];
		int Thurs[24];
		int Fri[24];
	};

	class Student
	{
		public:
			~Student();
			Student(const Student & other);
			Student& operator=(Student& other);
			Student(){initStudentOfCourseTime();}
			int enrollCourse(Course CourseValue);
			int disenroll(Course CourseValue);
			void extractSchedule();	
			void enterClassroom(Classroom& ClassroomValue,int index,int classroom_index);	
			void quitClassroom(Classroom& ClassroomValue);


			// getter functions
			void getName()  const;
			string getName2() const;
			void getSurname()  const;
			string getSurname2() const;
			int getLevel() const	;
			int getStudentNo()  const;		
			int getRemainderLevel() const;
			int get_class_id() const	{ return class_id;}
			int get_course_id() const	{ return course_id;}
			// setter functions;
			void set_class_id(int class_id_val)	{class_id =class_id_val; }
			void set_course_id(int course_id_val)	{course_id =course_id_val; }
			void setName(string nameValue);		
			void setSurname(string surnameValue);		
			void setLevel(int LevelValue); 
			void setStudentNo(int studentNo);
			void setRemainderLevel(int remainderLevelValue);
			void initStudentOfCourseTime();	/*	RESETS THE STUDENT'S WEEKLT SCHEDULE */


			void set_attendance_vector(int data,int index);
			int get_attendance_vector_data(int index);
			int get_attendance_vector_size();
			void set_course_attendance_vector(int data,int index);
			int get_course_attendance_vector_data(int index);
			int get_course_attendance_vector_size();






		private:
			vector <int> attendance;
			vector <int> course_attendance;
			int class_id=-1;
			int course_id=-1;
			string name;
			string surname;
			int student_no;
			int level;
			int remainder_level;
			vector<int> courseId; /* which courses you take */
			studentOfCourse * studentOfCourseTime = new studentOfCourse[1]; /* which hourse you have a course*/
	};			
	void initialized_student(Student StudentPtr[],int student_size);


}

#endif