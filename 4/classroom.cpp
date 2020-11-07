#include "classroom.h"

namespace Classroomss
{
	Classroom::Classroom()
	{

		//cout<<"Called No parameter Constructor for Classroom class"<<endl;
	}
	Classroom::Classroom(Classroom & other)			/*	Copy Constructor */
	{
		set_id(other.get_id());
		set_classNo(other.get_classNo());
		set_capacity(other.get_capacity());
		set_student_in_room(other.get_student_in_room());
		set_flag(other.get_flag());

		for(int i=0;i<9;i++)
		{
			available->pzt[i]=other.available->pzt[i];
			available->sal[i]=other.available->sal[i];
			available->car[i]=other.available->car[i];
			available->per[i]=other.available->per[i];
			available->cum[i]=other.available->cum[i];
		}
	}
	Classroom::~Classroom()
	{
		//cout<<"Called Destructor for Classroom class"<<endl;
		delete []	available;
	}

	Classroom& Classroom::operator=(Classroom& other)
	{
		set_id(other.get_id());
		set_classNo(other.get_classNo());
		set_capacity(other.get_capacity());
		set_student_in_room(other.get_student_in_room());
		set_flag(other.get_flag());

		for(int i=0;i<9;i++)
		{
			available->pzt[i]=other.available[0].pzt[i];
			available->sal[i]=other.available[0].sal[i];
			available->car[i]=other.available[0].car[i];
			available->per[i]=other.available[0].per[i];
			available->cum[i]=other.available[0].cum[i];
		}
		//return *this;
	}
}