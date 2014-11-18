#include "cLogView.h"

cLogView::cLogView()
{
}

int cLogView::menuLog() const
{
    uiPtr_->showLog();
    return 0;
}

int cLogView::setUI(UI &ptr)
{
    uiPtr_ = &ptr;
    return 0;
}
