#include "ActionDoubleMajor.h"
#include "Registrar.h"
#include "Rules.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "GUI/GUI.h"
#include"StudyPlan/StudyPlan.h"
ActionDoubleMajor::ActionDoubleMajor(Registrar* P):Action(P)
{
}

bool ActionDoubleMajor::Execute()
{

    GUI* pGUI = pReg->getGUI();

    Rule2 = pReg->getRules();
    //ActionData actData = pGUI->GetUserAction("choose your major please! [ CIE / AEROSPACE / RENEWABLE / NANOTECH / ENVAIROMENTAL ] ");
    pGUI->PrintMsg("choose your major please! [ CIE / AEROSPACE / RENEWABLE / NANOTECH / ENVAIROMENTAL ]");
    string majorec = pGUI->GetSrting();


    while ((majorec != "CIE") && (majorec != "AEROSPACE") && (majorec != "RENEWABLE") && (majorec != "NANOTECH") && (majorec != "ENVAIROMENTAL")) {
        pGUI->PrintMsg("Wrong! choose your major please! [ CIE / AEROSPACE / RENEWABLE / NANOTECH / ENVAIROMENTAL ]");
        majorec = pGUI->GetSrting();
    }
    // majorrules = new fstream("CIEREC.txt", ios::in);
    // pGUI->PrintMsg(" bb ");
     //fstream majorrules;
    if (majorec == "CIE") {
        // majorrules = new fstream("CIEREC.txt", ios::in);
        majorrules2.open("Actions\\CIEREC.txt"); //fstream majorrules("Text.txt");
       /*if (!(majorrules)) {
           return false;
        }*/

    }
    else if (majorec == "AEROSPACE") {
        majorrules2.open("Actions\\AEROREC.txt");


    }
    else if (majorec == "RENEWABLE") {
        majorrules2.open("Actions\\RENOREC.txt");

    }
    else if (majorec == "NANOTECH") {
        majorrules2.open("Actions\\NANOREC.txt");

    }
    else if (majorec == "ENVAIROMENTAL") {
        majorrules2.open("Actions\\ENVAREC.txt");

    }
    if (!(majorrules2)) {
        return false;
    }

    //Rules* Rule1 = new Rules;
    //fstream majorrules("Text.txt");
    int indicator = 1; //line indicator.... starts with line 1 up to line 19

    char* t;
    char* context = nullptr;
    const int size = 100;
    char line[size];

    while (majorrules2.getline(line, size)) {
        // pGUI->ClearStatusBar();
         //pGUI->PrintMsg(" yaaaaa ");
        if (indicator == 1) {
            // pGUI->PrintMsg(" webaadeen ");
            t = strtok_s(line, ",", &context);
            Rule2->totalCredits = stoi(t);
            indicator++;
            //pGUI->PrintMsg(t);

        }
        else if (indicator == 2) {
            t = strtok_s(line, ",", &context);
            Rule2->Uni_compulsory_cr = stoi(t);
            t = strtok_s(context, ",", &context);
            Rule2->Uni_elective_cr = stoi(t);
            indicator++;
        }
        else if (indicator == 3) {
            t = strtok_s(line, ",", &context);
            Rule2->ReqTrackCredits = stoi(t);
            indicator++;
        }
        else if (indicator == 4) {
            t = strtok_s(line, ",", &context);
            Rule2->Major_compulsory_cr = stoi(t);
            t = strtok_s(context, ",", &context);
            Rule2->Major_elective_cr = stoi(t);
            indicator++;
        }
        else if (indicator == 5) {
            t = strtok_s(line, ",", &context);
            Rule2->no_concentration = stoi(t);
            indicator++;
        }
        else if (indicator == 6) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                int num = stoi(t);
                Rule2->no_cr_concentrations.push_back(num);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 7) {
            t = strtok_s(line, ",", &context);
            //pGUI->PrintMsg("eheehe");
            while (t != NULL) {
                string s = t;
                Rule2->UnivCompulsory.push_back(s);
                t = strtok_s(NULL, ",", &context);

            }
            indicator++;
        }
        else if (indicator == 8) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->UnivElective.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 9) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->TrackCompulsory.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 10) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->MajorCompulsory.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 11) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->MajorElective.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 12) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->consentration1_com.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 13) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->consentration1_ele.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 14) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->consentration2_com.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 15) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->consentration2_ele.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 16) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->consentration3_com.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 17) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->consentration3_ele.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 18) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->consentration4_com.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 19) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule2->consentration4_ele.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }


    }
    Rule2->ReqMajorCredits = Rule2->Major_compulsory_cr + Rule2->Major_elective_cr;
    (majorrules2).close();
    Rule2->SemMinCredit = 12;
    Rule2->SemMaxCredit = 18;
    pGUI->PrintMsg(" \\*o*/ ");
    // pGUI->PrintMsg(" imported ! ");
   /* StudyPlan* pSPlan = pReg->getStudyPlay();
    bool check;
   check= pSPlan->checkRules(Rule2);*/
    return true;
    import = pSPlan->checkRules(Rule2);
}



/*bool ActionDoubleMajor::checkRulesOfDoubleMajor(Rules* Rule2)
{
    bool issuesStatus = true;
    // Check for the total credits of the studyplan
    vector<Course*> ALL =pSPlan-> getAllCourses();
    int TOTALCR = 0;

    for (int i = 0; i < ALL.size(); i++)
    {
        TOTALCR= (*)



    }


}*/
ActionDoubleMajor::~ActionDoubleMajor()
{
}