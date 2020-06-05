
// MFC-12-3View.cpp : CMFC123View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC123View ����/����

CMFC123View::CMFC123View()
	: CRecordView(IDD_MFC123_FORM)
	, show(0)
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFC123View::~CMFC123View()
{
}

void CMFC123View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC123View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC123View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC123Set;
	CRecordView::OnInitialUpdate();

}


// CMFC123View ���

#ifdef _DEBUG
void CMFC123View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC123View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC123Doc* CMFC123View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC123Doc)));
	return (CMFC123Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC123View ���ݿ�֧��
CRecordset* CMFC123View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC123View ��Ϣ�������


void CMFC123View::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
}


void CMFC123View::OnBnClickedRenew()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
