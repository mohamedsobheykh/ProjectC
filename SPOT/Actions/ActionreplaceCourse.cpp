#include "ActionreplaceCourse.h"
#include "..\Registrar.h"


ActionreplaceCourse::ActionreplaceCourse(Registrar* p) :Action(p)
{
}

bool ActionreplaceCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("select the Substituter course u wanna replace with: ");
	string Substituter = pGUI->GetSrting();   //I used Notes after I defined it as a data type "string" to save the notes in it 

	//updated instrad of report#2
	ActionData actData = pGUI->GetUserAction("Select a the replaced coures to:");


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
		//TODO: given course code, get course title, crd hours from registrar
		//For now, we will add any dummy values
		string Title = "Test101";
		int crd = 0;
		Course* pC = new Course(Substituter, Title, crd);
		pC->setGfxInfo(gInfo);

		StudyPlan* pS = pReg->getStudyPlay();
		if (pS->DeleteCourse((y - 150) / 50, choicedYear, SEMESTER(choicedSemester - 1)))
		{
			
			pS->AddCourse(pC, choicedYear, SEMESTER(choicedSemester - 1));
		}
		





		//TODO:


		return true;
	}

}
ActionreplaceCourse::~ActionreplaceCourse()
{
}
