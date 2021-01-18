#include "ActionDisplayInfo.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
using namespace std;
#include <iostream>

ActionDisplayInfo::ActionDisplayInfo(Registrar* p , ActionData actData_) : Action(p)
{
	actData = actData_;
}


bool ActionDisplayInfo::Execute()
{
	GUI* pGUI = pReg->getGUI();


	//TODO: add input validation


	//ActionData actData = pGUI->GetUserAction("double click on any course to get it's information ..");
	//TODO: add input validation done

	int x, y;
	Course* pC;
	//if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	do
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
		pC = pSPlan->getCourse(choicedYear, choicedSemester, choicedCourse);

		if (!pC) 
		{
			return false;
		}
		//select the course
		pC->setSelected(true);
		pGUI->DrawCourse(pC);

		char CR = char( pC->getCredits() );
		string Code = pC->getCode();
		string Title = pC->getTitle();
		actData = pGUI->GetUserAction("Code: " + Code + ", Title: " + Title + ", CR: " + CR);
		
		//unselect
		pC->setSelected(false);
		pGUI->DrawCourse(pC);

	} while (pC);

	return true;

}

ActionDisplayInfo::~ActionDisplayInfo()
{
}
