#pragma once


// EnlargePictrue 对话框

class EnlargePictrue : public CDialogEx
{
	DECLARE_DYNAMIC(EnlargePictrue)

public:
	EnlargePictrue(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EnlargePictrue();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void Paint_pic(CString file);
	CString File;
};
