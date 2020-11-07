#ifndef CLASSROOM_H
#define CLASSROOM_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;


namespace Classroomss
{
	struct Date
	{
		int pzt[9];		/* 0. day */
		int sal[9];		/* 1. day */
		int car[9];		/* 2. day */
		int per[9];		/* 3. day */
		int cum[9];		/* 4. day */
	};
	class Classroom
	{

	public:
		Classroom& operator=(Classroom& other);
		~Classroom();
		Classroom();
		Classroom(Classroom & other);	
		int get_id()				{return id;}
		string get_classNo()		{return classNo;}
		int get_capacity()			{return capacity;}
		int get_student_in_room()	{return student_in_room;}
		//get_available
		int get_flag()				{return flag;}

		/* SETTERS   */
		void set_id(int id_value)							{id=id_value;}
		void set_classNo(string classNoValue)				{classNo=classNoValue;}
		void set_capacity(int c)							{capacity=c;}
		void set_student_in_room(int sir)					{student_in_room=sir;}
		void set_flag(int f)								{flag=f;}


		Date * available = new Date[1];
	private:
		int id;
		string classNo;
		int capacity;
		int student_in_room;
		int flag=0;
		
	};

}

#endif