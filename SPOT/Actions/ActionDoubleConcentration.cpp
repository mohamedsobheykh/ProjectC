#include "ActionDoubleConcentration.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
#include "..\Registrar.h"
#include "..\Rules.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "..\GUI\GUI.h"

#include <iostream>
ActionDoubleConcentration::ActionDoubleConcentration(Registrar* p) :Action(p)
{
}

bool ActionDoubleConcentration::Execute()
{
	R = pReg->getRules();
	R->ReqUnivCredits = R->ReqUnivCredits + 6;
	GUI* pGUI = pReg->getGUI();
	//getting a pointer to reach GUI and interact with the user
	pGUI->PrintMsg("Enter(a) for Nano-FABRICATION , Enter(b) for Nano-VLSI or Enter (c) for Nano-PHOTONICS:");

	string Cocentration = pGUI->GetSrting();
	int i = 0;
	fstream openFile;
	openFile.open("Actions\\NANOREC.txt");//E:
	if (!(openFile))
	{
		cout << "not opened";
		//while (1);
		return false;
	}	

	else {
		//cout << "opened";


		//cout << "the 1st Con";


		//Rules* Rule1 = new Rules;
		char* cutting;
		char* context = nullptr;
		const int size = 500;
		char line[size];
		
		//AcademicYearOfferings d;
		while (openFile.getline(line, size))
		{
			cutting = strtok_s(line, ",", &context);
			//cout << cutting << " ";

			while (cutting != NULL && (i < 11))
			{
				cutting = strtok_s(NULL, ",", &context);
				//R->DoubleCon1.push_back(cutting);
			}
			i++;
			//cout << endl;
			while (cutting != NULL && (i >= 11))
			{
				if ((i == 12) && (Cocentration == "a"))
				{
					cout << cutting << " 1st" << endl;
					R->DoubleCon1.push_back(cutting);
				}
				if ((i == 14) && (Cocentration == "b"))
				{
					cout << cutting << " 2nd" << endl;
					R->DoubleCon2.push_back(cutting);
				}
				if ((i == 16) && (Cocentration == "c"))
				{
					cout << cutting << " 3rd" << endl;
					R->DoubleCon3.push_back(cutting);
				}
				//cutting = strtok_s(line, ",", &context);(i == 16)


				cutting = strtok_s(NULL, ",", &context);

			}
		}
		openFile.close();
	}
	
	//to be compeleted


	return true;
}


ActionDoubleConcentration::~ActionDoubleConcentration()
{
}
