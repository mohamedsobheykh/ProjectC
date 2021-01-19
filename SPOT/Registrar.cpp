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
#include"ActionCalculateGPA.h"
#include"ActionSelectCourseStatus.h"
#include "Actions/ActionReorderCourses.h"
#include "Actions/ActionDoubleConcentration.h"
#include "Actions/ActionMinor.h"

#include"ActionDoubleMajor.h"
#include"ActionDisplayFilter.h"
#include "Actions/ActionReport.h"


using namespace std;

Registrar::Registrar()
{
	pGUI = new GUI;	//create interface object
	pSPlan = new StudyPlan;	//create a study plan.
	pRules = new Rules;
	ImportCourseCat();// to call it automatic when the user run the program
	ImportCourseOfferings();// to call it automatic when the user run the program
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
		
		while (myfile.getline(line, size))
		{
			CourseInfo s;
			string a, b, c, d, e;
			cutting = strtok_s(line, ",", &context);
			int counter = 0;
			if (cutting != NULL)
			{
				//CourseInfo s;
				a = cutting;
			    //cout << cutting << " ";
				s.Code = cutting;
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				
				//a = cutting;
				//cout << a << " ";
				s.Title = cutting;
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				
				//b = cutting;
				//cout << b << " ";
				s.Credits = stoi(cutting);
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				
				c = cutting;
				//cout << c << " "; deleted forever 
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				
				if (string(cutting) != " ")
				{
					s.CoReqList.push_back(cutting);
				}
				
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				
				counter--;
				//cutting = strtok_s(NULL, ",", &context);
				counter++;
				
				//cout << e << " "; deldeted forever
				cutting = strtok_s(NULL, ",", &context);
				counter++;
				
				//f
				//cout << cutting << " ";
				for (int i : {1, 2, 3})
				{
					if (string(cutting) != " ")
					{
						s.PreReqList.push_back(cutting);
					}
					if (i == 3)
						break;
					cutting = strtok_s(NULL, ",", &context);
					counter++;
				}
				counter--;
				
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
	ifstream myfile("a.txt");
	if (!myfile.is_open())
	{
		cout << "there is an error! " << endl;
	}
	else
	{
		char* cutting;
		char* context = nullptr;
		const int size = 10000;
		char line[size];
		AcademicYearOfferings d;
		while (myfile.getline(line, size))
		{
			cutting = strtok_s(line, ",", &context);
	        cout << cutting << endl;
			d.Year = cutting;
			cutting = strtok_s(NULL, ",", &context);
			cout << cutting << endl;
			d.semester = atoi(cutting);
			//cout << d.semester;
			//int SEMESTERNUMBER = atoi(cutting) - 1;
			cutting = strtok_s(NULL, ",", &context);
			while (cutting != NULL)
			{
				cout << cutting << " ";
				cout << endl;
				d.Offerings[d.semester - 1].push_back(cutting);
				cutting = strtok_s(NULL, ",", &context);

			}
			
			cout << endl;
			cout << d.Offerings[2].size(); cout << endl;
			//pRules->OffringsList.push_back(d);
			//cout << "ih";
			//while (1);
			pRules->OffringsList.push_back(d);
			
		}
	}
	 //cout << pRules->OffringsList.size(); // to see if it add the offerings to its vector
}

//getting course data abedal
CourseInfo* Registrar::GetCourseInfo(Course_Code code)
{
	//cout << pRules->OffringsList.size(); // to see if it add the offerings to its vector

	//cout << "HI " << pRules->CourseCatalog.size();
	//while (1);

	for (int i = 0; i < pRules->CourseCatalog.size(); i++)
	{
		//cout << pRules->CourseCatalog[2].Code;
		if (pRules->CourseCatalog[i].Code == code)
		{
			
			return &pRules->CourseCatalog[i];
		}
	}
//here when the user enter a course that does not exist in the catalog

	for (int i = 0; i < pRules->CourseCatalog.size(); i++)
	{
		//cout << pRules->CourseCatalog[2].Code;
		if (pRules->CourseCatalog[i].Code != code)
		{

			return NULL;
		}
	}
}

Course* Registrar::NewCourse(Course_Code code) // to look for the chosed course in the catalog of courses
{
	CourseInfo* info = nullptr;
	for (int i = 0; i < pRules->CourseCatalog.size(); i++)
	{
		//cout << pRules->CourseCatalog[2].Code;
		if (pRules->CourseCatalog[i].Code == code)
		{
			info = &pRules->CourseCatalog[i];
		}
	}
	if (!info)  // if the course does not exist 
		return nullptr;

	Course* pC = new Course(info->Code, info->Title, info->Credits);// to get the course information 
	pC->setInfo(info);
	for (Course_Code i : info->PreReqList) // to check the pre for each course 
		cout << "/////////////" << info->Code << " prereq " << i << endl;
	return pC;
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
	//return &pRules;
	return pRules;
}

/*Rules* Registrar::getRulesOfDoubleMajor() const
{
	return pRules;
}*/


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
	case Display_Notes:
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
	case CalculateGPA:
		RequiredAction = new ActionCalculateGPA(this);
		break;
	case CourseStatus:
		RequiredAction = new ActionSelectCourseStatus(this);
		break;
	case DoubleConcentration:
		RequiredAction = new ActionDoubleConcentration(this);
		break;
	case Minor:
		RequiredAction = new ActionMinor(this);
		break;


	case DoubleMajor:
		RequiredAction = new ActionDoubleMajor(this);
		break;
	case Filter:
		RequiredAction = new ActionDisplayFilter(this);
		break;
	case Report:
		RequiredAction = new ActionReport(this);
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
		checkRules();

		Action* pAct = CreateRequiredAction();
		if (pAct)	//if user doesn't cancel
		{
			if (ExecuteAction(pAct))	//if action is not cancelled
			{
				
				UpdateInterface();
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
	if (pRules->Issues)
		delete pRules->Issues; 

	pRules->Issues = new Issues;

	if (!pSPlan->checkRules(pRules,pGUI))
	{
		
		int MOD = 0; int CRI = 0;
		for (int i = 0; i < pRules->Issues->planIssues.size(); i++)
		{
			if (pRules->Issues->planIssues[i].issueLabel == MODERATE)
				MOD++;
			else if (pRules->Issues->planIssues[i].issueLabel == CRITICAL)
			{
				CRI++;
				//pGUI->GetUserAction(pRules->Issues->planIssues[i].issueInfo);
			}
				
		}
		pGUI->PrintIssue(MOD,CRI);
	}
		
}

Registrar::~Registrar()
{
	delete pGUI;
}
// here