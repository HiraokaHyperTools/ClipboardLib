// ClipboardLib.h : ClipboardLib.DLL �̃��C�� �w�b�_�[ �t�@�C��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"		// ���C�� �V���{��


// CClipboardLibApp
// ���̃N���X�̎����Ɋւ��Ă� ClipboardLib.cpp ���Q�Ƃ��Ă��������B
//

class CClipboardLibApp : public CWinApp
{
public:
	CClipboardLibApp();

// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
