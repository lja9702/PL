
// PL2_TOY_PROJECTDlg.h: 헤더 파일
//

#pragma once
#include <stack>
#include <cstring>
#include <cstdlib>
#include <vector>

#define LEFT_PAREN 25
#define RIGHT_PAREN 26
#define CONST 28
#define OPER 29
#define VAR 30
#define UNKNOWN 99


using namespace std;
// CPL2TOYPROJECTDlg 대화 상자
class CPL2TOYPROJECTDlg : public CDialogEx
{
// 생성입니다.
public:
	CPL2TOYPROJECTDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PL2_TOY_PROJECT_DIALOG };
#endif

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
	CEdit writeBox;
	CEdit notationBox;
	CEdit printBox;
	CString prefixNotat;
	CString infixNotat;

	bool infixToPrefix = 0;
	int rightSyntax = 0;

	afx_msg void OnBnClickedButton_ScreenClear();
	afx_msg void OnBnClickedButton_ChangeNotation();
	afx_msg void OnBnClickedButton_Make();
	afx_msg void OnBnClickedButton_Save();
	afx_msg void OnBnClickedButton_Loading();
	afx_msg void OnBnClickedButton_Interpret();
	afx_msg void OnBnClickedButton_Exit();

	afx_msg void makePrefixNotation();
	afx_msg void reset();
	afx_msg int syntax_analyzer(int st, int end);
	afx_msg bool lexical_analyzer();
	
	typedef struct _match {
		CStringA lexeme;
		int token;
	}Match;
	
	int toklen = 0;
	int operres = 0;

	vector<Match> infixtok;
	vector<Match> prefixtok;
	vector<CString> midCode;
};
