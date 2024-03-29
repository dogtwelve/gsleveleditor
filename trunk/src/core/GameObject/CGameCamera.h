#ifndef GAME_CAMERA_H
#define GAME_CAMERA_H

#include "CGameObject.h"

class CGameCamera: public CGameObject
{
public:
	enum ECameraType
	{
		FreeCamera,
		EditorCamera,
		FollowObjectCamera
	};

protected:
	ICameraSceneNode	*m_camera;
	ISceneNodeAnimator	*m_animator;

#ifdef GSEDITOR
	ISceneNode			*m_cameraMesh;
#endif

	core::vector3df		m_targetPos;
	CGameObject			*m_targetObject;

	ECameraType			m_cameraType;
public:
	CGameCamera();

	virtual ~CGameCamera();

#ifdef GSEDITOR
	// setID
	// set id for object
	virtual void setID( long id )
	{
		m_cameraMesh->setID( id );
		CGameObject::setID(id);		
	}

	virtual void setVisible( bool b )
	{
		CGameObject::setVisible( b );
		m_cameraMesh->setVisible( b );
	}

	// setPosition
	// set 3d position
	virtual void setPosition(core::vector3df& pos)
	{
		CGameObject::setPosition( pos );
		if ( m_cameraMesh )
			m_cameraMesh->setPosition( pos );
	}

#endif

	// setTarget
	// set target look at camera
	void setTarget( core::vector3df& v );	

	// getTarget
	// get target look
	inline core::vector3df& getTarget()
	{
		return m_targetPos;
	}

	// getCameraNode
	// set camera node
	inline ICameraSceneNode* getCameraNode()
	{
		return m_camera;
	}

	// setTargetObject
	// set object need look
	inline void setTargetObject( CGameObject *p )
	{
		m_targetObject = p;
	}

	// getTargetObject
	// return the object is looking
	inline CGameObject *getTargetObject()
	{
		return m_targetObject;
	}
	
	// setFarValue
	// set far value clip
	inline void setFarValue( float f )
	{
		m_camera->setFarValue(f);
	}

	// updateObject
	// update object by frame...
	virtual void updateObject();

	// saveData
	// save data to serializable ( use for save in game .sav )
	virtual void saveData( CSerializable* pObj );

	// loadData
	// load data to serializable ( use for load in game .sav )
	virtual void loadData( CSerializable* pObj );

	// getData
	// get basic data to serializable
	virtual void getData( CSerializable* pObj );

	// updateData
	// update data
	virtual void updateData( CSerializable* pObj );

#ifdef GSEDITOR
	// drawObject
	// draw lookat vector
	virtual void drawObject();
#endif

	// setEditorCamera
	// set camera editor
	void setEditorCamera();

	// setFollowObjectCamera
	// set camera follow a object
	void setFollowObjectCamera( CGameObject* obj, float radius );
	
	// setFollowRot
	// set camera pos of follow obj type
	void setFollowRotate(float x, float y);

	// set static target
	void setFollowStaticTarget(bool b, const core::vector3df& v);

	// setFreeCamera
	// set camera free with custom pos & target
	void setFreeCamera();

};

#endif
