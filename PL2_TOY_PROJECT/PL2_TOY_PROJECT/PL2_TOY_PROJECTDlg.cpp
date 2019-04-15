
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
	DDX_Text(pDX, IDC_EDIT1, infixNotat);
	DDX_Control(pDX, IDC_EDIT2, notationBox);
	DDX_Text(pDX, IDC_EDIT2, prefixNotat);
	DDX_Control(pDX, IDC_EDIT3, printBox);
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
	writeBox.SetSel(0, -1, TRUE);
	writeBox.Clear();

	notationBox.SetSel(0, -1, TRUE);
	notationBox.Clear();

	printBox.SetSel(0, -1, TRUE);
	printBox.Clear();

	infixToPrefix = 0;	//infix를 prefix로 바꿨던 여부를 다시 0으로 초기화
}

void CPL2TOYPROJECTDlg::OnBnClickedButton_ChangeNotation()
{
	notationBox.SetSel(0, -1, TRUE);
	notationBox.Clear();

	writeBox.GetWindowText(infixNotat);
	CStringA inf = CStringA(infixNotat);

	int st = 0, end = inf.GetLength() - 1;
	while (st < end) {
		if (inf[st] != ' ' && inf[end] != ' ') break;
		if (inf[st] == ' ') st++;
		if (inf[end] == ' ')	end--;
	}
	if (st >= end) {
		MessageBox(_T("입력한 수식이 없습니다."), _T("Error"), MB_ICONERROR);
		return;
	}
	rightSyntax = checkSyntax(st, end, inf);
	if(rightSyntax < 0) {
		MessageBox(_T("Undefined"), _T("Error"), MB_ICONERROR);
		return;
	}
	else if (rightSyntax > 0) {
		MessageBox(_T("입력한 수식에 문제가 있습니다."), _T("Error"), MB_ICONERROR);
		return;
	}

	if (!infixReverse()) {
		MessageBox(_T("입력한 수식에 문제가 있습니다."), _T("Error"), MB_ICONERROR);
		return;
	}
	prefixNotat = makePrefixNotation();
	infixToPrefix = 1;
	notationBox.SetWindowText(prefixNotat);
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Make()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (infixNotat.GetLength() == 0 || !infixToPrefix) {
		MessageBox(_T("입력한 수식이 없습니다."), _T("Error"), MB_ICONERROR);
		return;
	}
	if (!infixReverse()) {
		MessageBox(_T("입력한 수식에 문제가 있습니다."), _T("Error"), MB_ICONERROR);
		return;
	}
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

bool CPL2TOYPROJECTDlg::infixReverse()	//infix를 뒤집어서 String에 저장하는 함수
{
	CStringA temp = CStringA(infixNotat);
	char infixArr[10000] = { 0 };
	memcpy(infixArr, temp.GetBuffer(), temp.GetLength());
	char reverse[10000] = { 0 };
	int icur = strlen(infixArr) - 1, cur = -1;
	bool flag = 0;
	while (icur >= 0) {
		if (infixArr[icur] == '(') {
			reverse[++cur] = ')';
			icur--;
			continue;
		}
		else if (infixArr[icur] == ')') {
			reverse[++cur] = '(';
			icur--;
			continue;
		}
		else if (reverse[cur] != ' ' && infixArr[icur] == ' ') {
			reverse[++cur] = ' ';
			icur--;
			continue;
		}
		else if (infixArr[icur] >= '0' && infixArr[icur] <= '9') {
			char digit[100] = { 0 };
			//digit 넣는 코드
			while (icur >= 0 && ((infixArr[icur] >= '0' && infixArr[icur] <= '9') || infixArr[icur] == '-')) {
				if (infixArr[icur] == '-' && infixArr[icur - 1] == '-') {
					return FALSE;
				}
				reverse[++cur] = infixArr[icur];
				icur--;
			}
		}
		else if ((infixArr[icur] >= 'A' && infixArr[icur] <= 'Z') || (infixArr[icur] >= 'a' && infixArr[icur] <= 'z')){
			//alpha 넣는 코드
			CStringA alpha;
			while (icur >= 0 && (infixArr[icur] >= 'A' && infixArr[icur] <= 'Z') || (infixArr[icur] >= 'a' && infixArr[icur] <= 'z')) {
				reverse[++cur] = infixArr[icur];
				alpha += infixArr[icur];
				icur--;
			}
		}
		else
			return FALSE;
	}
	prefixNotat = CString(reverse);
	return TRUE;
}

CString CPL2TOYPROJECTDlg::makePrefixNotation()	//스택을 이용해서 prefix로 바꾸는 함수
{
	CStringA temp = CStringA(prefixNotat);	
	
	char reverse[10000] = { 0 };
	memcpy(reverse, temp.GetBuffer(), temp.GetLength());
	CStringA res;	 //결과값
	int len = strlen(reverse), cur = 0;

	stack<CStringA> S;
	while (cur < len) {
		if (reverse[cur] == '(') {
			S.push("(");
			res += " ) ", cur++;
			continue;
		}
		else if (reverse[cur] == ')') {
			while (!S.empty()) {
				CStringA top = S.top();
				S.pop();
				if (!strcmp(top, "("))
					break;
				res += " ";
				res += top;
			}
			res += " ( ", cur++;
			continue;
		}
		else if (reverse[cur] == ' ') {
			res += " ";
			cur++;
			continue;
		}
		char digit[100] = { 0 }, dcur = -1;
		while (cur < len && ((reverse[cur] >= '0' && reverse[cur] <= '9') || (reverse[cur] == '-'))) {
			digit[++dcur] = reverse[cur];
			cur++;
		}
		if (strlen(digit) > 0)	res += digit;
		//alpha 넣는 코드
		char alpha[100] = { 0 };
		int acur = -1;
		while (cur < len && ((reverse[cur] >= 'A' && reverse[cur] <= 'Z') || reverse[cur] >= 'a' && reverse[cur] <= 'z')) {
			alpha[++acur] = reverse[cur];
			cur++;
		}
		if (strlen(alpha) > 0) {
			S.push(alpha);
		}
	}	

	while (!S.empty()) {
		res += S.top();
		res += " ";
		S.pop();
	}
	return CString(res.MakeReverse());
}

int CPL2TOYPROJECTDlg::checkSyntax(int st, int end, CStringA str)
{
	if (str[st] == '(' && str[end] == ')') {	//( <term> MINUS <term> )이거나 ( <term> IF <term> ) 찾기
		int cur = st + 1;
		while (cur < end) {
			if (str[cur] >= 'A' && str[cur] <= 'Z') {
				CStringA oper;
				int operst = cur;
				while (cur < end && str[cur] >= 'A' && str[cur] <= 'Z') {
					oper += str[cur];
					cur++;
				}
				int operfin = cur - 1;

				if (!strcmp(oper, "MINUS") || !strcmp(oper, "IF")) {
					int x1 = st + 1, x2 = operst - 1, y1 = operfin + 1, y2 = end - 1;
					while (x1 < x2) {
						if (str[x1] != ' ' && str[x2] != ' ')	break;
						if (str[x1] == ' ')	x1++;
						if (str[x2] == ' ') x2--;
					}
					if (x1 > x2)	return SYNERROR;
					while (y1 < y2) {
						if (str[y1] != ' ' && str[y2] != ' ')	break;
						if (str[y1] == ' ')	y1++;
						if (str[y2] == ' ') y2--;
					}
					if (y1 > y2)	return SYNERROR;
					return checkSyntax(x1, x2, str) + checkSyntax(y1, y2, str);
				}
				else 
					return UNDIF;
			}
			cur++;
		}
		return SYNERROR;
	}
	else if ((str[st] >= '0' && str[st] <= '9') || str[st] == '-') {
		if (str[st] == '-' && str[st + 1] == '-')	return SYNERROR;
		int cur = st;
		while (cur <= end && ((str[cur] >= '0' && str[cur] <= '9') || str[cur] == '-'))
			cur++;

		while (cur <= end && str[cur] == ' ')	cur++;
		if (cur <= end)	return SYNERROR;
		
		return 0;
	}
	else if (str[st] >= 'a' && str[st] <= 'z') {
		int cur = st;
		while (cur <= end && str[cur] >= 'a' && str[cur] <= 'z')
			cur++;

		while (cur <= end && str[cur] == ' ')	cur++;
		if (cur < end)	return SYNERROR;
		
		return 0;
	}
	return SYNERROR;
}