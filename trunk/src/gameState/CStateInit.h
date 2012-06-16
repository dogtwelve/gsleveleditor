#ifndef _STATE_INIT_
#define _STATE_INIT_

#include "CGameState.h"

class CStateInit: public CGameState
{
public:
	CStateInit();
	virtual ~CStateInit();

	virtual void onCreate();
	virtual void onFsCommand( const char *command, const char *param );

};

#endif