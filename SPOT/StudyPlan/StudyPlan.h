#pragma once
#include <vector>
#include "AcademicYear.h"
#include "../GUI/Drawable.h"


//A full study plan for as student
class StudyPlan:public Drawable
{
	int TotalCredits=0;		//total no. of credit hours for courses registred in this year
	int TotalUnivCredits=0, TotalMajorCredits=0,
		TotalTrackCredits=0, TotalConcentrationCredits=0,
		TotalMinorCredits=0;

	vector<AcademicYear*> plan;	//plan is a list of academic years
	//vector<Course*> AllCourses;
	string PlanNotes;
public:
	StudyPlan();
	bool AddCourse(Course*, int year, SEMESTER);
	bool DeleteCourse(int courseOrder, int year, SEMESTER); //delete a course abedal

	void coursetypeindecate(Rules* pRules);

	void virtual DrawMe(GUI*) const;
	virtual void SaveMe(fstream*);
	virtual void ImportMe(fstream*);
	virtual Course* getCourse(int, SEMESTER, int);

	virtual vector<Course*> getAllCourses(); //progreq...........................................

	bool checkRules(Rules* pRules,GUI* pGUI);
	virtual ~StudyPlan();
};

