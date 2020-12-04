#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>
#include "ActionSavePlan.h"

ActionSavePlan::ActionSavePlan(Registrar* p) : Action(p)
{
}

bool ActionSavePlan::Execute()
{
	StudyPlan* currentPlan = pReg->getStudyPlay();

	/////////////////////////

	GUI* pGUI = pReg->getGUI();
	pGUI->PrintMsg("Enter the study plan name: ");
	name = pGUI->GetSrting();
	pGUI->PrintMsg("Saved..");

	directory = "savedplans\\" + name + ".txt";

	pFile = new fstream(directory, ios::out);

	/////////////////////////////////

	if (!(*pFile)) // checks that the file is opened successfully
	{
		return false;
	}

	currentPlan->SaveMe(pFile);

	(*pFile).close();

	//add the saved plan to the list of saved plans
	fstream savedPlans("savedplans\\savedPlans.txt", ios::app); 
	savedPlans << directory << endl;
	savedPlans.close();

	return true;
}

ActionSavePlan::~ActionSavePlan()
{
	
	delete pFile;
}
