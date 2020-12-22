#include "ActionImportCat.h"
//#include "..\Registrar.h"
#include "..\Rules.h"
#include <vector>
#include "..\Registrar.h"
#include <iostream>
#include <fstream>





bool ActionImportCat::Execute()
{
    CourseCatalog.open("Actions\\CourseCatalog.txt"); //fstream majorrules("Text.txt");
    if (!(CourseCatalog)) {
        return false;
    }

   // int indicator = 1; //line indicator.... starts with line 1 up to line 19

    char* cutting;
    char* context = nullptr;
    const int size = 100;
    char line[size];

    while (CourseCatalog.getline(line, size)) {
        
        //while(cutting != NULL)
        //{ 
            CourseInfo* s = new CourseInfo;
            cutting = strtok_s(line, ",", &context);
            s->Code = cutting;
            cout << "gfd";
            cout << cutting;
            cutting = strtok_s(line, ",", &context);
            s->Title = cutting;
            cout << cutting;
            cutting = strtok_s(line, ",", &context);
            s->Credits = stoi(cutting);
            cout << cutting;
            cutting = strtok_s(line, ",", &context);
            s->CoReqList.push_back(cutting);
            cout << cutting;
            cutting = strtok_s(line, ",", &context);
            s->PreReqList.push_back(cutting);
            cout << cutting;
            
        //}
        
        


    }
  
    (CourseCatalog).close();
    
    return true;
}



ActionImportCat::~ActionImportCat()
{
}