#include "test.h"




void test(Classroom classrooms[],int classrooms_size,Course courses[] ,int courses_size,Lecturer lecturers[],int lecturers_size,Administrator administrator,Student StudentPtr[],int student_size)
{
	int p,cod,cre,hour;
	string arr,n,fie;
	int size_pid[lecturers_size];
	int courses_size_2 =courses_size ;
	int i;
	string command;
	ifstream inputStream;
	int testFlag=0;
	inputStream.open("test.txt");
	cout<<"START TEST SCENARIO"<<endl;
	while(testFlag==0)
	{
		getline(inputStream,command);
		cout<<command<<endl;

		if(command=="exit")			/* end program */
		{
			testFlag=1;
		}
		else if(command[1]=='p' && command[4]=='p')		/* propose functıon menu */
		{
			int lecturer_index=0;
				istringstream some_stream(command);
				some_stream>>arr>>p>>n>>cod>>cre>>hour>>fie;
				Course * temp;
				temp = new Course[1];
				temp[0].name=n;
				temp[0].code=cod;
				temp[0].credit=cre;
				temp[0].totalHours=hour;
				temp[0].field=fie;
				temp[0].pid=p;
				temp[0].id=courses_size+1;
				courses_size=courses_size;
				
				/* do lecturers pid lecturer initializitaion  */
				temp[0]=lecturers[lecturer_index].proposeCourse(courses ,temp[0],courses_size);
				if(temp[0].pid==0)
				{
					
				}
				else
				{
					Course * temp1;
					temp1 = new Course[courses_size+1];
					for(int i=0;i<courses_size;i++)
						temp1[i]=courses[i];
					courses_size++;				/* propose course adds mean courses */
					delete[] courses;
					courses=temp1;
					courses[courses_size-1]=temp[0];
					
				}
				
			cout<<endl<<endl;
		}
		else if(command[1]=='a' && command[5]=='g' && command[8]<='9' && command[8]>='0')		/* assign 4 4 functıon menu */
		{
			Course * temp;
				temp = new Course[1];
			istringstream some_stream(command);
			some_stream>>arr>>cod>>cre;
			temp[0].pid=cod;
			temp[0].id=cre;
			int flag=0;
			for(i=0;i<courses_size;i++)
			{
				if(cre==courses[i].id)				/* control Error */
				{
					temp[0]=courses[i];
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
				
				//alt satırdaki lecturers 0 durumunu düzelt
				/* lecturers[cod] cod:pid */
				temp[0]=lecturers[cod-1].assignCourse(courses,temp[0],courses_size);		/*for DONE assignCoursefunctıon */
				if(temp[0].pid==0)
				{
					
				}
				else
				{
					Course * temp1;
					temp1 = new Course[courses_size+1];
					for(int i=0;i<courses_size;i++)
						temp1[i]=courses[i];
					courses_size++;				
					delete[] courses;
					courses=temp1;
					courses[courses_size-1]=temp[0];							



					/* add course courses */
					courses[cre-1].pid=lecturers[cod-1].get_personal_id();
				}
				
				cout<<"DONE"<<endl;
				
			}	
			cout<<endl<<endl;		
		}
		else if(command=="-assign")						/* assign command */
		{
			int j,count=0;
			
			
			
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
			for(k=0;k<courses_size;k++)
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
			for(i=courses_size_2;i<courses_size;i++)			/* control gives lecturer 3 course */
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
			for(i=0;i<courses_size;i++)
			{
				if(courses[i].timetable==0)	/* control courses of timetable */
				{
					Course temp;
					
					temp=administrator.arrangeTimeTable(courses,i,courses_size);		/* for timetable arrangeTimeTable functıon */
					courses[i]=temp;
				}
			}
			
			for(i = 0;i<courses_size;i++)			/* print courses and course date*/
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

			temp=administrator.arrangeTimeTable(courses,courses_id-1,courses_size);			/* for timetable command arrangeTimeTable functıon */
			
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
			Classroom crm;
			Classroom * temp  = new Classroom[1];
			Course crs;
			ofstream outputStream;
			outputStream.open("arrangeC.txt");	
			for(i=0;i<courses_size;i++)
			{
				crs.id=courses[i].id;
				crm.set_id(classrooms[i%5].get_id());
				temp[0]=administrator.arrangeClassroom(classrooms,classrooms_size,courses,courses_size,crm,crs); /* for command arrangeClassroom functıon */
				crm.set_id(classrooms[i%5].get_id()-1);
				crs.id=courses[i].id-1;
				
				if(temp[0].get_flag()==1)			/* print courses and course date done tmetable*/
				{
					courses[crs.id].classroomNo=classrooms[classrooms[i%5].get_id()].get_classNo();
					classrooms[classrooms[i%5].get_id()]=temp[0];
					cout<<"DONE: ("<<crs.id+1<<") in "<<crm.get_id()+1<<" at "<<courses[crs.id].sDate1<<" "<<courses[crs.id].sHourStart1
						<<"_"<<courses[crs.id].sHourFinish1<<","<<courses[crs.id].sDate2<<"_"<<courses[crs.id].sHourStart2
						<<"_"<<courses[crs.id].sHourFinish2<<endl;
					outputStream<<crm.get_id()+1<<" "<<courses[crs.id].sDate1<<" "<<courses[crs.id].sHourStart1
						<<endl;
				}
			}
			cout<<endl;
			outputStream.close();
		}

		else if(command[1]=='a' && command[8]=='C' && command[13]==',')  /* arrange for w classroom */
		{
			int class_id,class2_id,courses_id;
			string v=",";

			istringstream some_stream(command);			
			some_stream>>arr>>courses_id>>class_id>>v>>class2_id;

			Classroom temp,crm,crm2;
			Course crs;
			crm.set_id(class_id);
			crm2.set_id(class2_id);
			crs.id=courses_id;
			
			temp=administrator.arrangeClassroom(classrooms,classrooms_size,courses,courses_size,crm,crs);/* arrangeC number1 */

			crm.set_id(class_id-1);
			crs.id=courses_id-1;
			if(temp.get_flag()==1)
			{
				classrooms[class_id]=temp;				/* print courses and course date done tmetable*/
				cout<<"DONE: ("<<courses_id<<") in "<<class_id<<" at "<<courses[crs.id].sDate1<<" "<<courses[crs.id].sHourStart1
					<<"_"<<courses[crs.id].sHourFinish1<<","<<courses[crs.id].sDate2<<"_"<<courses[crs.id].sHourStart2
					<<"_"<<courses[crs.id].sHourFinish2<<endl;
			}
			temp=administrator.arrangeClassroom(classrooms,classrooms_size,courses,courses_size,crm2,crs);/* arrangeC number2 */
			crm2.set_id(class2_id-1);
			crs.id=courses_id-1;
			if(temp.get_flag()==1)
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
			crm.set_id(class_id);
			crs.id=courses_id;
			
			temp=administrator.arrangeClassroom(classrooms,classrooms_size,courses,courses_size,crm,crs);
			crm.set_id(class_id-1);
			crs.id=courses_id-1;
			
			if(temp.get_flag()==1)
			{
				classrooms[class_id]=temp;	/* print courses and course date done tmetable*/
				cout<<"DONE: ("<<courses_id<<") in "<<class_id<<" at "<<courses[crs.id].sDate1<<" "<<courses[crs.id].sHourStart1
					<<"_"<<courses[crs.id].sHourFinish1<<","<<courses[crs.id].sDate2<<"_"<<courses[crs.id].sHourStart2
					<<"_"<<courses[crs.id].sHourFinish2<<endl;
			}
			cout<<endl;
		}
		else if(command[1]=='e' && command[3]=='t' && command[5]=='r')			/* command enter */
		{
			string strDay,comp_strDay;
			
			int flag=0;
			int course_hour,a2;
			int class_of_id=0;
			int student_id,hour,student_index=-1,classroom_index=-1;
			string classroom_id;
			int course_index=-1;
			istringstream some_stream(command);									/* parts string command */
			some_stream>>command>>student_id>>classroom_id>>hour;
			int day = hour/10;													/* initialize and define day */
			int day_hour=hour %10;
			day_hour =day_hour+8;												/* initialize and define day_hour */
			course_hour=day_hour;
			if(day==0)
			{
				strDay="Mon_";
			}
			else if(day==1)
			{
				strDay="Tue_";
			}
			else if(day==2)
			{
				strDay="Wed_";
			}
			else if(day==3)
			{
				strDay="Thu_";
			}
			else if(day==4)
			{
				strDay="Fri_";
			}
			for(int i=0;i<courses_size;i++)
			{
				if(courses[i].sDate1=="Mon_" && day==0)
				{
					if(courses[i].sHourStart1==day_hour)						/* determine course's day and hour [hour_of_week]	*/
					{
						course_index=i;
					}
					
				}

				else if(courses[i].sDate1=="Tue_"&& day==1)						/* determine course's day and hour [hour_of_week]	*/
				{
					if(courses[i].sHourStart1==day_hour)
					{
						course_index=i;
					}
					
				}
				else if(courses[i].sDate1=="Wed_" && day==2)					/* determine course's day and hour [hour_of_week]	*/
				{
					if(courses[i].sHourStart1==day_hour)
					{
						course_index=i;
					}
					
				}
				else if(courses[i].sDate1=="Thu_" && day==3)					/* determine course's day and hour [hour_of_week]	*/
				{
					if(courses[i].sHourStart1==day_hour)
					{
						course_index=i;
					}
					
				}
	
				else if(courses[i].sDate1=="Fri_" && day==4)					/* determine course's day and hour [hour_of_week]	*/
				{
					if(courses[i].sHourStart1==day_hour)
					{
						course_index=i;
					}
					
				}
			}
				
			
			for(int i = 0; i<student_size;i++)
			{
				if(StudentPtr[i].getStudentNo() == student_id)					/* are there student? */
				{
					student_index=i;
				}
			}
			for(int i = 0; i<classrooms_size;i++)								/* are there classroom? */
			{
				if(classrooms[i].get_classNo() == classroom_id)
				{
					classroom_index=i;
				}
			}
			if(classroom_index==-1 || student_index==-1)						/* ERROR BLOCK if are not student and classroom */
			{
				flag=1;
				cout<<"ERROR: no class or no student"<<endl;
			}
			for(int j = 0; j<classrooms_size;j++)
			{
				if(classrooms[j].get_classNo()==classroom_id)
				{
					class_of_id=j;
				}
			}
			ifstream inputStream;
			inputStream.open("arrangeC.txt");
			for(int i = 0;i<courses_size;i++)
			{
				getline(inputStream,command);
				istringstream some_stream(command);
				some_stream>>a2>>comp_strDay>>course_hour;
				//cout<<a2<<" "<<comp_strDay<<" "<<course_hour<<endl;
				//cout<<"--"<<class_of_id<<" "<<strDay<<" "<<day_hour<<endl;
				if(comp_strDay==strDay && course_hour==day_hour && a2==class_of_id)
				{
					flag=1;
					StudentPtr[student_index].set_course_attendance_vector(i+1,i+1);
					int data=StudentPtr[student_index].get_attendance_vector_data(i+1);
					data=data+1;
					StudentPtr[student_index].set_attendance_vector(data,i+1);

					StudentPtr[student_index].enterClassroom(classrooms[classroom_index],i+1,classroom_index);					/* call enterclassroom function */

				}
				

			}
			if(flag==0)
			{			
				cout<<"BLOCK: s/he is at another classroom"<<endl;							/* BLOCK: if student enter other classroom */	
			}
		}
		else if(command[1]=='q' && command[3]=='i' && command[4]=='t')				/* quit command */
		{
			int student_id,hour,student_index=-1,classroom_index=-1;
			string classroom_id;
			istringstream some_stream(command);										/* parts string */
			some_stream>>command>>student_id;
			for(int i = 0; i<student_size;i++)
			{
				if(StudentPtr[i].getStudentNo() == student_id)					/* are there student? */
				{
					student_index=i;
				}
			}
			
			if(student_index==-1)
			{
				cout<<"ERROR: no class or no student"<<endl;							/* ERROR BLOCK if are not student and classroom */
			}

			
			else if(student_index!=-1)
			{
				
				StudentPtr[student_index].quitClassroom(classrooms[StudentPtr[student_index].get_class_id()]);			/* call quitclassroom fuction */	
			}
			else{
				cout<<"BLOCK: s/he is at another classroom"<<endl;							/* BLOCK: if student enter other classroom */
			}

		}
		
		else if(command[1]=='a' && command[6]=='d' )										/* attendance command */
		{
			int course_id;
			istringstream some_stream(command);												/* part string */
			some_stream>>command>>course_id;

			for(int i =0 ;i<student_size;i++)
			{
			
				if(StudentPtr[i].get_course_attendance_vector_data(course_id)==course_id)
				{
					cout<<StudentPtr[i].getName2() << " " <<StudentPtr[i].get_attendance_vector_data(course_id)<<" - ";
				}				
			}cout<<endl;
			
		}
		
		
		else
		{
			cout << "BLOCK !! Try again ." << endl ;
		}


	}

	cout<<"FINISH TEST SCENARIO"<<endl;
	inputStream.close();

}