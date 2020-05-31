#ifndef TINY_TYDRAWLABELCONTROLLER_H_C6DF0618_189D_4CEC_AF0C_3DA32F8FAAE4_INCLUDED_
#define TINY_TYDRAWLABELCONTROLLER_H_C6DF0618_189D_4CEC_AF0C_3DA32F8FAAE4_INCLUDED_

#include "IsDrawEntController.h"

class CTinyUMLLabelController : public CIsDrawEntController
{
public:
	virtual void ModifyProperties();
	virtual void OnLButtonDblClk(const IS_MOUSE_EVENT& mouse_event);
	CTinyUMLLabelController();
	virtual ~CTinyUMLLabelController();

	IS_DECLARE_CONTROLLER_FUNC()
};

#endif
