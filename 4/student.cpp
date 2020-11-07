#include "student.h"
#include "classroom.h"

namespace Studentt
{
	

	Student::Student(const Student & other)			/* copy constructor */
	{
		/* shallow copy variables */
		setName( other.getName2() );
		setSurname ( other.getSurname2() );
		setLevel(other.getLevel()); 
		setStudentNo(other. getStudentNo());
		setRemainderLevel(other.getRemainderLevel());

		/* deep copy courseId vector */
		for(int i=0;i<other.courseId.size();i++)
		{
			if(courseId.size()>=i)
			{
				courseId[i]=other.courseId[i];
			}
			else
			{
				courseId.push_back(other.courseId[i]);
			}
		}
		for(int i=0;i<other.attendance.size();i++)
		{
			if(attendance.size()>=i)
			{
				attendance[i]=other.attendance[i];
			}
			else
			{
				attendance.push_back(other.attendance[i]);
			}
		}
		for(int i=0;i<other.course_attendance.size();i++)
		{
			if(course_attendance.size()>=i)
			{
				course_attendance[i]=other.course_attendance[i];
			}
			else
			{
				course_attendance.push_back(other.course_attendance[i]);
			}
		}

	
		for(int i=0;i<24;i++)				/* deep copy studentofCourseTime struct */
		{
			studentOfCourseTime->Mon[i]=other.studentOfCourseTime[0].Mon[i];
			studentOfCourseTime->Tues[i]=other.studentOfCourseTime[0].Tues[i];
			studentOfCourseTime->Wednes[i]=other.studentOfCourseTime[0].Wednes[i];
			studentOfCourseTime->Thurs[i]=other.studentOfCourseTime[0].Thurs[i];
			studentOfCourseTime->Fri[i]=other.studentOfCourseTime[0].Fri[i];
		}
	}

	Student::~Student()			/* DESTRUCTOR */
	{
		//cout<<"Called Destructor for Student class"<<endl;
		delete []studentOfCourseTime;			/* struct delete */
		courseId.clear();					/* clear vector */
		attendance.clear();
		course_attendance.clear();

	}

	Student& Student::operator=(Student& other)
	{
		/* shallow copy variables */
		setName( other.name );
		setSurname ( other.surname);
		setLevel(other.level); 
		setStudentNo(other. student_no);
		setRemainderLevel(other.getRemainderLevel());
			/* deep copy courseId vector */
		for(int i=0;i<other.courseId.size();i++)
		{
			if(courseId.size()>=i)
			{
				courseId[i]=other.courseId[i];
			}
			else
			{
				courseId.push_back(other.courseId[i]);
			}
		}
		for(int i=0;i<other.attendance.size();i++)
		{
			if(attendance.size()>=i)
			{
				attendance[i]=other.attendance[i];
			}
			else
			{
				attendance.push_back(other.attendance[i]);
			}
		}
		for(int i=0;i<other.course_attendance.size();i++)
		{
			if(course_attendance.size()>=i)
			{
				course_attendance[i]=other.course_attendance[i];
			}
			else
			{
				course_attendance.push_back(other.course_attendance[i]);
			}
		}

	
		for(int i=0;i<24;i++)	/* deep copy studentofCourseTime struct */
		{
			studentOfCourseTime->Mon[i]=other.studentOfCourseTime[0].Mon[i];
			studentOfCourseTime->Tues[i]=other.studentOfCourseTime[0].Tues[i];
			studentOfCourseTime->Wednes[i]=other.studentOfCourseTime[0].Wednes[i];
			studentOfCourseTime->Thurs[i]=other.studentOfCourseTime[0].Thurs[i];
			studentOfCourseTime->Fri[i]=other.studentOfCourseTime[0].Fri[i];
		}

		return *this;
	} 

	void Student::getName() const
	{
		 cout << name;  
	}
	string Student::getName2() const
	{
		return name;
	}
	string Student::getSurname2() const
	{
		return surname;
	}

