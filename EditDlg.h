#pragma once


// EditDlg 对话框

class EditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditDlg)

public:
	EditDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EditDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long m_number;
	CString m_name;
	CString m_sex;
	CString m_major;
	long m_birthdate;
	double m_phone;
	CString m_address;	
};
