
// MFC-12-2View.cpp : CMFC122View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC122View ����/����

CMFC122View::CMFC122View()
	: CRecordView(IDD_MFC122_FORM)
	, show(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\vcʵ����\\ͼƬ\\");

}

CMFC122View::~CMFC122View()
{
}

void CMFC122View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC122View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC122View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC122Set;
	CRecordView::OnInitialUpdate();

}


// CMFC122View ���

#ifdef _DEBUG
void CMFC122View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC122View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC122Doc* CMFC122View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC122Doc)));
	return (CMFC122Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC122View ���ݿ�֧��
CRecordset* CMFC122View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC122View ��Ϣ�������


void CMFC122View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC122View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC122View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFC122View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}

void CMFC122View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;//ͼƬ���Ͻǵ��λ�úͿ��
	CRect cr;
	GetDlgItem(IDC_STATIC)->GetClientRect(&cr);

	float cr_ratio = 1.0 * cr.Width() / cr.Height();
	float img_ratio = 1.0 * img.GetWidth() / img.GetHeight();

	if (cr_ratio > img_ratio)
	{//�ͻ�����߱ȴ���ͼ��
		h = cr.Height();//ͼƬ�߶�
		w = img_ratio * h;//ͼƬ���
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}
