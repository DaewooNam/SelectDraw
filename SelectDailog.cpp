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
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectDailog, CDialogEx)
END_MESSAGE_MAP()


// SelectDailog 메시지 처리기
