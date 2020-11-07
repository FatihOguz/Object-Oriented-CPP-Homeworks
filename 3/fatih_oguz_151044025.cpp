#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>	/* for exit */
#include "read.h"
#include "lecturer.h"
#include "course.h"
#include "classroom.h"
#include "administrator.h"
#include "test.h"

using namespace std;


int main()
{
	/* start read files and initialization */
	Administrator administrator;
	int courses_size = 0, classrooms_size = 0;
	int lecturers_size=0;
	int i=0;
	int testFlag=0;
	string command;
	read_courses_and_classrooms(courses_size,classrooms_size);
	

	read_lecturers(lecturers_size);
	

	vector <Classroom> classrooms;
	classrooms.resize(classrooms_size);
	
	courses.resize(courses_size);
	vector <Lecturer> lecturers;
	lecturers.resize(lecturers_size);

	initialized_courses_and_classrooms(&courses[0],courses_size,&classrooms[0],classrooms_size);

	initialized_lecturer(&lecturers[0],lecturers_size);
	cout<<endl<<endl;
	
	int p,cod,cre,hour;
	string arr,n,fie;
	int size_pid[lecturers_size];
	int courses_size_2 =courses_size ;
	for (i = 0; i < lecturers_size; ++i)
	{
		size_pid[i] = 0;
	}
	/* finish read files and initialization */

	/* test scenarıo functıon */
test( classrooms,classrooms_size,courses, courses_size,lecturers,lecturers_size,administrator);
	
	/* user do menu command*/

	while(testFlag==0)
	{
		getline(cin,command);
		cout<<command<<endl;

		if(command=="exit")			/* end program */
		{
			exit(1);
		}
		else if(command[1]=='p' && command[4]=='p')		/* propose functıon menu */
		{
			int lecturer_index=0;
				istringstream some_stream(command);
				some_stream>>arr>>p>>n>>cod>>cre>>hour>>fie;
				Course temp;
				temp.name=n;
				temp.code=cod;
				temp.credit=cre;
				temp.totalHours=hour;
				temp.field=fie;
				temp.pid=p;
				temp.id=courses.size()+1;
				courses_size=courses.size();
				
				/* do lecturers pid lecturer initializitaion  */
				temp=lecturers[lecturer_index].proposeCourse(courses ,temp,courses_size);
				if(temp.pid==0)
				{
					
				}
				else
				{
					courses.push_back(temp);				/* propose course adds mean courses */
				}
				
			cout<<endl<<endl;
		}
		else if(command[1]=='a' && command[5]=='g' && command[8]<='9' && command[8]>='0')		/* assign 4 4 functıon menu */
		{
			Course temp;
			istringstream some_stream(command);
			some_stream>>arr>>cod>>cre;
			temp.pid=cod;
			temp.id=cre;
			int flag=0;
			for(i=0;i<courses.size();i++)
			{
				if(cre==courses[i].id)				/* control Error */
				{
					temp=courses[i];
					flag=1;
				}
			}
			if(flag==0)
			{
				cout<<"Error: no lecture or course"<<endl;
			}
			
			
			
				else if(lecturers[cod-1].get_proffesions0()==courses[cre-1].field)			/* control block */
				{
					flag=0;
				}
				else if(lecturers[cod-1].get_proffesions1()==courses[cre-1].field)
				{
					flag=0;
				}
				else if(lecturers[cod-1].get_proffesions2()==courses[cre-1].field)
				{
					flag=0;
				}
				else if(lecturers[cod-1].get_proffesions3()==courses[cre-1].field)
				{
					flag=0;
				}
			
			if(flag==1)
			{
				cout<<"Block: field and profession mismatch"<<endl;
			}
			else if(flag==0)
			{
				courses_size=courses.size();
				//alt satırdaki lecturers 0 durumunu düzelt
				/* lecturers[cod] cod:pid */
				temp=lecturers[cod-1].assignCourse(courses,temp,courses_size);		/*for DONE assignCoursefunctıon */
				if(temp.pid==0)
				{
					
				}
				else
				{
					
					courses.push_back(temp);										/* add course courses vector*/
					courses[cre-1].pid=lecturers[cod-1].get_personal_id();
				}
				
				cout<<"DONE"<<endl;
				
			}	
			cout<<endl<<endl;		
		}
		else if(command=="-assign")						/* assign command */
		{
			int j,count=0;
			
			courses_size=courses.size();
			
			int know_lec[courses_size];
			int max=lecturers_size+2;
			for(i=0;i<courses_size;i++)
			{
				count=0;
				for(j=0;j<lecturers_size;j++)			/* control course field */
				{
					if(courses[i].field==lecturers[j].get_proffesions0())
					{
						count = count + 1;
					}
					else if(courses[i].field==lecturers[j].get_proffesions1())
					{
						count = count + 1;
					}
					else if(courses[i].field==lecturers[j].get_proffesions2())
					{
						count = count + 1;
					}
					else if(courses[i].field==lecturers[j].get_proffesions3())
					{
						count = count + 1;
					}
				}
				know_lec[i]=count;
			}

			int k=0;
			
			cout << endl ;
			for(k=0;k<courses.size();k++)
			{			
				i=min(know_lec,courses_size);		/* control gives lecturer 3 course */
				

				for(j=0;j<lecturers_size;j++)
				{
					if(courses[i].field==lecturers[j].get_proffesions0() && size_pid[j] <=2 && courses[i].lec==0 && courses[i].isMandatory==0)
					{
						lecturers[j].LectureCourses.push_back(courses[i]);
						courses[i].lec=lecturers[j].get_personal_id();
						size_pid[j] += 1;
					}
					else if(courses[i].field==lecturers[j].get_proffesions1() && size_pid[j] <=2 && courses[i].lec==0 && courses[i].isMandatory==0)
					{
						lecturers[j].LectureCourses.push_back(courses[i]);
						courses[i].lec=lecturers[j].get_personal_id();
						size_pid[j] += 1;
					}
					else if(courses[i].field==lecturers[j].get_proffesions2() && size_pid[j] <=2 && courses[i].lec==0 && courses[i].isMandatory==0)
					{
						lecturers[j].LectureCourses.push_back(courses[i]);
						courses[i].lec=lecturers[j].get_personal_id();
						size_pid[j] += 1;
					}
					else if(courses[i].field==lecturers[j].get_proffesions3() && size_pid[j] <=2 && courses[i].lec==0 && courses[i].isMandatory==0)
					{
						lecturers[j].LectureCourses.push_back(courses[i]);
						courses[i].lec=lecturers[j].get_personal_id();
						size_pid[j] += 1;
					}
				}
				know_lec[i]=max;	
			}			
			for(i=courses_size_2;i<courses.size();i++)			/* control gives lecturer 3 course */
			{			
				for(j=0;j<lecturers_size;j++)
				{
					if( size_pid[j] <=2  && courses[i].isMandatory!=0)
					{
						lecturers[j].LectureCourses.push_back(courses[i]);
						courses[i].lec=lecturers[j].get_personal_id();
						size_pid[j] += 1;
					}
					else if( size_pid[j] <=2  && courses[i].isMandatory!=0)
					{
						lecturers[j].LectureCourses.push_back(courses[i]);
						courses[i].lec=lecturers[j].get_personal_id();
						size_pid[j] += 1;
					}
					else if(size_pid[j] <=2 && courses[i].isMandatory!=0)
					{
						lecturers[j].LectureCourses.push_back(courses[i]);
						courses[i].lec=lecturers[j].get_personal_id();
						size_pid[j] += 1;
					}
					else if(size_pid[j] <=2 && courses[i].isMandatory!=0)
					{
						lecturers[j].LectureCourses.push_back(courses[i]);
						courses[i].lec=lecturers[j].get_personal_id();
						size_pid[j] += 1;
					}
				}
				know_lec[i]=max;	
			}	

			cout<<endl<<endl;
		}

		else if(command=="-timetable")				/* time table control */
		{
			

			int i=0,j=0,k=0;
			int count = 0; /* did not timetable */
			for(i=0;i<courses.size();i++)
			{
				if(courses[i].timetable==0)	/* control courses of timetable */
				{
					Course temp;
					temp=administrator.arrangeTimeTable(courses,i);		/* for timetable arrangeTimeTable functıon */
					courses[i]=temp;
				}
			}
			
			for(i = 0;i<courses.size();i++)			/* print courses and course date*/
			{
								cout<<courses[i].name<<" "<<courses[i].sDate1<<"_"<<courses[i].sHourStart1
					<<"_"<<courses[i].sHourFinish1<<","<<courses[i].sDate2<<"_"<<courses[i].sHourStart2
					<<"_"<<courses[i].sHourFinish2<<endl;
			}
			
			cout<<endl<<endl;
		}

		else if(command[1]=='t' && command[11]>='0' && command[11]<='9')		/* for special course timetable*/
		{
			int courses_id;
			
			istringstream some_stream(command);
			some_stream>>arr>>courses_id;
			Course temp;

			temp=administrator.arrangeTimeTable(courses,courses_id-1);			/* for timetable command arrangeTimeTable functıon */
			
			if(temp.timetable==1)				/* print courses and course date done tmetable*/
			{
				cout<<"DONE ";
				courses[courses_id-1]=temp;
				cout<<courses[courses_id-1].name<<" "<<courses[courses_id-1].sDate1<<"_"<<courses[courses_id-1].sHourStart1
					<<"_"<<courses[courses_id-1].sHourFinish1<<","<<courses[courses_id-1].sDate2<<"_"<<courses[courses_id-1].sHourStart2
					<<"_"<<courses[courses_id-1].sHourFinish2<<endl;

			}
			
			cout<<endl;
		}

		else if(command=="-arrangeC")			/* command arrangeC */
		{
			
			int class_id,courses_id;
			Classroom temp,crm;
			Course crs;
			
			for(i=0;i<courses_size;i++)
			{
				crs.id=courses[i].id;
				crm.id=classrooms[i%5].id;
				temp=administrator.arrangeClassroom(classrooms,classrooms_size,courses,courses_size,crm,crs); /* for command arrangeClassroom functıon */
				crm.id=classrooms[i%5].id-1;
				crs.id=courses[i].id-1;
				if(temp.flag==1)			/* print courses and course date done tmetable*/
				{
					classrooms[classrooms[i%5].id]=temp;
					cout<<"DONE: ("<<crs.id+1<<") in "<<crm.id+1<<" at "<<courses[crs.id].sDate1<<" "<<courses[crs.id].sHourStart1
						<<"_"<<courses[crs.id].sHourFinish1<<","<<courses[crs.id].sDate2<<"_"<<courses[crs.id].sHourStart2
						<<"_"<<courses[crs.id].sHourFinish2<<endl;
				}
			}
			cout<<endl;
		}

		else if(command[1]=='a' && command[8]=='C' && command[13]==',')  /* arrange for w classroom */
		{
			int class_id,class2_id,courses_id;
			string v=",";

			istringstream some_stream(command);			
			some_stream>>arr>>courses_id>>class_id>>v>>class2_id;

			Classroom temp,crm,crm2;
			Course crs;
			crm.id=class_id;
			crm2.id=class2_id;
			crs.id=courses_id;
			
			temp=administrator.arrangeClassroom(classrooms,classrooms_size,courses,courses_size,crm,crs);/* arrangeC number1 */

			crm.id=class_id-1;
			crs.id=courses_id-1;
			if(temp.flag==1)
			{
				classrooms[class_id]=temp;				/* print courses and course date done tmetable*/
				cout<<"DONE: ("<<courses_id<<") in "<<class_id<<" at "<<courses[crs.id].sDate1<<" "<<courses[crs.id].sHourStart1
					<<"_"<<courses[crs.id].sHourFinish1<<","<<courses[crs.id].sDate2<<"_"<<courses[crs.id].sHourStart2
					<<"_"<<courses[crs.id].sHourFinish2<<endl;
			}
			temp=administrator.arrangeClassroom(classrooms,classrooms_size,courses,courses_size,crm2,crs);/* arrangeC number2 */
			crm2.id=class2_id-1;
			crs.id=courses_id-1;
			if(temp.flag==1)
			{
				classrooms[class2_id]=temp;			/* print courses and course date done tmetable*/
				cout<<"DONE: ("<<courses_id<<") in "<<class_id<<" at "<<courses[crs.id].sDate1<<" "<<courses[crs.id].sHourStart1
					<<"_"<<courses[crs.id].sHourFinish1<<","<<courses[crs.id].sDate2<<"_"<<courses[crs.id].sHourStart2
					<<"_"<<courses[crs.id].sHourFinish2<<endl;
			}
			cout<<endl;

		}
				
		else if(command[1]=='a' && command[8]=='C' && command[10]<='9' && command[10]>='0')		/* command arangeC number*/
		{
			
			int class_id,courses_id;
			
			istringstream some_stream(command);
			some_stream>>arr>>courses_id>>class_id;
			Classroom temp,crm;
			Course crs;
			crm.id=class_id;
			crs.id=courses_id;
			
			temp=administrator.arrangeClassroom(classrooms,classrooms_size,courses,courses_size,crm,crs);
			crm.id=class_id-1;
			crs.id=courses_id-1;
			if(temp.flag==1)
			{
				classrooms[class_id]=temp;	/* print courses and course date done tmetable*/
				cout<<"DONE: ("<<courses_id<<") in "<<class_id<<" at "<<courses[crs.id].sDate1<<" "<<courses[crs.id].sHourStart1
					<<"_"<<courses[crs.id].sHourFinish1<<","<<courses[crs.id].sDate2<<"_"<<courses[crs.id].sHourStart2
					<<"_"<<courses[crs.id].sHourFinish2<<endl;
			}
			cout<<endl;
		}

		
		else
		{
			cout << "BLOCK !! Try again ." << endl ;
		}


}


	return 0;
}