

#pragma once


// CClipboard コマンド ターゲット

class CClipboard : public CCmdTarget
{
	DECLARE_DYNCREATE(CClipboard)

public:
	CClipboard();
	virtual ~CClipboard();

	virtual void OnFinalRelease();

protected:
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CClipboard)
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	void SetText(LPCTSTR inStr);

	enum 
	{
		dispidGetText = 102L,
		dispidSetText = 101L
	};
	BSTR GetText(void);
};


