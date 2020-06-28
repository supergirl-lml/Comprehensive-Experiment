// EditDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC-LML.h"
#include "EditDlg.h"
#include "afxdialogex.h"


// EditDlg 对话框

IMPLEMENT_DYNAMIC(EditDlg, CDialogEx)

EditDlg::EditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	,  m_number(0)
	, m_name(_T(""))
	, m_sex(_T(""))
	, m_major(_T(""))
	, m_birthdate(0)
	, m_phone(0)
	, m_address(_T(""))
{

}

EditDlg::~EditDlg()
{
}

void EditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_number);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_sex);
	DDX_Text(pDX, IDC_EDIT4, m_major);
	DDX_Text(pDX, IDC_EDIT5, m_birthdate);
	DDX_Text(pDX, IDC_EDIT6, m_phone);
	DDX_Text(pDX, IDC_EDIT7, m_address);
	DDX_Text(pDX, IDC_EDIT1, m_number);
	DDX_Text(pDX, IDC_EDIT5, m_birthdate);
}


BEGIN_MESSAGE_MAP(EditDlg, CDialogEx)
END_MESSAGE_MAP()


// EditDlg 消息处理程序
