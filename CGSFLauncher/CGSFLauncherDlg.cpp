
// CGSFLauncherDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CGSFLauncher.h"
#include "CGSFLauncherDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCGSFLauncherDlg 대화 상자



CCGSFLauncherDlg::CCGSFLauncherDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCGSFLauncherDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCGSFLauncherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_CHECK2, m_Check2);
	DDX_Control(pDX, IDC_CHECK3, m_Check3);
	DDX_Control(pDX, IDC_CHECK4, m_Check4);
	DDX_Control(pDX, IDC_CHECK5, m_Check5);
	DDX_Control(pDX, IDC_CHECK6, m_Check6);
	DDX_Control(pDX, IDC_CHECK7, m_Check7);
	DDX_Control(pDX, IDC_CHECK8, m_Check8);
	DDX_Control(pDX, IDC_CHECK9, m_Check9);
	DDX_Control(pDX, IDC_CHECK10, m_Check10);
	DDX_Control(pDX, IDC_CHECK11, m_Check11);
	DDX_Control(pDX, IDC_CHECK12, m_Check12);
	DDX_Control(pDX, IDC_CHECK13, m_Check13);
	DDX_Control(pDX, IDC_CHECK14, m_Check14);
	DDX_Control(pDX, IDC_CHECK15, m_Check15);
	DDX_Control(pDX, IDC_CHECK16, m_Check16);
	DDX_Control(pDX, IDC_CHECK17, m_Check17);
	DDX_Control(pDX, IDC_CHECK18, m_Check18);
}

BEGIN_MESSAGE_MAP(CCGSFLauncherDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCGSFLauncherDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCGSFLauncherDlg::OnBnClickedCancel)
	ON_COMMAND_RANGE(IDC_CHECK1, IDC_CHECK18, &CCGSFLauncherDlg::WriteCheckbox)

	ON_MESSAGE(WM_TRAYICON, &CCGSFLauncherDlg::OnTrayIcon)
	ON_COMMAND(WM_DIALOG_SHOW, &CCGSFLauncherDlg::OnDialogShow)
	ON_COMMAND(WM_ABOUTBOX, &CCGSFLauncherDlg::OnCreatorInfo)
	ON_COMMAND(WM_NOTICE, &CCGSFLauncherDlg::OnCreatorNotice)
	ON_COMMAND(WM_NONE, OnNONE)
	ON_COMMAND(WM_APP_EXIT, OnAppExit)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CCGSFLauncherDlg 메시지 처리기

BOOL CCGSFLauncherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CCGSFLauncherDlg::ReadCheckbox();
	TrayIconMgr::Instance()->AddTrayIcon(GetSafeHwnd());	

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCGSFLauncherDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCGSFLauncherDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCGSFLauncherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCGSFLauncherDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
	CCGSFLauncherDlg::WriteCheckbox();
	ShellExecute(NULL, _T("open"), _T("FPSClient.exe"), NULL, NULL, 0);
}


void CCGSFLauncherDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CCGSFLauncherDlg::ReadCheckbox()
{
	CStdioFile file;
	CString data_str;
	CString temp;
	CString result;
	int LinePos = 0, WordPos = 0;

	if (file.Open(_T("security_level.ini"), CFile::modeRead | CFile::typeText)) // 현재 폴더의 test.txt 파일의 내용을 가져온다.
	{
		while (file.ReadString(data_str)) // 파일의 내용을 한 줄씩 읽어서 data_str 에 저장한다.
		{
			LinePos = 0;
			while ((temp = data_str.Tokenize(_T("\n"), LinePos)) != "") // 각 구분자로 구분하여 데이터 내용을 가져와 temp에 저장. 
			{
				WordPos = 0;
				while ((temp = data_str.Tokenize(_T("="), WordPos)) != "") // 각 구분자로 구분하여 데이터 내용을 가져와 temp에 저장. 
				{
					if (temp == GLOBAL_HOOK)
					{
						m_Check1.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == HOOK_RECOVERY)
					{
						m_Check2.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == KERNSEC)
					{
						m_Check3.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == LDRDLLNOTI)
					{
						m_Check4.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == CREATEREMOTE_HOOK)
					{
						m_Check5.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == SETWINDOWSHOOKEX)
					{
						m_Check6.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == D3D9_ANTI_HOOK)
					{
						m_Check7.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == D3D9_VTABLE_HASH)
					{
						m_Check8.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == THREAD_PROTECT)
					{
						m_Check9.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == SPEED_HACK)
					{
						m_Check10.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == MEMORY_CRC)
					{
						m_Check11.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == FILE_HASH)
					{
						m_Check12.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == SENDINPUT)
					{
						m_Check13.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == SENDMESSAGE)
					{
						m_Check14.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == WINDOWED)
					{
						m_Check15.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == CODE_VM)
					{
						m_Check16.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == DEBUG_MODE)
					{
						m_Check17.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}
					else if (temp == DRBP)
					{
						m_Check18.SetCheck(_ttoi(data_str.Tokenize(_T("="), WordPos)));
					}

				}
				if (LinePos == 0x1F) // 원하는 데이터의 위치가 0x1F 이므로 해당 위치의 데이터만 가져와서 출력한다.
				{
					//result.Format("%s", temp);
					//m_List_Result_Data.InsertItem(0, result);
					//CAN_ID_AnalyzerDlg::File_Data_Process(result, "");
				}
			}
		}
		file.Close(); // 모든 파일의 내용을 가져왔으면 파일을 닫는다.
	}
	else
	{
		CCGSFLauncherDlg::WriteCheckbox();
		MessageBoxW(_T("security_level.ini 파일이 없습니다.\n기본설정 파일이 생성되었습니다."));
	}
}


