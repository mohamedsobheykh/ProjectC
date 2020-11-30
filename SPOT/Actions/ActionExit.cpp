#include "ActionExit.h"
#include <iostream>
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include <fstream>


#include <iostream>
ActionExit::ActionExit(Registrar* p) :Action(p)
{
}

bool ActionExit::Execute()
{
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("Do want to leave?! 'yes' or 'y' to exit : ");
	string leave = pGUI->GetSrting();   //I used Notes after I defined it as a data type "string" to save the notes in it 

	if (leave == "y" || leave == "yes")
	{
		exit(-1);
	}
	else
	{

	}

	return true;
}


ActionExit::~ActionExit()
{
}
