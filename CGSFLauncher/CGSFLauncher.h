
// CGSFLauncher.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCGSFLauncherApp:
// �� Ŭ������ ������ ���ؼ��� CGSFLauncher.cpp�� �����Ͻʽÿ�.
//

class CCGSFLauncherApp : public CWinApp
{
public:
	CCGSFLauncherApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCGSFLauncherApp theApp;