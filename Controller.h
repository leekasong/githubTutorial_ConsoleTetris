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
	Termios NonBlockingTerminalMode();
	inline char GetNonBlockingInput(); //input ascii value return
	void ResetNonBlockingTerminalMode(Termios a_org_term);
	
	//notify model
	void CheckInput();
	void notify(char a_sender);
	 
};

#endif
