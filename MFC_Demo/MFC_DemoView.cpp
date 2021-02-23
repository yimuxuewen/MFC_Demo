
// MFC_DemoView.cpp: CMFCDemoView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_Demo.h"
#endif

#include "MFC_DemoDoc.h"
#include "MFC_DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDemoView

IMPLEMENT_DYNCREATE(CMFCDemoView, CView)

BEGIN_MESSAGE_MAP(CMFCDemoView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCDemoView 构造/析构

CMFCDemoView::CMFCDemoView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCDemoView::~CMFCDemoView()
{
}

BOOL CMFCDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDemoView 绘图

void CMFCDemoView::OnDraw(CDC* /*pDC*/)
{
	CMFCDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCDemoView 打印

BOOL CMFCDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCDemoView 诊断

#ifdef _DEBUG
void CMFCDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDemoDoc* CMFCDemoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDemoDoc)));
	return (CMFCDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDemoView 消息处理程序
