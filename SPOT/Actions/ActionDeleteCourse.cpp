#include "ActionDeleteCourse.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>
ActionDeleteCourse::ActionDeleteCourse(Registrar* p) :Action(p)
{
}

bool ActionDeleteCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();
	ActionData actData = pGUI->GetUserAction("Select the course to be removed: ");
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
		int choicedYear = (x / yearWidth)+1;
		int choicedSemester = ((x % yearWidth) / semWidth);
		int choicedCourse = (y - 150) / 50;
		StudyPlan* pSPlan = pReg->getStudyPlay();
		pSPlan->DeleteCourse(choicedCourse, choicedYear, SEMESTER(choicedSemester));
		
		

		graphicsInfo gInfo{ x, y };
		//TODO: given course code, get course title, crd hours from registrar
		//For now, we will add any dummy values
		//string Title = "Test101";
		//int crd = 0;
		//string code = "fgd";
		//Course* pC = new Course(code, Title, crd);
		////Course* pC;
		//if(gInfo.y >)
		//pC->setGfxInfo(gInfo);


		//TODO: add input validation


		
			//TODO:

		//pReg->UpdateInterface();
		return true;
		
	}
}

ActionDeleteCourse::~ActionDeleteCourse()
{
}
