#include "Controller.h"

Controller::Controller()
{
	
	m_old_termio = NonBlockingTerminalMode();
}

Controller::~Controller()
{

	ResetNonBlockingTerminalMode(m_old_termio);
}

int Controller::setModel(Model *pModel){
    this->model=pModel;
    return true;
}

int Controller::setView(View *pView){
    this->view=pView;
    return true;
}


void Controller::CheckInput()
{
	char input_key = GetNonBlockingInput(); //input ascii value return

	//0 -> no input
	if(input_key != 0){
		this->model->update(input_key);
	}
}

#define MODEL	1
#define VIEW	2
void Controller::notify(char a_sender)
{
	if(sender == MODEL){
		view->update();
	}else if(sender == VIEW){
		model->update();
	}
}
