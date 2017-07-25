// Clipboard.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "ClipboardLib.h"
#include "Clipboard.h"


// CClipboard

IMPLEMENT_DYNCREATE(CClipboard, CCmdTarget)


CClipboard::CClipboard()
{
	EnableAutomation();
	
	// OLE �I�[�g���[�V���� �I�u�W�F�N�g���A�N�e�B�u�ł������A�A�v���P�[�V������ 
	//	���s��Ԃɂ��Ă��������A�R���X�g���N�^�� AfxOleLockApp ���Ăяo���܂��B
	
	AfxOleLockApp();
}

CClipboard::~CClipboard()
{
	// ���ׂẴI�u�W�F�N�g�� OLE �I�[�g���[�V�����ō쐬���ꂽ�ꍇ�ɃA�v���P�[�V����
	// 	���I�����邽�߂ɁA�f�X�g���N�^�� AfxOleUnlockApp ���Ăяo���܂��B
	
	AfxOleUnlockApp();
}


void CClipboard::OnFinalRelease()
{
	// �I�[�g���[�V���� �I�u�W�F�N�g�ɑ΂���Ō�̎Q�Ƃ���������Ƃ���
	// OnFinalRelease ���Ăяo����܂��B��{�N���X�͎����I�ɃI�u�W�F�N
	// �g���폜���܂��B��{�N���X���Ăяo���O�ɁA�I�u�W�F�N�g�ŕK�v�ȓ�
	// �ʂȌ㏈����ǉ����Ă��������B

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CClipboard, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CClipboard, CCmdTarget)
	DISP_FUNCTION_ID(CClipboard, "SetText", dispidSetText, SetText, VT_EMPTY, VTS_BSTR)
END_DISPATCH_MAP()

// ����: VBA ����^�C�v �Z�[�t�ȃo�C���h���T�|�[�g���邽�߂ɁAIID_IClipboard �̃T�|�[�g��ǉ����܂��B
//  ���� IID �́A.IDL �t�@�C���̃f�B�X�p�b�` �C���^�[�t�F�C�X�փA�^�b�`����� 
//  GUID �ƈ�v���Ȃ���΂Ȃ�܂���B

// {A3117608-2FC5-4CAF-979C-636271D502CE}
static const IID IID_IClipboard =
{ 0xA3117608, 0x2FC5, 0x4CAF, { 0x97, 0x9C, 0x63, 0x62, 0x71, 0xD5, 0x2, 0xCE } };

BEGIN_INTERFACE_MAP(CClipboard, CCmdTarget)
	INTERFACE_PART(CClipboard, IID_IClipboard, Dispatch)
END_INTERFACE_MAP()

// {D07AF957-C9ED-43C2-BF4C-4636A8C9F9FB}
IMPLEMENT_OLECREATE_FLAGS(CClipboard, "ClipboardLib.Clipboard", afxRegApartmentThreading, 0xd07af957, 0xc9ed, 0x43c2, 0xbf, 0x4c, 0x46, 0x36, 0xa8, 0xc9, 0xf9, 0xfb)


// CClipboard ���b�Z�[�W �n���h��

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
