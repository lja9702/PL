#pragma once


class CTOYFunction : public CDialogEx
{
	// ...
public:

	CEdit   m_edStr;  // 변환해야할 스트링

	CString m_cString;



	// ...



};


CString makePostfix(CString str);