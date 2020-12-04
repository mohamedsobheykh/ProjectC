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

	pGUI->PrintMsg("delte Course from plan: Enter course Code(e.g. CIE202):");
	Course_Code code = pGUI->GetSrting();

	//TODO: add input validation


	ActionData actData = pGUI->GetUserAction("Select a year to delete coures from:");
	//TODO: add input validation

	int x, y;
	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		//get coord where user clicked
		x = actData.x;
		y = actData.y;

		graphicsInfo gInfo{ x, y };
		
		//TODO:


		return true;
	}
}

ActionDeleteCourse::~ActionDeleteCourse()
{
}
