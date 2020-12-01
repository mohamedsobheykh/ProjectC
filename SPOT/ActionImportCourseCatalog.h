

#pragma once
#include "Actions/Action.h"
#include <fstream>
class ImportCoursecatalog :
	public Action
{
public:

	ImportCoursecatalog(Registrar*);
	bool Execute();


};

