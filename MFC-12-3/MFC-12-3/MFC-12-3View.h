
// MFC-12-3View.h : CMFC123View ��Ľӿ�
//

#pragma once

class CMFC123Set;

class CMFC123View : public CRecordView
{
protected: // �������л�����
	CMFC123View();
	DECLARE_DYNCREATE(CMFC123View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC123_FORM };
#endif
	CMFC123Set* m_pSet;

// ����
public:
	CMFC123Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC123View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long show;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedRenew();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnEnChangeEdit1();
};

#ifndef _DEBUG  // MFC-12-3View.cpp �еĵ��԰汾
inline CMFC123Doc* CMFC123View::GetDocument() const
   { return reinterpret_cast<CMFC123Doc*>(m_pDocument); }
#endif

