#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

//default constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
	this->degreeProgram;
}
//constructor with parameters

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

//Student setters

void Student::setID(string sID) {
	this->studentID = sID;

	return;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;


}

void Student::setLastName(string lastName) {
	this->lastName = lastName;


}

void Student::setemailAddress(string emailAddress) {
	this->emailAddress = emailAddress;

}

void Student::setAge(int studentAge) {
	this->age = studentAge;


}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	for (int i = 0; i < 3; i++)
		this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;



}



void Student::setDegreeProgram(DegreeProgram degreeprogram) {
	this->degreeProgram = degreeprogram;


}

//Student getters

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getemailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysInCourse() {
	return daysInCourse;
}


DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

//Student print functions

void Student::printID() {
	cout << studentID;

	return;
}

void Student::printFirstName() {
	cout << firstName << endl;

	return;
}

void Student::printLastName() {
	cout << lastName << endl;

	return;
}

void Student::printemailAddress() {
	cout << emailAddress << endl;

	return;
}

void Student::printAge() {
	cout << age << endl;

	return;
}

void Student::printDaysToComp() {
	cout << daysInCourse[0] << " " << daysInCourse[1] << " " << daysInCourse[2] << endl;

	return;
}

void Student::printDegreeProgram() {
	string degreeString;
	if (degreeProgram == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		degreeString = "SOFTWARE";
	}

	cout << degreeString << endl;

	return;
}

//print all

void Student::print() {
	string degreeString;
	if (degreeProgram == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "ERROR";
	}

	//was not able to perfectly align all students. Used \t (tab) to format as best as possible
	cout << studentID
		<< "   First Name: " << getFirstName() << '\t'
		<< "   Last Name: " << getLastName() << '\t'
		<< "   Age: " << getAge() << '\t'
		<< "Days in courses: {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "}" << '\t'
		<< "Degree Program: " << degreeString << " " << endl;

	return;
}