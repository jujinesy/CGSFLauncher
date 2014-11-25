
// CGSFLauncherDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#define GLOBAL_HOOK _T("Global_Hook")
#define HOOK_RECOVERY _T("Hook_Recovery")
#define KERNSEC _T("Kernsec")
#define LDRDLLNOTI _T("LdrDllNoti")
#define CREATEREMOTE_HOOK _T("CreateRemote_Hook")
#define SETWINDOWSHOOKEX _T("SetWindowsHookEx")
#define D3D9_ANTI_HOOK _T("D3D9_Anti_Hook")
#define D3D9_VTABLE_HASH _T("D3D9_vTable_Hash")
#define THREAD_PROTECT _T("Thread_Protect")
#define SPEED_HACK _T("Speed_Hack")
#define MEMORY_CRC _T("Memory_CRC")
#define FILE_HASH _T("File_Hash")
#define SENDINPUT _T("SendInput")
#define SENDMESSAGE _T("SendMessage")
#define WINDOWED _T("Windowed")
#define CODE_VM _T("Code_VM")
#define DEBUG_MODE _T("Debug_Mode")
#define DRBP _T("DRBP")

// CCGSFLauncherDlg 대화 상자
class CCGSFLauncherDlg : public CDialogEx
{
// 생성입니다.
public:
	CCGSFLauncherDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CGSFLAUNCHER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CButton m_Check1;
	CButton m_Check2;
	CButton m_Check3;
	CButton m_Check4;
	CButton m_Check5;
	CButton m_Check6;
	CButton m_Check7;
	CButton m_Check8;
	CButton m_Check9;
	CButton m_Check10;
	CButton m_Check11;
	CButton m_Check12;
	CButton m_Check13;
	CButton m_Check14;
	afx_msg void ReadCheckbox();
	afx_msg void WriteCheckbox(UINT id = 0);
	CButton m_Check15;
	CButton m_Check16;
	CButton m_Check17;
	CButton m_Check18;
};
