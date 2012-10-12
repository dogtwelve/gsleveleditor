#ifndef _UIWIDGET_H_
#define _UIWIDGET_H_

#include "stdafx.h"
#include "IEventReceiver.h"

#include "swfUI/CGameUI.h"
#include "swfUI/CMenuFx.h"
#include "swfUI/CMenuFxObj.h"

#include "gameControl/CTouchManager.h"

class CUIWidget
{
protected:
	CUIWidget				*m_parent;
	std::vector<CUIWidget*>	m_childs;
	
	core::recti				m_rect;
	int						m_controlID;
	bool					m_visible;

public:
	CUIWidget();
	CUIWidget(CUIWidget* parent);

	virtual ~CUIWidget();

	// addChild
	// add child widget
	void addChild( CUIWidget *child );
	
	// removeChild
	// remove a child from childs list
	void removeChild( CUIWidget *child );

	// destroyChild
	// destroy all child
	void destroyChild();

	// remove
	// remove from parent
	void remove();
	
	// getRect
	// get bounding rect of control
	const core::recti& getRect()
	{
		return m_rect;
	}

	// setControlID
	// set touch id
	inline void setControlID( int id )
	{
		m_controlID = id;
	}

	// getControlID
	// get touch id
	inline int getControlID()
	{
		return m_controlID;
	}

	// isVisible
	// check widget is visible
	inline bool isVisible()
	{
		return m_visible;
	}

	// setVisible
	// set visible
	inline void setVisible( bool b )
	{
		m_visible = b;
	}

	// getRectByFxObj
	// get rect from flash obj
	static void getRectByFxObj( CMenuFxObj fxObj, core::recti& rect );

	// update
	// update per frame
	virtual void update();

	// onTouchEvent
	// update touch event
	virtual bool onEvent( const SEvent& gameEvent);

};

#endif