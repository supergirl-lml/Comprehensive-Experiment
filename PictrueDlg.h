#pragma once


// PictrueDlg �Ի���

class PictrueDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PictrueDlg)

public:
	PictrueDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PictrueDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void draw_pic(CString file);
	CString File;
};
