#include <iostream>
#include <cstdlib>//exit
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
struct studentOfCourse
{
	int Mon[24];
	int Tues[24];
	int Wednes[24];
	int Thurs[24];
	int Fri[24];
};
struct Course
{
	int id;
	string name;
	int code;
	int credit;
	int totalHours;
	string lectureDates;
/*************down variables about lectureDates****************************/
	string firstDay;
	int firstDay_start;
	int firstDay_finish;

	string secondDay;
	int secondDay_start;
	int secondDay_finish;

	string thirdDay;
	int thirdDay_start;
	int thirdDay_finish;
	
	int field;
};
struct Classroom
{
	int id;
	string c_no;
	int capacity;
	int student_inroom;

};
class Student
{
public:
	Student(){initStudentOfCourseTime();}
	int enrollCourse(Course CourseValue);
	int disenroll(Course CourseValue);
	void extractSchedule();	
	void enterClassroom(Classroom& ClassroomValue);	
	void quitClassroom(Classroom& ClassroomValue);

	// getter functions
	inline void getName()  const;
	inline string getName2() const;
	inline void getSurname()  const;
	inline string getSurname2() const;
	inline int getLevel() const	;
	inline int getStudentNo()  const;		
	inline int getRemainderLevel() const;
	
	// setter functions;
	inline void setName(string nameValue);		
	inline void setSurname(string surnameValue);		
	inline void setLevel(int LevelValue); 
	inline void setStudentNo(int studentNo);
	inline void setRemainderLevel(int remainderLevelValue);
	void initStudentOfCourseTime();	/*	RESETS THE STUDENT'S WEEKLT SCHEDULE */
private:
	string name;
	string surname;
	int student_no;
	int level;
	int remainder_level;
	vector<int> courseId; /* which courses you take */
	studentOfCourse studentOfCourseTime; /* which hourse you have a course*/
};

/* GLOBAL FUNCTIONS */
void printCourseIdAndName(Course courseArray[],int course_size);
void dates(Course CoursePtr[],int course_size);


