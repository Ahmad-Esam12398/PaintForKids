
#include "./Actions/Action.h"
class ActionSelect : public Action {
    Point p1;
public:
    ActionSelect(ApplicationManager* pMgr);
    virtual void Execute();
    void Undo();
    void Redo();
};