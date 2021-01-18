#include "ActionMinor.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>
ActionMinor::ActionMinor(Registrar* p) :Action(p)
{
}

bool ActionMinor::Execute()
{
	GUI* pGUI = pReg->getGUI();
	//getting a pointer to reach GUI and interact with the user
	pGUI->PrintMsg("What is your original major? CIE, SPC, NANO, RRE or ENV");
	string orignial = pGUI->GetSrting();
	pGUI->PrintMsg("Enter 5 courses: ");
	if (orignial != "SPC")
	{
		string course[5];
		for (int i = 0; i < 5; i++)
		{
			pGUI->PrintMsg("Enter a course: ");
			course[i] = pGUI->GetSrting();
		}
	}
	// to be compeleted
	return true;
}


ActionMinor::~ActionMinor()
{
}
