
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

	reset();
}

void CPL2TOYPROJECTDlg::OnBnClickedButton_ChangeNotation()
{
	prefixtok.clear();
	infixtok.clear();

	prefixNotat = _T("");
	infixNotat = _T("");

	writeBox.GetWindowText(infixNotat);
	rightSyntax = lexical_analyzer();	//어휘를 분석하고 문제가 어휘가 있는 식인지 판단하는 함수

	if(!rightSyntax){
		MessageBox(_T("입력한 수식에 문제가 있습니다."), _T("Error"), MB_ICONERROR);
		return;
	}

	toklen = infixtok.size();
	if (toklen == 0) {
		MessageBox(_T("입력한 수식이 없습니다."), _T("Error"), MB_ICONERROR);
		return;
	}
	
	rightSyntax = syntax_analyzer(0, toklen - 1);	//구문을 분석하여 문법에 맞는 수식인지 판단

	if(rightSyntax > 1) {		//정의되어있지 않은 연산자
		MessageBox(_T("Undefined"), _T("Error"), MB_ICONERROR);
		return;
	}
	else if (!rightSyntax) {		
		MessageBox(_T("입력한 수식에 문제가 있습니다."), _T("Error"), MB_ICONERROR);
		return;
	}

	makePrefixNotation();			//전위연산으로 바꾸어주는 함수
	infixToPrefix = 1;				//전위연산으로 바꾸기 성공

	notationBox.SetWindowText(prefixNotat);

	return;
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Make()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	reset();
	writeBox.GetWindowText(infixNotat);
	rightSyntax = lexical_analyzer();	//어휘를 분석하고 문제가 어휘가 있는 식인지 판단하는 함수

	if (!rightSyntax) {
		MessageBox(_T("입력한 수식에 문제가 있습니다."), _T("Error"), MB_ICONERROR);
		return;
	}

	toklen = infixtok.size();
	if (toklen == 0) {
		MessageBox(_T("입력한 수식이 없습니다."), _T("Error"), MB_ICONERROR);
		return;
	}

	rightSyntax = syntax_analyzer(0, toklen - 1);	//구문을 분석하여 문법에 맞는 수식인지 판단

	if (rightSyntax > 1) {		//정의되어있지 않은 연산자
		MessageBox(_T("Undefined"), _T("Error"), MB_ICONERROR);
		return;
	}
	else if (!rightSyntax) {
		MessageBox(_T("입력한 수식에 문제가 있습니다."), _T("Error"), MB_ICONERROR);
		return;
	}

	toklen = infixtok.size();
	makePrefixNotation();			//전위연산으로 바꾸어주는 함수
	infixToPrefix = 1;				//전위연산으로 바꾸기 성공

	CString midCodeString;

	midCode.push_back(_T("begin"));
	if (prefixtok.size() == 1) {
		midCode.push_back(CString(prefixtok[0].lexeme));
		midCode.push_back(_T("end"));
	}
	else {
		for (int i = toklen - 1; i >= 0; i--) {
			if (prefixtok[i].token == LEFT_PAREN || prefixtok[i].token == RIGHT_PAREN)
				continue;
			else if (prefixtok[i].token == OPER)
				midCode.push_back(CString(prefixtok[i].lexeme));
			else
				midCode.push_back(_T("push " + CString(prefixtok[i].lexeme)));
		}
		midCode.push_back(_T("end"));
	}

	for (int i = 0; i < midCode.size(); i++) {
		midCodeString += CString(midCode[i] + _T("\r\n"));
	}
	notationBox.SetWindowText(midCodeString);
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Save()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString tmpinput;
	char input[10000] = { 0 };

	//edit control 변수
	CEdit *textBox;
	textBox = (CEdit*)GetDlgItem(IDC_EDIT2);

	textBox->GetWindowTextW(tmpinput);

	for (int i = 0; i < tmpinput.GetLength(); i++) {
		input[i] = tmpinput.GetAt(i);
	}

	CFileDialog dlgFile(FALSE, _T("txt"), _T("inter*.txt"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL);
	dlgFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");

	if (IDOK == dlgFile.DoModal()) {
		CString strPathName = dlgFile.GetPathName();
		CFile file;
		file.Open(strPathName, CFile::modeWrite | CFile::modeCreate);
		file.Write(input, strlen(input));

		file.Close();
	}
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Loading()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ULONGLONG length;
	char buf[10000] = { 0 };
	//파일 불러오기 대화상자
	CFileDialog dlgaFile(TRUE, _T("txt"), _T("inter*.txt"), OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, NULL);
	dlgaFile.m_ofn.lpstrFilter = _T("Text File(*.txt)");


	//파일내용 읽어오기
	if (IDOK == dlgaFile.DoModal()) {

		CString strPathName = dlgaFile.GetPathName();
		CFile file;
		file.Open(strPathName, CFile::modeRead);
		length = file.GetLength();
		file.Read(buf, length * sizeof(char));
		file.Close();

		writeBox.SetSel(0, -1, TRUE);
		writeBox.Clear();
		reset();

		//edit control 변수 
		CEdit *textBox;
		textBox = (CEdit*)GetDlgItem(IDC_EDIT2);
		//파일 내용 쓰기
		textBox->SetWindowTextW(CA2W(buf));

	}
	else return;

	midCode.clear();

	int buflen = strlen(buf), cur = 0;

	while (cur < buflen) {
		if (buf[cur] == 'b') {
			midCode.push_back(_T("begin"));
			cur += 5;
			continue;
		}
		else if (buf[cur] == 'M') {
			midCode.push_back(_T("MINUS"));
			cur += 5;
			continue;
		}
		else if(buf[cur] == 'I')
			midCode.push_back(_T("IF"));
		else if (buf[cur] == 'p') {
			CString str;
			while (cur < buflen && buf[cur] != '\r') {
				str += buf[cur];
				cur++;
			}
			midCode.push_back(str);
		}
		else if (buf[cur] == 'e')
			midCode.push_back(_T("end"));

		cur++;
	}
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Interpret()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (midCode.empty()) {
		MessageBox(_T("중간코드를 생성해주세요!!!"), _T("Error"), MB_ICONERROR);
		return;
	}
	int end = midCode.size() - 1;

	stack<CStringA> S;
	for (int i = 1; i < end; i++) {
		CStringA str = CStringA(midCode[i]);
		if (!strcmp(str, "MINUS") || !strcmp(str, "IF"))
			S.push(str);
		else {
			CStringA oper;	//숫자만 스택에 삽입
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] >= '0' && str[i] <= '9')
					oper += str[i];
			}
			CStringA top = S.top();
			if (strcmp(top, "MINUS") && strcmp(top, "IF")) {
				int oper2 = atoi(oper);
				int oper1 = atoi(top);
				S.pop();
				top = S.top();
				S.pop();
				CString cstr;
				if (!strcmp(top, "MINUS")) {
					int res = oper1 - oper2;
					cstr.Format(_T("%d"), res);
					S.push(CStringA(cstr));
				}
				else {
					if (oper1 <= 0) {
						cstr.Format(_T("0"));
						S.push(CStringA(cstr));
					}
					else {
						cstr.Format(_T("%d"), oper2);
						S.push(CStringA(cstr));
					}
				}
			}
			else S.push(oper);
		}
	}
	if (S.size() > 1 && !S.empty()) {
		int oper2 = atoi(S.top());
		S.pop();
		int oper1 = atoi(S.top());
		S.pop();
		CStringA op = S.top();
		S.pop();
		CString cstr;
		if (!strcmp(op, "MINUS")) {
			int res = oper1 - oper2;
			cstr.Format(_T("%d"), res);
			S.push(CStringA(cstr));
		}
		else {
			if (oper1 <= 0) {
				cstr.Format(_T("0"));
				S.push(CStringA(cstr));
			}
			else {
				cstr.Format(_T("%d"), oper2);
				S.push(CStringA(cstr));
			}
		}
	}

	printBox.SetWindowText(CString(S.top()) + _T("\r\n"));
}


