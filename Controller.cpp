#include "Controller.h"

Termios Controller::NonBlockingTerminalMode() {
	struct termios org_term;
	tcgetattr(STDIN_FILENO, &org_term);
	struct termios new_term;
	new_term.c_lflag &= ~(ECHO | ICANON);
	new_term.c_cc[VMIN] = 0;
	new_term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
	return org_term;
}
void Controller::ResetNonBlockingTerminalMode(Termios m_old_termio) {
	tcsetattr(STDIN_FILENO, TCSANOW, &m_old_termio);
}
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

inline char Controller::GetNonBlockingInput() {
	if (kbhit()) {
		char input = (char)getch();
		if (input != 224) //스페이스바 
			return input;
		else //방향키일때
		{
			input = (char)getch();
			return input; //위 : 72 아래 : 80 오른쪽 : 77 왼쪽 : 75
		}
	}
	return 0;
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
