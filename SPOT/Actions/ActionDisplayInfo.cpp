#include "ActionDisplayInfo.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>

ActionDisplayInfo::ActionDisplayInfo(Registrar* p) : Action(p)
{
}

bool ActionDisplayInfo::Execute()
{
	GUI* pGUI = pReg->getGUI();


	//TODO: add input validation


	ActionData actData = pGUI->GetUserAction("double click on any course to get it's information ..");
	//TODO: add input validation done

	int x, y;
	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		//get coord where user clicked
		x = actData.x;
		y = actData.y;
		int yearWidth = 260;
		int semWidth = 86;
		//int semWidth = 80;
		//int courseHight = 50;
		int choicedYear = (x / yearWidth) + 1;
		SEMESTER  choicedSemester = SEMESTER(((x % yearWidth) / semWidth));
		int choicedCourse = (y - 150) / 50;

		StudyPlan* pSPlan = pReg->getStudyPlay();
		//get the choiced course from the study plan function getcourse()
		Course* pC = pSPlan->getCourse(choicedYear, choicedSemester, choicedCourse);
		
		char CR = char( pC->getCredits() );
		string Code = pC->getCode();
		string Title = pC->getTitle();
		pGUI->PrintMsg("Code: " + Code + ", Title: " + Title + ", CR: " + CR);

		return true;
	}
}

ActionDisplayInfo::~ActionDisplayInfo()
{
}
