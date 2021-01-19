#include "ActionMinor.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include "..\Rules.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "..\GUI\GUI.h"
#include <iostream>
ActionMinor::ActionMinor(Registrar* p) :Action(p)
{
}

bool ActionMinor::Execute()
{
	R2 = pReg->getRules();
	GUI* pGUI = pReg->getGUI();
	//getting a pointer to reach GUI and interact with the user
	pGUI->PrintMsg("What is your original major? CIE, SPC, NANO, RRE or ENV");
	string orignial = pGUI->GetSrting();
	pGUI->PrintMsg("Enter 5 courses: ");
	string course[5];
	 
	if (orignial != "SPC")
	{
		
		for (int i = 0; i < 5; i++)
		{
			pGUI->PrintMsg("Enter a course: ");
			course[i] = pGUI->GetSrting();
		}
	}
	else
	{
		//string course[5];
		pGUI->PrintMsg("Enter 5 courses: ");
		for (int i = 0; i < 5; i++)
		{
			pGUI->PrintMsg("Enter a course: ");
			course[i] = pGUI->GetSrting();
			while (course[i] == "CIE 202")
			{
				pGUI->PrintMsg("you are not allowed to take C++ again but may be CIE 205: ");
				course[i] = pGUI->GetSrting();
			}
		}

	}
	for (int i = 0; i < 5; i++)
	{
		cout << course[i] << " ";
		R2->Minor.push_back(course[i]);
	}
	// to be compeleted
	return true;
}


ActionMinor::~ActionMinor()
{
}
