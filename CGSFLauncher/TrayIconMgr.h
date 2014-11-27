#pragma once
#include "resource.h"
#include "CGSFLauncherDlg.h"
#include "CppSingleton.h"

class TrayIconMgr : public CppSingleton <TrayIconMgr>
//class TrayIconMgr
{
public:
	TrayIconMgr();
	virtual ~TrayIconMgr();
	// 팝업메뉴생성
	void MakePopupMenu(HWND hWnd, int x, int y);
	// 트래이아이콘 존재 여부
	bool m_bExist;
	// 트래이아이콘 숨김여부
	bool m_bHide;
	// 팝업메뉴의 이벤트 발생시 처리 함
	void ProcTrayMsg(HWND hWnd, WPARAM wParam, LPARAM lParam);
	// 트래이아이콘 추가
	bool AddTrayIcon(HWND hWnd);
	// 트래이아이콘 툴팁
	bool TrayIconTooltip(HWND hWnd);
	// 트레이아이콘 제거
	bool DelTrayIcon(HWND hWnd);

	// 트래이아이콘 생성
	afx_msg LRESULT OnTrayIcon(WPARAM wParam, LPARAM lParam);
	//afx_msg LRESULT OnTrayIcon(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDialogShow();
};