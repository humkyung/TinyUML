// TinyUMLEntityContainer.h: interface for the CTinyUMLEntityContainer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TINYUMLENTITYCONTAINER_H__1E472D01_A921_4A0D_93C6_4B6F66252B9D__INCLUDED_)
#define AFX_TINYUMLENTITYCONTAINER_H__1E472D01_A921_4A0D_93C6_4B6F66252B9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IsDrawEntContainer.h"

class CTinyUMLEntityContainer : public CIsDrawEntContainer  
{
public:
	virtual void Append( CIsObject* obj );
	virtual void Serialize(CArchive& ar);
	CTinyUMLEntityContainer();
	virtual ~CTinyUMLEntityContainer();
};

#endif // !defined(AFX_TINYUMLENTITYCONTAINER_H__1E472D01_A921_4A0D_93C6_4B6F66252B9D__INCLUDED_)
