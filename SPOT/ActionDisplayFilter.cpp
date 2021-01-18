#include "ActionDisplayFilter.h"
#include"StudyPlan/AcademicYear.h"
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
ActionDisplayFilter::ActionDisplayFilter(Registrar* P):Action(P)
{
}

bool ActionDisplayFilter::Execute()
{
	GUI* pGUI = pReg->getGUI();
	ActionData actData = pGUI->GetUserAction("Enter the courses you want to hide please");


	int yearWidth = 260;
	int semWidth = 86;
	//int semWidth = 80;
	//int courseHight = 50;

	// declaring a pointer to GUI Interface
	int x, y;
	Course* pC;
	if (actData.actType == DRAW_AREA)
	{
		x = actData.x;
		y = actData.y;

		int choicedYear = (x / yearWidth) + 1;
		SEMESTER  choicedSemester = SEMESTER(((x % yearWidth) / semWidth));
		int choicedCourse = (y - 150) / 50;

		StudyPlan* pSPlan = pReg->getStudyPlay();
		pC = pSPlan->getCourse(choicedYear, choicedSemester, choicedCourse);
		Course* pC = pSPlan->getCourse(choicedYear, choicedSemester, choicedCourse);

		if (!pC)
		{
			return false;
		}
		pC->setShowCourse(0);
		pGUI->PrintMsg("The course has been hided");
		
	
	}
return true;
}
ActionDisplayFilter::~ActionDisplayFilter()
{
}