	void Student::getSurname() const
	{
		 cout << surname;  
	}

	int Student::getLevel() const
	{
		 return level; 
	}
	 int Student::getStudentNo() const
	 {
	  return student_no; 
	 }
	int Student::getRemainderLevel() const
	{
	 	return remainder_level; 
	}
	/********************************************SETTER FUNCTIONS****************************************************************************************/
	void Student::setName(string nameValue)
	{
		 name = nameValue;
	}
	void Student::setSurname(string surnameValue)
	{
		surname=surnameValue ;
	}
	void Student::setLevel(int levelValue)
	{
		level=levelValue;
		remainder_level = level + 19;
	}
	void Student::setStudentNo(int studentNo)
	{
		student_no=studentNo;
	}
	void Student::setRemainderLevel(int remainderLevelValue)
	{
		remainder_level=remainderLevelValue;
	}



	/**************************************************************ENTER CLASSROOM*********************************************************/
	void Student::enterClassroom(Classroom& ClassroomValue,int index,int classroom_index)
	{
		ClassroomValue.set_student_in_room(ClassroomValue.get_student_in_room() + 1) ; /* update attendance */
		int k=get_attendance_vector_data(index+1);

		set_attendance_vector(k+1,index+1);
		class_id=classroom_index;
		cout<<ClassroomValue.get_student_in_room()<<" (student in room)"<<endl;
	}
	/********************************************************QUIT CLASSROOM******************************************************************/
	void Student::quitClassroom(Classroom& ClassroomValue)
	{
		ClassroomValue.set_student_in_room(ClassroomValue.get_student_in_room() - 1) ;			/* update attendance */
		class_id=-1;
		cout<<ClassroomValue.get_student_in_room()<<" (student in room)"<<endl;	
	}




	/* SONRADAN EKLENENLER **************************************************************************************************************/


	void Student::initStudentOfCourseTime()
	{
		int j;			/* initialize struct */
		for(j=0;j<24;j++)
		{
			studentOfCourseTime->Mon[j]=0;
			studentOfCourseTime->Tues[j]=0;
			studentOfCourseTime->Wednes[j]=0;
			studentOfCourseTime->Thurs[j]=0;
			studentOfCourseTime->Fri[j]=0;
		}
	}



	void initialized_student(Student StudentPtr[],int student_size)
	{
		ifstream inputStream;
		inputStream.open("student.txt");	
		string arr;
		string sName,sSurname;
		int sNo,sLevel;
		Student * temp;
		int index=1;			
		int studentSize=0;
		int i=0;
		/* initialize student */
		for(studentSize=0;studentSize<student_size;studentSize++)
		{
				getline(inputStream,arr);
				istringstream some_stream(arr);
				some_stream>>sName>>sSurname>>sNo>>sLevel;
				StudentPtr[studentSize].setName(sName);
				StudentPtr[studentSize].setSurname(sSurname);
				StudentPtr[studentSize].setStudentNo(sNo);
				StudentPtr[studentSize].setLevel(sLevel);			
		}
		inputStream.close();


	}

	void Student::set_attendance_vector(int data,int index)
	{
		if(index>attendance.size())
		{
			attendance.resize(index+1);
			attendance[index]=data;
		}
		else
		{
			attendance[index]=data;
		}
	}
	int Student::get_attendance_vector_data(int index)
	{
		if(index<attendance.size())
		{
			return attendance[index];
		}
	}
	int Student::get_attendance_vector_size()
	{
		return attendance.size();
	}
	void Student::set_course_attendance_vector(int data,int index)
	{
		if(index>course_attendance.size())
		{
			course_attendance.resize(index+1);
			course_attendance[index]=data;
		}
		else
		{
			course_attendance[index]=data;
		}
	}
	int Student::get_course_attendance_vector_data(int index)
	{
		if(index<course_attendance.size())
		{
			return course_attendance[index];
		}
	}
	int Student::get_course_attendance_vector_size()
	{
		return course_attendance.size();
	}




}/* end namespace */



