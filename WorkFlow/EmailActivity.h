#ifndef EMAILACTIVITY_H
#define EMAILACTIVITY_H
#include "Activity.h"
class EmailActivity final: public Activity
{

    public:
         virtual void Execute () override;
    private:
};


#endif