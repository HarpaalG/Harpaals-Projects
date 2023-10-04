#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include <array>
#include "student.h"
#include "degree.h"

using namespace std;



class Roster {

public:

	Student* classRosterArray[5];
	Roster(int classSize);
	string GetStudentID(int index);
	void add(string studentData);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidemailAddresss();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	int classSize;
	int index;

	~Roster();
};

#endif
