#include "ActionDesplayNotes.h"
#include "..\Registrar.h"
#include <fstream>
#include <istream>
#include <iostream>
using namespace std;

#include <iostream>
ActionDesplayNotes::ActionDesplayNotes(Registrar* p) :Action(p)
{
}

bool ActionDesplayNotes::Execute()
{

	GUI* pGUI = pReg->getGUI();
	ActionData actData = pGUI->GetUserAction("Select a year to display its note:");


	int x, y;
	if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
	{
		//get coord where user clicked
		x = actData.x;
		y = actData.y;
		int yearWidth = 260;
		int semWidth = 86;
		// semWidth = 80;
		// courseHight = 50;
		int choicedYear = (x / yearWidth) + 1;

		if (choicedYear == 1)
		{
			fstream f("notes1.txt", ios::in);
			string line;
			if (f.is_open())
			{
				getline(f, line);
				pGUI->PrintNotes(line);
				f.close();
			}

			pGUI->PrintMsg("press Enter to hide the notes:");
			string Hide = pGUI->GetSrting();
		}
		else if (choicedYear == 2)
		{
			fstream f("notes2.txt", ios::in);
			string line;
			if (f.is_open())
			{
				getline(f, line);
				pGUI->PrintNotes(line);
				f.close();
			}
			pGUI->PrintMsg("press Enter to hide the notes:");
			string Hide = pGUI->GetSrting();

		}
		else if (choicedYear == 3)
		{
			fstream f("notes3.txt", ios::in);
			string line;
			if (f.is_open())
			{
				getline(f, line);
				pGUI->PrintNotes(line);
				f.close();
			}
			pGUI->PrintMsg("press Enter to hide the notes:");
			string Hide = pGUI->GetSrting();

		}

		else if (choicedYear == 4)
		{
			fstream f("notes4.txt", ios::in);
			string line;
			if (f.is_open())
			{
				getline(f, line);
				pGUI->PrintNotes(line);
				f.close();
			}
			pGUI->PrintMsg("press Enter to hide the notes:");
			string Hide = pGUI->GetSrting();

		}
		else if (choicedYear == 5)
		{
			fstream f("notes5.txt", ios::in);
			string line;
			if (f.is_open())
			{
				getline(f, line);
				pGUI->PrintNotes(line);
				f.close();
			}
			pGUI->PrintMsg("press Enter to hide the notes:");
			string Hide = pGUI->GetSrting();

		}
		else
		{
		}
		//pGUI->CreateNewWindow();
	//pGUI->GetSrting
	//pReg->UpdateInterface();

	//window* pWind2 = new window(500, 500, 30, 30);
	//pWind2->DrawDouble(50,50,23.7);
	//pWind2->DrawCircle(20,20,20);
	//pGUI->CreateNewWindow();
	//pGUI->PrintMsg("Add notes to plan: Enter your note:");
	  //I used Notes after I defined it as a data type "string" to save the notes in it 
	//ifstream Desplay("notes.txt");
	//if (Desplay.is_open())
	//{
	//	//cout << "dgf";
	//	/*notes << Desplay << endl;*/
	//	//pGUI->PrintMsg("Desplay");
	//}
	//else
	//{
	//	cout << "there is an error to open the file";
	//}
	//window w(1200,700, 5, 5);

	//w.ChangeTitle("hgfd");
	//w.DrawCircle(2,3,5);
	//window *pWind2 = new window(900, 700, 10, 10);
	//pWind2->DrawRectangle(20,20,20,20);
	//pWind2->ChangeTitle("Notes");
	//pWind2->DrawCircle(50, 50 , 25);
		return true;
	}
}

ActionDesplayNotes::~ActionDesplayNotes()
{
}
