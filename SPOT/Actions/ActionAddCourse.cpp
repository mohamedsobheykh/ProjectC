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
		
		
		
		graphicsInfo gInfo{ x, y };
		//TODO: given course code, get course title, crd hours from registrar
		//For now, we will add any dummy values
		string Title = "Test101";
		int crd = 0;
		Course* pC = new Course(code, Title, crd);
		pC->setGfxInfo(gInfo);
		//FOR THE FIRST YEAR
		if(x < 80)
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 1, FALL);
			
		}
		else if ((x > 86.7) & (x < 166))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 1, SPRING);
			
		}
		else if ((x > 166) & (x < 253))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 1, SUMMER);
			
		}
		

		//FOR THE SECIND YEAR
		else if ((x > 260.2) & (x < 340.2)) // 0.2 TO PASS THE PORDERS
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 2, FALL);
			
		}
		else if ((x > 346.8) & (x < 420.6))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 2, SPRING);
			
		}
		else if ((x > 427.2) & (x < 507.2))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 2, SUMMER);
			
		}
		//FOR THE THIRD YEAR
		else if ((x > 507.2) & (x < 593.8)) // 0.2 TO PASS THE PORDERS
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 3, FALL);
			
		}
		else if ((x > 600.4) & (x < 680.4))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 3, SPRING);
			
		}
		else if ((x > 687) & (x < 767))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 3, SUMMER);
			
		}

		//FOR THE 4TH YAER
		else if ((x > 773.6) & (x < 853.6)) // 0.2 TO PASS THE PORDERS
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 4, FALL);
			
		}
		else if ((x > 860.2) & (x < 940.2))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 4, SPRING);
			
		}
		else if ((x > 946.8) & (x < 1026.8))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			
			pS->AddCourse(pC, 4, SUMMER);
			
		}

		//FOR THE 5TH YEAR
		else if ((x > 1033.4) & (x < 1113.4)) // 0.2 TO PASS THE PORDERS
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 5, FALL);
			
		}
		else if ((x > 1120) & (x < 1200))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 5, SPRING);
			
		}
		else if ((x > 1206.6) & (x < 1286.6))
		{
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 5, SUMMER);	
			
		}
		//END YEARS
		
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
