#include "View.h"

View::View(){
    //Make an UI thread
    
}

View::~View(){
    //Free thread resources

}

int View::setController(Controller *pController){
    this->controller=pController;
    return 1;
}   
int View::setModel(Model *pModel){
    this->model=pModel;
    return 1;
}

int View::update(){
    //Get datas from model and draw changed map and score
	return 1;
}