void CPL2TOYPROJECTDlg::OnBnClickedButton_Exit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int conclusion = MessageBox(L"종료 하시겠습니까?", L"종료", MB_OKCANCEL);
	if (conclusion == IDOK)
		exit(0);
}


void CPL2TOYPROJECTDlg::reset() {	//초기화하는 함수

	notationBox.SetSel(0, -1, TRUE);
	notationBox.Clear();

	printBox.SetSel(0, -1, TRUE);
	printBox.Clear();
	midCode.clear();

	infixToPrefix = 0;	//infix를 prefix로 바꿨던 여부를 다시 0으로 초기화
	toklen = 0;
	rightSyntax = 0;
	operres = 0;
	prefixtok.clear();
	infixtok.clear();
	
	prefixNotat = _T("");
	infixNotat = _T("");
}

bool CPL2TOYPROJECTDlg::analyze() {
	if (!lexical_analyzer())
		return 0;
	if (!syntax_analyzer(0, toklen - 1))
		return 0;

	makePrefixNotation();
	return 1;
}

bool CPL2TOYPROJECTDlg::lexical_analyzer() {	//어휘분석기
	
	CStringA arr = CStringA(infixNotat);
	int cur = 0, len = strlen(arr);
	Match m;
	while (cur < len) {
		if (arr[cur] == ' ')	cur++;
		else if (arr[cur] == '(') {
			m.lexeme = "(";	m.token = LEFT_PAREN;
			infixtok.push_back(m);
			cur++;
		}
		else if (arr[cur] == ')') {
			m.lexeme = ")";	m.token = RIGHT_PAREN;
			infixtok.push_back(m);
			cur++;
		}
		else if (arr[cur] >= 'A' && arr[cur] <= 'Z') {
			CStringA st;
			while (cur < len && arr[cur] != ' ' && arr[cur] >= 'A' && arr[cur] <= 'Z') {
				st += arr[cur];
				cur++;
			}
			m.lexeme = st;
			if (!strcmp(st, "MINUS") || !strcmp(st, "IF"))
				m.token = OPER;

			else	m.token = UNKNOWN;

			infixtok.push_back(m);
		}
		else if ((arr[cur] >= '0' && arr[cur] <= '9') || arr[cur] == '-') {
			CStringA st;
			if (arr[cur] == '-' && arr[cur + 1] == '-')
				return FALSE;
			
			while (cur < len && ((arr[cur] >= '0' && arr[cur] <= '9') || arr[cur] == '-')) {
				st += arr[cur];
				cur++;
			}
			m.lexeme = st, m.token = CONST;
			infixtok.push_back(m);
		}
		else if (arr[cur] >= 'a' && arr[cur] <= 'z') {
			CStringA st;
			while (cur < len && arr[cur] != ' ') {
				st += arr[cur];
				cur++;
			}
			m.lexeme = st, m.token = VAR;
			infixtok.push_back(m);
		}
		else return FALSE;
	}
	return TRUE;
}

