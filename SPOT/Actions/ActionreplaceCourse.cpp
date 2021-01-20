#include "ActionreplaceCourse.h"
#include "..\Registrar.h"

//, ActionData actData
ActionreplaceCourse::ActionreplaceCourse(Registrar* p) : Action(p)
{
	//this->actData = actData;
}

bool ActionreplaceCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();

	ActionData actData = pGUI->GetUserAction("Select a  course to be replaced :");

	//updated instrad of report#2
	

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
		//pReg->NewCourse
		pGUI->PrintMsg("Enter the code of Substituter course u wanna replace with: ");
		string Substituter = pGUI->GetSrting();
		graphicsInfo gInfo{ x, y };
		CourseInfo* s = pReg->GetCourseInfo(Substituter);
		string Title = s->Title;//"Test101";
		int crd = s->Credits;// CourseInfo; //pGUI->;
		
		CourseInfo* cinfo = pReg->GetCourseInfo(Substituter);
		Course* pC = new Course(Substituter, Title, crd);

		pC->setGfxInfo(gInfo);
		//bool a = true;
		StudyPlan* pS = pReg->getStudyPlay();

		AcademicYear* c;

		if (pS->DeleteCourse((y - 150) / 50, choicedYear, SEMESTER(choicedSemester - 1)))
		{
			pS->AddCourse(pC, choicedYear, SEMESTER(choicedSemester - 1));
			
		}




		return true;
	}

}
ActionreplaceCourse::~ActionreplaceCourse()
{
}
