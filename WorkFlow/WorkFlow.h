#ifndef WORKFLOW_H
#define WORKFLOW_H
#include "Activity.h"
#include <vector>
class WorkFlow
{
    public:
        void AddActivity(Activity* activity);
        const std::vector<Activity*> GetActivities();

    private:
        std::vector<Activity*> activities;
};


#endif