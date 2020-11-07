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

Course Administrator::arrangeTimeTable(vector<Course> courses,int courses_id)
{
	int i=0;
	int count=0;
	int day;
	Course temp;
	
	
	if(courses_id >= courses.size())			/* control course */
	{
		cout<<"Error: no course"<<endl;
		return temp;
	}
	if(courses[courses_id].timetable==1 || courses[courses_id].timetable==2)		/* control before arrange*/
	{
		
		cout<<"Assigned Before:"; /* print course and date*/
		cout<<courses[courses_id].name<<" "<<courses[courses_id].sDate1<<"_"<<courses[courses_id].sHourStart1
					<<"_"<<courses[courses_id].sHourFinish1<<","<<courses[courses_id].sDate2<<"_"<<courses[courses_id].sHourStart2
					<<"_"<<courses[courses_id].sHourFinish2<<endl;
					temp.timetable=2;
		return temp;
	}
	else
	{
		for(i=0;i<courses_id;i++)
		{
			count = count + courses[i].totalHours;
		}
		
		courses[courses_id].timetable=1;
		day=count%5;

		/* random arrange course*/
		if(day==0)								/* random arrange for monday */
		{
			day=count % 8;
			day=day+8;
			courses[courses_id].sDate1="Mon_";				/* arrange day and hours */	
			courses[courses_id].sHourStart1=day;		
			courses[courses_id].sHourFinish1=day + courses[courses_id].totalHours;

			for(i=courses[courses_id].sHourStart1;i<courses[courses_id].sHourFinish1;i++)
				courses[courses_id].lecturerDates.pzt[i-8]=1;
		}
		else if(day==1)								/* random arrange for tuesday */
		{
			day=count % 8;
			day=day+8;
			courses[courses_id].sDate1="Tue_";
			courses[courses_id].sHourStart1=day;			/* arrange day and hours */	
			courses[courses_id].sHourFinish1=day + courses[courses_id].totalHours;
			
			for(i=courses[courses_id].sHourStart1;i<courses[courses_id].sHourFinish1;i++)
				courses[courses_id].lecturerDates.sal[i-8]=1;
		}
		else if(day==2)								/* random arrange for wednesday */
		{
			day=count % 8;
			day=day+8;
			courses[courses_id].sDate1="Wed_";
			courses[courses_id].sHourStart1=day;			/* arrange day and hours */	
			courses[courses_id].sHourFinish1=day + courses[courses_id].totalHours;
			
			for(i=courses[courses_id].sHourStart1;i<courses[courses_id].sHourFinish1;i++)
				courses[courses_id].lecturerDates.car[i-8]=1;
		}
		else if(day==3)								/* random arrange for thuesday */
		{
			day=count % 8;
			day=day+8;
			courses[courses_id].sDate1="Thu_";
			courses[courses_id].sHourStart1=day;			/* arrange day and hours */	
			courses[courses_id].sHourFinish1=day + courses[courses_id].totalHours;
			
			for(i=courses[courses_id].sHourStart1;i<courses[courses_id].sHourFinish1;i++)
				courses[courses_id].lecturerDates.per[i-8]=1;
		}	
		else if(day==4)										/* random arrange for friday */
		{
			day=count % 8;
			day=day+8;
			courses[courses_id].sDate1="Fri_";
			courses[courses_id].sHourStart1 = day;			/* arrange day and hours */	
			courses[courses_id].sHourFinish1 = day + courses[courses_id].totalHours;
			
			for(i=courses[courses_id].sHourStart1;i<courses[courses_id].sHourFinish1;i++)
				courses[courses_id].lecturerDates.cum[i-8]=1;
		}
		temp=courses[courses_id];
	}
	return temp;
	
}

