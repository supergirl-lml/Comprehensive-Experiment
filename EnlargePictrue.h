#pragma once


// EnlargePictrue �Ի���

class EnlargePictrue : public CDialogEx
{
	DECLARE_DYNAMIC(EnlargePictrue)

public:
	EnlargePictrue(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EnlargePictrue();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void Paint_pic(CString file);
	CString File;
};
