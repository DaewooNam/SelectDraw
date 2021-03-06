// SelectDailog.cpp: 구현 파일
//

#include "stdafx.h"
#include "SelectDraw.h"
#include "SelectDailog.h"
#include "afxdialogex.h"


// SelectDailog 대화 상자

IMPLEMENT_DYNAMIC(SelectDailog, CDialogEx)

SelectDailog::SelectDailog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDNO, pParent)
{

}

SelectDailog::~SelectDailog()
{
}

void SelectDailog::DoDataExchange(CDataExchange* pDX)
{
	
	DDX_Control(pDX, IDC_COMBO_DRAW, g_CtrlCombo);
	
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectDailog, CDialogEx)
	
	ON_CBN_SELCHANGE(IDC_COMBO_DRAW, &SelectDailog::OnCbnSelchangeComboDraw)
END_MESSAGE_MAP()


// SelectDailog 메시지 처리기


BOOL SelectDailog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CComboBox* m_Combo = (CComboBox*)GetDlgItem(IDC_COMBO_DRAW);
	
	
	m_Combo->AddString("Line");
	m_Combo->AddString("Ellipse");
	m_Combo->AddString("Rectangle");

	m_Combo->SetCurSel(2);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}




