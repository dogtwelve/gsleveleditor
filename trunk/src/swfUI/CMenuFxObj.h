#ifndef _MENUFXOBJ_H_
#define _MENUFXOBJ_H_

#include "CGameUI.h"

class CMenuFxObj
{
protected:
	gameswf::character	*m_character;
public:
	CMenuFxObj()
	{
		m_character = NULL;
	}

	CMenuFxObj( gameswf::character* ch );		
	virtual ~CMenuFxObj();	

	// findObj
	// find obj on flash menu
	CMenuFxObj findObj( char *name );

	// setpos xy
	void setPosition( int x, int y );

	// getBound
	// get bound
	void getBound(int *x, int *y, int *w, int *h);

	// setVisible
	// set visible
	void setVisible( bool b );

	// setText
	// set text on edit
	void setText( const char *lpString );

	// setText
	// set tex with unicode
	void setText( const wchar_t *lpString );

	// getText
	// get current text on edit
	const char *getText();

	// gotoFrame
	// goto frame
	void gotoFrame( const char *label, bool play );
	void gotoFrame( int frame, bool play );

	// getFrameCount
	// get number of frame
	int getFrameCount();

	// invokeASCallback
	// call action script func
	void invokeASCallback( const char* funcName, const gameswf::as_value* arguments, int argumentCount );
};

#endif