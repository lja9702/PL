﻿
// PL2_TOY_PROJECTDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "PL2_TOY_PROJECT.h"
#include "PL2_TOY_PROJECTDlg.h"
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


// CPL2TOYPROJECTDlg 대화 상자



CPL2TOYPROJECTDlg::CPL2TOYPROJECTDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PL2_TOY_PROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPL2TOYPROJECTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, writeBox);
	DDX_Control(pDX, IDC_EDIT2, notationBox);
}

BEGIN_MESSAGE_MAP(CPL2TOYPROJECTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPL2TOYPROJECTDlg::OnBnClickedButton_ScreenClear)
	ON_EN_CHANGE(IDC_EDIT1, &CPL2TOYPROJECTDlg::OnEnChangeEdit)
	ON_EN_CHANGE(IDC_EDIT2, &CPL2TOYPROJECTDlg::OnEnChangeEdit_IntermediateCode)
	ON_EN_CHANGE(IDC_EDIT3, &CPL2TOYPROJECTDlg::OnEnChangeEdit_result)
	ON_BN_CLICKED(IDC_BUTTON2, &CPL2TOYPROJECTDlg::OnBnClickedButton_ChangeNotation)
	ON_BN_CLICKED(IDC_BUTTON3, &CPL2TOYPROJECTDlg::OnBnClickedButton_Make)
	ON_BN_CLICKED(IDC_BUTTON4, &CPL2TOYPROJECTDlg::OnBnClickedButton_Save)
	ON_BN_CLICKED(IDC_BUTTON5, &CPL2TOYPROJECTDlg::OnBnClickedButton_Loading)
	ON_BN_CLICKED(IDC_BUTTON6, &CPL2TOYPROJECTDlg::OnBnClickedButton_Interpret)
	ON_BN_CLICKED(IDC_BUTTON7, &CPL2TOYPROJECTDlg::OnBnClickedButton_Exit)
END_MESSAGE_MAP()


// CPL2TOYPROJECTDlg 메시지 처리기

BOOL CPL2TOYPROJECTDlg::OnInitDialog()
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

void CPL2TOYPROJECTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPL2TOYPROJECTDlg::OnPaint()
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
HCURSOR CPL2TOYPROJECTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*OnBnClickedButton_ScreenClear: EditBox를 전부 초기화하는 Dlg*/
void CPL2TOYPROJECTDlg::OnBnClickedButton_ScreenClear()
{
	CEdit *pEdit;
	for (int i = 0; i < 3; i++) {	//EditBox를 초기화 하는 코드
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT1 + i);
		pEdit->SetSel(0, -1, TRUE);
		pEdit->Clear();
	}
}

void CPL2TOYPROJECTDlg::OnBnClickedButton_ChangeNotation()
{
	CString str;
	writeBox.GetWindowText(str);
	//notationBox.SetWindowText(str);
	str = makePostfix(str);

}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Make()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Save()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Loading()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Interpret()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Exit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CPL2TOYPROJECTDlg::OnEnChangeEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPL2TOYPROJECTDlg::OnEnChangeEdit_IntermediateCode()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPL2TOYPROJECTDlg::OnEnChangeEdit_result()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

CString makePostfix(CString str)
{
	stack<CString> S;
	CString token, res;
	int pos = 0;
	
	while ((token = str.Tokenize(_T(" "), pos)) != _T("")){
		if (!token.Compare((LPCWSTR)"(")) {
			S.push(token);
			res += token;
		}
		else if (!token.Compare((LPCWSTR)")")) {
			while (!S.empty()) {
				CString top = S.top();
				S.pop();
				
				if (top.Compare((LPCWSTR)"(")) {
					break;
				}
				res += token;
			}
			res += token;
		}
		else if (!token.Compare((LPCWSTR)"MINUS"))	S.push(token);
		else if (!token.Compare((LPCWSTR)"IF"))	S.push(token);
		else res += token;
	}
	return res;
}