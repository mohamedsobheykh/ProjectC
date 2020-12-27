#include "Registrar.h"
#include "GUI/GUI.h"
#include "Actions/ActionAddCourse.h"
#include "Actions/ActionDeleteCourse.h"
#include "Actions/ActionAddNotes.h"
#include "Actions/ActionExit.h"
#include "Actions/ActionSavePlan.h"
#include "Actions/ActionImportPlan.h"
#include "Actions/ActionImportReq.h"
#include <iostream>
#include "Actions/ActionDisplayInfo.h"
#include "Actions/ActionDesplayNotes.h"
#include "Actions/ActionreplaceCourse.h"


#include "Actions/ActionReorderCourses.h"


using namespace std;

Registrar::Registrar()
{
	pGUI = new GUI;	//create interface object
	pSPlan = new StudyPlan;	//create a study plan.
	pRules = new Rules;
	ImportCourseCat();
}
void Registrar::ImportCourseCat()
{
	ifstream myfile("Catalog.txt");
	if (!myfile.is_open())
	{
		cout << "there is an error! " << endl;
	}
	else
	{
		char* cutting;
		char* context = nullptr;
		const int size = 100;
		char line[size];
		CourseInfo s;
		while (myfile.getline(line, size))
		{
			string a, b, c, d, e;
			cutting = strtok_s(line, ",", &context);
			int counter = 0;
			while (cutting != NULL)
			{
				//CourseInfo s;
				a = cutting;
			    //cout << cutting << " ";
				s.Code = cutting;
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				//CourseInfo* s = new CourseInfo;
				//if (counter == 0)
				//{
				//a = cutting;
				//cout << a << " ";
				s.Title = cutting;
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				//}
				//else if (counter == 1)
				//{
				//b = cutting;
				//cout << b << " ";
				s.Credits = stoi(cutting);
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				//}
				//else if (counter == 2)
				//{
				c = cutting;
				//cout << c << " "; deleted forever 
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				//}
				//else if (counter == 3)
				//{
				d = cutting;
				//cout << d << " ";
				if (d != " ")
				{
					s.CoReqList.push_back(cutting);
				}
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				//}
				//else if (counter == 4)
				//{
				e = cutting;
				//cout << e << " "; deldeted forever
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				//}
				//f
				//cout << cutting << " ";
				if (cutting != " ")
				{
					s.PreReqList.push_back(cutting);
				}
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				//g
				//cout << cutting << " ";
				if (cutting != " ")
				{
					s.PreReqList.push_back(cutting);
				}
				cutting = strtok_s(NULL, ",", &context);
				counter++;

				//cout << cutting << " ";
				if (cutting != " ")
				{
					s.PreReqList.push_back(cutting);
				}
				cutting = strtok_s(NULL, ",", &context);
				counter++;

				//else if (counter == 5)
				//{
				//    //e = cutting;
				//    cout << cutting << " ";
				cutting = strtok_s(NULL, ",", &context);
				//    counter++;
				//}
				//s->Code = cutting;
				//cout << "gfd";
				//pRules->CourseCatalog.push_back(s);
			}
			
			//cout << endl;
			//RegRules.CourseCatalog.push_back(s);
			pRules->CourseCatalog.push_back(s);
			//cout << "abd";
		}
	} 
}

void Registrar::ImportCourseOfferings()
{
}

//getting course data abedal
CourseInfo* Registrar::GetCourseInfo(Course_Code code)
{
	//cout << "HI " << pRules->CourseCatalog.size();
	//while (1);

	for (int i = 0; i < pRules->CourseCatalog.size(); i++)
	{
		//cout << pRules->CourseCatalog[2].Code;
		if (pRules->CourseCatalog[i].Code == code)
		{
			
			return &pRules->CourseCatalog[i];
		}

		else
		{
			//cout << i;
			//return NULL;
		}
	}
	
}

//returns a pointer to GUI
GUI* Registrar::getGUI() const
{
	return pGUI;
}

//returns the study plan
StudyPlan* Registrar::getStudyPlay() const
{
	return pSPlan;
}

Rules* Registrar::getRules() const
{
	return pRules;
}


