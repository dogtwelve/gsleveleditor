#ifndef _STATE_INIT_
#define _STATE_INIT_

#include "CGameState.h"

class CStateInit: public CGameState
{
protected:
	bool		m_loadMainMenu;

public:
	CStateInit();
	virtual ~CStateInit();
	
	virtual void onCreate();
	virtual void onDestroy();
	virtual void onFsCommand( const char *command, const char *param );
	virtual void onRender();
	virtual void onUpdate();
};

#endif