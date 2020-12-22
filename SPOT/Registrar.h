#pragma once	
#include "GUI\GUI.h"
#include "Actions\Action.h"
#include "Rules.h"
#include "StudyPlan/StudyPlan.h"



//The maestro class for the application
class Registrar
{
	GUI *pGUI;	//pointer to GUI 
	Rules* pRules;	//Registration rules
	StudyPlan *pSPlan;

public:
	Registrar();
	GUI* getGUI() const;
	Action* CreateRequiredAction();
	bool ExecuteAction(Action*);
	void UpdateInterface();
	StudyPlan* getStudyPlay() const;
<<<<<<< Updated upstream

	Rules* getRules() const;

	void checkRules();

=======
	void ImportCourseCat();
>>>>>>> Stashed changes
	void Run();

	~Registrar();
};

