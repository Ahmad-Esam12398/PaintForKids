
#ifndef ACTION_LOAD
#define ACTION_LOAD
#include "Action.h"
class ActionLoad : public Action
{
private:
	string FileName;

public:

	ActionLoad(ApplicationManager* pApp);

	virtual void Execute();
	void Undo();
	void Redo();
};
#endif
