// gsgameplay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IView.h"

#include "gameState/CStateInit.h"
#include "gameState/CGameStateManager.h"
#include "gameLevel/CGameLevel.h"

IView* g_view = NULL;

IView* getIView()
{
	return g_view;
}

class CApplication: public IEventReceiver, IView
{	
public:
	long	m_lastUpdateTime;
	int		m_fps;

protected:
	gui::IGUIFont*	m_font;
public:

	virtual bool OnEvent(const SEvent& event)
	{
		vector<eventType>::iterator i = m_eventReceivers.begin(), end = m_eventReceivers.end();
		while ( i != end )
		{
			(*i).second->OnEvent( event );
			i++;
		}
		return true;
	}

	// getIView
	// for multi-inherit
	IView* getIView()
	{
		return (IView*) this;
	}

	void initApplication( IrrlichtDevice* device )
	{
		// init irrlicht device
		m_device	= device;
		m_driver	= device->getVideoDriver();
		m_smgr		= device->getSceneManager();
		m_fileSystem = device->getSceneManager()->getFileSystem();

		m_lastUpdateTime =  m_device->getTimer()->getTime();
		m_fps = 0;

		m_device->setWindowCaption( STR_APP_TITLE );
		
		// get debug font
		m_font	= device->getGUIEnvironment()->getFont("data/font/bigfont.png");
		
		// init instance for level
		CGameLevel::createGetInstance();

		// init instance for gamestate
		CGameStateMgr::createGetInstance();
		registerEvent( "gameStateMgr", CGameStateMgr::getInstance() );

		// init instance for flashui
		CGameUI::createGetInstance();
		registerEvent( "gameUIFlash", CGameUI::getInstance() );
	
		// push gamestate
		CGameStateMgr::getInstance()->pushState( new CStateInit() );
	}

	void destroyApplication()
	{
		// drop event
		unRegisterEvent( CGameStateMgr::getInstance() );
		unRegisterEvent( CGameUI::getInstance() );
		
		// release instance
		CGameStateMgr::releaseInstance();
		CGameUI::releaseInstance();
		CGameLevel::releaseInstance();
	}

	void mainLoop()
	{		
		// calc delta time
		long now = m_device->getTimer()->getTime();
		m_timeStep = (f32)(now - m_lastUpdateTime); // Time in seconds
		m_lastUpdateTime = now;
		
		// update state
		CGameLevel::getInstance()->update();
		CGameUI::getInstance()->update();
		CGameStateMgr::getInstance()->update();

		// clear screen
		m_driver->beginScene(true, true, video::SColor(255,0,0,0));
		
		
		// draw 3d level
		CGameLevel::getInstance()->render();

		// draw game 2d flash ui		
		core::recti viewport = m_driver->getViewPort();
		CGameUI::getInstance()->render( 0, 0, viewport.getWidth(), viewport.getHeight(), false );	

		// render on 2d gamestate
		CGameStateMgr::getInstance()->render();

		// draw debug fps string
		int fps = m_driver->getFPS();
		core::stringw tmp(L"gsgameplay - ");
		tmp += m_driver->getName();

		tmp += L"\nfps: ";
		tmp += fps;
		
		tmp += L"\nPrimitive: ";
		tmp += m_driver->getPrimitiveCountDrawn();

		m_font->draw( tmp.c_str(), core::rect<s32>(10,10,300,100), video::SColor(255,255,255,255));			

		m_fps = fps;

		m_driver->endScene();
		
		Sleep(1);
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	CApplication myApp;
	g_view = myApp.getIView();

	IrrlichtDevice* device = NULL;
	
#ifdef _IRR_COMPILE_WITH_OPENGL_
	device = createDevice( irr::video::EDT_OPENGL, core::dimension2d<u32>(1024, 768), 16, false, false, false, &myApp );
#else if _IRR_COMPILE_WITH_OGLES2_
	device = createDevice( irr::video::EDT_OGLES2, core::dimension2d<u32>(1024, 768), 16, false, false, false, &myApp );
#endif

	if ( device == NULL )
		return 1;

	myApp.initApplication( device );

	while(device->run())
	{
		myApp.mainLoop();		
	}

	myApp.destroyApplication();
	device->drop();

	return 0;
}

