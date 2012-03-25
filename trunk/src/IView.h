#ifndef _IVIEW_
#define _IVIEW_

#include "stdafx.h"

#ifdef GSEDITOR
	#include "IDoc.h"
	#include "IController.h"
#endif

class	CZone;
class	CGameObject;

class IView
{
protected:
	IrrlichtDevice*			m_device;
	IVideoDriver*			m_driver;
	ISceneManager*			m_smgr;

	SExposedVideoData		m_videoData;

#ifdef GSEDITOR
	IDoc*					m_document;
	CGameObject*			m_contextObj;
#endif

public:

	IView();
	virtual ~IView();

#ifdef GSEDITOR
	// alertError
	// show error msgbox
	virtual void alertError( wchar_t *lpString ) = 0;

	// yesNoQuestion
	// show yes, no msgbox
	virtual bool yesNoQuestion( wchar_t *lpString ) = 0;

	// setStatusText
	// set text on status bar
	virtual void setStatusText( int part, wchar_t *lpString ) = 0;


	// idleUpdateWindow
	// update window
	virtual void idleUpdateWindow() = 0;

public:

	// setObjectProperty
	// set object property on listview window
	virtual void setObjectProperty(CGameObject *pObj) = 0;

	// setObjectForContext
	// set object for menu command
	inline void setObjectForContext(CGameObject *pObj)
	{
		m_contextObj = pObj;
	}

	// getObjectForContext
	// get object for menu command
	inline CGameObject* getObjectForContext()
	{
		return m_contextObj;
	}
#endif

	typedef std::pair<string,IEventReceiver*>	eventType;
	vector<	eventType >	m_eventReceivers;

public:
	
	int	m_mouseX;
	int m_mouseY;

	// getScreenCoordinatesFrom3DPosition
	// convert 3d xyz to 2d xy
	virtual bool getScreenCoordinatesFrom3DPosition(const core::vector3df& pos3d, int *x, int *y);

	// getSelectRay
	// get 3d ray from camera to pointer
	core::line3df getSelectRay();

public:	

	// getDevice
	// get irr device
	inline IrrlichtDevice* getDevice()
	{
		return m_device;
	}

	// getDriver
	// get irr driver
	inline IVideoDriver* getDriver()
	{
		return m_driver;
	}

	// getSceneMgr
	// get irr scene
	inline ISceneManager* getSceneMgr()
	{
		return m_smgr;
	}
	
	// getVideoData
	// get viewData
	inline SExposedVideoData& getVideoData()
	{
		return m_videoData;
	}

#ifdef GSEDITOR
	// getDocument
	// get current document
	inline IDoc* getDocument()
	{
		return m_document;
	}

	// newDocument
	// renew document
	virtual void newDocument() = 0;

	// enableFreeCamera
	// disable or enable change camera view on editor
	virtual void enableFreeCamera( bool b );

	// getCurrentObjectTemplate
	// get current name
	virtual wchar_t* getCurrentObjectTemplate() = 0;

	// objTemplate
	// set current template
	virtual void setCurrentObjectTemplate( wchar_t *objTemplate ) = 0;

	// getGameObjectOfCurrentTemplate
	// get current obj
	virtual CGameObject* getGameObjectOfCurrentTemplate() = 0;

	// getCurrentZone
	// get current zone
	virtual CZone* getCurrentZone() = 0;

	// setCurrentZone
	// get current zone
	virtual void setCurrentZone(CZone *pZone) = 0;

	// getDocumentTreeView
	// get tree view control of document
	virtual uiTreeView* getDocumentTreeView() = 0;
#endif
	
	// register event
	// register input event
	void registerEvent( string name, IEventReceiver *pEvent );

	// unRegisterEvent
	// unregister input event
	void unRegisterEvent( IEventReceiver *pEvent );

};

extern IView* getIView();

#endif