#include "ActionAddNotes.h"
#include "..\Registrar.h"
#include <fstream>
#include <iostream>
ActionAddNotes::ActionAddNotes(Registrar* p) :Action(p)
{
}

bool ActionAddNotes::Execute()
{

	GUI* pGUI = pReg->getGUI();

	ActionData actData = pGUI->GetUserAction("Select a year to add note to: ");


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
		
		if (choicedYear == 1)
		{
			pGUI->PrintMsg("Enter your note: ");
			string Notes = pGUI->GetSrting();   //I used Notes after I defined it as a data type "string" to save the notes in it 
			//pGUI->PrintNotes(Notes);


			fstream notes("notes1.txt", ios::app);
			if (notes.is_open())
			{
				notes << Notes << endl;
			}
			else
			{
				pGUI->PrintMsg("there is an error to open the file");
			}

			notes.close();
		}
		else if(choicedYear == 2)
		{
			pGUI->PrintMsg("Enter your note: ");
			string Notes = pGUI->GetSrting();   //I used Notes after I defined it as a data type "string" to save the notes in it 
			//pGUI->PrintNotes(Notes);


			fstream notes("notes2.txt", ios::app);
			if (notes.is_open())
			{
				notes << Notes << endl;
			}
			else
			{
				pGUI->PrintMsg("there is an error to open the file");
			}

			notes.close();
			
		}
		else if (choicedYear == 3)
		{
			pGUI->PrintMsg("Enter your note: ");
			string Notes = pGUI->GetSrting();   //I used Notes after I defined it as a data type "string" to save the notes in it 
			//pGUI->PrintNotes(Notes);


			fstream notes("notes3.txt", ios::app);
			if (notes.is_open())
			{
				notes << Notes << endl;
			}
			else
			{
				pGUI->PrintMsg("there is an error to open the file");
			}

			notes.close();

		}

		else if (choicedYear == 4)
		{
			pGUI->PrintMsg("Enter your note: ");
			string Notes = pGUI->GetSrting();   //I used Notes after I defined it as a data type "string" to save the notes in it 
			//pGUI->PrintNotes(Notes);


			fstream notes("notes4.txt", ios::app);
			if (notes.is_open())
			{
				notes << Notes << endl;
			}
			else
			{
				pGUI->PrintMsg("there is an error to open the file");
			}

			notes.close();

		}
		else if (choicedYear == 5)
		{
			pGUI->PrintMsg("Enter your note: ");
			string Notes = pGUI->GetSrting();   //I used Notes after I defined it as a data type "string" to save the notes in it 
			//pGUI->PrintNotes(Notes);


			fstream notes("notes5.txt", ios::app);
			if (notes.is_open())
			{
				notes << Notes << endl;
			}
			else
			{
				pGUI->PrintMsg("there is an error to open the file");
			}

			notes.close();

		}
		else
		{}
	}
	//GUI* pGUI = pReg->getGUI();
	//pGUI->PrintMsg("Add notes to plan: Enter your note:");
	//
	//
	//string Notes = pGUI->GetSrting();   //I used Notes after I defined it as a data type "string" to save the notes in it 
	////pGUI->PrintNotes(Notes);
	//	

	//fstream notes("notes.txt", ios::app);
	//if (notes.is_open())
	//{
	//	notes << Notes << endl;
	//}
	//else
	//{
	//	pGUI->PrintMsg("there is an error to open the file");
	//}

	//notes.close();
	
	

	return true;
}


ActionAddNotes::~ActionAddNotes()
{
}
