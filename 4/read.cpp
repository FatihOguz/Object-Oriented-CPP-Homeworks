#include "read.h"



void read_courses_and_classrooms(int& num1,int& num2)
{
	int flag = 1;
	ifstream inputStream;
	string arr;

	inputStream.open("courses_classrooms.txt");				/* open file */

	inputStream>>arr;										/* read word by word */
	while(!inputStream.eof())
	{
		inputStream>>arr;
		if(arr == "CLASSROOMS")
		{
			flag = 0;
		}
		else if(flag==1)
		{
			num1++;				/* class size */
		}
		else
		{
			num2++;			/* course size */
		}
	}
	inputStream.close();				/* close file */

	num1 = num1 / 6;
	num2 = num2 / 3;
}
void read_lecturers(int& num1)
{
	
	ifstream inputStream;
	string arr;

	inputStream.open("lecturers.txt");				/* open file */

	getline(inputStream,arr);
	num1++;
	while(!inputStream.eof())
	{
		getline(inputStream,arr);					/* read line by line*/
		num1++;										/* lecturer size */
	}
	inputStream.close();						/* close file */


}
void read_students(int & student_size)
{
	ifstream inputStream;
	string arr;
	student_size=0;
	inputStream.open("student.txt");				/* open file */

	getline(inputStream,arr);
	student_size++;
	while(!inputStream.eof())
	{
		getline(inputStream,arr);					/* read line by line*/
		student_size++;									/* lecturer size */
	}
	inputStream.close();						/* close file */
}

