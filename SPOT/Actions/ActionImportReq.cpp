#include "ActionImportReq.h"
#include "..\Registrar.h"
#include "..\Rules.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "..\GUI\GUI.h"

using namespace std;

ActionImportReq::ActionImportReq(Registrar* p) :Action(p)
{
}

bool ActionImportReq::Execute()
{
	GUI* pGUI = pReg->getGUI();

	//ActionData actData = pGUI->GetUserAction("choose your major please! [ CIE / AEROSPACE / RENEWABLE / NANOTECH / ENVAIROMENTAL ] ");
	pGUI->PrintMsg("choose your major please! [ CIE / AEROSPACE / RENEWABLE / NANOTECH / ENVAIROMENTAL ]");
	string majorrec = pGUI->GetSrting();


	while ((majorrec != "CIE") && (majorrec != "AEROSPACE") && (majorrec != "RENEWABLE") && (majorrec != "NANOTECH") && (majorrec != "ENVAIROMENTAL")) {
        pGUI->PrintMsg("Wrong! choose your major please! [ CIE / AEROSPACE / RENEWABLE / NANOTECH / ENVAIROMENTAL ]");
        majorrec = pGUI->GetSrting();
	}
   // majorrules = new fstream("CIEREC.txt", ios::in);
   // pGUI->PrintMsg(" bb ");
    //fstream majorrules;
	if (majorrec == "CIE") {
      // majorrules = new fstream("CIEREC.txt", ios::in);
        majorrules.open("Actions\\CIEREC.txt"); //fstream majorrules("Text.txt");
       /*if (!(majorrules)) {
           return false;
        }*/
    
    }
	else if (majorrec == "AEROSPACE") {
        majorrules.open("Actions\\AEROREC.txt");


	}
	else if (majorrec == "RENEWABLE") {
        majorrules.open("Actions\\RENOREC.txt");

	}
	else if (majorrec == "NANOTECH") {
        majorrules.open("Actions\\NANOREC.txt");

	}
	else if (majorrec == "ENVAIROMENTAL") {
        majorrules.open("Actions\\ENVAREC.txt");

	}
    if (!(majorrules)) {
        return false;
    }
    
    //Rules* Rule1 = new Rules;
    //fstream majorrules("Text.txt");
    int indicator = 1; //line indicator.... starts with line 1 up to line 19

    char* t;
    char* context = nullptr;
    const int size = 100;
    char line[size];

    while (majorrules.getline(line, size)) {
        // pGUI->ClearStatusBar();
         //pGUI->PrintMsg(" yaaaaa ");
        if (indicator == 1) {
           // pGUI->PrintMsg(" webaadeen ");
            t = strtok_s(line, ",", &context);
            Rule1->ReqUnivCredits = stoi(t);
            indicator++;
            //pGUI->PrintMsg(t);
            
        }
        else if (indicator == 2) {
            t = strtok_s(line, ",", &context);
            Rule1->Uni_compulsory_cr = stoi(t);
            t = strtok_s(context, ",", &context);
            Rule1->Uni_elective_cr = stoi(t);
            indicator++;
        }
        else if (indicator == 3) {
            t = strtok_s(line, ",", &context);
            Rule1->ReqTrackCredits = stoi(t);
            indicator++;
        }
        else if (indicator == 4) {
            t = strtok_s(line, ",", &context);
            Rule1->Major_compulsory_cr = stoi(t);
            t = strtok_s(context, ",", &context);
            Rule1->Major_elective_cr = stoi(t);
            indicator++;
        }
        else if (indicator == 5) {
            t = strtok_s(line, ",", &context);
            Rule1->no_concentration = stoi(t);
            indicator++;
        }
        else if (indicator == 6) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                int num = stoi(t);
                Rule1->no_cr_concentrations.push_back(num);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 7) {
            t = strtok_s(line, ",", &context);
            //pGUI->PrintMsg("eheehe");
            while (t != NULL) {
                string s = t;
                Rule1->UnivCompulsory.push_back(s);
                t = strtok_s(NULL, ",", &context);
                
            }
            indicator++;
        }
        else if (indicator == 8) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->UnivElective.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 9) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->TrackCompulsory.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 10) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->MajorCompulsory.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 11) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->MajorElective.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 12) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->consentration1_com.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 13) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->consentration1_ele.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 14) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->consentration2_com.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 15) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->consentration2_ele.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 16) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->consentration3_com.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 17) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->consentration3_ele.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 18) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->consentration4_com.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }
        else if (indicator == 19) {
            t = strtok_s(line, ",", &context);
            while (t != NULL) {
                string s = t;
                Rule1->consentration4_ele.push_back(s);
                t = strtok_s(NULL, ",", &context);
            }
            indicator++;
        }


    }
    Rule1->ReqMajorCredits = Rule1->Major_compulsory_cr + Rule1->Major_elective_cr;
    (majorrules).close();
    pGUI->PrintMsg(" \\*o*/ ");
   // pGUI->PrintMsg(" imported ! ");
	return true;
}

ActionImportReq::~ActionImportReq()
{
}