
// SelectDrawView.h: CSelectDrawView 클래스의 인터페이스
//

#pragma once
#include "SelectDailog.h"


enum { PT_START, PT_END, PT_MAX };
enum DRAWTYPE {DT_RECT, DT_ELLIPSE, DT_LINE, DT_MAX};



struct DrawSelect
{
	CPoint		pt[PT_MAX];
	DRAWTYPE	enDrawType;


	
};





class CSelectDrawView : public CView
{
protected: // serialization에서만 만들어집니다.
	CSelectDrawView();
	DECLARE_DYNCREATE(CSelectDrawView)

// 특성입니다.
public:
	CSelectDrawDoc* GetDocument() const;

// 작업입니다.
public:

	SelectDailog			m_SelDlg;
	CPoint					m_PtPos[PT_MAX];
	DrawSelect				*m_pDwSel; //구조체 포인터 사용 이유
	DRAWTYPE				m_enCurDwSel;
	list<DrawSelect*>		m_ListDwSel; // * 위치 주의
	CString					m_strCombo; 




// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CSelectDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SelectDrawView.cpp의 디버그 버전
inline CSelectDrawDoc* CSelectDrawView::GetDocument() const
   { return reinterpret_cast<CSelectDrawDoc*>(m_pDocument); }
#endif