Action* Registrar::CreateRequiredAction() 
{	
	ActionData actData = pGUI->GetUserAction("Pick and action...");
	Action* RequiredAction = nullptr;

	switch (actData.actType)
	{
	case ADD_CRS:	//add_course action
		RequiredAction = new ActionAddCourse(this);
		break;
	case DEL_CRS:   // delete_course action 'abedal
		RequiredAction = new ActionDeleteCourse(this);
		break;
	case Replace_CRS:   // replace_course action 'abedal
		RequiredAction = new ActionreplaceCourse(this);
		break;
	case ADD_Notes:
		RequiredAction = new ActionAddNotes(this);
		break;
	case Despaly_Notes:
		RequiredAction = new ActionDesplayNotes(this);
		break;
	case SAVE:
		RequiredAction = new ActionSavePlan(this);
		break;
	case LOAD:
		RequiredAction = new ActionImportPlan(this);
		break;
	case ImportReq:
		RequiredAction = new ActionImportReq(this);
		break;
	case EXIT:
		RequiredAction = new ActionExit(this);
		break;
	case DRAW_AREA:
		RequiredAction = new ActionDisplayInfo(this , actData);
		break;
	case REORDER:
		RequiredAction = new ActionReorderCourses(this);
		break;


	//TODO: Add case for each action
	
	/*case EXIT:
		break;
		*/
	}
	return RequiredAction;
}

//Executes the action, Releases its memory, and return true if done, false if cancelled
bool Registrar::ExecuteAction(Action* pAct)
{
	bool done = pAct->Execute();
	delete pAct;	//free memory of that action object (either action is exec or cancelled)
	return done;
}

void Registrar::Run()
{

	while (true)
	{
		//update interface here as CMU Lib doesn't refresh itself
		//when window is minimized then restored
		UpdateInterface();

		Action* pAct = CreateRequiredAction();
		if (pAct)	//if user doesn't cancel
		{
			if (ExecuteAction(pAct))	//if action is not cancelled
			{
				UpdateInterface();
				checkRules();
			}
		}
		//cout << ActionImportReq.Rule1.
		
	}
}


void Registrar::UpdateInterface()
{
	pGUI->UpdateInterface();	//update interface items
	pSPlan->DrawMe(pGUI);		//make study plan draw itself
}

void Registrar::checkRules()
{
	pRules->Issues = new Issues;

	if (!pSPlan->checkRules(pRules))
	{
		//TODO
		for (int i = 0; i < pRules->Issues->planIssues.size(); i++)
		{
			//pGUI->GetUserAction(pRules->Issues->planIssues[i].issueInfo);
		}
	}

	delete pRules->Issues;
		
}

Registrar::~Registrar()
{
	delete pGUI;
}
// here
////cutting = strtok_s(NULL, ",", &context);
//				/*a = cutting;
//				cout << cutting << " ";
//				cutting = strtok_s(NULL, ",", &context);
//				counter++;*/
//				//CourseInfo* s = new CourseInfo;
//
//if (counter == 0)
//{
//	//s.Code = cutting;
//	cout << cutting << " ";
//	cutting = strtok_s(NULL, ",", &context);
//	counter++;
//}
//else if (counter == 1)
//{
//	//s.Title = cutting;
//	cout << cutting << " ";
//	cutting = strtok_s(NULL, ",", &context);
//	counter++;
//}
//else if (counter == 2)
//{
//	//s.Credits = stoi(cutting);
//	cout << cutting << " ";
//	cutting = strtok_s(NULL, ",", &context);
//	counter++;
//}
//else if (counter == 3)
//{
//	//s.CoReqList.push_back(cutting);
//	cout << cutting << " ";
//	cutting = strtok_s(NULL, ",", &context);
//	counter++;
//}
//else if (counter == 4)
//{
//	e = cutting;
//	cout << e << " ";
//	cutting = strtok_s(NULL, ",", &context);
//	counter++;
//}
//else if (counter == 5)
//{
//	//e = cutting;
//	cout << cutting << " ";
//	cutting = strtok_s(NULL, ",", &context);
//	counter++;
//}
////s->Code = cutting;
////cout << "gfd";