int CPL2TOYPROJECTDlg::syntax_analyzer(int st, int end)	//구문분석기   return 1 : 정상적 return 0: 비정상적 return 2: undefined
{
	if (st > end)	return 0;
	else if (st == end && (infixtok[st].token == CONST || infixtok[st].token == VAR)) {
			return 1;
	}
	else if (infixtok[st].token == LEFT_PAREN && infixtok[end].token == RIGHT_PAREN) {
		for (int i = st; i < end; i++) {
			if (infixtok[i].token == OPER || infixtok[i].token == UNKNOWN) {
				int left = syntax_analyzer(st + 1, i - 1);
				int right = syntax_analyzer(i + 1, end - 1);
				if (left == 1 && right == 1) {
					if (infixtok[i].token == UNKNOWN)	return 2;
					return 1;
				}
			}
		}
	}
	return 0;
}

void CPL2TOYPROJECTDlg::makePrefixNotation()	//스택을 이용해서 prefix로 바꾸는 함수
{
	CStringA res;	 //결과값
	int cur = toklen - 1;

	Match m;
	stack<Match> S;
	while (cur >= 0) {
		if (infixtok[cur].token == RIGHT_PAREN) {
			S.push(infixtok[cur]);
			prefixtok.push_back(infixtok[cur]);
		}
		else if (infixtok[cur].token == LEFT_PAREN) {
			while (!S.empty()) {
				Match top = S.top();
				S.pop();
				if (top.token == RIGHT_PAREN)
					break;
				prefixtok.push_back(top);
			}
			prefixtok.push_back(infixtok[cur]);
		}
		else if (infixtok[cur].token == OPER) 
			S.push(infixtok[cur]);

		else if (infixtok[cur].token == CONST || infixtok[cur].token == VAR)
			prefixtok.push_back(infixtok[cur]);

		cur--;
	}	

	while (!S.empty()) {
		prefixtok.push_back(S.top());
		S.pop();
	}

	for (int i = toklen - 1; i >= 0; i--) {
		prefixNotat += CString(prefixtok[i].lexeme);
		prefixNotat += " ";
	}
}
