//
//  roster.h
//  WGU C867
//
//  Created by Joshua Burnette on 3/25/20.
//  Copyright © 2020 Joshua Burnette. All rights reserved.
//

#ifndef roster_h
#define roster_h


#include <iostream>
#include <string>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using namespace std;

class Roster {
    public:
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
        void printAll();
        void printByDegreeProgram(Degree degreeProgram);
        void printDaysInCourse(string studentID);
        void printInvalidEmails();
        void remove(string studentID);
        Student** GetClassRosterArray();
        ~Roster();
        
    
    private:
    	
        Student *classRosterArray[5];
        int idx = 0;
    
    
};

#endif /* roster_h */
