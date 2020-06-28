
// MFC-LMLView.cpp : CMFCLMLView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-LML.h"
#endif

#include "MFC-LMLSet.h"
#include "MFC-LMLDoc.h"
#include "MFC-LMLView.h"
#include"AddDlg.h"
#include"EditDlg.h"
#include"PictrueDlg.h"
#include"QueryDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCLMLView

IMPLEMENT_DYNCREATE(CMFCLMLView, CRecordView)

BEGIN_MESSAGE_MAP(CMFCLMLView, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &CMFCLMLView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCLMLView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCLMLView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCLMLView::OnRecordLast)
	ON_COMMAND(Add, &CMFCLMLView::OnAdd)
	ON_COMMAND(ID_Edit, &CMFCLMLView::OnEdit)
	ON_COMMAND(ID_Delete, &CMFCLMLView::OnDelete)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCLMLView::OnBnClickedButtonEnlargePicture)
	ON_COMMAND(ID_Query, &CMFCLMLView::OnQuery)
END_MESSAGE_MAP()

// CMFCLMLView 构造/析构

CMFCLMLView::CMFCLMLView()
	: CRecordView(IDD_MFCLML_FORM)
	, photo(_T(""))
	, number(0)
	, name(_T(""))
	, sex(_T(""))
	, major(_T(""))
	, birthdate(0)
	, phone(0)
	, address(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	

}

CMFCLMLView::~CMFCLMLView()
{
}

void CMFCLMLView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	//DDX_Text(pDX, IDC_EDIT1, m_pSet->column8);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column7);
}

BOOL CMFCLMLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCLMLView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCLMLSet;
	CRecordView::OnInitialUpdate();

}


// CMFCLMLView 诊断

#ifdef _DEBUG
void CMFCLMLView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCLMLView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCLMLDoc* CMFCLMLView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCLMLDoc)));
	return (CMFCLMLDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCLMLView 数据库支持
CRecordset* CMFCLMLView::OnGetRecordset()
{
	return m_pSet;
}



// CMFCLMLView 消息处理程序


void CMFCLMLView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	m_pSet->GetFieldValue(short(8), s);
	draw_pic(s);
}

void CMFCLMLView::draw_pic(CString file)
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

void CMFCLMLView::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFCLMLView::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFCLMLView::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFCLMLView::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFCLMLView::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
	AddDlg adlg;
	int a = adlg.DoModal();
	if (a == IDOK) {
		m_pSet->AddNew();
		m_pSet->column1 = adlg.m_number;
		m_pSet->column2 = adlg.m_name;
		m_pSet->column3 = adlg.m_sex;
		m_pSet->column4 = adlg.m_major; 
		m_pSet->column5 = adlg.m_birthdate; 
		m_pSet->column6 = adlg.m_phone; 
		m_pSet->column7 = adlg.m_address;
		m_pSet->column8 = adlg.m_photo;
		m_pSet->Update();
		m_pSet->Requery();

	}
	
}


void CMFCLMLView::OnEdit()
{
	// TODO: 在此添加命令处理程序代码
	EditDlg edlg;
	UpdateData(true);
	edlg.m_number    = m_pSet->column1;
	edlg.m_name      = m_pSet->column2;
	edlg.m_sex       = m_pSet->column3;
	edlg.m_major     = m_pSet->column4;
	edlg.m_birthdate = m_pSet->column5;
	edlg.m_phone     = m_pSet->column6;
	edlg.m_address   = m_pSet->column7;
	int e = edlg.DoModal();
	UpdateData(false);
	if (e == IDOK) {
		m_pSet->Edit();
		m_pSet->column1 = edlg.m_number;
		m_pSet->column2 = edlg.m_name;
		m_pSet->column3 = edlg.m_sex;
		m_pSet->column4 = edlg.m_major;
		m_pSet->column5 = edlg.m_birthdate;
		m_pSet->column6 = edlg.m_phone;
		m_pSet->column7 = edlg.m_address;
		m_pSet->Update();
		UpdateData(false);

	}
}


void CMFCLMLView::OnDelete()
{
	// TODO: 在此添加命令处理程序代码
	CRecordsetStatus status;
	m_pSet->GetStatus(status);
	m_pSet->Delete();
	if (status.m_lCurrentRecord == 0)
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CMFCLMLView::OnBnClickedButtonEnlargePicture()
{
	// TODO: 在此添加控件通知处理程序代码
	PictrueDlg pdlg;
	m_pSet->GetFieldValue(short(8), s);
	UpdateData(true);
	pdlg.File = s;
	UpdateData(false);
	int r = pdlg.DoModal();
	if (r == IDOK)
	{

	}
}


void CMFCLMLView::OnQuery()
{
	// TODO: 在此添加命令处理程序代码
	QueryDlg qdlg;
	int q = qdlg.DoModal();
     UpdateData();
	 if (q == IDOK) {

          QueryStr = qdlg.query;
		 if (m_pSet->IsOpen())
			 m_pSet->Close();
		 m_pSet->m_strFilter = _T("QueryStr");// ;
		// m_pSet->Update();
		 m_pSet->Requery();
		// m_pSet->m_strSort = QueryStr;
		/* m_pSet->Open();
		 if (!m_pSet->IsEOF())
		 
		else
			MessageBox(_T("没有查询到要找的记录"));*/
		
	}//UpdateData(false);
		//
}
