#include "ActionDesplayNotes.h"
#include "..\Registrar.h"

//#include "../Courses/UnivCourse.h"
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

	//pGUI->PrintMsg("Add notes to plan: Enter your note:");
	  //I used Notes after I defined it as a data type "string" to save the notes in it 
	ifstream Desplay("notes.txt");
	if (Desplay.is_open())
	{
		//cout << "dgf";
		/*notes << Desplay << endl;*/
		//pGUI->PrintMsg("Desplay");
	}
	else
	{
		cout << "there is an error to open the file";
	}
	
	return true;
}


ActionDesplayNotes::~ActionDesplayNotes()
{
}
