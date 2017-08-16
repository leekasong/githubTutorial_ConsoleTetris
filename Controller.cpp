#include "Controller.h"

Termios Controller :: NonBlockingTerminalMode()
{
	Termios a_org_term;
	Termios new_term;

	tcgetattr(STDIN_FILENO, &a_org_term);

	new_term = a_org_term;
	new_term.c_lflag &= ~(ECHO | ICANON);
	new_term.c_cc[VMIN] = 0;
	new_term.c_cc[VTIME] = 0;

	tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
	return a_org_term;
}

inline char Controller::GetNonBlockingInput() {
	int input_key = 0;
	input_key = getch();
	if (read(STDIN_FILENO, &input_key, 1) != 1)
		input_key = 0;
	else {
		if (input_key == 224) {
			input_key = getch();
			if (input_key == 75); //哭率
			else if (input_key == 72); //拉率
			else if (input_key == 80); //酒阀率
			else if (input_key == 77); //坷弗率
			else if (input_key == 27) {
				char dummy;
				while (read(STDIN_FILENO, &dummy, 1) == 1);
			}
		}
		else
			return input_key;
	}
	return input_key;
}

void Controller :: ResetNonBlockingTerminalMode(m_old_termio) {
	tcsetattr(STDIN_FILENO, TCSANOW, &a_org_term);
}

Controller::Controller()
{
	m_old_term = NonBlockingTerminalMode();
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
	char input_key = GetNonBlockingInput()
		//input ascii value return

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

void Get