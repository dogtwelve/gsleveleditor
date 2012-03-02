#include "stdafx.h"
#include "CMapTreeWin.h"
#include "ids.h"
#include "CGlobalInstance.h"
#include "IView.h"
#include "Resource.h"

CMapTreeWindow::CMapTreeWindow( WCHAR* lpString, uiWindow *p )
	:CBaseWindow( lpString, p )
{
	m_treeView = ref<uiTreeView>( new uiTreeView(L"MapTree", 0,0, 1, 1, true, this) );
	m_treeView->setMargin(0,0,30,0);
	m_treeView->setDock( this, UIDOCK_FILL );
	m_treeView->changeStyleEx( 0, WS_EX_CLIENTEDGE );	
	m_treeView->showWindow( true );
	m_treeView->setEventOnSelectChange<CMapTreeWindow, &CMapTreeWindow::_onTreeSelect>( this );

	uiIcon iconRoot( MAKEINTRESOURCE(IDI_TREEROOT) );
	uiIcon iconContainer( MAKEINTRESOURCE(IDI_TREECONTAINER) );
	uiIcon iconContainerOpen( MAKEINTRESOURCE(IDI_TREECONTAINEROPEN) );
	uiIcon iconContainerHidden( MAKEINTRESOURCE(IDI_TREECONTAINERHIDDEN) );	

	m_nTreeRootIcon			= m_treeView->pushSmallImage( &iconRoot );
	m_nTreeContainer		= m_treeView->pushSmallImage( &iconContainer );
	m_nTreeContainerOpen	= m_treeView->pushSmallImage( &iconContainerOpen );
	m_nTreeContainerHidden	= m_treeView->pushSmallImage( &iconContainerHidden );	

	SetWindowTheme(m_treeView->getHandle(), TEXT("explorer"), NULL);
		
	// init
	initTreeView();
}

CMapTreeWindow::~CMapTreeWindow()
{
}

void CMapTreeWindow::initTreeView()
{
	// add root
	const WCHAR *lpRootName = L"toado3d";
	m_rootItem = m_treeView->addItem( (WCHAR*)lpRootName );
	
	// select root
	m_treeView->selectItem( m_rootItem );
}

void CMapTreeWindow::clearAllTreeView()
{
	m_treeView->deleteAllItem();
}

void CMapTreeWindow::_OnPaint( uiGraphics *pG )
{
	uiWindow::_OnPaint( pG );
	drawTitleBackground(pG, 0,0, this->getWidth(), 30, TEXT("Cấu trúc bản đồ"));	
}

LRESULT CMapTreeWindow::messageMap( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	if ( uMsg == WM_CONTEXTMENU )
	{
		POINT pt;
		POINTSTOPOINT(pt, lParam);		
		HWND wndSend = (HWND)wParam;

		if ( wndSend == m_treeView->getHandle() )
		{
			POINT point;
			point.x = pt.x;
			point.y = pt.y;
			ScreenToClient( m_treeView->getHandle(), &point);
			
			uiTreeViewItem *pItem = m_treeView->getHisTest( point.x, point.y );
									
			if ( pItem )
			{

			}
		}
	}

	return uiWindow::messageMap( hWnd, uMsg, wParam, lParam );
}

void CMapTreeWindow::_onTreeSelect(uiObject *sender)
{
	uiListTreeViewItem list;
	m_treeView->getItemSelected( &list );
	
	int selectCount = list.size();
	if ( selectCount == 1 )
	{
		uiTreeViewItem *pItem = list[0];
	}	
}