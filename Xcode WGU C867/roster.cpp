//
//  roster.cpp
//  WGU C867
//
//  Created by Joshua Burnette on 3/25/20.
//  Copyright © 2020 Joshua Burnette. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include "roster.h"





void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
    
    int numDaysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3}; // pass this to constructor
    
    
    if      (degreeProgram == SECURITY)
        {
            classRosterArray[idx] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, numDaysArray, degreeProgram);
        }
        
    else if (degreeProgram == NETWORKING)
        {
            classRosterArray[idx] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, numDaysArray, degreeProgram);
        }
        
    else
        {
            classRosterArray[idx] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, numDaysArray, degreeProgram);
        }
    
        idx++;
}

void Roster::remove(string studentID)
{
    int i = 0;

        for (i = 0; i < 5; i++)
        {
            if (classRosterArray[i] != nullptr)
            {
                if (classRosterArray[i] -> GetStudentID() == studentID)
            
                {
                    delete classRosterArray[i];
                    classRosterArray[i] = nullptr;
                
                    cout << studentID << " has been removed.";
                
                    return;
                
                }
            }
            
        }
        cout << "Error!! There is no student with the Student ID: " << studentID << endl;
}


void Roster::printAll()
{
    for (int i = 0; i < 5; i++)
    {
        classRosterArray[i] -> Print();
        cout << endl;
    }
    
}


void Roster::printDaysInCourse(string studentID)
{
    float avgNumDays;
    int   totalDays = 0;
    int*  daysToCompleteCourse;
    
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] -> GetStudentID() == studentID)
        {
            daysToCompleteCourse = classRosterArray[i] -> GetDaysToComplete();
            
            for (int j = 0; j < 3; j++)
            {
            totalDays += daysToCompleteCourse[j];
            }
            
            avgNumDays = totalDays / 3;
            cout << "Average number of days for Student " << studentID << " in the three courses: " << avgNumDays << ".";
            break;
            
        }
        
    }
    cout << endl;
    cout << endl;
}


void Roster::printInvalidEmails()
{
    for (int i = 0; i < 5; i++)
    {
        int npos = -1;
        string tempEmailHolder = classRosterArray[i] -> GetEmailAddress();
        
        if ((tempEmailHolder.find ('@') == npos) ||
            (tempEmailHolder.find ('.') == npos) ||
            (tempEmailHolder.find (' ') != npos))
            {
                cout << tempEmailHolder << " is not a valid email address!" << endl;
            }
        
        
    }
    
    cout << endl;
}


void Roster::printByDegreeProgram(Degree degreeProgram)
{
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] -> GetDegreeType() == degreeProgram)
        {
            classRosterArray[i] -> Print();
        }
        
        
    }
    cout << endl;
    
}

Student** Roster::GetClassRosterArray()
{
    return classRosterArray;
}
    


Roster::~Roster()
{
    cout << "Destructor called." << endl;
    for (int i = 0; i < 5; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
    cout << endl;
    return;
    
}

int main (){
    cout << "Course Title: WGU - Scripting and Programming - Applications – C867" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "Student ID: 001221270" << endl;
    cout << "Joshua Burnette" << endl;
    cout << endl;
    cout << "    *********************************************   " << endl;
    cout << endl;
    
    
   
    
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Joshua,Burnette,JBur269@wgu.edu,32,25,0,0,SOFTWARE"
    };
    
    
    Roster classRoster; // contains classRosterArray that i'm building
                // grab each string from student data in a loop... parse into its 9 tokens
                // pass those tokens to the add function
                // Tom wants to see the subclass constructors finished
                // watch that seminar.
    
    
    
    for (int i = 0; i < 5; i++)
    {
        
        string paraHolder[9]; // for each parameter
        string token;
        istringstream stringStream(studentData[i]);
        
        int j = 0;
        
        while (getline(stringStream, token, ','))
        {
            paraHolder[j] = token;
            j++;
        }
        
        Degree degreeType;
        
        if (paraHolder[8] == "SECURITY")
        {
            degreeType = SECURITY;
        }
        
        else if (paraHolder[8] == "NETWORK")
        {
            degreeType = NETWORKING;
        }
        
        else
        {
            degreeType = SOFTWARE;
        }
        
        classRoster.add(paraHolder[0], paraHolder[1], paraHolder[2], paraHolder[3], stoi(paraHolder[4]), stoi(paraHolder[5]), stoi(paraHolder[6]), stoi(paraHolder[7]), degreeType);
        
        
    }
    
    
    
    cout << "printAll():" << endl;
    classRoster.printAll();
    cout << "printInvalidEmails(): " << endl;
    classRoster.printInvalidEmails();
    //loop through classRosterArray and for each element:
    cout << "printAverageDaysInCourse(): " << endl;
    for (int i = 0; i < 5; i++)
    {
       
        classRoster.printDaysInCourse(classRoster.GetClassRosterArray()[i] -> GetStudentID());
    }
    
    cout << "printByDegreeProgram(): " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    
    cout << "remove():" << endl;
    classRoster.remove("A3");
    cout << endl;
    classRoster.remove("A3");
    cout << endl;
    

    
}
