#include "Registrar.h"

#include "Actions/ActionAddCourse.h"
#include "Actions/ActionDeleteCourse.h"
#include "Actions/ActionAddNotes.h"
#include "Actions/ActionExit.h"

Registrar::Registrar()
{
	pGUI = new GUI;	//create interface object
	pSPlan = new StudyPlan;	//create a study plan.
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

bool Registrar::saveStudyPlan(string name)
{
	string directory = "savedplans\\" + name + ".txt";
	fstream* pFile = new fstream (directory, ios::out);

	if (!*pFile) // checks that the file is opened successfully
	{
		return false;
	}

	pSPlan->SaveMe(pFile);

	(*pFile).close();
	delete pFile;
	return true;
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
	case ADD_Notes:
		RequiredAction = new ActionAddNotes(this);
		break;
	case EXIT:
		RequiredAction = new ActionExit(this);
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
				UpdateInterface();
		}
		
	}
}


void Registrar::UpdateInterface()
{
	pGUI->UpdateInterface();	//update interface items
	pSPlan->DrawMe(pGUI);		//make study plan draw itself
}

Registrar::~Registrar()
{
	delete pGUI;
}
