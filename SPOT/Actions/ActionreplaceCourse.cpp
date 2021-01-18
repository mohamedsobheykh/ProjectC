#include "ActionreplaceCourse.h"
#include "..\Registrar.h"


ActionreplaceCourse::ActionreplaceCourse(Registrar* p) :Action(p)
{
}

bool ActionreplaceCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();

	

	//updated instrad of report#2
	ActionData actData = pGUI->GetUserAction("Select the replaced coures to:");
	
	
	int x, y;
	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		//get coord where user clicked
		x = actData.x;
		y = actData.y;
		int yearWidth = 260;
		int semWidth = 86;
		//int semWidth = 80;
		//int courseHight = 50;
		int choicedYear = (x / yearWidth) + 1;
		int choicedSemester = ((x % yearWidth) / semWidth) + 1;


		graphicsInfo gInfo{ x, y };
		
		string Title = "Test101";
		int crd = 0;
		pGUI->PrintMsg("Enter the code of Substituter course u wanna replace with: ");
		string Substituter = pGUI->GetSrting();
		Course* pC = new Course(Substituter, Title, crd);
	
		pC->setGfxInfo(gInfo);
		bool a = true;
		StudyPlan* pS = pReg->getStudyPlay();
		
		if ( pS->DeleteCourse((y - 150) / 50, choicedYear, SEMESTER(choicedSemester - 1)))
		{
			pS->AddCourse(pC, choicedYear, SEMESTER(choicedSemester - 1));
			return false;
		}
		
		


		return true;
	}

}
ActionreplaceCourse::~ActionreplaceCourse()
{
}
