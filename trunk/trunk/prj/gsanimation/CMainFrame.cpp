#include "stdafx.h"
#include "CMainFrame.h"
#include "Resource.h"

CMainFrame::CMainFrame()
{
	m_currentFile = "";
}

CMainFrame::~CMainFrame()
{
}
	
// create
// Khoi tao cua so
int CMainFrame::create(LPWSTR lpTitle, int x, int y, int w, int h, uiWindow* pParent, LPWSTR lpName)
{
	int ret = uiForm::create( lpTitle, x, y, w, h, pParent, lpName );	

	// add rebar
	uiRebar *pRebar = ref<uiRebar>( new uiRebar(L"RebarTool", 0,0, 300,30, this) );	

	// toolbar play
	uiToolbar *pToolbar = ref<uiToolbar>( new uiToolbar(L"Tools", 0,0,0,0, 32,32, pRebar ) );
	
	uiBitmap iconOpen( MAKEINTRESOURCE(IDB_TOOLBAROPEN), true );	
	uiBitmap iconSave( MAKEINTRESOURCE(IDB_TOOLBARSAVE), true );	
	uiBitmap iconMesh( MAKEINTRESOURCE(IDB_TOOLBARMESH), true );
	uiBitmap iconAnim( MAKEINTRESOURCE(IDB_TOOLBARANIM), true );

	pToolbar->pushImage( &iconOpen );
	pToolbar->pushImage( &iconSave );
	pToolbar->pushImage( &iconMesh );
	pToolbar->pushImage( &iconAnim );

	pToolbar->setButtonWidth(120);	
	pToolbar->setTextRight(true);

	uiToolbarButton *toolbarButton = pToolbar->addButton(L"Open animation", 0);
	toolbarButton->setEventOnClicked<CMainFrame, &CMainFrame::toolbarOpenAnim>( this );

	toolbarButton = pToolbar->addButton(L"Save animation", 1);	
	toolbarButton->setEventOnClicked<CMainFrame, &CMainFrame::toolbarSaveAnim>( this );

	toolbarButton = pToolbar->addButton(L"Load mesh", 2);
	toolbarButton->setEventOnClicked<CMainFrame, &CMainFrame::toolbarLoadMesh>( this );

	toolbarButton = pToolbar->addButton(L"Load animation", 3);
	toolbarButton->setEventOnClicked<CMainFrame, &CMainFrame::toolbarLoadAnimDae>( this );

	uiRebarBand bandToolbar( pToolbar,L"");
	bandToolbar.setBreakBand( true );	
	bandToolbar.enableGripper(false);
	bandToolbar.setMinWidthHeight( 0, 39 );

	// add band to rebar	
	pRebar->addBand( &bandToolbar );
	pRebar->setDock( this, UIDOCK_TOP );	
	pRebar->showBandBorder( false );
	pRebar->showWindow(true);

	uiSplitContainer *split = ref<uiSplitContainer>( new uiSplitContainer(L"mainSplit", 0, 0, 1000, 600, this, 2, 1) );
	
	m_irrWin = ref<CIrrWindow>( new CIrrWindow(L"irrWindow", split) );
	m_propertyWin = ref<uiListProperty>( new uiListProperty(L"propertyWindow", 0,0, 1000, 30, split,5) );
	
	uiListPropertyGroup *pHeader = m_propertyWin->addGroup(L"Animation header");
	pHeader->enableColText(true);
	pHeader->setColText(L"State name", 0);
	pHeader->setColText(L"Next name", 1);
	pHeader->setColText(L"Anim name", 2);
	pHeader->setColText(L"Time begin", 3);
	pHeader->setColText(L"Time", 4);

	m_propertyWin->showWindow( true );

	split->setWindow( m_irrWin, 0, 0 );
	split->setWindow( m_propertyWin, 1, 0 );
	split->setRowSize( 0, 400 );
	split->setRowSize( 1, 300 );
	
	split->changeWindowStyle( UISTYLE_CHILD );
	split->setDock( this, UIDOCK_FILL );
	split->updateSplit();
	split->showWindow( true );

	return ret;
}

void CMainFrame::_OnPaint(uiGraphics * pG)
{
	uiForm::_OnPaint( pG );
}

void CMainFrame::_OnSize(uiSizeEvent sizeEvent, int nWidth, int nHeight)
{
	uiForm::_OnSize( sizeEvent, nWidth, nHeight );
}
	
bool CMainFrame::_OnKeyDown( uiKeyEvent keyEvent )
{
	return true;
}

bool CMainFrame::_OnKeyUp( uiKeyEvent keyEvent )
{
	return true;
}

void CMainFrame::_OnMouseWheel	( uiMouseEvent mouseEvent, int x, int y )
{
}

void CMainFrame::_OnIdle()
{
	m_irrWin->irrUpdate();
}

// registerWindow
// Dang ky cua so form
bool CMainFrame::registerWindow(LPWSTR lpNameApp, HINSTANCE hInst)
{
	WNDCLASSEXW wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = uiWindow::windowProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInst;	
	wndclass.hCursor = LoadCursor (NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH) GetStockObject (LTGRAY_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = lpNameApp;
	wndclass.hIconSm = LoadIcon (NULL, MAKEINTRESOURCE(IDI_GSANIMATION) );
	wndclass.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_GSANIMATION));

	if (! RegisterClassExW(&wndclass))
		return false;

	return true;
}

// messageMap
// Phan tich su kien cho uiForm
LRESULT	CMainFrame::messageMap(HWND hWnd,UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return uiForm::messageMap(hWnd, uMsg, wParam, lParam);
}

void CMainFrame::toolbarOpenAnim( uiObject *pSender )
{

}

void CMainFrame::toolbarSaveAnim( uiObject *pSender )
{
	WCHAR lpPath[ MAX_PATH ] = {0};	
	char lpFileName[ MAX_PATH ] = {0};

	if ( m_currentFile.size() == 0 )
	{
		uiSaveOpenDialog dialog;	
		dialog.clearAllFileExt();
		dialog.addFileExt( L"Animation (.anim)", L"*.anim");
		dialog.addFileExt( L"All files (.*)", L"*.*" );
		if ( dialog.doModal( uiApplication::getRoot(), true ) == false )
			return;

		dialog.getFileName( lpPath );
		uiString::copy<char, WCHAR>( lpFileName, lpPath );
		
		//pParticleComponent->saveXML( lpFileName );

		m_currentFile = lpFileName;
	}
	else
	{
		//pParticleComponent->saveXML( m_currentFile.c_str() );		
	}

	uiString::copy<WCHAR, const char>( lpPath, m_currentFile.c_str() );

	WCHAR title[1024];
	swprintf(title, 1024, L"%s - %s", TEXT( STR_APP_TITLE ), lpPath);
	setCaption( title );
}

void CMainFrame::toolbarLoadMesh( uiObject *pSender )
{
	WCHAR lpPath[ MAX_PATH ] = {0};	
	char lpFileName[ MAX_PATH ] = {0};
	
	uiSaveOpenDialog dialog;	
	dialog.clearAllFileExt();
	dialog.addFileExt( L"Mesh file (.x, *.dae)", L"*.x|*.dae" );
	dialog.addFileExt( L"All files (.*)", L"*.*" );
	if ( dialog.doModal( uiApplication::getRoot(), false ) == false )
		return;
		
	dialog.getFileName( lpPath );
	uiString::copy<char, WCHAR>( lpFileName, lpPath );

}

void CMainFrame::toolbarLoadAnimDae( uiObject *pSender )
{
	
}