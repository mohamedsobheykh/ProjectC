#pragma once
#include "..\Courses\Course.h"
#include "../Rules.h"
#include <fstream>
#include "Action.h"

class ActionImportCat : public Action
{
	
    //Course* s = new Course (string r_code, string r_title, int crd);
	fstream CourseCatalog;
public:
	//ActionImportcat(Registrar*);
	bool virtual Execute();
	virtual ~ActionImportCat();
};
