#pragma once


// ElargeDlg �Ի���

class ElargeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ElargeDlg)

public:
	ElargeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ElargeDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CString File;
	void ElargeDlg::Paint_pic(CString file);
};
