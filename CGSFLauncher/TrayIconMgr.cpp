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


// 팝업메뉴생성

void TrayIconMgr::MakePopupMenu(HWND hWnd, int x, int y)
{
	//팝업 메뉴를 생성하고 메뉴 구성
	HMENU hMenu = CreatePopupMenu();
	CCGSFLauncherDlg* CWnd;
	(CCGSFLauncherDlg*)CWnd = (CCGSFLauncherDlg*)CWnd::FromHandle(hWnd);

	if (m_bHide)
	{
		AppendMenu(hMenu, MF_STRING, WM_DIALOG_SHOW, _T("런처 숨기기"));
	}
	else{
		AppendMenu(hMenu, MF_STRING, WM_DIALOG_SHOW, _T("런처 열기"));
	}
	AppendMenu(hMenu, MF_STRING, WM_NONE, _T("업데이트 날자 : 14.12.14"));
	AppendMenu(hMenu, MF_STRING, WM_NOTICE, _T("업데이트 내용"));	
	AppendMenu(hMenu, MF_STRING, WM_ABOUTBOX, _T("런처 정보"));	
	AppendMenu(hMenu, MF_STRING, WM_APP_EXIT, _T("종료"));

	SetForegroundWindow(hWnd);//생성된 팝업메뉴 밖을 클릭할 때 팝업 닫기
	//팝업 메뉴 띄우기
	TrackPopupMenu(hMenu, TPM_LEFTALIGN | TPM_RIGHTBUTTON, x, y, 0, hWnd, NULL);
}

// 팝업메뉴의 이벤트 발생시 처리 함
void TrayIconMgr::ProcTrayMsg(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu = NULL;
	POINT pos;

	if (lParam == WM_RBUTTONDOWN)
	{
		GetCursorPos(&pos);
		MakePopupMenu(hWnd, pos.x, pos.y); //팝업 메뉴 생성 및 출력
	}
}

// 트래이아이콘 추가
bool TrayIconMgr::AddTrayIcon(HWND hWnd)
{
	if (m_bExist)		//이미 트레이 아이콘이 있다면 종료
		return FALSE;

	NOTIFYICONDATA nid;	//아이콘을 생성하여 설정
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
	if (Shell_NotifyIcon(NIM_ADD, &nid) == 0) //트레이 아이콘 표시
		return FALSE;
	m_bExist = true;
	return TRUE;
}

// 트래이아이콘 툴팁
bool TrayIconMgr::TrayIconTooltip(HWND hWnd)
{
	NOTIFYICONDATA nid;	//아이콘을 생성하여 설정

	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = hWnd;

	nid.uFlags = NIF_INFO;
	lstrcpy(nid.szInfo, _T("새로운 공지사항이 도착했습니다.\n공지사항을 확인해 주세요."));
	lstrcpy(nid.szInfoTitle, _T("알림"));
	nid.dwInfoFlags = NIIF_INFO;
	nid.uTimeout = 10000;
	Shell_NotifyIcon(NIM_MODIFY, &nid);
	return TRUE;
}

// 트레이아이콘 제거
bool TrayIconMgr::DelTrayIcon(HWND hWnd)
{
	NOTIFYICONDATA nid;

	ZeroMemory(&nid, sizeof(NOTIFYICONDATA));
	nid.cbSize = sizeof(NOTIFYICONDATA);
	nid.hWnd = hWnd;
	nid.uFlags = NULL;
	if (Shell_NotifyIcon(NIM_DELETE, &nid) == 0) //트레이 아이콘 삭제
		return FALSE;
	return TRUE;
}