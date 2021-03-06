
// SelectDrawView.cpp: CSelectDrawView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SelectDraw.h"
#endif

#include "SelectDrawDoc.h"
#include "SelectDrawView.h"
#include "SelectDailog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSelectDrawView

IMPLEMENT_DYNCREATE(CSelectDrawView, CView)

BEGIN_MESSAGE_MAP(CSelectDrawView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSelectDrawView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_CBN_SELCHANGE(IDC_COMBO_DRAW, &SelectDailog::OnCbnSelchangeComboDraw)
END_MESSAGE_MAP()

// CSelectDrawView 생성/소멸

CSelectDrawView::CSelectDrawView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_enCurDwSel = DT_RECT;
	//m_pDwSel = new DrawSelect; //여기서 초기화 시 중복 되는 값이 안되는 이유..?
	m_PtPos[PT_START].x = m_PtPos[PT_START].y = m_PtPos[PT_END].x = m_PtPos[PT_END].y = 0;


}

CSelectDrawView::~CSelectDrawView()
{
}

BOOL CSelectDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSelectDrawView 그리기

void CSelectDrawView::OnDraw(CDC* pDC)
{
	CSelectDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	



	if (g_strCombo == "Line")
		m_enCurDwSel = DT_LINE;
	else if(g_strCombo == "Ellipse")
		m_enCurDwSel = DT_ELLIPSE;
	else if(g_strCombo == "Rectangle")
		m_enCurDwSel = DT_RECT;





	//m_list
	/*
	for each(auto dwSel in m_ListDwSel)
	//for(list<DrawSelect*>::iterator itor = m_ListDwSel.begin();itor != m_ListDwSel.end();itor)

	{
		switch (dwSel->enDrawType)
		{
		case DT_RECT:
		{

			pDC->Rectangle(dwSel->pt[PT_START].x, dwSel->pt[PT_START].y, dwSel->pt[PT_END].x, dwSel->pt[PT_END].y);

			break;
		}
		case DT_ELLIPSE:
		{
			pDC->Ellipse(dwSel->pt[PT_START].x, dwSel->pt[PT_START].y, dwSel->pt[PT_END].x, dwSel->pt[PT_END].y);

			break;
		}
		case DT_LINE:
		{
			pDC->MoveTo(dwSel->pt[PT_START]);
			pDC->LineTo(dwSel->pt[PT_END]);

			break;
		}

		}

		
	}
	*/

	int size;
	size = (int)m_ListDwSel.size();

	TRACE("size = %d", size);




	//m_draw
	switch (m_enCurDwSel)
	{
	case DT_RECT:
	{


		pDC->Rectangle(m_PtPos[PT_START].x, m_PtPos[PT_START].y, m_PtPos[PT_END].x, m_PtPos[PT_END].y);

		break;
	}
	case DT_ELLIPSE:
	{
		pDC->Ellipse(m_PtPos[PT_START].x, m_PtPos[PT_START].y, m_PtPos[PT_END].x, m_PtPos[PT_END].y);

		break;
	}
	case DT_LINE:
	{
		pDC->MoveTo(m_PtPos[PT_START]);
		pDC->LineTo(m_PtPos[PT_END]);

		break;
	}

	}




}


// CSelectDrawView 인쇄


void CSelectDrawView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSelectDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSelectDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSelectDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CSelectDrawView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSelectDrawView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSelectDrawView 진단

#ifdef _DEBUG
void CSelectDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CSelectDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSelectDrawDoc* CSelectDrawView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSelectDrawDoc)));
	return (CSelectDrawDoc*)m_pDocument;
}
#endif //_DEBUG



void CSelectDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_PtPos[PT_START] = point;
	




	CView::OnLButtonDown(nFlags, point);
}


void CSelectDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_PtPos[PT_END] = point;
	m_pDwSel = new DrawSelect;

	m_pDwSel->enDrawType = m_enCurDwSel;
	m_pDwSel->pt[PT_END] = point;
	m_pDwSel->pt[PT_START] = m_PtPos[PT_START];


	
	m_ListDwSel.push_back(m_pDwSel);

	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}


void CSelectDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnMouseMove(nFlags, point);
}




// CSelectDrawView 메시지 처리기


void CSelectDrawView::OnInitialUpdate()
{


	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CView::OnInitialUpdate();

	CRect rc;

	GetClientRect(&rc);

	m_SelDlg.Create(IDNO, this);
	m_SelDlg.SetWindowPos(NULL, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);


	

}

void SelectDailog::OnCbnSelchangeComboDraw()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int idx;
	idx = g_CtrlCombo.GetCurSel();
	g_CtrlCombo.GetLBText(idx, g_strCombo);
}
