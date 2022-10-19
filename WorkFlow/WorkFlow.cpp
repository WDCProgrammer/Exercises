#include "WorkFlow.h"



void WorkFlow::AddActivity(Activity* activity)
{
    activities.push_back(activity);
}

const std::vector<Activity*> WorkFlow::GetActivities()
{
    return activities;
}