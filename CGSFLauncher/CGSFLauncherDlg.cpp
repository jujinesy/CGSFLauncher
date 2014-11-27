
// CGSFLauncherDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CGSFLauncher.h"
#include "CGSFLauncherDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CCGSFLauncherDlg ��ȭ ����



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


// CCGSFLauncherDlg �޽��� ó����

BOOL CCGSFLauncherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CCGSFLauncherDlg::ReadCheckbox();
	TrayIconMgr::Instance()->AddTrayIcon(GetSafeHwnd());	

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CCGSFLauncherDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CCGSFLauncherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCGSFLauncherDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//CDialogEx::OnOK();
	CCGSFLauncherDlg::WriteCheckbox();
	ShellExecute(NULL, _T("open"), _T("FPSClient.exe"), NULL, NULL, 0);
}


void CCGSFLauncherDlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnCancel();
}


void CCGSFLauncherDlg::ReadCheckbox()
{
	CStdioFile file;
	CString data_str;
	CString temp;
	CString result;
	int LinePos = 0, WordPos = 0;

	if (file.Open(_T("security_level.ini"), CFile::modeRead | CFile::typeText)) // ���� ������ test.txt ������ ������ �����´�.
	{
		while (file.ReadString(data_str)) // ������ ������ �� �پ� �о data_str �� �����Ѵ�.
		{
			LinePos = 0;
			while ((temp = data_str.Tokenize(_T("\n"), LinePos)) != "") // �� �����ڷ� �����Ͽ� ������ ������ ������ temp�� ����. 
			{
				WordPos = 0;
				while ((temp = data_str.Tokenize(_T("="), WordPos)) != "") // �� �����ڷ� �����Ͽ� ������ ������ ������ temp�� ����. 
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
				if (LinePos == 0x1F) // ���ϴ� �������� ��ġ�� 0x1F �̹Ƿ� �ش� ��ġ�� �����͸� �����ͼ� ����Ѵ�.
				{
					//result.Format("%s", temp);
					//m_List_Result_Data.InsertItem(0, result);
					//CAN_ID_AnalyzerDlg::File_Data_Process(result, "");
				}
			}
		}
		file.Close(); // ��� ������ ������ ���������� ������ �ݴ´�.
	}
	else
	{
		CCGSFLauncherDlg::WriteCheckbox();
		MessageBoxW(_T("security_level.ini ������ �����ϴ�.\n�⺻���� ������ �����Ǿ����ϴ�."));
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
	return 0; //���ϰ��� ������ ����
}

// Ʈ���� ����
void CCGSFLauncherDlg::OnAppExit()
{
	OnDestroy();
}

//���̾�α� ���߱�, ���̱�
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

//��������
void CCGSFLauncherDlg::OnCreatorNotice(void)
{
}

void CCGSFLauncherDlg::OnNONE(void)
{
}

// ���̾�α� ����� ����ȣ�� �Լ�
void CCGSFLauncherDlg::OnDestroy(void)
{
	TrayIconMgr::Instance()->DelTrayIcon(GetSafeHwnd());
	exit(1);
}