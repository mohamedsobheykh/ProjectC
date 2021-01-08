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
	//getting a pointer to reach GUI and interact with the user
	pGUI->PrintMsg("Add Course to plan: Enter course Code(e.g. CIE202):");

	//using the function printmsg to print a message on the status bar
	//wating the user to enable him to enter the code for that course

	Course_Code code = pGUI->GetSrting();
	
	CourseInfo* CourseData = pReg->GetCourseInfo(code); //added new to get the information of the courses 
	if (CourseData == NULL)   // to check if the code entered does not exist in the catalog of courses
	{
		pGUI->PrintMsg("the code entered does not exist in the catalog of courses, Press enter to take another action:");
		Course_Code code = pGUI->GetSrting();
	}
	

	else // if the code entered already exists in the Catalog 
	{
		ActionData actData = pGUI->GetUserAction("Select a year to add coures to:");
	
		//to get the x and y cordinates on wgich the user clicked 
		int x, y;
		if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
		{
			//get coord where user clicked
			x = actData.x;
			y = actData.y;
			int yearWidth = 260 ;
			//the width of the academic year
			int semWidth = 86;
			//the width of semester
			//drwan area Width = 80;
			//int courseHight = 50;
			int choicedYear = (x / yearWidth) + 1;
			// devide x ordinate by 260 and return an int to get the number of year

			int choicedSemester = ((x % yearWidth) / semWidth) ;
			//getting the remainder of a course with its year  and devide x ordinate by 86 and return an int to get the number of semester
			graphicsInfo gInfo{ x, y };
			//TODO: given course code, get course title, crd hours from registrar
			//For now, we will add any dummy values
			//string Title = "Test101";
			//int crd = 0;
		
	
			string Title = CourseData->Title;// added 
			int crd = CourseData->Credits;// added 

			Course* pC = new Course(code, Title, crd);
			pC->setGfxInfo(gInfo);

			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, choicedYear, SEMESTER(choicedSemester));
			//: Ask registrar to add course to the year selected by the user  done
			//: add the course to the correct year obtained from registrar   done

			
		
		}

	}
	//TODO:
	

	return true;
}


ActionAddCourse::~ActionAddCourse()
{
}
