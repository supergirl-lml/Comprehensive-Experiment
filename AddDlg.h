#pragma once


// AddDlg �Ի���

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
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
	CString m_photo;
};
