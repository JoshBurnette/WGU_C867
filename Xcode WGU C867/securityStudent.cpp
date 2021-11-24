//
//  securityStudent.cpp
//  WGU C867
//
//  Created by Joshua Burnette on 3/25/20.
//  Copyright © 2020 Joshua Burnette. All rights reserved.
//

#include <iostream>

#include "securityStudent.h"


SecurityStudent::SecurityStudent(){}

SecurityStudent::SecurityStudent(string setStudentID, string setFirstName, string setLastName, string setEmailAddress, int setAge, int setDaysToComplete[], Degree setDegreeType) : Student(setStudentID, setFirstName, setLastName, setEmailAddress, setAge, setDaysToComplete)
{
    
    
    degreeType = setDegreeType; // sets DegreeType for the subclass... all the other parameters are passed to the Student class constructor
}


Degree SecurityStudent::GetDegreeType() // function that returns the DegreeType
{
    return degreeType;
}


void   SecurityStudent::Print() // Print function based on E.3.C
{
    cout << GetStudentID();
    cout << "\tFirst Name: " <<  GetFirstName();
    cout << "\tLast Name: " << GetLastName();
    // cout << "\tEmail Address: " << GetEmailAddress();   email not listed in E.3.C
    cout << "\tAge: " << GetAge();
    cout << "\tdaysInCourse: {";
   for (int i = 0; i < 3; i++)
    {
        if (i != 2)
        {
        cout << GetDaysToComplete()[i] << ", ";
        }
        if (i == 2)
        {
            cout <<GetDaysToComplete()[i] << "}";
        }
    }
    cout << " Degree: SECURITY";
    cout << endl;
}


