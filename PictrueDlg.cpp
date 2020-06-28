// PictrueDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC-LML.h"
#include "PictrueDlg.h"
#include "afxdialogex.h"


// PictrueDlg �Ի���

IMPLEMENT_DYNAMIC(PictrueDlg, CDialogEx)

PictrueDlg::PictrueDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

PictrueDlg::~PictrueDlg()
{
}

void PictrueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PictrueDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// PictrueDlg ��Ϣ�������


void PictrueDlg::draw_pic(CString file)
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

void PictrueDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	draw_pic(File);
}