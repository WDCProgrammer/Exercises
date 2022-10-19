#include "WorkFlowEngine.h"



void WorkFlowEngine::Run(WorkFlow* workflow)
{

    for(auto flow: workflow->GetActivities())
        {
            flow->Execute();
        }


}