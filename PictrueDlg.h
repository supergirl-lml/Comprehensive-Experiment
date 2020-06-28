#pragma once


// PictrueDlg 对话框

class PictrueDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PictrueDlg)

public:
	PictrueDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PictrueDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void draw_pic(CString file);
	CString File;
};
