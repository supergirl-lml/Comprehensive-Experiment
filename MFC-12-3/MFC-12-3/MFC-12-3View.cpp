
// MFC-12-3View.cpp : CMFC123View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC-12-3.h"
#endif
#include"RenewDlg.h"
#include"AddDlg.h"
#include "MFC-12-3Set.h"
#include "MFC-12-3Doc.h"
#include "MFC-12-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC123View

IMPLEMENT_DYNCREATE(CMFC123View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC123View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC123View::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC123View::OnBnClickedRenew)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC123View::OnBnClickedAdd)
	ON_EN_CHANGE(IDC_EDIT1, &CMFC123View::OnEnChangeEdit1)
END_MESSAGE_MAP()

// CMFC123View 构造/析构

CMFC123View::CMFC123View()
	: CRecordView(IDD_MFC123_FORM)
	, show(0)
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFC123View::~CMFC123View()
{
}

void CMFC123View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC123View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFC123View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC123Set;
	CRecordView::OnInitialUpdate();

}


// CMFC123View 诊断

#ifdef _DEBUG
void CMFC123View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC123View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC123Doc* CMFC123View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC123Doc)));
	return (CMFC123Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC123View 数据库支持
CRecordset* CMFC123View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC123View 消息处理程序


void CMFC123View::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CMFC123View::OnBnClickedRenew()
{
	// TODO: 在此添加控件通知处理程序代码
	RenewDlg reDlg;
	int r = reDlg.DoModal();
	if (r == IDOK)
	{
		m_pSet->Delete();
		long i = reDlg.reNew;
		m_pSet->AddNew();
		m_pSet->m_1 = i;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFC123View::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	AddDlg addDlg;
	int r = addDlg.DoModal();
	if (r == IDOK)
	{
		long t = addDlg.add;
		m_pSet->AddNew();
		m_pSet->m_1 = t;
		m_pSet->Update();
		UpdateData(false);
	}

}


void CMFC123View::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
