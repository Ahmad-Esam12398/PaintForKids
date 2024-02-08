#ifndef ACTION_CHNG_BKGRND_CLR_H
#define ACTION_CHNG_BKGRND_CLR_H

#include "Action.h"
#include "../Figures/CFigure.h"

class ActionChngBkGrndClr : public Action {
	ActionType inputColorAction;
	color BkGrndClr;
	color OldBkGrndClr;

	bool IsColor;
public:
	ActionChngBkGrndClr(ApplicationManager* pApp);

	//Changes current/selected figure draw color
	virtual void Execute();
	void Undo();
	void Redo();
};

#endif