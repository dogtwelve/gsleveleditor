#include "stdafx.h"
#include "CSelectObjectController.h"
#include "IView.h"
#include "IDoc.h"

CSelectObjectController::CSelectObjectController()
{
}

CSelectObjectController::~CSelectObjectController()
{
}

void CSelectObjectController::initController()
{
	m_isLMouseDown = false;
	m_isRMouseDown = false;
	m_selectState = false;
}

void CSelectObjectController::cancelController()
{
}

void CSelectObjectController::onKeyUp(int keyCode)
{
}

void CSelectObjectController::onLMouseDown(int x, int y)
{
	m_isLMouseDown = true;

	m_beginX = x;
	m_beginY = y;

	IDoc *pDoc = getIView()->getDocument();
	
	// check control hold
	bool isControlHold = GetAsyncKeyState( VK_CONTROL ) < 0;

	// clear select
	ArrayGameObject *currentSelect = pDoc->getSelectObject();

	// if the object is selected
	if ( currentSelect->size() >  0 && isControlHold == false )
	{
		m_selectState = true;

		// check all select object
		ArrayGameObjectIter iObj = currentSelect->begin(), iEnd = currentSelect->end();
		while ( iObj != iEnd )
		{
			// get object
			CGameObject *p = (*iObj);			
			ISceneNode *pNode = p->getSceneNode();

			// get bounding object box 
			core::aabbox3df objBox = pNode->getBoundingBox();
			pNode->getAbsoluteTransformation().transformBox( objBox );

			// get select ray
			core::line3df selectRay = getIView()->getSelectRay();

			// check collision
			if ( objBox.intersectsWithLine( selectRay ) )
			{
				m_selectState = false;
				break;
			}

			iObj++;
		}		
	}
	else
	{
		// no object is selected
		m_selectState = true;
	}

}

void CSelectObjectController::onLMouseUp(int x, int y)
{
	m_isLMouseDown = false;

	IDoc *pDoc = getIView()->getDocument();

	if ( m_selectState == true )
	{
		int beginX = m_beginX;
		int beginY = m_beginY;
		int endX = x;
		int endY = y;

		if ( beginX > endX )
			core::swap<int>( beginX, endX );
		if ( beginY > endY )
			core::swap<int>( beginY, endY );

		core::recti	selectRect( beginX, beginY, endX, endY );		
		
		// clear current select if not hold control
		bool isControlHold = GetAsyncKeyState( VK_CONTROL ) < 0;
		
		// clear the select if not hold control
		if ( isControlHold == false )
			pDoc->clearSelect();
		
		// detect select
		if ( selectRect.getWidth() > 5 && selectRect.getHeight() > 5 )
			pDoc->selectObject( beginX, beginY, selectRect.getWidth(), selectRect.getHeight(), isControlHold );
		else
			pDoc->selectObject( x, y, isControlHold );
		
		// set state for select object
		setStateForSelectObject();
	}

}

void CSelectObjectController::onRMouseDown(int x, int y)
{
	m_isRMouseDown = true;
}

void CSelectObjectController::onRMouseUp(int x, int y)
{
	m_isRMouseDown = false;
}

void CSelectObjectController::onMouseWhell(bool scrollDown, int x, int y)
{
}

void CSelectObjectController::onMouseMove(int x, int y)
{
	IView *pView = getIView();

	if ( m_selectState == false && m_isLMouseDown == true )
	{
		CGameObject *pObject = pView->getDocument()->getFirstObjSelect();

		// move object
		core::line3df	ray = pView->getSelectRay();
		core::plane3df	plane( pObject->getPosition(), pObject->getUp() );
		
		// get position
		core::vector3df hit;
		bool b = plane.getIntersectionWithLine( ray.start, ray.getVector(), hit );
		
		if ( b )
		{
			pObject->setPosition( hit );
		}

	}
}

void CSelectObjectController::render()
{
	IVideoDriver *driver = getIView()->getDriver();
	
	// draw select rect
	if ( m_isLMouseDown && m_selectState == true )
	{
		int beginX = m_beginX;
		int beginY = m_beginY;
		int endX = getIView()->m_mouseX;
		int endY = getIView()->m_mouseY;

		if ( beginX > endX )
			core::swap<int>( beginX, endX );
		if ( beginY > endY )
			core::swap<int>( beginY, endY );

		core::recti	selectRect( beginX, beginY, endX, endY );
		
		// draw select
		driver->draw2DRectangle( SColor(80, 0,255,0), selectRect );
		driver->draw2DRectangleOutline( selectRect, SColor(200, 0,255,0) );
	}

}

// setStateForSelectObject
// set state when mouse up
void CSelectObjectController::setStateForSelectObject()
{
	// update state for select object
	getIView()->getDocument()->setStateForSelectObject( CGameObject::Move );
}