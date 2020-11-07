#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "course.h"
#include "classroom.h"


using namespace std;
using namespace Classroomss;


namespace Administratort
{
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
		Classroom& arrangeClassroom(Classroom classrooms[],int classrooms_size,Course courses[],int courses_size,Classroom crm, Course crs);
		Course arrangeTimeTable(Course courses[] , int courses_id,int courses_size);
		Administrator& operator=(Administrator& other );
		~Administrator();
		Administrator(Administrator& admin);
		Administrator(){
			//cout<<"called no parameter constructor for Administrator"<<endl;
		}
	private:
		int pid; /* personal id of lecturer */
		int password;
	};
}

#endif