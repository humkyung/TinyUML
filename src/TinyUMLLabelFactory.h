#ifndef TINY_TYDRAWLABELFACTORY_H_C6DF0618_189D_4CEC_AF0C_3DA32F8FAAE4_INCLUDED_
#define TINY_TYDRAWLABELFACTORY_H_C6DF0618_189D_4CEC_AF0C_3DA32F8FAAE4_INCLUDED_

#include "IsDrawEntFactory.h"

class CTinyUMLLabelFactory : public CIsDrawEntFactory
{
public:
	virtual void OnLButtonDown(const IS_MOUSE_EVENT& mouse_event);
	CTinyUMLLabelFactory();
	virtual ~CTinyUMLLabelFactory();
};

#endif
