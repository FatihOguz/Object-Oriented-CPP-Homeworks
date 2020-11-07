#include "lecturer.h"



namespace Lecturert
{
	Lecturer::Lecturer(){
		//cout<<"NO parameter constructor"<<endl;
	}
	Lecturer::~Lecturer()
	{
		//cout<<"called Destructor for Lecturer Class"<<endl;
			LectureCourses.clear();
	}

	Lecturer::Lecturer(Lecturer& other)/*Copy constructor*/
	{
		//cout<<"Called Copy Constructor for Lecturer"<<endl;
		set_name(other.get_name());
		set_surname(other.get_surname());
		set_personal_id(other.get_personal_id());
		set_title(other.get_title());
		set_proffesions0(other.get_proffesions0());
		set_proffesions1(other.get_proffesions1());
		set_proffesions2(other.get_proffesions2());
		set_proffesions3(other.get_proffesions3());

		for(int i=0;i<other.LectureCourses.size();i++)
		{
			if(i>=LectureCourses.size())
			{
				LectureCourses.push_back(other.LectureCourses[i]);
			}
			else
			{
				LectureCourses[i]=other.LectureCourses[i];
			}
		}
	}
	Lecturer& Lecturer::operator=(Lecturer& other)/*assignment operator overloading*/
	{
		LectureCourses.clear();
		set_name(other.get_name());
		set_surname(other.get_surname());
		set_personal_id(other.get_personal_id());
		set_title(other.get_title());
		set_proffesions0(other.get_proffesions0());
		set_proffesions1(other.get_proffesions1());
		set_proffesions2(other.get_proffesions2());
		set_proffesions3(other.get_proffesions3());
		for(int i=0;i<other.LectureCourses.size();i++)
		{	
			LectureCourses[i]=other.LectureCourses[i];
		}
		return *this;
		
	}
	void Lecturer::assignCourse(Course temp)
	{
		if(LectureCourses.size()<=3)
		LectureCourses.push_back(temp);
	}

	Course Lecturer::assignCourse(Course courses[] ,Course temp,int courses_size)
	{
		int i,count=0;
		string command,arr,n,fie;
		int cod,cre,hour,p;
		
		for(i=0;i<courses_size;i++)
		{
			if(personal_id==courses[i].pid)	/* Problem1:each lecturer gives 3 course */
			{
				count++;
			}
		}

		if(count>=3)			/* control assign 3 lecture */
		{
			temp.pid=0;
			cout<<"Block:full courses of lecturer's"<<endl;
			return temp;
		}
		else		/* give course */
		{
			
				for(i=0;i<courses_size;i++)
				{
					if(temp.id==courses[i].id)
					{
						temp=courses[i];		/* temp assign courses[i]. */
					}
				}
				temp.pid=personal_id;
				LectureCourses.push_back(temp);	/* lecturer assign course */


				count=0;
				
			for(i=0;i<courses_size;i++)
			{
				if(courses[i].isMandatory==0)
				{
					if(personal_id==courses[i].pid)
					{		
						count++;					/* control assign lecturer < 3 if lecturer propose course  so count++*/
					}
					
				}
			}
	courses[courses_size-1].id=courses_size;
			if(count<=3)							/* control assign lecturer < 3 if lecturer propose course */
			{
				cout<<"propose a course please"<<endl;			/* propose a course */
				getline(cin,command);
				
				istringstream some_stream(command);
				some_stream>>arr>>p>>n>>cod>>cre>>hour>>fie;
				Course temp1;
				temp1.name=n;
				temp1.code=cod;
				temp1.credit=cre;
				temp1.totalHours=hour;
				temp1.field=fie;
				temp1.pid=p;
				temp1.id=courses_size+1;
				temp1.isMandatory=-1;		
				/* lecturers pid lecturer initializitaion yapar */
				temp1=proposeCourse(courses ,temp1,courses_size);
				return temp1;
			}
		}	
	}

	Course Lecturer::proposeCourse(Course courses[],Course temp,int courses_size)
	{
		int count1=0;
		int i=0;
		for(i=0;i<courses_size;i++)
		{
			if(temp.pid==courses[i].pid)
			{
				count1++;			/* lecturer propose max 3 course */
			}
		}

		if(count1<3)			/* control how much propose elective course  */
		{
			
			temp.pid=999;
			temp.isMandatory=personal_id;			/* (control)course is elective or mandatory */
			return temp;
			
		}
		else
		{
			
			temp.pid=0;
			return temp;
		}
	}


