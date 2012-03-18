#include "StdAfx.h"
#include "RibbonCommandHandler.h"
#include "ids.h"
#include "Resource.h"
#include "CGlobalInstance.h"

#include "IView.h"
#include "IDoc.h"
#include "IController.h"

#include "CZone.h"

STDMETHODIMP CRibbonCommandHandler::Execute(UINT nCmdID,
                   UI_EXECUTIONVERB verb, 
                   const PROPERTYKEY* key,
                   const PROPVARIANT* ppropvarValue,
                   IUISimplePropertySet* pCommandExecutionProperties)
{
    
	switch (verb)
    {
    case UI_EXECUTIONVERB_PREVIEW:				
        break;
    case UI_EXECUTIONVERB_CANCELPREVIEW:		
        break;
    case UI_EXECUTIONVERB_EXECUTE:
		if ( nCmdID == ID_SELECT )
			onSelectObjectCommand();
		else if ( nCmdID == ID_ROTATE )
			onRotateObjectCommand();
		else if ( nCmdID == ID_SCALE )
			onScaleObjectCommand();
		else if ( nCmdID == ID_CAMERAVIEW )
			onCameraViewCommand();
		else if ( nCmdID == ID_ADDOBJECT )
			onAddObjectCommand();

		break;
    }
	
	// active window
	uiApplication::getRoot()->setFocus();

	return S_OK;
}

//
//  FUNCTION: UpdateProperty()
//
//  PURPOSE: Called by the Ribbon framework when a command property (PKEY) needs to be updated.
//
//  COMMENTS:
//
//    Depending on the value of key, this will populate the gallery, update the selected item or 
//    text, or enable/disable the gallery.
//
//
STDMETHODIMP CRibbonCommandHandler::UpdateProperty(UINT nCmdID,
                              REFPROPERTYKEY key,
                              const PROPVARIANT* ppropvarCurrentValue,
                              PROPVARIANT* ppropvarNewValue)
{
	return S_OK;
}

HRESULT CRibbonCommandHandler::CreateInstance(CRibbonCommandHandler **ppHandler)
{
    if (!ppHandler)
    {
        return E_POINTER;
    }

    *ppHandler = NULL;

    HRESULT hr = S_OK;

    CRibbonCommandHandler* pHandler = new CRibbonCommandHandler();

    if (pHandler != NULL)
    {
        *ppHandler = pHandler;        
    }
    else
    {
        hr = E_OUTOFMEMORY;
    }

    return hr;
}

// IUnknown methods.
STDMETHODIMP_(ULONG) CRibbonCommandHandler::AddRef()
{
    return InterlockedIncrement(&m_cRef);
}

STDMETHODIMP_(ULONG) CRibbonCommandHandler::Release()
{
    LONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
    {
        delete this;
    }

    return cRef;
}

STDMETHODIMP CRibbonCommandHandler::QueryInterface(REFIID iid, void** ppv)
{
    if (!ppv)
    {
        return E_POINTER;
    }

    if (iid == __uuidof(IUnknown))
    {
        *ppv = static_cast<IUnknown*>(this);
    }
    else if (iid == __uuidof(IUICommandHandler))
    {
        *ppv = static_cast<IUICommandHandler*>(this);
    }
    else 
    {
        *ppv = NULL;
        return E_NOINTERFACE;
    }

    AddRef();
    return S_OK;
}

