#pragma once
#include"Registrar.h"
#include"Actions/Action.h"
#include<string>

class ActionDoubleMajor : public Action
{
public:

    ActionDoubleMajor(Registrar* P);
    bool virtual Execute();
    virtual ~ActionDoubleMajor();

private:
    //StudyPlan* pSPlan;
    fstream majorrules2;
    Rules* Rule2;
    StudyPlan* pSPlan;
    bool import = true;

};



