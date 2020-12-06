#include "ActionReorderCourses.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>

ActionReorderCourses::ActionReorderCourses(Registrar* p) : Action (p)
{
}

bool ActionReorderCourses::Execute()
{
	GUI* pGUI = pReg->getGUI();


	//TODO: add input validation


	ActionData actDataDel = pGUI->GetUserAction("Select the course ..");
	//TODO: add input validation done
	int yearWidth = 260;
	int semWidth = 86;

	int xDel, yDel;
	if (actDataDel.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		//get coord where user clicked
		xDel = actDataDel.x;
		yDel = actDataDel.y;

		
		int choicedYearDel = (xDel / yearWidth) + 1;
		SEMESTER  choicedSemesterDel = SEMESTER(((xDel % yearWidth) / semWidth));
		int choicedCourseDel = (yDel - 150) / 50;

		StudyPlan* pSPlan = pReg->getStudyPlay();

		//Course* pNewC = new Course("", "", 0);
		Course* pC = pSPlan->getCourse(choicedYearDel, choicedSemesterDel, choicedCourseDel);

		if (!pC)
		{
			return false;
		}

		//select the course to highlight it with red highlighter
		pC->setSelected(true);
		pGUI->DrawCourse(pC);

		//get the choiced course from the study plan function getcourse()
		ActionData actDataAdd = pGUI->GetUserAction("select the drop place ..");

		//unhighlight after the user chosed the drop place
		pC->setSelected(false);

		int xAdd, yAdd;

		if (actDataAdd.actType == DRAW_AREA)
		{
			xAdd = actDataAdd.x;
			yAdd = actDataAdd.y;

			int choicedYearAdd = (xAdd / yearWidth) + 1;
			SEMESTER  choicedSemesterAdd = SEMESTER(((xAdd % yearWidth) / semWidth));
			int choicedCourseAdd = (yAdd - 150) / 50;

			//check that the user doesn't put the course in the same place
			if (choicedYearAdd == choicedYearDel && choicedSemesterAdd == choicedSemesterDel)
			{
				return false;
			}
			// check that the course is added successfully
			if (! pSPlan->AddCourse(pC, choicedYearAdd, choicedSemesterAdd))
			{
				
				return false;
			}

			pSPlan->DeleteCourse(choicedCourseDel, choicedYearDel, choicedSemesterDel);

			pGUI->PrintMsg("Done :*");
		}
		else
		{
			return false;
		}


	}
	return true;
}

ActionReorderCourses::~ActionReorderCourses()
{
}
