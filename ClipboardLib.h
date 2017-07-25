// ClipboardLib.h : ClipboardLib.DLL のメイン ヘッダー ファイル
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CClipboardLibApp
// このクラスの実装に関しては ClipboardLib.cpp を参照してください。
//

class CClipboardLibApp : public CWinApp
{
public:
	CClipboardLibApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
