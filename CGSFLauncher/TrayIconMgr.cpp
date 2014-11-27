#include "stdafx.h"
#include "TrayIconMgr.h"

TrayIconMgr::TrayIconMgr()
: m_bExist(false)
, m_bHide(TRUE)
{
}


TrayIconMgr::~TrayIconMgr()
{
}


// �˾��޴�����

void TrayIconMgr::MakePopupMenu(HWND hWnd, int x, int y)
{
	//�˾� �޴��� �����ϰ� �޴� ����
	HMENU hMenu = CreatePopupMenu();
	CCGSFLauncherDlg* CWnd;
	(CCGSFLauncherDlg*)CWnd = (CCGSFLauncherDlg*)CWnd::FromHandle(hWnd);

	if (m_bHide)
	{
		AppendMenu(hMenu, MF_STRING, WM_DIALOG_SHOW, _T("��ó �����"));
	}
	else{
		AppendMenu(hMenu, MF_STRING, WM_DIALOG_SHOW, _T("��ó ����"));
	}
	AppendMenu(hMenu, MF_STRING, WM_NONE, _T("������Ʈ ���� : 14.12.14"));
	AppendMenu(hMenu, MF_STRING, WM_NOTICE, _T("������Ʈ ����"));	
	AppendMenu(hMenu, MF_STRING, WM_ABOUTBOX, _T("��ó ����"));	
	AppendMenu(hMenu, MF_STRING, WM_APP_EXIT, _T("����"));

	SetForegroundWindow(hWnd);//������ �˾��޴� ���� Ŭ���� �� �˾� �ݱ�
	//�˾� �޴� ����
	TrackPopupMenu(hMenu, TPM_LEFTALIGN | TPM_RIGHTBUTTON, x, y, 0, hWnd, NULL);
}

// �˾��޴��� �̺�Ʈ �߻��� ó�� ��
void TrayIconMgr::ProcTrayMsg(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu = NULL;
	POINT pos;

	if (lParam == WM_RBUTTONDOWN)
	{
		GetCursorPos(&pos);
		MakePopupMenu(hWnd, pos.x, pos.y); //�˾� �޴� ���� �� ���
	}
}

// Ʈ���̾����� �߰�
bool TrayIconMgr::AddTrayIcon(HWND hWnd)
{
	if (m_bExist)		//�̹� Ʈ���� �������� �ִٸ� ����
		return FALSE;

	NOTIFYICONDATA nid;	//�������� �����Ͽ� ����
	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = hWnd;
	//nid.szInfo = (LPCTSTR)"sd";
	//nid.szInfoTitle = (LPCTSTR)"sd";
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = WM_TRAYICON;
	wsprintf(nid.szTip, _T("CGSF Launcher"));

	nid.uID = 0;
	nid.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	if (Shell_NotifyIcon(NIM_ADD, &nid) == 0) //Ʈ���� ������ ǥ��
		return FALSE;
	m_bExist = true;
	return TRUE;
}

// Ʈ���̾����� ����
bool TrayIconMgr::TrayIconTooltip(HWND hWnd)
{
	NOTIFYICONDATA nid;	//�������� �����Ͽ� ����

	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = hWnd;

	nid.uFlags = NIF_INFO;
	lstrcpy(nid.szInfo, _T("���ο� ���������� �����߽��ϴ�.\n���������� Ȯ���� �ּ���."));
	lstrcpy(nid.szInfoTitle, _T("�˸�"));
	nid.dwInfoFlags = NIIF_INFO;
	nid.uTimeout = 10000;
	Shell_NotifyIcon(NIM_MODIFY, &nid);
	return TRUE;
}

// Ʈ���̾����� ����
bool TrayIconMgr::DelTrayIcon(HWND hWnd)
{
	NOTIFYICONDATA nid;

	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = hWnd;
	nid.uFlags = NULL;
	if (Shell_NotifyIcon(NIM_DELETE, &nid) == 0) //Ʈ���� ������ ����
		return FALSE;
	return TRUE;
}