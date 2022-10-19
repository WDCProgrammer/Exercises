#include "EmailActivity.h"
#include "UploadVideoActivity.h"
#include "Activity.h"
#include "VideoProcessedActivity.h"
#include "WebServiceActivity.h"
#include "WorkFlow.h"
#include "WorkFlowEngine.h"




int main(int argc, char* argv[])
{

    EmailActivity email;
    UploadVideoActivity upload;
    VideoProcessedActivity processed;
    WebServiceActivity web;

    WorkFlow workFlow;
    workFlow.AddActivity(&upload);
    workFlow.AddActivity(&web);
    workFlow.AddActivity(&email);
    workFlow.AddActivity(&processed);


    WorkFlowEngine engine;
    engine.Run(&workFlow);

    return 0;
}