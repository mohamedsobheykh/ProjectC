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

	//importedPlan->ImportMe(pFile);

	for (int yearNumber = 1; yearNumber <= 5; yearNumber++)
	{
		string* line = new string;
		for (int sem = FALL; sem < SEM_CNT; sem++)
		{
			// getting one semester which represented by a line
			getline(*pFile, *line);

			// getting every course in the semester
			// first create the array which will get the course codes
			int NOFCounter = 0;
			for (char s : *line)
			{
				if (s == ',')
					NOFCounter++;
			}
			NOFCounter++;
			string* courseCode = new string[NOFCounter];

			// it loops on the line string and turn it into and array of course codes
			courseCode[0] = "";
			int Counter = 0;
			for (char s : *line)
			{
				if (s == ',')
				{
					Counter++;
					courseCode[Counter] = "";
				}
				else
				{
					courseCode[Counter] += s;
				}
			}

			// we take the array of the course codes and turn it into objects of courses in the academic semester
			// we start the loop from i=2 because the year name is in i=0 and the sem name is in i=1
			for (int i = 2; i < NOFCounter; i++)
			{

				Course* pC = pReg->NewCourse(courseCode[i]);
				//setting the x graphic info for the course 
				if (!pC)
					continue;
				graphicsInfo courseCoordinates;
				courseCoordinates.x = (yearNumber - 1) * 260 + sem * 86;
				pC->setGfxInfo(courseCoordinates);
				// and finall add the course to the academic year
				importedPlan->AddCourse(pC, yearNumber, SEMESTER(sem));
			}

			delete[] courseCode;
		}
		delete line;
	}
	//change the current study plan at the registrar into the imported plan
	*(pReg->getStudyPlay()) = *importedPlan;
	
	pGUI->PrintMsg("Imported ..");
	
	return true;
}

ActionImportPlan::~ActionImportPlan()
{

}
