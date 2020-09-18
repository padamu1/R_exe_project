
// R_projectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "R_project.h"
#include "R_projectDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRprojectDlg 대화 상자



CRprojectDlg::CRprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_R_PROJECT_DIALOG, pParent)
	, m_FILE(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILE, m_FILE);
}

BEGIN_MESSAGE_MAP(CRprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_FILEOPEN, &CRprojectDlg::OnBnClickedButtFileopen)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &CRprojectDlg::OnBnClickedButtExit)
	ON_BN_CLICKED(IDC_BUTT_ZERO, &CRprojectDlg::OnBnClickedButtZero)
	ON_BN_CLICKED(IDC_BUTT_DURUP, &CRprojectDlg::OnBnClickedButtDurup)
	ON_BN_CLICKED(IDC_BUTT_BANANA, &CRprojectDlg::OnBnClickedButtBanana)
	ON_BN_CLICKED(IDC_BUTT_TUL, &CRprojectDlg::OnBnClickedButtTul)
END_MESSAGE_MAP()


// CRprojectDlg 메시지 처리기

BOOL CRprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRprojectDlg::OnPaint()
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
HCURSOR CRprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRprojectDlg::OnBnClickedButtFileopen()
{
	// TODO: 파일 열기 컨트롤
	static TCHAR BASED_CODE szFilter[] = _T("Excel FILE(*.csv)|*.csv|모든파일(*.*)|*.*||");

	CFileDialog dlg(TRUE, _T("*.csv"), _T("exel"), OFN_HIDEREADONLY, szFilter);

	if (IDOK == dlg.DoModal())

	{

		CString pathName = dlg.GetPathName();
		std::string s = pathName;
		char from = '\\';
		char to = '/';
		std::replace(s.begin(), s.end(), from, to); // replace all 'x' to 'y'
		
		m_FILE = s.c_str();
		UpdateData(FALSE);
	}
	
}


void CRprojectDlg::OnBnClickedButtExit()
{
	// TODO:종료 프로그램
	OnOK();
	
}


void CRprojectDlg::OnBnClickedButtZero()
{
	m_FILE = "";
	UpdateData(FALSE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRprojectDlg::OnBnClickedButtDurup()
{
	UpdateData(TRUE);
	CString FILENAME = m_FILE;
	if (FILENAME == "") {
		MessageBox("csv 파일을 선택해주세요");
	}
	else {
		ofstream batch;
		batch.open("durup.bat", ios::out);
		batch << "@echo ON\n";
		batch << "for /f \"tokens=* usebackq\" %%a in (`^WHERE /R C:\\\\" << "\"Program Files\" R.exe`) do set b=%%a\n";
		batch << "\"%b%\" --slave --vanilla --file=data_durup.R --args " << FILENAME << "\n";
		batch << "pause\n";
		batch.close();
		system("durup.bat");
	}
}


void CRprojectDlg::OnBnClickedButtBanana()
{
	UpdateData(TRUE);
	CString FILENAME = m_FILE;
	if (FILENAME == "") {
		MessageBox("csv 파일을 선택해주세요");
	}
	else {
		ofstream batch;
		batch.open("banana.bat", ios::out);
		batch << "@echo ON\n";
		batch << "for /f \"tokens=* usebackq\" %%a in (`^WHERE /R C:\\\\"<<"\"Program Files\" R.exe`) do set b=%%a\n";
		batch << "\"%b%\" --slave --vanilla --file=data_banana.R --args " << FILENAME << "\n";
		batch << "pause\n";
		batch.close();
		system("banana.bat");
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CRprojectDlg::OnBnClickedButtTul()
{
	UpdateData(TRUE);
	CString FILENAME = m_FILE;
	if (FILENAME == "") {
		MessageBox("csv 파일을 선택해주세요");
	}
	else {
		ofstream batch;
		batch.open("terbuchur.bat", ios::out);
		batch << "@echo ON\n";
		batch << "for /f \"tokens=* usebackq\" %%a in (`^WHERE /R C:\\\\" << "\"Program Files\" R.exe`) do set b=%%a\n";
		batch << "\"%b%\" --slave --vanilla --file=data_terbuchur.R --args " << FILENAME << "\n";
		batch << "pause\n";
		batch.close();
		system("terbuchur.bat");
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
