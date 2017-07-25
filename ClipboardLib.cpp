// ClipboardLib.cpp : DLL の初期化ルーチンです。
//

#include "stdafx.h"
#include "ClipboardLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: この DLL が MFC DLL に対して動的にリンクされる場合、
//		MFC 内で呼び出されるこの DLL からエクスポートされたどの関数も
//		関数の最初に追加される AFX_MANAGE_STATE マクロを
//		持たなければなりません。
//
//		例:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 通常関数の本体はこの位置にあります
//		}
//
//		このマクロが各関数に含まれていること、MFC 内の
//		どの呼び出しより優先することは非常に重要です。
//		これは関数内の最初のステートメントでなければな 
//		らないことを意味します、コンストラクタが MFC
//		DLL 内への呼び出しを行う可能性があるので、オブ
//		ジェクト変数の宣言よりも前でなければなりません。
//
//		詳細については MFC テクニカル ノート 33 および
//		58 を参照してください。
//


// CClipboardLibApp

BEGIN_MESSAGE_MAP(CClipboardLibApp, CWinApp)
END_MESSAGE_MAP()


// CClipboardLibApp コンストラクション

CClipboardLibApp::CClipboardLibApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}


// 唯一の CClipboardLibApp オブジェクトです。

CClipboardLibApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0xCD40487F, 0xDFD6, 0x40DC, { 0x84, 0x55, 0x82, 0xFA, 0x45, 0xB0, 0xB3, 0x2A } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CClipboardLibApp 初期化

BOOL CClipboardLibApp::InitInstance()
{
	CWinApp::InitInstance();

	// すべての OLE サーバー ファクトリを実行中に登録してください。これにより、
	//  OLE ライブラリが他のアプリケーションからオブジェクトを作成できるようになります。
	COleObjectFactory::RegisterAll();

	return TRUE;
}

// DllGetClassObject - クラス ファクトリを返します。

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}


// DllCanUnloadNow - COM が DLL をアンロードできるようにします。

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}


// DllRegisterServer - エントリをシステム レジストリに追加します。

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll())
		return SELFREG_E_CLASS;

	return S_OK;
}


// DllUnregisterServer - エントリをレジストリから削除します。

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll(FALSE))
		return SELFREG_E_CLASS;

	return S_OK;
}