int main()
{
	int count=1;
	
	int flag=1;	//false;
	int i,j,k,l;
	Student *StudentPtr = new Student[1];
	Student *temp=new Student[1];
	int index = 2;
	int studentSize=0;
	int remainderLevelValue;
	

	int course_size=0;
	int class_size=0;
	string c1,array;

	
	fstream inputStream;
	ofstream outputStream;

	/****************************************THİS FIND course_size and class_size******************************************/
	inputStream.open("courses_classrooms.txt");
	inputStream>>c1;


	while(!inputStream.eof())
	{
		inputStream>>c1;
		if(c1=="CLASSROOMS")
		{
			flag=0;
		}
		else if(flag==1)
		{
			course_size+=1;
		}
		else
		{
			class_size+=1;
		}
	}
	course_size/=6;
	class_size/=3;
	inputStream.close();
	
/****************************************THİS FIND course_size and class_size******************************************/


/**********************************FILLS COURSE AND CLASS STRUCT THAN FILE************************************************************/
	Course *CoursePtr=new Course[course_size];
	Classroom *ClassroomPtr=new Classroom[class_size];

	inputStream.open("courses_classrooms.txt");

	inputStream >> c1 ;
	for(i=0;i<course_size;i++)
	{
		inputStream>>CoursePtr[i].id ; 
		inputStream>>CoursePtr[i].name;
		inputStream>>CoursePtr[i].code;
		inputStream>>CoursePtr[i].credit;
		inputStream>>CoursePtr[i].totalHours;
		inputStream>>CoursePtr[i].lectureDates;
	}
	inputStream >> c1 ;
	for(i=0;i<class_size;i++)
	{
		inputStream>>ClassroomPtr[i].id ; 
		inputStream>>ClassroomPtr[i].c_no ;
		inputStream>>ClassroomPtr[i].capacity; 	
		ClassroomPtr[i].student_inroom=ClassroomPtr[i].capacity; 
	}

/**********************************FILLS COURSE AND CLASS STRUCT THAN FILE************************************************************/

	dates(CoursePtr,course_size); /* FİXED lectureDates (this is Course struct variable )*/



/****************************************************MENU****************************************************************************/
	string sName,sSurname;
	int sNo,sLevel;
	int test=0;

		outputStream.open("file.txt");
	/* GET A COMMAND FROM THE KEYBOARD*/
	while(1==1)
	{
		if(test==0)
		{
			c1="-ns Murat Boz 111 4";
		}
		else if(test==1)
		{
			c1="-ns Seda Akyol 112 1";
		}
		else if(test==2)
		{
			c1="-ns Zafer Çalış 113 2";
		}
		else if(test==3)
		{
			c1="-list";
		}
		else if(test==4)
		{
			c1="-e 111 1";
		}
		else if(test==5)
		{
			c1="-e 111 4";
		}
		else if(test==6)
		{
			c1="-e 111 8";
		}
		else if(test==7)
		{
			c1="-e 111 5";
		}
		else if(test==8)
		{
			c1="-e 112 6";
		}
		else if(test==9)
		{
			c1="-e 113 3";
		}
		else if(test==10)
		{
			c1="-de 111 4";
		}
		else if(test==11)
		{
			c1="-de 111 4";
		}
		else if(test==12)
		{
			c1="-de 112 6";
		}

		else if(test==13)
		{
			c1="-o 111";
		}
		else if(test==14)
		{
			c1="-o";
		}
		
		else if(test==15)
		{
			c1="-o -f file.txt";
		}
		else if(test==16)
		{
			c1="-o -f 113 file.txt";
		}
		else if(test==17)
		{
			c1="-o -f 112 file.txt";
		}
		else if(test==18)
		{
			c1="-o -f 111 file.txt";
		}

		else
		{
			exit(1);
		}
				
		cout<<c1<<endl;
		if(c1=="exit")
		{
			exit(1);
		}
/***************************************************OUTPUTS COMMAND*******************************************/
		else if(c1=="-o")
		{
			for(i=0;i<studentSize;++i)
			{
				StudentPtr[i].getName();
				cout<<" ";
				StudentPtr[i].getSurname();
				cout<<": [] total credits:" << (StudentPtr[i].getLevel() + 19) - StudentPtr[i].getRemainderLevel() 
					 << "  credit right: " << StudentPtr[i].getRemainderLevel()  << endl ; 	
			}
		}

		else if(c1[1]=='o' && c1[3]>='0' && c1[3]<='9')
		{
			istringstream some_stream(c1);
			some_stream>>array>>sNo;
			for(i=0;i<studentSize;i++)
			{
				if(sNo==StudentPtr[i].getStudentNo() )
				{
					StudentPtr[i].getName();
					cout<<" ";
					StudentPtr[i].getSurname();
					cout<<": [] total credits:" << (StudentPtr[i].getLevel() + 19) - StudentPtr[i].getRemainderLevel() 
					 << "  credit right: " << StudentPtr[i].getRemainderLevel()  << endl ;
				}
			}
		}
		else if (c1[1]=='o' && c1[4]>='f' && c1[6]>='0' && c1[6]<='9')
		{
			istringstream some_stream(c1);
			some_stream>>c1 >>array>>sNo;			
			for(i=0;i<studentSize;i++)
			{
				if(sNo == StudentPtr[i].getStudentNo())
				{
					outputStream<<StudentPtr[i].getName2();
					outputStream<<" ";
					outputStream<<StudentPtr[i].getSurname2();
				    outputStream<<": [] total credits:" << (StudentPtr[i].getLevel() + 19) - StudentPtr[i].getRemainderLevel() 
				    << "  credit right: " << StudentPtr[i].getRemainderLevel()  << endl ;
				}
			}
		}

		else if(c1[1]=='o' && c1[4]=='f')
		{
			istringstream some_stream(c1);
			some_stream>>array>>sNo;			
			for(i=0;i<studentSize;i++)
			{
					outputStream<<StudentPtr[i].getName2();
					outputStream<<" ";
					outputStream<<StudentPtr[i].getSurname2();
				    outputStream<<": [] total credits:" << (StudentPtr[i].getLevel() + 19) - StudentPtr[i].getRemainderLevel() 
				    << "  credit right: " << StudentPtr[i].getRemainderLevel()  << endl ;
			}
		}

/*****************************************************NEW STUDENT COMMAND****************************************************/
		else if(c1[1]=='n' && c1[2]=='s')
		{
			istringstream some_stream(c1);
			some_stream>>c1>>sName>>sSurname>>sNo>>sLevel;
			StudentPtr[studentSize].setName(sName);
			StudentPtr[studentSize].setSurname(sSurname);
			StudentPtr[studentSize].setStudentNo(sNo);
			StudentPtr[studentSize].setLevel(sLevel);
			
			temp = new Student[index];
			i=0;
			while(i<index - 1)
			{
				temp[i]=StudentPtr[i];
				i++;
			}
			StudentPtr = temp;
			index++;
			studentSize++;
		}
/************************************************************ENROLL COMMAND*******************************************/
		else if(c1[1]=='e')
		{
			istringstream some_stream(c1);
			some_stream>>c1>>sNo>>sLevel;

			i=0;
			j=0;
			
			while(sNo != StudentPtr[i].getStudentNo())
			{
				i=i+1;
			}
			while(sLevel!= CoursePtr[j].id)
			{
				j=j+1;
			}
			StudentPtr[i].enrollCourse(CoursePtr[j]);
			StudentPtr[i].enterClassroom(ClassroomPtr[j%class_size]);
			cout<<ClassroomPtr[j%class_size].c_no<<" there have a "<<ClassroomPtr[j%class_size].student_inroom<<" student "<<endl;
			StudentPtr[i].extractSchedule();
		}
/*********************************************************DISENROLL COMMAND**********************************************************/
		else if(c1[1]=='d' && c1[2]=='e')
		{
			istringstream some_stream(c1);
			some_stream>>c1>>sNo>>sLevel;
			i=0;
			j=0;
			while(sNo!=StudentPtr[i].getStudentNo())
			{
				i=i+1;
			}
			while(sLevel!=CoursePtr[j].id  )
			{
				j=j+1;
			}
			StudentPtr[i].disenroll(CoursePtr[j]);
			StudentPtr[i].quitClassroom(ClassroomPtr[j%class_size]);
			cout<<ClassroomPtr[j%class_size].c_no<<" there have a "<<ClassroomPtr[j%class_size].student_inroom<<" student "<<endl;
			StudentPtr[i].extractSchedule();
		}
/********************************************************************************LIST COMMAND*****************************************/
		else if(c1=="-list")
		{
				
			printCourseIdAndName(CoursePtr,course_size);
		}

		else
		{
			cout << "BLOCK !! Try again ." << endl ;
		}
		test++;
	}
	outputStream.close();
	
	return 0;
}

