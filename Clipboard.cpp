// Clipboard.cpp : 実装ファイル
//

#include "stdafx.h"
#include "ClipboardLib.h"
#include "Clipboard.h"


// CClipboard

IMPLEMENT_DYNCREATE(CClipboard, CCmdTarget)


CClipboard::CClipboard()
{
	EnableAutomation();
	
	// OLE オートメーション オブジェクトがアクティブである限り、アプリケーションを 
	//	実行状態にしてください、コンストラクタは AfxOleLockApp を呼び出します。
	
	AfxOleLockApp();
}

CClipboard::~CClipboard()
{
	// すべてのオブジェクトが OLE オートメーションで作成された場合にアプリケーション
	// 	を終了するために、デストラクタが AfxOleUnlockApp を呼び出します。
	
	AfxOleUnlockApp();
}


void CClipboard::OnFinalRelease()
{
	// オートメーション オブジェクトに対する最後の参照が解放されるときに
	// OnFinalRelease が呼び出されます。基本クラスは自動的にオブジェク
	// トを削除します。基本クラスを呼び出す前に、オブジェクトで必要な特
	// 別な後処理を追加してください。

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CClipboard, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CClipboard, CCmdTarget)
	DISP_FUNCTION_ID(CClipboard, "SetText", dispidSetText, SetText, VT_EMPTY, VTS_BSTR)
END_DISPATCH_MAP()

// メモ: VBA からタイプ セーフなバインドをサポートするために、IID_IClipboard のサポートを追加します。
//  この IID は、.IDL ファイルのディスパッチ インターフェイスへアタッチされる 
//  GUID と一致しなければなりません。

// {A3117608-2FC5-4CAF-979C-636271D502CE}
static const IID IID_IClipboard =
{ 0xA3117608, 0x2FC5, 0x4CAF, { 0x97, 0x9C, 0x63, 0x62, 0x71, 0xD5, 0x2, 0xCE } };

BEGIN_INTERFACE_MAP(CClipboard, CCmdTarget)
	INTERFACE_PART(CClipboard, IID_IClipboard, Dispatch)
END_INTERFACE_MAP()

// {D07AF957-C9ED-43C2-BF4C-4636A8C9F9FB}
IMPLEMENT_OLECREATE_FLAGS(CClipboard, "ClipboardLib.Clipboard", afxRegApartmentThreading, 0xd07af957, 0xc9ed, 0x43c2, 0xbf, 0x4c, 0x46, 0x36, 0xa8, 0xc9, 0xf9, 0xfb)


// CClipboard メッセージ ハンドラ

void CClipboard::SetText(LPCWSTR inStr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (inStr == NULL) {
		if (OpenClipboard(0)) {
			EmptyClipboard();
			CloseClipboard();
			return;
		}
	}
	else {
		HGLOBAL hGlobalMemory = GlobalAlloc(GHND, 2 * (wcslen(inStr) + 1));
		if (hGlobalMemory != NULL) {
			PVOID pGlobalMemory = GlobalLock(hGlobalMemory);
			if (pGlobalMemory != NULL) {
				lstrcpyW(reinterpret_cast<LPWSTR>(pGlobalMemory), inStr);
				GlobalUnlock(hGlobalMemory);
				if (OpenClipboard(0)) {
					EmptyClipboard();
					SetClipboardData(CF_UNICODETEXT, hGlobalMemory);
					CloseClipboard();
					return;
				}
			}
			GlobalFree(hGlobalMemory);
		}
	}
	AfxThrowOleDispatchException(101, L"SetText failure");
}
