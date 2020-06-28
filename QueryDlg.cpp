// QueryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC-LML.h"
#include "QueryDlg.h"
#include "afxdialogex.h"


// QueryDlg 对话框

IMPLEMENT_DYNAMIC(QueryDlg, CDialogEx)

QueryDlg::QueryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, query(_T(""))
{

}

QueryDlg::~QueryDlg()
{
}

void QueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, query);
}


BEGIN_MESSAGE_MAP(QueryDlg, CDialogEx)
END_MESSAGE_MAP()


// QueryDlg 消息处理程序
