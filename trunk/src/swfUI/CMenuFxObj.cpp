#include "stdafx.h"
#include "CMenuFxObj.h"

CMenuFxObj::CMenuFxObj( gameswf::character* ch )
{
	m_character = ch;
}

CMenuFxObj::~CMenuFxObj()
{
}

// setpos xy
void CMenuFxObj::setPosition( int x, int y )
{
	if ( m_character )
	{
		const gameswf::matrix& curMat = m_character->get_matrix();

		gameswf::matrix mat;
		mat.concatenate_translation(PIXELS_TO_TWIPS(x), PIXELS_TO_TWIPS(y));
		mat.set_scale_rotation( curMat.get_x_scale(), curMat.get_y_scale(), curMat.get_rotation() );

		m_character->set_matrix(mat);
	}
}

// setVisible
// set visible
void CMenuFxObj::setVisible( bool b )
{
	if ( m_character )
	{
		m_character->set_visible( b );
	}
}

// setText
// set text on edit
void CMenuFxObj::setText( const char *lpString )
{
	if(m_character && m_character->is(gameswf::AS_EDIT_TEXT))
	{
		gameswf::edit_text_character* edit_text = (gameswf::edit_text_character*)m_character;
		edit_text->set_text_value( tu_string(lpString) );
	}
}

// setText
// set tex with unicode
void CMenuFxObj::setText( const wchar_t *lpString )
{
	if(m_character && m_character->is(gameswf::AS_EDIT_TEXT))
	{
		gameswf::edit_text_character* edit_text = (gameswf::edit_text_character*)m_character;

		char stringc[1024];
		uiString::convertUnicodeToUTF8( (const unsigned short*) lpString, stringc );
		edit_text->set_text_value( tu_string(stringc) );
	}
}

// getText
// get current text on edit
const char *CMenuFxObj::getText()
{
	if(m_character && m_character->is(gameswf::AS_EDIT_TEXT))
	{
		gameswf::edit_text_character* edit_text = (gameswf::edit_text_character*)m_character;
		return edit_text->m_text.c_str();
	}
	return NULL;
}

// gotoFrame
// goto frame
void CMenuFxObj::gotoFrame( const char *label, bool play )
{
	if(m_character && m_character->is(gameswf::AS_SPRITE))
	{
		gameswf::sprite_instance* si = (gameswf::sprite_instance*)m_character;		
		si->goto_labeled_frame(label);
		si->set_play_state(play ? gameswf::sprite_instance::PLAY : gameswf::sprite_instance::STOP);
	}
}

void CMenuFxObj::gotoFrame( int frame, bool play )
{
	if(m_character && m_character->is(gameswf::AS_SPRITE))
	{
		gameswf::sprite_instance* si = (gameswf::sprite_instance*)m_character;		
		si->goto_frame(frame);		
		si->set_play_state(play ? gameswf::sprite_instance::PLAY : gameswf::sprite_instance::STOP);	
	}
}

// getFrameCount
// get number of frame
int CMenuFxObj::getFrameCount()
{
	if(m_character && m_character->is(gameswf::AS_SPRITE))
	{
		gameswf::sprite_instance* si = (gameswf::sprite_instance*)m_character;		
		return si->get_frame_count();
	}
	return 0;
}

// invokeASCallback
// call action script func
void CMenuFxObj::invokeASCallback( const char* funcName, const gameswf::as_value* arguments, int argumentCount )
{
	if(m_character && m_character->is(gameswf::AS_SPRITE))
	{
		gameswf::sprite_instance* si = (gameswf::sprite_instance*)m_character;		
		
		// Keep m_as_environment alive during any method calls!
		gameswf::gc_ptr<gameswf::as_object>	this_ptr(m_character);

		// In ActionScript 2.0, event method names are CASE SENSITIVE.
		// In ActionScript 1.0, event method names are CASE INSENSITIVE.
		gameswf::call_method( si->get_environment(), m_character, funcName, arguments, argumentCount );
	}
}