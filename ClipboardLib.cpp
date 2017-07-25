// ClipboardLib.cpp : DLL �̏��������[�`���ł��B
//

#include "stdafx.h"
#include "ClipboardLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ���� DLL �� MFC DLL �ɑ΂��ē��I�Ƀ����N�����ꍇ�A
//		MFC ���ŌĂяo����邱�� DLL ����G�N�X�|�[�g���ꂽ�ǂ̊֐���
//		�֐��̍ŏ��ɒǉ������ AFX_MANAGE_STATE �}�N����
//		�����Ȃ���΂Ȃ�܂���B
//
//		��:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �ʏ�֐��̖{�̂͂��̈ʒu�ɂ���܂�
//		}
//
//		���̃}�N�����e�֐��Ɋ܂܂�Ă��邱�ƁAMFC ����
//		�ǂ̌Ăяo�����D�悷�邱�Ƃ͔��ɏd�v�ł��B
//		����͊֐����̍ŏ��̃X�e�[�g�����g�łȂ���΂� 
//		��Ȃ����Ƃ��Ӗ����܂��A�R���X�g���N�^�� MFC
//		DLL ���ւ̌Ăяo�����s���\��������̂ŁA�I�u
//		�W�F�N�g�ϐ��̐錾�����O�łȂ���΂Ȃ�܂���B
//
//		�ڍׂɂ��Ă� MFC �e�N�j�J�� �m�[�g 33 �����
//		58 ���Q�Ƃ��Ă��������B
//


// CClipboardLibApp

BEGIN_MESSAGE_MAP(CClipboardLibApp, CWinApp)
END_MESSAGE_MAP()


// CClipboardLibApp �R���X�g���N�V����

CClipboardLibApp::CClipboardLibApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}


// �B��� CClipboardLibApp �I�u�W�F�N�g�ł��B

CClipboardLibApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0xCD40487F, 0xDFD6, 0x40DC, { 0x84, 0x55, 0x82, 0xFA, 0x45, 0xB0, 0xB3, 0x2A } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CClipboardLibApp ������

BOOL CClipboardLibApp::InitInstance()
{
	CWinApp::InitInstance();

	// ���ׂĂ� OLE �T�[�o�[ �t�@�N�g�������s���ɓo�^���Ă��������B����ɂ��A
	//  OLE ���C�u���������̃A�v���P�[�V��������I�u�W�F�N�g���쐬�ł���悤�ɂȂ�܂��B
	COleObjectFactory::RegisterAll();

	return TRUE;
}

// DllGetClassObject - �N���X �t�@�N�g����Ԃ��܂��B

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}


// DllCanUnloadNow - COM �� DLL ���A�����[�h�ł���悤�ɂ��܂��B

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}


// DllRegisterServer - �G���g�����V�X�e�� ���W�X�g���ɒǉ����܂��B

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll())
		return SELFREG_E_CLASS;

	return S_OK;
}


// DllUnregisterServer - �G���g�������W�X�g������폜���܂��B

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll(FALSE))
		return SELFREG_E_CLASS;

	return S_OK;
}