Classroom Administrator::arrangeClassroom(vector <Classroom> classrooms,int classrooms_size,vector <Course> courses,int courses_size,Classroom crm, Course crs)
{
	int i=0,j=0,k=0;
	int flag1=0;  		/* is there classroom */
	int flag2=0;	/* is there  course  */
	int flag3=0;	/* is courses's timetable ?  */
	int index=crs.id;
	Classroom temp;
	int index2=77777;
	for(i=0;i<classrooms_size;i++)
	{
		if(classrooms[i].id==crm.id)
		{
			flag1=1; 				/* there is classroom  */
			index2=i;
		}
	}
	for(i=0;i<courses_size;i++)
	{
		if(courses[i].id==crs.id)
		{
			flag2=1;
			index=i;			/*  there is course */
		}
	}
	

	if(courses[index].timetable!=0)
	{
		flag3=1;			/* course's timetable is */
	}
	
	if(flag1==0 || flag2==0 || flag3==0)
	{
		
		cout<<"Error: no class or no course or timetable not arranged yet "<<endl;
		return temp; /* classroom's of flag 0 DONE if do 1 !!!!!!!!!!!*/
	}
	
	crm=classrooms[index2];
	if(flag1==1 && flag2==1 && flag3==1)		/* PART DONE */
	{	

		
		int count = 0;
		if(courses[index].sDate1=="Mon")			/* arrange Monday */
		{
			for(i=0;i<12;i++)
			{
				if(courses[index].lecturerDates.pzt[i]==1 && classrooms[index2].available.pzt[i]==0)
				{
					count++;				/* compare totalHours */
				}

			}
			if(count==courses[index].totalHours)
			{
				for(i=0;i<12;i++)
				{
					if(courses[index].lecturerDates.pzt[i]==1)
					{
						crm.available.pzt[i]=1;					/* do available 1 */
					}
				}
			}

			
		}

		else if(courses[index].sDate1=="Tue")		/* arrange tuesday */
		{
			for(i=0;i<12;i++)
			{
				if(courses[index].lecturerDates.sal[i]==1 && classrooms[index2].available.sal[i]==0)
				{
					count++;			/* compare totalHours */
				}

			}
			if(count==courses[index].totalHours)
			{
				for(i=0;i<12;i++)
				{
					if(courses[index].lecturerDates.sal[i]==1)
					{
						crm.available.sal[i]=1;					/* do available 1 */
					}
				}
			}
		}

		else if(courses[index].sDate1=="Wed")			/* arrange wednesday */
		{
			for(i=0;i<12;i++)
			{
				if(courses[index].lecturerDates.car[i]==1 && classrooms[index2].available.car[i]==0)
				{
					count++;			/* compare totalHours */
				}		

			}
			if(count==courses[index].totalHours)
			{
				for(i=0;i<12;i++)
				{
					if(courses[index].lecturerDates.car[i]==1)
					{
						crm.available.car[i]=1;				/* do available 1 */
					}
				}
			}
		}

		else if(courses[index].sDate1=="Thu")				/* arrange thuesday */
		{
			for(i=0;i<12;i++)
			{
				if(courses[index].lecturerDates.per[i]==1 && classrooms[index2].available.per[i]==0)
				{
					count++;				/* compare totalHours */
				}

			}
			if(count==courses[index].totalHours)
			{
				for(i=0;i<12;i++)
				{
					if(courses[index].lecturerDates.per[i]==1)
					{
						crm.available.per[i]=1;			/* do available 1 */
					}
				}
			}
		}

		else if(courses[index].sDate1=="Fri")				/* arrange friday */
		{
			for(i=0;i<12;i++)
			{
				if(courses[index].lecturerDates.cum[i]==1 && classrooms[index2].available.cum[i]==0)
				{
					count++;				/* compare totalHours */
				}

			}
			if(count==courses[index].totalHours)
			{
				for(i=0;i<12;i++)
				{
					if(courses[index].lecturerDates.cum[i]==1)
					{
						crm.available.cum[i]=1;						/* do available 1 */
					}
				}
			}
		}
		temp=crm;
		temp.flag=1;		/* courses's of flag 0 DONE if do 1 !!!!!!!!!!!*/
		return temp;
		
	}
	else
	{
		cout<<"Block: class is not available, there is another class assigned"<<endl;
		return temp;	/* classroom's flag  0 if  do  1 !!!!!!(DONE) */
	}
}