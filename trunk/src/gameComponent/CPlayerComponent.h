#ifndef _CPLAYERCOMPONENT_H_
#define _CPLAYERCOMPONENT_H_

#include "IObjectComponent.h"
#include "CColladaMeshComponent.h"
#include "CGameComponent.h"

#define SHIFTBIT(x)	(1<<x)

class CInventoryComponent;
class CColladaMeshComponent;

class CPlayerComponent: 
	public IObjectComponent,
	public IEventReceiver
{
public:	
	enum EPlayerState
	{
		PlayerNone = 0,
		PlayerIdle,		
		PlayerRun,
		PlayerFire,
		NumStateCount
	};

	enum EPlayerSubState
	{
		SubStateInit = 0,
		SubStateActive,
		SubStateEnd,
	};

	enum EKeyActionBit
	{
		KeyNone		= 0,
		KeyUp		= SHIFTBIT(1),
		KeyLeft		= SHIFTBIT(2),
		KeyRight	= SHIFTBIT(3),
		KeyBack		= SHIFTBIT(4),
		KeyFire		= SHIFTBIT(5)
	};

protected:
	EPlayerSubState			m_subState;
	EPlayerState			m_state;
	EPlayerState			m_nextState;

	float					m_runSpeed;
	float					m_runBackSpeed;

	float					m_animTotalTime;
	float					m_animCurrentTime;

	CColladaAnimation*		m_animationPackage;
	CColladaMeshComponent*	m_collada;
	CInventoryComponent*	m_inventory;

	CGameColladaSceneNode*	m_bipSpineNode;
	CGameColladaSceneNode*	m_bipSpine1Node;
	CGameColladaSceneNode*	m_gunDummyNode;

	// m_targetRotation
	// the target rotation
	float					m_runRotation;
	float					m_currentRunRot;
	core::vector3df			m_targetRotation;
	int						m_keyActionBit;
public:
	CPlayerComponent(CGameObject* obj);
	virtual ~CPlayerComponent();

	// init
	// run when init object
	virtual void initComponent();

	// update
	// run when update per frame
	virtual void updateComponent();

	// saveData
	// save data to serializable
	virtual void saveData( CSerializable* pObj );

	// loadData
	// load data to serializable
	virtual void loadData( CSerializable* pObj );

	// OnEvent
	// cache event
	virtual bool OnEvent(const SEvent& irrEvent);
public:

	// setState
	// set state for player
	void setState( EPlayerState state )
	{
		if ( m_state == state )
		{
			m_nextState = state;
			return;
		}

		if ( m_state == PlayerNone )
		{
			m_state		= state;
			m_subState	= SubStateInit;
		}
		else
		{
			m_nextState = state;
			m_subState	= SubStateEnd;
		}
	}

protected:
	
	// updateState	
	void updateState();

	void updateStateIdle();
	void updateStateRun();
	void updateStateFire();

	// updateRotateBip
	// rotate the foot to move vector
	void updateRotateBip();

	// updateRotateObject
	// rotate the object to camera front
	void updateRotateObject();

	// updateWeaponPosition
	// update weapon
	void updateWeaponPosition();	

	// doNextState
	// change to next state
	void doNextState()
	{		
		// change next state
		m_state = m_nextState;
		m_subState = SubStateInit;				
		m_nextState = CPlayerComponent::PlayerNone;
	}
};

#endif