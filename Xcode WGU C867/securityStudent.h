//
//  securityStudent.h
//  WGU C867
//
//  Created by Joshua Burnette on 3/25/20.
//  Copyright © 2020 Joshua Burnette. All rights reserved.
//

#ifndef securityStudent_h
#define securityStudent_h


#include "student.h"

// subclass of Student

class SecurityStudent : public Student {

    public:
        SecurityStudent();
        SecurityStudent(string setStudentID, string setFirstName, string setLastName, string setEmailAddress, int setAge, int setDaysToComplete[], Degree setDegreeType); // constructor
        Degree GetDegreeType(); // function to return the DegreeType
        void   Print();

    private:
    
        Degree degreeType = SECURITY;
};

#endif /* securityStudent_h */
