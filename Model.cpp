#include "Model.h"
#include "Map.h"

Model::Model(){
	
}

Model::~Model(){
//	delete mp_map;
}
int Model::setView(View *pView){
    this->mp_view=pView;
    return 1;
}
int Model::notifyView(){
	//view->Update();
	return 1;
}
