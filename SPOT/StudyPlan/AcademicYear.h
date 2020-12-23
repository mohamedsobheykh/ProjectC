#pragma once
#include <list>

#include "..\Courses\Course.h"
#include "../GUI/Drawable.h"
#include "../Rules.h"
using namespace std;
//Represent one year in the student's study plan
class AcademicYear:public Drawable
{
	int TotalCredits=0;		//total no. of credit hours for courses registred in this year
	int TotalUnivCredits=0, TotalMajorCredits=0,
		TotalTrackCredits=0, TotalConcentrationCredits=0,
		TotalMinorCredits=0;

	//Each year is an array of 3 lists of courses. Each list cossrsponds to a semester
	//So YearCourses[FALL] is the list of FALL course in that year
	//So YearCourses[SPRING] is the list of SPRING course in that year
	//So YearCourses[SUMMER] is the list of SUMMER course in that year
	list<Course*> YearCourses[SEM_CNT];
	
public:
	AcademicYear();
	virtual ~AcademicYear();


	bool AddCourse(Course*, SEMESTER);
	bool DeleteCourse(int, SEMESTER);  // to delete a course from a specific year and demester
	//int size(Course*, SEMESTER);
	
	Course* getCourse(SEMESTER, int);

	void virtual DrawMe(GUI*) const;
	void SaveMe(fstream*, int);
	virtual void ImportMe(fstream*, int);

	bool checkCredits(Rules* pRules);
};

