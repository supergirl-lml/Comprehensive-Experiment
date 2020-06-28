// AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC-LML.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// AddDlg 对话框

IMPLEMENT_DYNAMIC(AddDlg, CDialogEx)

AddDlg::AddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_number(0)
	, m_name(_T(""))
	, m_sex(_T(""))
	, m_major(_T(""))
	, m_birthdate(0)
	, m_phone(0)
	, m_address(_T(""))
	, m_photo(_T(""))
{

}

AddDlg::~AddDlg()
{
}

void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDABORT, m_number);
	DDX_Text(pDX, IDABORT2, m_name);
	DDX_Text(pDX, IDABORT3, m_sex);
	DDX_Text(pDX, IDABORT4, m_major);
	DDX_Text(pDX, IDABORT5, m_birthdate);
	DDX_Text(pDX, IDABORT6, m_phone);
	DDX_Text(pDX, IDABORT7, m_address);
	DDX_Text(pDX, IDABORT8, m_photo);
}


BEGIN_MESSAGE_MAP(AddDlg, CDialogEx)
END_MESSAGE_MAP()


// AddDlg 消息处理程序

