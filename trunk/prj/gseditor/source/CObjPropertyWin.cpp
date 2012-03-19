#include "stdafx.h"
#include "CObjPropertyWin.h"
#include "CSerializable.h"

CObjPropertyWindow::CObjPropertyWindow( WCHAR* lpString, uiWindow *p )
	:CBaseWindow(lpString, p)
{
	m_propertyWnd = ref<uiListProperty>( new uiListProperty(TEXT("propertyWnd"), 0,0,10,10, this, 2) );

	m_propertyWnd->setMargin(0,0,30,0);
	m_propertyWnd->setDock( this, UIDOCK_FILL );
	m_propertyWnd->showWindow(true);

	// set event on change property
	m_propertyWnd->setEventOnCmbChange		<CObjPropertyWindow, &CObjPropertyWindow::_OnUpdatedProperty>( this );
	m_propertyWnd->setEventOnDeActive		<CObjPropertyWindow, &CObjPropertyWindow::_OnUpdatedProperty>( this );
	m_propertyWnd->setEventOnUpdateProperty	<CObjPropertyWindow, &CObjPropertyWindow::_OnUpdatedProperty>( this );

	m_currentObject = NULL;
}

CObjPropertyWindow::~CObjPropertyWindow()
{	
}

void CObjPropertyWindow::_OnPaint( uiGraphics *pG )
{
	uiWindow::_OnPaint( pG );
	drawTitleBackground(pG, 0,0, this->getWidth(), 30, TEXT("Object property") );	
}

// setObject
// set object to view property
void CObjPropertyWindow::setObject( CGameObject *pObject )
{
	if ( pObject == m_currentObject && pObject != NULL )
	{
		_OnGetObjectProperty();
		return;
	}

	m_currentObject = pObject;
	m_objectInfo.clear();

	// delete all items
	m_propertyWnd->deleteAllItem();

	if ( m_currentObject )
	{				
		// get object info
		m_currentObject->saveData( &m_objectInfo );

		ArraySerializableRecIter iRec = m_objectInfo.getAllRecord()->begin(); 
		ArraySerializableRecIter iEnd = m_objectInfo.getAllRecord()->end();
		
		wchar_t lpName[512]		= {0};
		wchar_t lpValue[512]	= {0};
		uiListPropertyRow *pRow = NULL;

		while ( iRec != iEnd )
		{
			SSerializableRec &r = (*iRec);
			
			// convert name
			uiString::convertUTF8ToUnicode( r.name, (unsigned short*)lpName );
			
			// erase tag object
			r.tagObject = NULL;

			// add object
			if ( r.type == NSSerializable::groupInfo )
			{
				// add group
				m_propertyWnd->addGroup( lpName );
			}
			else if ( r.type != NSSerializable::arrayByte )
			{
				// add row
				pRow = m_propertyWnd->addRowItem( lpName );
				
				// tag the control to row property
				r.tagObject = pRow;
				
				// convert value
				uiString::convertUTF8ToUnicode( r.data, (unsigned short*)lpValue );
				pRow->setText( lpValue, 1 );

				// enable edit
				if ( r.readOnly == false )
				{
					if ( r.type == NSSerializable::boolType )
					{
					}
					else if ( r.type == NSSerializable::stringType || r.type == NSSerializable::filePathType )
					{
						pRow->setControl( UILISTPROPERTY_EDIT, 1, NULL );
					}	
					else
					{
						uiEdit *pEditText = (uiEdit*)pRow->setControl( UILISTPROPERTY_EDIT, 1, NULL );

						if ( r.type == NSSerializable::intType || r.type == NSSerializable::longType )
							pEditText->setNumberValueOnly( true );
						else
							((uiListPropertyEdit*)pEditText)->setNumberFloatValueOnly( true );
					}
				}
			}
			iRec++;
		}
	}

	// update list property
	m_propertyWnd->reDrawInterface();

}

// _OnGetObjectProperty
// need get data from object to property row
void CObjPropertyWindow::_OnGetObjectProperty()
{
	// get object info
	m_objectInfo.clear();
	m_currentObject->saveData( &m_objectInfo );

	ArraySerializableRecIter iRec = m_objectInfo.getAllRecord()->begin(); 
	ArraySerializableRecIter iEnd = m_objectInfo.getAllRecord()->end();
	
	wchar_t lpName[512]		= {0};
	wchar_t lpValue[512]	= {0};

	int nRow = 0;
	uiListPropertyRow *pRow = NULL;

	while ( iRec != iEnd )
	{
		SSerializableRec &r = (*iRec);
		
		// convert name
		uiString::convertUTF8ToUnicode( r.name, (unsigned short*)lpName );
		
		// erase object
		r.tagObject = NULL;

		if ( r.type != NSSerializable::arrayByte && r.type != NSSerializable::groupInfo )
		{
			// convert value
			pRow = (uiListPropertyRow*)m_propertyWnd->getItem(nRow);

			// tag object
			r.tagObject = pRow;

			// set value to row
			uiString::convertUTF8ToUnicode( r.data, (unsigned short*)lpValue );
			pRow->setText( lpValue, 1 );
		}

		iRec++;
		nRow++;
	}

	// update list property
	m_propertyWnd->reDrawInterface();
}

// _OnUpdatedProperty
// need set data to object
void CObjPropertyWindow::_OnUpdatedProperty( uiObject *pSender )
{
	if ( m_currentObject == NULL )
		return;

	ArraySerializableRecIter iRec = m_objectInfo.getAllRecord()->begin(); 
	ArraySerializableRecIter iEnd = m_objectInfo.getAllRecord()->end();
	
	wchar_t	lpValueW[512] = {0};
	char	lpValue[512]	= {0};

	int nRow = 0;
	uiListPropertyRow *pRow = NULL;

	while ( iRec != iEnd )
	{
		SSerializableRec &r = (*iRec);
		
		uiListPropertyRow *pRow = (uiListPropertyRow*) r.tagObject;

		if ( pRow )
		{
			// get text
			pRow->getText(lpValueW, 1);

			// convert name
			uiString::convertUnicodeToUTF8( (unsigned short*) lpValueW, lpValue );
			strcpy( r.data, lpValue );
		}		

		iRec++;
	}
		
	int pos = m_objectInfo.getCursorRecord();
	m_currentObject->updateData( &m_objectInfo );
	m_objectInfo.setCursorRecord( pos );
}