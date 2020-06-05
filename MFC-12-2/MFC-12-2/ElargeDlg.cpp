// ElargeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC-12-2.h"
#include "ElargeDlg.h"
#include "afxdialogex.h"


// ElargeDlg 对话框

IMPLEMENT_DYNAMIC(ElargeDlg, CDialogEx)

ElargeDlg::ElargeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ElargeDlg::~ElargeDlg()
{
}

void ElargeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ElargeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// ElargeDlg 消息处理程序





void ElargeDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	
	 Paint_pic(File);
}

void ElargeDlg::Paint_pic(CString file)
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

