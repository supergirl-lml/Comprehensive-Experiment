// RenewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC-12-3.h"
#include "RenewDlg.h"
#include "afxdialogex.h"


// RenewDlg �Ի���

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


// RenewDlg ��Ϣ�������
