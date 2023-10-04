#include <iostream>
#include <string>
#include <array>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;


//class constructor
Roster::Roster(int classSize) {
	this->classSize = classSize;
	this->index = 0;
	for (int i = 0; i < classSize; i++) {
		this->classRosterArray[i] = new Student;
	}
	return;
}

string Roster::GetStudentID(int index) {

	string sID = classRosterArray[index]->getStudentID();
	return sID;
}


//Adding student objects to classRosterArray using Roster::add
void Roster::add(string studentDataTable) {

	string sID, firstname, lastname, emailAddress;
	int studentAge, daysInCourse1, daysInCourse2, daysInCourse3;

	if (index < classSize) {

		classRosterArray[index] = new Student();

		int i = studentDataTable.find(",");
		sID = studentDataTable.substr(0, i);
		classRosterArray[index]->setID(sID);

		int j = i + 1;
		i = studentDataTable.find(",", j);
		firstname = studentDataTable.substr(j, i - j);
		classRosterArray[index]->setFirstName(firstname);

		j = i + 1;
		i = studentDataTable.find(",", j);
		lastname = studentDataTable.substr(j, i - j);
		classRosterArray[index]->setLastName(lastname);

		j = i + 1;
		i = studentDataTable.find(",", j);
		emailAddress = studentDataTable.substr(j, i - j);
		classRosterArray[index]->setemailAddress(emailAddress);

		j = i + 1;
		i = studentDataTable.find(",", j);
		studentAge = stoi(studentDataTable.substr(j, i - j));
		classRosterArray[index]->setAge(studentAge);

		j = i + 1;
		i = studentDataTable.find(",", j);
		daysInCourse1 = stoi(studentDataTable.substr(j, i - j));

		j = i + 1;
		i = studentDataTable.find(",", j);
		daysInCourse2 = stoi(studentDataTable.substr(j, i - j));

		j = i + 1;
		i = studentDataTable.find(",", j);
		daysInCourse3 = stoi(studentDataTable.substr(j, i - j));
		classRosterArray[index]->setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);

		j = i + 1;
		i = studentDataTable.find(",", j);
		string type = studentDataTable.substr(j, i - j);
		if (type == "SOFTWARE") {
			classRosterArray[index]->setDegreeProgram(SOFTWARE);
		}
		else if (type == "SECURITY") {
			classRosterArray[index]->setDegreeProgram(SECURITY);
		}
		else if (type == "NETWORK") {
			classRosterArray[index]->setDegreeProgram(NETWORK);
		}
		else {
			cout << "Degree not found" << endl;
		}
		index++;
	}
	return;
}


//removing student from roster
void Roster::remove(string id) {

	bool foundStudent = false;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (id == classRosterArray[i]->getStudentID()) {
			classRosterArray[i] = nullptr;
			foundStudent = true;
			break;
		}
	}
	if (foundStudent == false) {
		cout << "Error: Student " << id << " not found." << endl;
	}
	else if (foundStudent == true) {
		cout << "Student " << id << " removed." << endl;
	}
	return;
}
//print all
void Roster::printAll() {
	cout << "All current students: " << endl;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] == nullptr)
		{
			continue;
		}
		else {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
	return;
}
//print average number of days
void Roster::printAverageDaysInCourse(string id) {
	for (int i = 0; i < classSize; i++) {
		if (id == classRosterArray[i]->getStudentID()) {
			cout << "Student " << id << " - " << "average days in course: " <<
				((classRosterArray[i]->getDaysInCourse()[0] +
					classRosterArray[i]->getDaysInCourse()[1] +
					classRosterArray[i]->getDaysInCourse()[2]) / 3)
				<< endl;

		}
	}
	return;
}

//print invalid emailAddresss
void Roster::printInvalidemailAddresss() {
	for (int i = 0; i < classSize; ++i) {
		string emailAddressAd = classRosterArray[i]->getemailAddress();
		if ((emailAddressAd.find('@') == string::npos) || (emailAddressAd.find(' ') != string::npos) || (emailAddressAd.find('.') == string::npos)) {
			cout << "Invalid email:" << endl;
			cout << classRosterArray[i]->getStudentID() << ": " << emailAddressAd << endl;
		}
	}
	cout << endl;
	return;
}



//print students with specified degree program
void Roster::printByDegreeProgram(DegreeProgram degPro) {
	string degreeString;
	if (degPro == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degPro == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degPro == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "ERROR";
	}
	cout << "Students with degree program: " << degreeString << endl;
	int numStudents = 0;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degPro) {
			classRosterArray[i]->print();
			++numStudents;
		}
	}
	if (numStudents == 0) {
		cout << "ERROR" << endl;
	}
	return;
}
//destructor with print message
Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	} 
	cout << "Destructor called - Terminating Student Data." << endl;
}