void CCGSFLauncherDlg::WriteCheckbox(UINT id)
{
	CStdioFile file;
	file.Open(_T("security_level.ini"), CFile::modeCreate | CFile::modeWrite);

	CString save, temp;
	save.Format(_T("[OpenProcess]\n"));
	temp.Format(_T("%s=%d\n"), GLOBAL_HOOK, m_Check1.GetCheck()); save = save + temp;
	temp.Format(_T("%s=%d\n"), HOOK_RECOVERY, m_Check2.GetCheck()); save = save + temp;
	temp.Format(_T("%s=%d\n\n"), KERNSEC, m_Check3.GetCheck()); save = save + temp;

	temp.Format(_T("[DLL_Injection]\n")); save = save + temp;
	temp.Format(_T("%s=%d\n"), LDRDLLNOTI, m_Check4.GetCheck()); save = save + temp;
	temp.Format(_T("%s=%d\n"), CREATEREMOTE_HOOK, m_Check5.GetCheck()); save = save + temp;
	temp.Format(_T("%s=%d\n\n"), SETWINDOWSHOOKEX, m_Check6.GetCheck()); save = save + temp;

	temp.Format(_T("[DirectX]\n")); save = save + temp;
	temp.Format(_T("%s=%d\n"), D3D9_ANTI_HOOK, m_Check7.GetCheck()); save = save + temp;
	temp.Format(_T("%s=%d\n\n"), D3D9_VTABLE_HASH, m_Check8.GetCheck()); save = save + temp;

	temp.Format(_T("[Thread]\n")); save = save + temp;
	temp.Format(_T("%s=%d\n\n"), THREAD_PROTECT, m_Check9.GetCheck()); save = save + temp;

	temp.Format(_T("[Speed_Hack]\n")); save = save + temp;
	temp.Format(_T("%s=%d\n\n"), SPEED_HACK, m_Check10.GetCheck()); save = save + temp;

	temp.Format(_T("[CRC]\n")); save = save + temp;
	temp.Format(_T("%s=%d\n"), MEMORY_CRC, m_Check11.GetCheck()); save = save + temp;
	temp.Format(_T("%s=%d\n\n"), FILE_HASH, m_Check12.GetCheck()); save = save + temp;

	temp.Format(_T("[Key_Macro]\n")); save = save + temp;
	temp.Format(_T("%s=%d\n"), SENDINPUT, m_Check13.GetCheck()); save = save + temp;
	temp.Format(_T("%s=%d\n\n"), SENDMESSAGE, m_Check14.GetCheck()); save = save + temp;

	temp.Format(_T("[Windowed]\n")); save = save + temp;
	temp.Format(_T("%s=%d\n\n"), WINDOWED, m_Check15.GetCheck()); save = save + temp;

	temp.Format(_T("[Anti_Debugging]\n")); save = save + temp;
	temp.Format(_T("%s=%d\n"), CODE_VM, m_Check16.GetCheck()); save = save + temp;
	temp.Format(_T("%s=%d\n\n"), DEBUG_MODE, m_Check17.GetCheck()); save = save + temp;

	temp.Format(_T("[Debug_Register]\n")); save = save + temp;
	temp.Format(_T("%s=%d"), DRBP, m_Check18.GetCheck()); save = save + temp;
	file.WriteString(save);
	file.Close();
}

LRESULT CCGSFLauncherDlg::OnTrayIcon(WPARAM wParam, LPARAM lParam)
{
	TrayIconMgr::Instance()->ProcTrayMsg(GetSafeHwnd(), wParam, lParam);
	return 0; //리턴값이 없으면 에러
}

// 트레이 종료
void CCGSFLauncherDlg::OnAppExit()
{
	OnDestroy();
}

//다이얼로그 감추기, 보이기
void CCGSFLauncherDlg::OnDialogShow()
{
	if (TrayIconMgr::Instance()->m_bHide)
	{
		ShowWindow(false);
		TrayIconMgr::Instance()->m_bHide = false;
	}
	else
	{
		ShowWindow(true);
		TrayIconMgr::Instance()->m_bHide = true;
	}
}

void CCGSFLauncherDlg::OnCreatorInfo(void)
{
	OnSysCommand(IDM_ABOUTBOX, NULL);
}

//공지사항
void CCGSFLauncherDlg::OnCreatorNotice(void)
{
}

void CCGSFLauncherDlg::OnNONE(void)
{
}

// 다이얼로그 종료시 최종호출 함수
void CCGSFLauncherDlg::OnDestroy(void)
{
	TrayIconMgr::Instance()->DelTrayIcon(GetSafeHwnd());
	exit(1);
}