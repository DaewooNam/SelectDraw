#pragma once


// SelectDailog 대화 상자

class SelectDailog : public CDialogEx
{
	DECLARE_DYNAMIC(SelectDailog)

public:
	SelectDailog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SelectDailog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDNO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	
	afx_msg void OnCbnSelchangeComboDraw();
};
