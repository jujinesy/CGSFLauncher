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
	// �˾��޴�����
	void MakePopupMenu(HWND hWnd, int x, int y);
	// Ʈ���̾����� ���� ����
	bool m_bExist;
	// Ʈ���̾����� ���迩��
	bool m_bHide;
	// �˾��޴��� �̺�Ʈ �߻��� ó�� ��
	void ProcTrayMsg(HWND hWnd, WPARAM wParam, LPARAM lParam);
	// Ʈ���̾����� �߰�
	bool AddTrayIcon(HWND hWnd);
	// Ʈ���̾����� ����
	bool TrayIconTooltip(HWND hWnd);
	// Ʈ���̾����� ����
	bool DelTrayIcon(HWND hWnd);

	// Ʈ���̾����� ����
	afx_msg LRESULT OnTrayIcon(WPARAM wParam, LPARAM lParam);
	//afx_msg LRESULT OnTrayIcon(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDialogShow();
};