/**************************************************STUDENT CLASS MEMBER FUNCTIONS*****************************************************************/
/*************************************************GETTER FUNCTIONS***************************************************************************************/
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


/****************************OTHER MEMBER FUNCTIONS****************************************************************************/
int Student::enrollCourse(Course CourseValue)
{
	int i;
	int count=0;
	bool flag=true;

	if(CourseValue.firstDay=="MON")
	{
		for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
		{
			count=count+studentOfCourseTime.Mon[i];	/* İF THERE IS NO LESSON,studentOfCourseTime=0 so if there is overlapping course count>1*/
		}
		
	}
	else if(CourseValue.firstDay=="TUES")
	{
		
		for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
		{
			count=count+studentOfCourseTime.Tues[i];	
		}
		
	}
	
	else if(CourseValue.firstDay=="WEDNES")
	{
		
		for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
		{
			count=count+studentOfCourseTime.Wednes[i];	/* İF THERE IS NO LESSON,studentOfCourseTime=0 so if there is overlapping course count>1*/
		}
		
	}
	
	else if(CourseValue.firstDay=="THURS")
	{
		
		for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
		{
			count=count+studentOfCourseTime.Thurs[i];
		}
		
	}
	
	else if(CourseValue.firstDay=="FRI")
	{
		
		for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
		{
			count=count+studentOfCourseTime.Fri[i];
		}
		
	}
	
	if(CourseValue.secondDay=="MON")
	{
		
		for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
		{
			count=count+studentOfCourseTime.Mon[i];		/* İF THERE IS NO LESSON,studentOfCourseTime=0 so if there is overlapping course count>1*/
		}
	}
	
	else if(CourseValue.secondDay=="TUES")
	{
		
		for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
		{
			count=count+studentOfCourseTime.Tues[i];
		}
		
	}
	
	else if(CourseValue.secondDay=="WEDNES")/* İF THERE IS NO LESSON,studentOfCourseTime=0 so if there is overlapping course count>1*/
	{
		
		for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
		{
			count=count+studentOfCourseTime.Wednes[i];
		}
		
	}
	
	else if(CourseValue.secondDay=="THURS")
	{
		
		for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
		{
			count=count+studentOfCourseTime.Thurs[i];
		}
		
	}
	
	else if(CourseValue.secondDay=="FRI")/* İF THERE IS NO LESSON,studentOfCourseTime=0 so if there is overlapping course count>1*/
	{
		
		for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
		{
			count=count+studentOfCourseTime.Fri[i];
		}
		
	}
	
	if(CourseValue.thirdDay=="MON")
	{
		
		for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
		{
			count=count+studentOfCourseTime.Mon[i];		/* İF THERE IS NO LESSON,studentOfCourseTime=0 so if there is overlapping course count>1*/
		}
		
	}
	
	else if(CourseValue.thirdDay=="TUES")
	{
		
		for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
		{
			count=count+studentOfCourseTime.Tues[i];
		}
		
	}
	
	else if(CourseValue.thirdDay=="WEDNES")
	{
		
		for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
		{
			count=count+studentOfCourseTime.Wednes[i];    /* İF THERE IS NO LESSON,studentOfCourseTime=0 so if there is overlapping course count>1*/
		}
		
	}
	
	else if(CourseValue.thirdDay=="THURS")
	{
		
		for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
		{
			count=count+studentOfCourseTime.Thurs[i];
		}
		
	}
	
	else if(CourseValue.thirdDay=="FRI")/* İF THERE IS NO LESSON,studentOfCourseTime=0 so if there is overlapping course count>1*/
	{
		
		for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
		{
			count=count+studentOfCourseTime.Fri[i];
		}
	}
	if(count>1)		/* if count>1 overlapping course*/
	{
		flag=false; /* overlappinf course --> false*/
	}

	/* IT WAS DECIDED TO ENROLL IN THE COURSE */

	if(remainder_level>=CourseValue.credit && flag==true) /*flag=true-> no overlapping course*/
	{

		setRemainderLevel(remainder_level - CourseValue.credit);	/* this function updates level (credit) */
		cout<<"DONE!"<<endl;

		/* if there is not course this hour, studentOfCourseTime=0 .  */
		/* if there is  course this hour, studentOfCourseTime=1 .  */
		/* if there is double course this hour, studentOfCourseTime=2 .  */


			if(CourseValue.firstDay=="MON")
			{
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Mon[i]+=1;
				}
				
			}
			
			else if(CourseValue.firstDay=="TUES")
			{
				
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Tues[i]+=1;
				}
			}
			
			/* if there is not course this hour, studentOfCourseTime=0 .  */
			/* if there is  course this hour, studentOfCourseTime=1 .  */
			/* if there is double course this hour, studentOfCourseTime=2 .  */
			else if(CourseValue.firstDay=="WEDNES")
			{
				
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Wednes[i]+=1;
				}	
			}
			
			else if(CourseValue.firstDay=="THURS")
			{
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Thurs[i]+=1;
				}
			}
			
			else if(CourseValue.firstDay=="FRI")
			{
				
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Fri[i]+=1;
				}
				
			}
			/* if there is not course this hour, studentOfCourseTime=0 .  */
			/* if there is  course this hour, studentOfCourseTime=1 .  */
			/* if there is double course this hour, studentOfCourseTime=2 .  */			
			if(CourseValue.secondDay=="MON")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Mon[i]+=1;
				}
			}
			
			else if(CourseValue.secondDay=="TUES")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Tues[i]+=1;
				}
			}
			
			else if(CourseValue.secondDay=="WEDNES")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Wednes[i]+=1;
				}
				
			}
			/* if there is not course this hour, studentOfCourseTime=0 .  */
			/* if there is  course this hour, studentOfCourseTime=1 .  */
			/* if there is double course this hour, studentOfCourseTime=2 .  */
			else if(CourseValue.secondDay=="THURS")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Thurs[i]+=1;
				}
				
			}
			
			else if(CourseValue.secondDay=="FRI")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Fri[i]+=1;
				}
				
			}
			/* if there is not course this hour, studentOfCourseTime=0 .  */
			/* if there is  course this hour, studentOfCourseTime=1 .  */
			/* if there is double course this hour, studentOfCourseTime=2 .  */
			if(CourseValue.thirdDay=="MON")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Mon[i]+=1;
				}
			}
			
			else if(CourseValue.thirdDay=="TUES")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Tues[i]+=1;
				}
			}
			
			else if(CourseValue.thirdDay=="WEDNES")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Wednes[i]+=1;
				}
			}
			/* if there is not course this hour, studentOfCourseTime=0 .  */
			/* if there is  course this hour, studentOfCourseTime=1 .  */
			/* if there is double course this hour, studentOfCourseTime=2 .  */
			else if(CourseValue.thirdDay=="THURS")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Thurs[i]+=1;
				}
				
			}
			
			else if(CourseValue.thirdDay=="FRI")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Fri[i]+=1;
				}	
			}
			courseId.push_back(CourseValue.id);	/* push course ıd. Course_ıd vector in  private student class*/	
	}
	else
	{
		cout<<"BLOCK! Because of(credits ["
			<<remainder_level
			<<"] Overlap ["
			<<CourseValue.credit
			<<"] )"
			<<endl;
	}
	
	return remainder_level;
}
/***********************************************DISENROLL******************************************************************************/
int Student::disenroll(Course CourseValue)
{
	bool flag=false;
	int i=0;
	
	for(i=0;i<courseId.size();i++)
	{
		
		if(CourseValue.id==courseId[i])
		{
			/* Did you take this course in advance */
			courseId[i] = -1;
			flag=true;
		}
	}
	if((remainder_level+CourseValue.credit) <= (19+level) && flag==true )
	{
		/* if there is not course this hour, studentOfCourseTime=0 .  */
		/* if there is  course this hour, studentOfCourseTime=1 .  */
		/* if there is double course this hour, studentOfCourseTime=2 .  */

		setRemainderLevel(remainder_level+CourseValue.credit);	/* this function updates level (credit) */
		cout<<"DONE!"<<endl;

			if(CourseValue.firstDay=="MON")
			{
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Mon[i]-=1;
				}
				
			}
			
			else if(CourseValue.firstDay=="TUES")
			{
				
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Tues[i]-=1;
				}
			}
		/* if there is not course this hour, studentOfCourseTime=0 .  */
		/* if there is  course this hour, studentOfCourseTime=1 .  */
		/* if there is double course this hour, studentOfCourseTime=2 .  */
			else if(CourseValue.firstDay=="WEDNES")
			{
				
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Wednes[i]-=1;
				}	
			}
			
			else if(CourseValue.firstDay=="THURS")
			{
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Thurs[i]-=1;
				}
			}
			
			else if(CourseValue.firstDay=="FRI")
			{
				
				for(i=CourseValue.firstDay_start;i<CourseValue.firstDay_finish;i++)
				{
					studentOfCourseTime.Fri[i]-=1;
				}
				
			}
		/* if there is not course this hour, studentOfCourseTime=0 .  */
		/* if there is  course this hour, studentOfCourseTime=1 .  */
		/* if there is double course this hour, studentOfCourseTime=2 .  */
			if(CourseValue.secondDay=="MON")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Mon[i]-=1;
				}
			}
			
			else if(CourseValue.secondDay=="TUES")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Tues[i]-=1;
				}
			}
			
			else if(CourseValue.secondDay=="WEDNES")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Wednes[i]-=1;
				}
				
			}
		/* if there is not course this hour, studentOfCourseTime=0 .  */
		/* if there is  course this hour, studentOfCourseTime=1 .  */
		/* if there is double course this hour, studentOfCourseTime=2 .  */
			else if(CourseValue.secondDay=="THURS")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Thurs[i]-=1;
				}
				
			}
			
			else if(CourseValue.secondDay=="FRI")
			{
				
				for(i=CourseValue.secondDay_start;i<CourseValue.secondDay_finish;i++)
				{
					studentOfCourseTime.Fri[i]-=1;
				}
				
			}
		/* if there is not course this hour, studentOfCourseTime=0 .  */
		/* if there is  course this hour, studentOfCourseTime=1 .  */
		/* if there is double course this hour, studentOfCourseTime=2 .  */	
			if(CourseValue.thirdDay=="MON")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Mon[i]-=1;
				}
			}
			
			else if(CourseValue.thirdDay=="TUES")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Tues[i]-=1;
				}
			}
			
			else if(CourseValue.thirdDay=="WEDNES")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Wednes[i]-=1;
				}
			}
		/* if there is not course this hour, studentOfCourseTime=0 .  */
		/* if there is  course this hour, studentOfCourseTime=1 .  */
		/* if there is double course this hour, studentOfCourseTime=2 .  */			
			else if(CourseValue.thirdDay=="THURS")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Thurs[i]-=1;
				}
				
			}
			
			else if(CourseValue.thirdDay=="FRI")
			{
				
				for(i=CourseValue.thirdDay_start;i<CourseValue.thirdDay_finish;i++)
				{
					studentOfCourseTime.Fri[i]-=1;
				}
			}
	}
	else
	{
		cout<<"BLOCK! Because of(credits ["
			<<remainder_level
			<<"] Overlap ["
			<<CourseValue.credit
			<<"] )"
			<<endl;
	}
	
	return remainder_level;
}
/****************************************INIT STUDENT OF COURSE************************************************************************/
void Student::initStudentOfCourseTime()
{
	int j;
/* 			initilization free of weekly schedule */
		for(j=0;j<24;j++)
		{
			studentOfCourseTime.Mon[j]=0;
			studentOfCourseTime.Tues[j]=0;
			studentOfCourseTime.Wednes[j]=0;
			studentOfCourseTime.Thurs[j]=0;
			studentOfCourseTime.Fri[j]=0;

		}
}
/*************************************EXTRACT SCHEDULE*****************************************************************************/
void Student::extractSchedule()
{

	int i,j;
	vector<string> schedule;		/* multidimensional array for weekly schedule */
	schedule.resize(10);

	vector<string> day;
	day.push_back("MONDAY");
	day.push_back("TUESDAY");
	day.push_back("WEDNESDAY");
	day.push_back("THURSDAY");
	day.push_back("FRIDAY");
	for(j=0;j<5;j++)
	{
		cout<<day[j]<<endl;
		cout<<"08:00 09:00 10:00 11:00 12:00 13:00 14:00 15:00 16:00"<<endl;

		/* if there are course that hour, write full else free*/
		for(i=8;i<17;i++)
		{
			if(j==0)
			{
				if(studentOfCourseTime.Mon[i]==0)
				schedule[i-8]="FREE ";
				else
				{
					schedule[i-8]="FULL ";
				}
			}
			else if(j==1)
			{
				if(studentOfCourseTime.Tues[i]==0)
				schedule[i-8]="FREE ";
				else
				{
					schedule[i-8]="FULL ";
				}
			}
			else if(j==2)
			{
				if(studentOfCourseTime.Wednes[i]==0)
				schedule[i-8]="FREE ";
				else
				{
					schedule[i-8]="FULL ";
				}
			}
			else if(j==3)
			{
				if(studentOfCourseTime.Thurs[i]==0)
				schedule[i-8]="FREE ";
				else
				{
					schedule[i-8]="FULL ";
				}
			}
			else if(j==4)
			{
				if(studentOfCourseTime.Fri[i]==0)
				schedule[i-8]="FREE ";
				else
				{
					schedule[i-8]="FULL ";
				}
			}	
			
			cout<<schedule[i-8]<<" ";
		}
		cout<<endl<<endl;
	}
}
/**************************************************************ENTER CLASSROOM*********************************************************/
void Student::enterClassroom(Classroom& ClassroomValue)
{
	if(ClassroomValue.student_inroom > 0  )
	{
		ClassroomValue.student_inroom -= 1;
	}

}
/********************************************************QUIT CLASSROOM******************************************************************/
void Student::quitClassroom(Classroom& ClassroomValue)
{
	if(ClassroomValue.student_inroom < ClassroomValue.capacity)
	{
		ClassroomValue.student_inroom += 1;
	}
}

