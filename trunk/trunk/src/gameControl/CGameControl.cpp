#include "stdafx.h"
#include "CGameControl.h"
#include "IView.h"

CGameControl::CGameControl()
{
    m_isEnable = false;
    
    m_screenTouchID = -1;
}

CGameControl::~CGameControl()
{

}

// setNameFx
// set name of flash obj
void CGameControl::setNameFx( const std::string& nameDpadTouch, const std::string& nameDPad,const std::string& nameDpadMove )
{
    m_fxnameDpadTouch = nameDpadTouch;
    m_fxnameDpad = nameDPad;
    m_fxnameDpadMove = nameDpadMove;
    
    // flash gamehud
    CMenuFx *menuFx = CGameUI::getInstance()->getFlash("uiGameHud");
    
    // get touch touch dpad
    CMenuFxObj *dpadTouch = menuFx->findObj((char*) nameDpadTouch.c_str());
    if ( dpadTouch )
    {
        int x,y,w,h;
        float fw, fh;
        
        dpadTouch->getBound(&x, &y, &w, &h);        
        menuFx->getFxScaleRatio(&fw, &fh);
        
        float realX, realY, realW, realH;
        realX = (float)x / fw;
        realY = (float)y / fh;
        realW = (float)w / fw;
        realH = (float)h / fh;
        
		char string[512] = {0};
		sprintf(string,"dpadRect:{%f, %f, %f, %f}: %f, %f", realX, realY, realW, realH, fw, fh);
		os::Printer::log(string);

        m_touchDpad.UpperLeftCorner = core::vector2di( (int)realX, (int)realY);
        m_touchDpad.LowerRightCorner = core::vector2di( (int)(realX+realW), (int)(realY+realH) );
        
        dpadTouch->drop();
    }
    
    // set fx for dpad
    m_moveDpad.setDpadFxName(nameDPad, nameDpadMove);
}

// update
// main loop update
void CGameControl::update()
{
    m_moveDpad.update();
}

// OnEvent
// IEventReceiver implement
bool CGameControl::OnEvent(const SEvent& event)
{
    if ( m_isEnable == false )
        return true;
    
    IrrlichtDevice *device = getIView()->getDevice();
    
    if ( event.EventType == EET_MOUSE_INPUT_EVENT )
    {
        s32 controlID = event.EventControlID;
        core::vector2di mousePos(event.MouseInput.X, event.MouseInput.Y);
        
        if ( event.MouseInput.Event == EMIE_LMOUSE_PRESSED_DOWN )
        {
            // touch on dpad
            if ( m_touchDpad.isPointInside( mousePos ) == true )
            {
                if ( m_moveDpad.getControlID() == -1 )
                {
                    m_moveDpad.setControlID( controlID );
                    m_moveDpad.setDpadPos( event.MouseInput.X, event.MouseInput.Y );                    
                }
            }  
            else if ( m_screenTouchID == -1 )
            {
#if defined (IOS) || defined (ANDROID)
                device->getCursorControl()->setPosition( event.MouseInput.X, event.MouseInput.Y);
#endif
				m_screenTouchID = controlID;

				// debug code
				//char string[512] = {0};
				//sprintf(string, "*** Touch screen detected, touchID = %d", controlID);
				//os::Printer::log(string);

				ISceneManager *smgr = getIView()->getSceneMgr();
                if ( smgr->getActiveCamera() )
                    smgr->getActiveCamera()->OnEvent( event );                
            }
        }
        else if ( event.MouseInput.Event == EMIE_MOUSE_MOVED )
        {            
            // move dpad
            if ( m_moveDpad.getControlID() == controlID )
                m_moveDpad.setTouchPos( event.MouseInput.X, event.MouseInput.Y );
            else if ( m_screenTouchID == controlID )
            {
#if defined (IOS) || defined (ANDROID)
                device->getCursorControl()->setPosition( event.MouseInput.X, event.MouseInput.Y);
#endif
				ISceneManager *smgr = getIView()->getSceneMgr();
                if ( smgr->getActiveCamera() )
                    smgr->getActiveCamera()->OnEvent( event );
            }
        }
        else if ( event.MouseInput.Event == EMIE_LMOUSE_LEFT_UP )
        {
            // release dpad move
            if ( m_moveDpad.getControlID() == controlID )
            {
                m_moveDpad.setControlID( -1 );
            }
            else if ( m_screenTouchID == controlID )
            {

#if defined (IOS) || defined (ANDROID)
                device->getCursorControl()->setPosition( event.MouseInput.X, event.MouseInput.Y);
#endif                
                ISceneManager *smgr = getIView()->getSceneMgr();
                if ( smgr->getActiveCamera() )
                    smgr->getActiveCamera()->OnEvent( event );

                m_screenTouchID = -1;
				
				// debug code
				//char string[512] = {0};
				//sprintf(string, "***** Touch screen release, touchID = %d", controlID);
				//os::Printer::log(string);
            }
        }
    }
    return true;
}

// isTouchOnScreen
// check a null touch on screen
bool CGameControl::isTouchOnScreen( int touchID )
{
	if ( touchID == m_screenTouchID )
        return true;
    
	return false;
}

// isTouchOnDPad
// check touch on dpad
bool CGameControl::isTouchOnDPad( int x, int y )
{
    core::vector2di mousePos(x, y);
    return m_touchDpad.isPointInside( mousePos );
}