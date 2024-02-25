/*
 * FileIO.cpp
 *
 *  Created on: 3 Mar 2021
 *      Author: musarratahmed
 */



#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool getStu(ifstream& stuFile, int& studId, int& exam1, int& exam2, int& final)
{
	stuFile>>studId>>exam1>>exam2>>final;
	if(!stuFile)
	{
		return false;
	}
	return true;
}

void calcGrade(int exam1, int exam2, int final, int& avg, char& grade)
{
	avg = (exam1+exam2+final)/3;

	if(avg >= 90)
		grade = 'A';
	else if(avg >= 80)
		grade = 'B';
	else if(avg >= 70)
		grade = 'C';
	else if(avg >= 60)
		grade = 'D';
	else
		grade = 'F';
	return;
}

void writeStu(ofstream& gradeFile, int studId, int avg, char grade)
{
	gradeFile.fill('0');
	gradeFile<<setw(4)<<studId;
	gradeFile.fill(' ');
	gradeFile<<setw(3)<<avg;
	gradeFile<<' '<<grade<<endl;

	return;
}

int main()
{
	ifstream stuFile;
	stuFile.open("/Users/musarratahmed/eclipse-workspace/FileHandling/Students.txt");

	if(!stuFile)
	{
		cout<<"Error opening student file";
		exit(100);
	}

	ofstream gradeFile;
	gradeFile.open("/Users/musarratahmed/eclipse-workspace/FileHandling/Grades.txt");
	if(!gradeFile)
	{
		cout<<"Error opening grade file";
		exit(100);
	}

	int studentId;
	int exam1,exam2;
	int finalExam;
	int avg;
	char grade;

	while(getStu(stuFile, studentId, exam1, exam2, finalExam))
	{
		calcGrade(exam1, exam2, finalExam, avg, grade);
		writeStu(gradeFile, studentId, avg, grade);
	}

	stuFile.close();
	gradeFile.close();
	return 0;
}
