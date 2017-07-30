#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "common.h"

class Controller{
    private:
        Model *model;
        View *view;
    public:
        Controller();
        ~Controller();
    //For model
        int setModel(Model *pModel);
    //For view
        int setView(View *pView);
    //For this
        //int updateView();
        //Add setter and getter to control datas in model class

};

#endif
