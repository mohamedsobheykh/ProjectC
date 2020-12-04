#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>
#include "ActionImportPlan.h"

ActionImportPlan::ActionImportPlan(Registrar* p) : Action(p)
{
}
bool ActionImportPlan::Execute()
{
	StudyPlan* importedPlan = new StudyPlan;

	//////////////////////
	GUI* pGUI = pReg->getGUI();
	pGUI->PrintMsg("(1)- For getting study plan by name, (2)- For getting study plan by directory: ");
	
	string choice = pGUI->GetSrting();
	if (choice == "1")
	{
		pGUI->PrintMsg("Enter the plan name: ");
		name = pGUI->GetSrting();
		directory = "savedplans\\" + name + ".txt";
		//there is no validation that the plan exist or not for now
	}
	else if (choice == "2")
	{
		pGUI->PrintMsg("Enter the directory: ");
		directory = pGUI->GetSrting();
		//there is no validation that this directory contains a plan
	}

	
	///////////////////////

	pFile = new fstream(directory, ios::in);

	if (!(*pFile))
	{
		pGUI->PrintMsg("Failed!");
		return false;
	}

	importedPlan->ImportMe(pFile);
	//change the current study plan at the registrar into the imported plan
	*(pReg->getStudyPlay()) = *importedPlan;

	pGUI->PrintMsg("Imported ..");
	
	return true;
}

ActionImportPlan::~ActionImportPlan()
{

}
