#include "ActionImportCourseCatalog.h"
#include "Registrar.h"
#include "Courses/UnivCourse.h"
#include <iostream>
#include<string.h>

ImportCoursecatalog::ImportCoursecatalog(Registrar* p) :Action(p)
{
}

bool ImportCoursecatalog::Execute()
{
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg(" Enter course Code(e.g. CIE202):");
	Course_Code code = pGUI->GetSrting();

	fstream CourseCatalog("CourseCatalog.txt", ios::in);
	fstream CC("CC.txt", ios::out);
	string filename;
	cout << "enter the file name: " << "\n" << endl;
	cin >> filename;
	CourseCatalog.open(filename);
	if (CourseCatalog.is_open())
	{
		string courseCode;
		string title;
		int numOfCreditHour;
		string coreq;
		string prereq;
		while (CourseCatalog >> courseCode >> title >> numOfCreditHour >> coreq >> prereq)
		{
			CC << courseCode << "" << title << "" << endl;
		}
	}


	return true;
}

