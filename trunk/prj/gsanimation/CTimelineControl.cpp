#include "stdafx.h"
#include "CTimelineControl.h"

#define OFFSET_X	70

CTimelineControl::CTimelineControl(uiWindow* parent, int x, int y, int w, int h)
	:uiWindow(L"timeLineControl", x, y, w, h, parent)
{
	changeWindowStyle( UISTYLE_CHILD );
	showWindow(true);

	m_timeLength	= 0.0f;
	m_crollX		= 0;
	m_maxValue = 0.0f;
	m_minValue = 0.0f;

	m_lengthPixel	= 15;	
	m_needSortValue	= true;	
	m_changeTime = false;

	m_lbuttonDown = false;
	m_rbuttonDown = false;
}

CTimelineControl::~CTimelineControl()
{	
}

void CTimelineControl::_OnPaint( uiGraphics *pG )
{
	paintControl(pG);
}

void CTimelineControl::_OnLButtonDown( uiMouseEvent mouseEvent, int x, int y )
{
	this->setCapture();

	m_lbuttonDown = true;
	if ( m_changeTime )
	{
		m_currentTime = getTimeValue( x - OFFSET_X + m_crollX );
		update();
	}
}

void CTimelineControl::_OnLButtonUp( uiMouseEvent mouseEvent, int x, int y )
{
	this->releaseCapture();

	m_lbuttonDown = false;
}

void CTimelineControl::_OnRButtonDown( uiMouseEvent mouseEvent, int x, int y )
{
	this->setCapture();

	m_rbuttonDown = true;
	m_x = x;
	m_y = y;
}

void CTimelineControl::_OnRButtonUp( uiMouseEvent mouseEvent, int x, int y )
{
	this->releaseCapture();

	m_rbuttonDown = false;
}

void CTimelineControl::_OnMouseMove( uiMouseEvent mouseEvent, int x, int y )
{
	if ( m_changeTime && m_lbuttonDown )
	{
		m_currentTime = getTimeValue( x - OFFSET_X + m_crollX );
		update();
	}

	if ( m_rbuttonDown )
	{
		int nWidth = getClientWidth();
		float timeWidth = m_lengthPixel*m_timeLength;
		int limitW = (int)timeWidth + OFFSET_X * 2;

		if ( nWidth < limitW )
		{
			int dx = x - m_x;			
			m_crollX -= dx;
			
			if ( m_crollX < 0 )
				m_crollX = 0;
			else if ( nWidth + m_crollX > limitW  )
			{
				m_crollX = limitW - nWidth;
			}
		}
		update();
	}
	m_x = x;
	m_y = y;
}

void CTimelineControl::sortValue( vector<STimelineValue>& value )
{
	int len = (int)value.size();
	
	for (int i = 1; i <= len - 1; i++)
	{
		STimelineValue s = value[i];
		
		int j = i - 1;
		int done = 0;

		do
		{
			if ( value[j].time > s.time )
			{
				value[j + 1] = value[j];

				j = j - 1;
				if ( j < 0 )
					done = 1;
			}
			else
				done = 1;
		}
		while (done == 0);
		
		value[j + 1] = s;		
	}
}

void CTimelineControl::calcMinMax( vector<STimelineValue>& value )
{
	m_maxValue = 0.0f;
	m_minValue = 0.0f;

	int len = (int)value.size();
	if ( len > 0 )
	{
		m_maxValue = value[0].x;
		m_minValue = value[0].x;
	}

	for ( int i = 1; i < len; i++ )
	{
		if ( m_minValue > value[i].x )
			m_minValue = value[i].x;
		if ( m_minValue > value[i].y )
			m_minValue = value[i].y;
		if ( m_minValue > value[i].z )
			m_minValue = value[i].z;

		if ( m_maxValue < value[i].x )
			m_maxValue = value[i].x;
		if ( m_maxValue < value[i].y )
			m_maxValue = value[i].y;
		if ( m_maxValue < value[i].z )
			m_maxValue = value[i].z;
	}
}

void CTimelineControl::update()
{
	uiGraphics g(this);
	paintControl( &g );
}