HRESULT CRibbonCommandHandler::CreateUIImageFromBitmapResource(LPCTSTR pszResource, IUIImage **ppimg)
{
    HRESULT hr = E_FAIL;

    *ppimg = NULL;

    if (NULL == m_pifbFactory)
    {
        hr = CoCreateInstance(CLSID_UIRibbonImageFromBitmapFactory, NULL, CLSCTX_ALL, IID_PPV_ARGS(&m_pifbFactory));
        if (FAILED(hr))
        {
            return hr;
        }
    }

    // Load the bitmap from the resource file.
    HBITMAP hbm = (HBITMAP) LoadImage(GetModuleHandle(NULL), pszResource, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
    if (hbm)
    {
        // Use the factory implemented by the framework to produce an IUIImage.
        hr = m_pifbFactory->CreateImage(hbm, UI_OWNERSHIP_TRANSFER, ppimg);
        if (FAILED(hr))
        {
            DeleteObject(hbm);
        }
    }
    return hr;
}

CRibbonItem* CRibbonCommandHandler::createRibbonItem( IUICollection *pCollection, wchar_t *lpString, UINT imageID )
{
	CRibbonItem *pItem = new CRibbonItem();	
	pItem->m_text = lpString;

	if ( imageID > 0 )
	{
		IUIImage *pImg;
		if ( CreateUIImageFromBitmapResource( MAKEINTRESOURCE( imageID ), &pImg) == S_OK )
			pItem->m_image = pImg;
	}	
	
	pCollection->Add( pItem );
	pItem->Release();

	return pItem;
}

void CRibbonCommandHandler::setSelectItem( UINT idCmd, int select )
{	
	PROPVARIANT ret;	
	UIInitPropertyFromUInt32(UI_PKEY_SelectedItem, select, &ret);
	CGlobalInstance::getInstance()->m_ribbonFramework->SetUICommandProperty( idCmd, UI_PKEY_SelectedItem, ret );
}

void CRibbonCommandHandler::getSelectItem( UINT idCmd, int *select )
{
	PROPVARIANT ret;
	CGlobalInstance::getInstance()->m_ribbonFramework->GetUICommandProperty( idCmd, UI_PKEY_SelectedItem, &ret );

	UINT uSelect;
	UIPropertyToUInt32(UI_PKEY_SelectedItem, ret, &uSelect);
	*select = (int)uSelect;
}

void CRibbonCommandHandler::setColorCommand( UINT idCmd, UINT rgbColor )
{
	
}

bool CRibbonCommandHandler::getColorCommand( UINT idCmd, UINT *rgbColor )
{		
	PROPVARIANT ret;
	CGlobalInstance::getInstance()->m_ribbonFramework->GetUICommandProperty( idCmd, UI_PKEY_ColorType, &ret );

	// Retrieve color type.
	UINT type = UI_SWATCHCOLORTYPE_NOCOLOR;
    UIPropertyToUInt32(UI_PKEY_ColorType, ret, &type);

	*rgbColor = 0;

	if ( type == UI_SWATCHCOLORTYPE_RGB )
	{
		PROPVARIANT ret;
		
		CGlobalInstance::getInstance()->m_ribbonFramework->GetUICommandProperty( idCmd, UI_PKEY_Color, &ret );
		UIPropertyToUInt32(UI_PKEY_Color, ret, rgbColor);

		// select color
		return true;
	}
	
	// no color
	return false;
}

void CRibbonCommandHandler::setEnableCommand( UINT idCmd, bool enable )
{
	// enable, disable font control
	PROPVARIANT ret;
	UIInitPropertyFromBoolean(UI_PKEY_Enabled, enable, &ret);

	CGlobalInstance::getInstance()->m_ribbonFramework->SetUICommandProperty( idCmd, UI_PKEY_Enabled, ret );
}

void CRibbonCommandHandler::setSelectCommand( UINT	idCmd, bool select )
{
	PROPVARIANT ret;
	UIInitPropertyFromBoolean(UI_PKEY_BooleanValue, select, &ret);
	CGlobalInstance::getInstance()->m_ribbonFramework->SetUICommandProperty( idCmd, UI_PKEY_BooleanValue, ret );
}

void CRibbonCommandHandler::setVisibleCommand( UINT idCmd, bool visible )
{
	PROPVARIANT ret;
	UIInitPropertyFromBoolean(UI_PKEY_BooleanValue, visible, &ret);
	CGlobalInstance::getInstance()->m_ribbonFramework->SetUICommandProperty( idCmd, UI_PKEY_Viewable, ret );
}


void CRibbonCommandHandler::resetDefaultCommand()
{	
	setSelectCommand( ID_SELECT,	false );
	setSelectCommand( ID_ROTATE,	false );
	setSelectCommand( ID_SCALE,		false );

	setSelectCommand( ID_CAMERAVIEW,	false );
	setSelectCommand( ID_ADDOBJECT,		false );

	

	IUIFramework *ribbonFramework = CGlobalInstance::getInstance()->m_ribbonFramework;

	// refresh control
	ribbonFramework->InvalidateUICommand( ID_SELECT,	UI_INVALIDATIONS_STATE, NULL );
	ribbonFramework->InvalidateUICommand( ID_ROTATE,	UI_INVALIDATIONS_STATE, NULL );
	ribbonFramework->InvalidateUICommand( ID_SCALE,		UI_INVALIDATIONS_STATE, NULL );
	
	ribbonFramework->InvalidateUICommand( ID_CAMERAVIEW,	UI_INVALIDATIONS_STATE, NULL );
	ribbonFramework->InvalidateUICommand( ID_ADDOBJECT,		UI_INVALIDATIONS_STATE, NULL );
}

void CRibbonCommandHandler::selectOnlyCommand( UINT idCmd )
{
	resetDefaultCommand();
	setSelectCommand( idCmd, true );
}

void CRibbonCommandHandler::showContextMenu(int menuID, POINT& ptLocation, HWND hWnd)
{
	getDisplayLocation(ptLocation, hWnd);

    HRESULT hr = E_FAIL;
	
	IUIFramework*	pFramework = CGlobalInstance::getInstance()->m_ribbonFramework;

    // The basic pattern of how to show Contextual UI in a specified location.
    IUIContextualUI* pContextualUI = NULL;
    if (SUCCEEDED(pFramework->GetView( menuID, IID_PPV_ARGS(&pContextualUI))))
    {
        hr = pContextualUI->ShowAtLocation(ptLocation.x, ptLocation.y);
        pContextualUI->Release();
    }
}

void CRibbonCommandHandler::getDisplayLocation(POINT &pt, HWND hWnd)
{
	if (pt.x == -1 && pt.y == -1)
    {
        HRESULT hr = E_FAIL;

        // Display the menu in the upper-left corner of the client area, below the ribbon.
		IUIFramework*	pFramework = CGlobalInstance::getInstance()->m_ribbonFramework;

        IUIRibbon* pRibbon;
        hr = pFramework->GetView(0, IID_PPV_ARGS(&pRibbon));
        if (SUCCEEDED(hr))
        {
            UINT32 uRibbonHeight = 0;
            hr = pRibbon->GetHeight(&uRibbonHeight);
            if (SUCCEEDED(hr))
            {
                pt.x = 0;
                pt.y = uRibbonHeight;
                ClientToScreen(hWnd, &pt);
            }
            pRibbon->Release();
        }
        if (FAILED(hr))
        {
            // Default to just the upper-right corner of the entire screen.
            pt.x = 0;
            pt.y = 0;
        }
    }
}


/////////////////////////////////////////////////////////
// COMMAND 
/////////////////////////////////////////////////////////

void CRibbonCommandHandler::onCameraViewCommand()
{
	selectOnlyCommand( ID_CAMERAVIEW );
	CControllerManager::getInstance()->setController( IController::NullController );
	getIView()->enableFreeCamera( true );
}

void CRibbonCommandHandler::onAddObjectCommand()
{
	selectOnlyCommand( ID_ADDOBJECT );
	CControllerManager::getInstance()->setController( IController::AddObject );
	getIView()->enableFreeCamera( false );
}

void CRibbonCommandHandler::onSelectObjectCommand()
{
	selectOnlyCommand( ID_SELECT );
	CControllerManager::getInstance()->setController( IController::SelectObject );
	getIView()->getDocument()->setStateForSelectObject( CGameObject::Move );
	getIView()->enableFreeCamera( false );
}

void CRibbonCommandHandler::onRotateObjectCommand()
{
	selectOnlyCommand( ID_ROTATE );
	CControllerManager::getInstance()->setController( IController::RotateObject );
	getIView()->getDocument()->setStateForSelectObject( CGameObject::Rotation );
	getIView()->enableFreeCamera( false );
}

void CRibbonCommandHandler::onScaleObjectCommand()
{
	selectOnlyCommand( ID_SCALE );
	CControllerManager::getInstance()->setController( IController::ScaleObject );
	getIView()->getDocument()->setStateForSelectObject( CGameObject::Scale );
	getIView()->enableFreeCamera( false );
}

void CRibbonCommandHandler::onDeleteSelectObjectCommand()
{
	IDoc *pDoc = getIView()->getDocument();

	// get current select
	ArrayGameObject listSelect = *pDoc->getSelectObject();
	pDoc->clearSelect();

	// delete object
	ArrayGameObjectIter i = listSelect.begin(), iEnd = listSelect.end();
	while ( i != iEnd )
	{
		CGameObject* pObj = (*i);
		
		CZone *pZone = (CZone*)pObj->getParent();
		if ( pZone )
			pZone->removeObject( pObj );

		i++;
	}

}

/////////////////////////////////////////////////////////
// END COMMAND 
/////////////////////////////////////////////////////////