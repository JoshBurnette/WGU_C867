//
//  student.h
//  WGU C867
//
//  Created by Joshua Burnette on 3/25/20.
//  Copyright © 2020 Joshua Burnette. All rights reserved.
//

#ifndef student_h
#define student_h

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {
    
        

    public:
    
        Student();  //constructor
        //Student(string, string, string, string, int, int*);
        Student(string setStudentID, string setFirstName, string setLastName, string setEmailAddress, int setAge, int setDaysToComplete[]);
    
        // mutators or setters for each instance variable from part D1
        void    SetStudentID(string setStudentID);
        void    SetFirstName(string setFirstName);
        void    SetLastName(string setLastName);
        void    SetEmailAddress(string setEmailAddress);
        void    SetAge(int setAge);
        void    SetDaysToComplete(int setDaysToComplete[]);
        void    SetDegreeType(Degree setDegreeType);
        
        
        // accessors or getters for each instance variable from part D1
        string  GetStudentID() const;
        string  GetFirstName() const;
        string  GetLastName() const;
        string  GetEmailAddress() const;
        int     GetAge() const;
        int*    GetDaysToComplete();
    
virtual void    Print() = 0;
virtual Degree  GetDegreeType() = 0;
    
        // destructor
virtual ~Student();
    
    
    
    private:
    
        string  studentID;
        string  firstName;
        string  lastName;
        string  emailAddress;
        int     age;
        int     daysToComplete[3];
        Degree  degreeType;
        
};


#endif /* student_h */
