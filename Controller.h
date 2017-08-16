#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "common.h"
#include <termios.h>
#include <unistd.h>

typedef struct termios Termios
class Controller{
private:
	Model *model;
    View *view;
	Termios m_old_termio;
public:
	Controller();
    ~Controller();
    //For model
	int setModel(Model *pModel);
    //For view
	int setView(View *pView);
    //For this
    //int updateView();
	////Add setter and getter to control datas in model class
	
	//Non-Block input Mode setting
	Termios NonBlockingTerminalMode() {
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
	inline char GetNonBlockingInput() {
		int input_key=0;
		input_key = getch();
		if (read(STDIN_FILENO, &input_key, 1) != 1)
			input_key = 0;
		else {
			if(input_key==224){
				input_key = getch();
				if (input_key == 75); //哭率
				else if (input_key == 72); //拉率
				else if (input_key == 80); //酒阀率
				else if (input_key == 77); //坷弗率
				else if (input_key == 27){
					char dummy;
					while (read(STDIN_FILENO, &dummy, 1) == 1);
				}
			}
		}
		return input_key;
	} 
	
	//input ascii value return
	void ResetNonBlockingTerminalMode(Termios a_org_term) {
		tcsetattr(STDIN_FILENO, TCSANOW, &a_org_term);
	}
	
	//notify model
	void CheckInput();
	void notify(char a_sender);
	 
};

#endif
