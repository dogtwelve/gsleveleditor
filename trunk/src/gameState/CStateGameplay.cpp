#include "stdafx.h"
#include "IView.h"
#include "CStateGameplay.h"
#include "CGameCameraFollowAnimator.h"

#include "gameControl/CGameControl.h"

CStateGameplay::CStateGameplay()
	:CGameState(CGameState::GSStateGameplay)
{
	m_level = new CGameLevel();
}

CStateGameplay::~CStateGameplay()
{
	delete m_level;	
	CGameLevel::setCurrentLevel( NULL );
}

void CStateGameplay::onCreate()
{
	CGameLevel::setCurrentLevel( m_level );

	// show ui
	m_menuFx = CGameUI::getInstance()->getFlash("uiGameHud");
	
	setFxStateVisible( m_state, true );
	setFxAllStateVisible( m_state, false );

	// hide dpad touch
	CMenuFxObj dpadTouch = m_menuFx->findObj("mcDpadTouch");
	dpadTouch.setVisible(false);

    
	CMenuFxObj dPadBase = m_menuFx->findObj("mcDpadBase");
	dPadBase.setVisible(false);	

    // enable gamecontrol
    CGameControl::getInstance()->setEnable(true);
    CGameControl::getInstance()->setNameFx("mcDpadTouch", "mcDpadBase", "mcDpadMove");
	
#ifdef HAS_MULTIPLAYER
	const char *isHost = CGameLevel::getLevelProperty("isHost");
	if ( strcmp(isHost, "true") == 0 )
		m_mpMgr = new CMultiplayerManager(true, false);
	else
    {
        const char *connectIP = CGameLevel::getLevelProperty("serverIp");
		m_mpMgr = new CMultiplayerManager(false, false, connectIP);
        m_mpMgr->sendReadyGameMessage();
    }
#endif

}

void CStateGameplay::onDestroy()
{
    // enable gamecontrol
    CGameControl::getInstance()->setEnable(false);
}

void CStateGameplay::onFsCommand( const char *command, const char *param )
{
}

void CStateGameplay::onUpdate()
{
#ifdef HAS_MULTIPLAYER
	m_mpMgr->update();
#endif
	m_level->update();
}

void CStateGameplay::onRender()
{
	m_level->render();
}