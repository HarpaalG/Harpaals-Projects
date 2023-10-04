#include <iostream>
#include <string>
#include <array>
#include "student.h"
#include "roster.h"
#include "degree.h"
using namespace std;

//Using print function to keep main() clean
void PrintHeaderInfo() {
    cout << "Course: Scripting & Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 010712570" << endl;
    cout << "Name: Harpaal Gohlwar" << endl << endl;
}
    
    
    int main()
{

    PrintHeaderInfo();

    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Harpaal,Gohlwar,hgohlw1@wgu.edu,24,7,39,19,SOFTWARE"
    };


    Roster* classRoster = new Roster(5);
        for (int i = 0; i < 5; i++) {
            classRoster->add(studentData[i]);
        };


        //all functions
    classRoster->printAll();
    cout << endl;

    classRoster->printInvalidemailAddresss();

        for (int i = 0; i < 5; i++) {

            classRoster->printAverageDaysInCourse(classRoster->GetStudentID(i));
        }
        cout << endl;
        cout << endl;

        classRoster->printByDegreeProgram(SOFTWARE);
        cout << endl;
        cout << endl;

        classRoster->remove("A3");
        cout << endl;
        cout << endl;

        classRoster->printAll();
        cout << endl;

        classRoster->remove("A3");
        cout << endl;



        //destructor - should print out text when called
        classRoster->~Roster();
        delete classRoster;

    }