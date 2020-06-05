// RenewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC-12-3.h"
#include "RenewDlg.h"
#include "afxdialogex.h"


// RenewDlg 对话框

IMPLEMENT_DYNAMIC(RenewDlg, CDialogEx)

RenewDlg::RenewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, reNew(0)
{

}

RenewDlg::~RenewDlg()
{
}

void RenewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, reNew);
}


BEGIN_MESSAGE_MAP(RenewDlg, CDialogEx)
END_MESSAGE_MAP()


// RenewDlg 消息处理程序
