
// MFC-12-2View.cpp : CMFC122View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-12-2.h"
#endif
#include"ElargeDlg.h"
#include "MFC-12-2Set.h"
#include "MFC-12-2Doc.h"
#include "MFC-12-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC122View

IMPLEMENT_DYNCREATE(CMFC122View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC122View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC122View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC122View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC122View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC122View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC122View::OnBnClickedButtonEnlarge)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC122View 构造/析构

CMFC122View::CMFC122View()
	: CRecordView(IDD_MFC122_FORM)
	, show(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\vc实验题\\图片\\");

}

CMFC122View::~CMFC122View()
{
}

void CMFC122View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC122View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC122View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC122Set;
	CRecordView::OnInitialUpdate();

}


// CMFC122View 诊断

#ifdef _DEBUG
void CMFC122View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC122View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC122Doc* CMFC122View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC122Doc)));
	return (CMFC122Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC122View 数据库支持
CRecordset* CMFC122View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC122View 消息处理程序


void CMFC122View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC122View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC122View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFC122View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}

void CMFC122View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;//图片左上角点的位置和宽高
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);

	float cr_ratio = 1.0 * cr.Width() / cr.Height();
	float img_ratio = 1.0 * img.GetWidth() / img.GetHeight();

	if (cr_ratio > img_ratio)
	{//客户区宽高比大于图像
		h = cr.Height();//图片高度
		w = img_ratio * h;//图片宽度
		sx = (cr.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = cr.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (cr.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}


void CMFC122View::OnBnClickedButtonEnlarge()
{
	// TODO: 在此添加控件通知处理程序代码
	ElargeDlg  dlg;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;

	UpdateData(true);
	dlg.File=filename;
	UpdateData(false);
	int r = dlg.DoModal();
	if (r == IDOK) {

		
	}

}


void CMFC122View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}
