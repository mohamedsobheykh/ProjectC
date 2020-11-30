#include "ActionAddNotes.h"
#include "..\Registrar.h"
//#include "../Courses/UnivCourse.h"
#include <fstream>

	
#include <iostream>
ActionAddNotes::ActionAddNotes(Registrar* p) :Action(p)
{
}

bool ActionAddNotes::Execute()
{
	GUI* pGUI = pReg->getGUI();

	pGUI->PrintMsg("Add notes to plan: Enter your note:");
	string Notes = pGUI->GetSrting();   //I used Notes after I defined it as a data type "string" to save the notes in it 
	fstream notes("notes.txt", ios::app);
	if (notes.is_open())
	{
		notes << Notes << endl;
	}
	else
	{
		cout << "there is an error to open the file";
	}

	notes.close();
	//TODO: add input validation





	//TODO:


	return true;
}


ActionAddNotes::~ActionAddNotes()
{
}
