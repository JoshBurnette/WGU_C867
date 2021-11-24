//
//  student.cpp
//  WGU C867
//
//  Created by Joshua Burnette on 3/25/20.
//  Copyright © 2020 Joshua Burnette. All rights reserved.
//


#include <iostream>
#include "student.h"

   Student::Student() // constructor with no parameters
{
    // don't think I need this...
}
   
  
Student::Student(string setStudentID, string setFirstName, string setLastName, string setEmailAddress, int setAge, int setDaysToComplete[])
{
        studentID = setStudentID;
        firstName = setFirstName;
        lastName = setLastName;
        emailAddress = setEmailAddress;
        age = setAge;
        daysToComplete[0] = setDaysToComplete[0];
        daysToComplete[1] = setDaysToComplete[1];
        daysToComplete[2] = setDaysToComplete[2];
    
    
}


        

// accessors followed by mutators.... or getters followed by setters:

// but ... do i need all of these individual setters?  or is my constructor doing that work for me?

string  Student::GetStudentID() const
{
            return studentID;
}

void    Student::SetStudentID(string setStudentID)
{
            studentID = setStudentID;
}

string  Student::GetFirstName() const
{
            return firstName;
}

void    Student::SetFirstName(string setFirstName)
{
            firstName = setFirstName;
}

string  Student::GetLastName() const
{
            return lastName;
}

void    Student::SetLastName(string setLastName)
{
            lastName = setLastName;
}
string  Student::GetEmailAddress() const
{
            return emailAddress;
}

void    Student::SetEmailAddress(string setEmailAddress)
{
            emailAddress = setEmailAddress;
}

int     Student::GetAge() const
{
            return age;
}

void    Student::SetAge(int setAge)
{
            age = setAge;
}


int*    Student::GetDaysToComplete()
{
    return daysToComplete;
}

void    Student::SetDaysToComplete(int setDaysToComplete[]){
    daysToComplete[0] = setDaysToComplete[0];
    daysToComplete[1] = setDaysToComplete[1];
    daysToComplete[2] = setDaysToComplete[2];
}

void    Student::Print(){}


Degree  Student::GetDegreeType()
{
    return degreeType;
}

void    Student::SetDegreeType(Degree setDegreeType)
{
    degreeType = setDegreeType;
}




// destructor
Student::~Student()
{

}