/*************************************** GLOBAL FUNCTIONS IMPLEMENTATION ************************************************************/


/*********************************************************************PRINT COURSE ID AND NAME************************************/
void printCourseIdAndName(Course courseArray[],int course_size)
{
	for(int i=0;i<course_size;i++)
		cout<<"("<<courseArray[i].id<<")"<<courseArray[i].name<<" ";
	cout<<endl;
}
/*****************************************************************************DATES**********************************************/
void dates(Course CoursePtr[],int course_size)
{
	int i,j;
	int arr[course_size];
	int count=0;
/* 	fill space other sign (-,_,,) */
	for(i=0;i<course_size;i++)
	{
		count=0;
		for(j=0;j<CoursePtr[i].lectureDates.length();j++)
		{
			if(CoursePtr[i].lectureDates[j]=='-')
			{
				CoursePtr[i].lectureDates[j]=' ';
			}
			else if(CoursePtr[i].lectureDates[j]=='_')
			{
				CoursePtr[i].lectureDates[j]=' ';
			}
			else if(CoursePtr[i].lectureDates[j]==',')
			{
				CoursePtr[i].lectureDates[j]=' ';
				count++;
			}
		}
		arr[i]=count;
	}
/*	assign firstDay,secondDay,thirdDay, and these finish and start variables */
	for(i=0;i<course_size;i++)
	{
		if(arr[i]==1)
		{
			istringstream some_stream(CoursePtr[i].lectureDates);
			some_stream>>CoursePtr[i].firstDay
						>>CoursePtr[i].firstDay_start
						>>CoursePtr[i].firstDay_finish
						>>CoursePtr[i].secondDay
						>>CoursePtr[i].secondDay_start
						>>CoursePtr[i].secondDay_finish;
			CoursePtr[i].thirdDay='0';
			CoursePtr[i].thirdDay_start=0;
			CoursePtr[i].thirdDay_finish=0;
		}
/*	assign firstDay,secondDay,thirdDay, and these finish and start variables */
		/* if course thirdday arr[i]=2		*/
		else if(arr[i]==2)
		{
			istringstream some_stream(CoursePtr[i].lectureDates);
			some_stream>>CoursePtr[i].firstDay
						>>CoursePtr[i].firstDay_start
						>>CoursePtr[i].firstDay_finish
						>>CoursePtr[i].secondDay
						>>CoursePtr[i].secondDay_start
						>>CoursePtr[i].secondDay_finish
						>>CoursePtr[i].thirdDay
						>>CoursePtr[i].thirdDay_start
						>>CoursePtr[i].thirdDay_finish;
		}	
	}
}
/****************************************************************************************************************************************/