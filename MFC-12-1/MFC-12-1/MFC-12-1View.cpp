
// MFC-12-1View.cpp : CMFC121View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC-12-1.h"
#endif

#include "MFC-12-1Set.h"
#include "MFC-12-1Doc.h"
#include "MFC-12-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFC121View

IMPLEMENT_DYNCREATE(CMFC121View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC121View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC121View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC121View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC121View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC121View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC121View ����/����

CMFC121View::CMFC121View()
	: CRecordView(IDD_MFC121_FORM)
	, picName(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path=_T("C:\\vcʵ����\\ͼƬ\\");
}

CMFC121View::~CMFC121View()
{
}

void CMFC121View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC121View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC121Set;
	CRecordView::OnInitialUpdate();

}


// CMFC121View ���

#ifdef _DEBUG
void CMFC121View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC121View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC121Doc* CMFC121View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC121Doc)));
	return (CMFC121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC121View ���ݿ�֧��
CRecordset* CMFC121View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC121View ��Ϣ�������


void CMFC121View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
	
	
}


void CMFC121View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFC121View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
	  m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
	
}


void CMFC121View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
	
}


void CMFC121View::draw_pic(CString file)
{
	//CString filename = cfd.GetPathName();
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


void CMFC121View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}