void CTimelineControl::paintControl( uiGraphics *pG )
{
	if ( m_needSortValue == true )
	{
		sortValue(m_value);	
		calcMinMax(m_value);
		m_needSortValue = false;
	}

	int nWidth = getClientWidth();
	int nHeight = getClientHeight();
	
	uiBrush bgGrey( uiColor(0x9f9f9f) );	
	uiFont tahoma(14, L"tahoma");
	tahoma.setFontNormal();

	uiGraphics *graphics = pG->createBackBuffer( nWidth, nHeight );
	
	// fill background
	graphics->drawFillRectangle(0,0, nWidth, nHeight, &bgGrey);	
	
	if ( m_timeLength > 0.0f )
	{
		float midValue = (m_maxValue + m_minValue)*0.5f;	
		
		uiPen pen(1, PS_SOLID, uiColor(0x888888));
		uiPen penX(2, PS_SOLID, uiColor(0x0000ff));
		uiPen penY(2, PS_SOLID, uiColor(0x00ff00));
		uiPen penZ(2, PS_SOLID, uiColor(0xff0000));

		graphics->selectObject(&pen);

		// draw center line
		graphics->drawLine(0, getY(midValue), nWidth, getY(midValue));
		
		// draw limit line
		graphics->drawLine(0, getY(m_minValue), nWidth, getY(m_minValue));
		graphics->drawLine(0, getY(m_maxValue), nWidth, getY(m_maxValue));
		
		graphics->selectObject( &tahoma );
		graphics->setTextBkTransparent(true);
		
		wchar_t text[512];
		graphics->setTextColor( uiColor(0xffffff) );

		swprintf(text,512,L"%.2f", m_minValue);
		graphics->drawText( 5, getY(m_minValue), text );

		swprintf(text,512,L"%.2f", m_maxValue);
		graphics->drawText( 5, getY(m_maxValue), text );

		swprintf(text,512,L"%.2f", midValue);
		graphics->drawText( 5, getY(midValue), text );
		
		// set clipping
		graphics->setClip(OFFSET_X, 0, nWidth - OFFSET_X, nHeight);

		int len = (int)m_value.size();
		for ( int i = 1; i < len; i++ )
		{
			int x0 = getX( m_value[i-1].time );
			int x1 = getX( m_value[i].time );
									
			int y0 = getY( m_value[i-1].x );
			int y1 = getY( m_value[i].x );

			// draw col
			graphics->selectObject(&pen);
			graphics->drawLine(x1,0, x1,nHeight);
			
			swprintf(text,512,L"%.2f", m_value[i].time);
			graphics->drawText( x1, 0, text );

			// draw line x
			graphics->selectObject(&penX);
			graphics->drawLine(x0, y0, x1, y1);
			
			// draw line y
			y0 = getY( m_value[i-1].y );
			y1 = getY( m_value[i].y );
			graphics->selectObject(&penY);
			graphics->drawLine(x0, y0, x1, y1);

			// draw line z
			y0 = getY( m_value[i-1].z );
			y1 = getY( m_value[i].z );
			graphics->selectObject(&penZ);
			graphics->drawLine(x0, y0, x1, y1);
		}
		
		for ( int i = 0; i < len; i++ )
		{
			int r = 4;
			int x1 = getX( m_value[i].time );									
			int y1 = getY( m_value[i].x );					

			// draw rectX
			graphics->selectObject(&penX);			
			graphics->drawRectangle( x1-r,y1-r,x1+r,y1+r );
			
			// draw rectY
			y1 = getY( m_value[i].y );
			graphics->selectObject(&penY);
			graphics->drawRectangle( x1-r,y1-r,x1+r,y1+r );

			// draw rectZ
			y1 = getY( m_value[i].z );
			graphics->selectObject(&penZ);
			graphics->drawRectangle( x1-r,y1-r,x1+r,y1+r );
		}

		graphics->selectObject(&penX);
	
		// paint current time
		uiPen penTime(1, PS_SOLID, uiColor(0x00FFFF));
		int xTime = getX( m_currentTime );

		graphics->selectObject(&penTime);	
		graphics->drawLine( xTime, 0, xTime, nHeight );

	}	

	pG->swapBuffer(0,0,nWidth, nHeight, graphics, 0,0,nWidth,nHeight, SRCCOPY);
	graphics->releaseGraphics();	
}

float CTimelineControl::getTimeValue( int v )
{
	if ( v <= 0 || m_timeLength == 0.0f )
		return 0;

	float timeWidth = m_lengthPixel*m_timeLength;
	float f = v/timeWidth;
	if ( f >= 1.0f )
		f = 1.0f;

	return m_timeLength*f;
}

int CTimelineControl::getX( float v )
{
	int offsetX = OFFSET_X;
	if ( v <= 0 || m_timeLength == 0.0f )
		return offsetX - m_crollX;
	
	float timeWidth = m_lengthPixel*m_timeLength;
	if ( v >= m_timeLength )
		return (int)timeWidth + offsetX - m_crollX;

	return (int)(v*timeWidth/m_timeLength) + offsetX - m_crollX;
}

int CTimelineControl::getY( float v )
{
	float paddingY = 30.0f;
	float height = (float)getClientHeight() - paddingY*2;
	
	if ( v <= m_minValue )
		return (int)(paddingY + height);
	else if ( v >= m_maxValue )
		return (int)paddingY;

	float posY = paddingY + (m_maxValue - v)*height/( m_maxValue - m_minValue );	
	return (int)posY;
}