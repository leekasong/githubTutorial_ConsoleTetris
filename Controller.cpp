#include "Controller.h"

Controller::Controller()
{

}

Controller::~Controller()
{

}

int Controller::setModel(Model *pModel){
    this->model=pModel;
    return true;
}

int Controller::setView(View *pView){
    this->view=pView;
    return true;
}


/*int Controller::updateView(){
    return view.update();
}*/
