#include "ActionAddCourse.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>
ActionAddCourse::ActionAddCourse(Registrar* p):Action(p)
{
}

bool ActionAddCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();	
	
	pGUI->PrintMsg("Add Course to plan: Enter course Code(e.g. CIE202):");
	Course_Code code = pGUI->GetSrting();

	//TODO: add input validation


	ActionData actData = pGUI->GetUserAction("Select a year to add coures to:");
	//TODO: add input validation done
	
	int x, y;
	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		//get coord where user clicked
		x = actData.x;
		y = actData.y;
		int yearWidth = 260 ;
		int semWidth = 86;
		//int semWidth = 80;
		//int courseHight = 50;
		int choicedYear = (x / yearWidth) + 1;
		int choicedSemester = ((x % yearWidth) / semWidth) ;
	
		
		graphicsInfo gInfo{ x, y };
		//TODO: given course code, get course title, crd hours from registrar
		//For now, we will add any dummy values
		string Title = "Test101";
		int crd = 0;
		Course* pC = new Course(code, Title, crd);
		pC->setGfxInfo(gInfo);

		StudyPlan* pS = pReg->getStudyPlay();
		pS->AddCourse(pC, choicedYear, SEMESTER(choicedSemester));

		
		//TODO: Ask registrar to add course to the year selected by the user  done
		//TODO: add the course to the correct year obtained from registrar   done

		//For the seke of demo, we will add the course to the 1st year, 1st semester
		
	}

	
	//TODO:
	

	return true;
}


ActionAddCourse::~ActionAddCourse()
{
}