	void initialized_courses_and_classrooms(Course courses[],int courses_size,Classroom classrooms[],int classrooms_size)
	{
		int flag = 1;
		ifstream inputStream;
		string arr;
		int finteger;
		int classrooms_index=0;
		int courses_index=0;

		inputStream.open("courses_classrooms.txt");

		inputStream>>arr;


			if(arr == "COURSES")									/* initilzed courses part */
			{
				for(courses_index=0;courses_index<courses_size;courses_index++)
				{
					inputStream>>finteger;		/* number in file*/
					courses[courses_index].id=finteger;
					inputStream>>arr;
					courses[courses_index].name = arr;
					inputStream>>finteger;
					courses[courses_index].code = finteger;
					inputStream>>finteger;
					courses[courses_index].credit = finteger;
					inputStream>>finteger;
					courses[courses_index].totalHours = finteger;
					inputStream>>arr;
					courses[courses_index].field = arr;
					courses[courses_index].isMandatory =0;
					courses[courses_index].lec =0;	
					courses[courses_index].timetable =0;			
				}
				inputStream>>arr;										/* initilzed classroom part  */
				for(classrooms_index=0;classrooms_index<classrooms_size;classrooms_index++)
				{
					inputStream>>finteger;		/* number in file*/
					classrooms[classrooms_index].set_id(finteger);
					inputStream>>arr;
					classrooms[classrooms_index].set_classNo(arr);
					inputStream>>finteger;
					classrooms[classrooms_index].set_capacity(finteger);
				}
			}
			
			else if(arr == "CLASSROOMS")												/* initilzed classroom part  */										
			{
				for(classrooms_index=0;classrooms_index<classrooms_size;classrooms_index++)
				{
					inputStream>>finteger;		/* number in file*/
					classrooms[classrooms_index].set_id(finteger);
					inputStream>>arr;
					classrooms[classrooms_index].set_classNo(arr);
					inputStream>>finteger;
					classrooms[classrooms_index].set_capacity(finteger);
				}
				inputStream>>arr;													/* initilzed courses part */
				for(courses_index=0;courses_index<courses_size;courses_index++)
				{
					inputStream>>finteger;		/* number in file*/
					courses[courses_index].id=finteger;
					inputStream>>arr;
					courses[courses_index].name = arr;
					inputStream>>finteger;
					courses[courses_index].code = finteger;
					inputStream>>finteger;
					courses[courses_index].credit = finteger;
					inputStream>>finteger;
					courses[courses_index].totalHours = finteger;
					inputStream>>arr;
					courses[courses_index].field = arr;
					courses[courses_index].isMandatory =0;
					courses[courses_index].lec =0;	
					courses[courses_index].timetable =0;	
				}
			}

			inputStream.close();
			
		}
		

	void initialized_lecturer(Lecturer lecturers[],int lecturer_size)
	{
		ifstream inputStream;
		string arr ,	n ,sn ,p,c0,c1,c2,c3;
		int pid;
		int lecturer_index=0;
		inputStream.open("lecturers.txt");
		int i=0;

		for(lecturer_index=0; lecturer_index < lecturer_size; lecturer_index++)
		{
			getline(inputStream,arr);
			for(i=0;i<arr.size();i++)
			{
				if(arr[i]==',')
				{
					arr[i]=' ';
				}
				
			}
			i++;
			arr[i]='\0';
			c0=" ";
			c1=" ";
			c2=" ";
			c3=" ";
			istringstream some_stream(arr);
			some_stream>>pid>>n>>sn>>p>>c0>>c1>>c2>>c3;							/* initilzed lecturers part */

			lecturers[lecturer_index].set_personal_id(pid) ;
			lecturers[lecturer_index].set_name(n);
			lecturers[lecturer_index].set_surname(sn);		
			lecturers[lecturer_index].set_title(p);

			lecturers[lecturer_index].set_proffesions0(c0);
			lecturers[lecturer_index].set_proffesions1(c1);
			lecturers[lecturer_index].set_proffesions2(c2);
			lecturers[lecturer_index].set_proffesions3(c3);
		}


		inputStream.close();
			
	}
	int min(int arr[],int size)				/* find index of array's min eleman */
	{
		int i=0;
		int index=0;
		int min=arr[0];
		for(i=0;i<size;i++)
		{
			if(arr[i]<=min)
			{
				min=arr[i];
				index=i;
			}
		}
		return index;
	}
}
