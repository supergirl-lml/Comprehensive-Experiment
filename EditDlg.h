#pragma once


// EditDlg �Ի���

class EditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditDlg)

public:
	EditDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EditDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
