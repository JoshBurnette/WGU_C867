//
//  softwareStudent.h
//  WGU C867
//
//  Created by Joshua Burnette on 3/25/20.
//  Copyright © 2020 Joshua Burnette. All rights reserved.
//

#ifndef softwareStudent_h
#define softwareStudent_h

#include "student.h"

// subclass of Student
class SoftwareStudent : public Student {

    public:
        
        SoftwareStudent();
        SoftwareStudent(string setStudentID, string setFirstName, string setLastName, string setEmailAddress, int setAge, int setDaysToComplete[], Degree setDegreeType); // constructor
        Degree GetDegreeType(); // function to return DegreeType
        void   Print();

    private:
        
        Degree degreeType = SOFTWARE;
    };


#endif /* softwareStudent_h */
