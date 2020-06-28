
// MFC-LMLView.h : CMFCLMLView ��Ľӿ�
//

#pragma once

class CMFCLMLSet;

class CMFCLMLView : public CRecordView
{
protected: // �������л�����
	CMFCLMLView();
	DECLARE_DYNCREATE(CMFCLMLView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCLML_FORM };
#endif
	CMFCLMLSet* m_pSet;

// ����
public:
	CMFCLMLDoc* GetDocument() const;

// ����
public:
	CString s;
	CString QueryStr;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCLMLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString photo;
	afx_msg void OnPaint();
	void draw_pic(CString file);
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	long number;
	CString name;
	CString sex;
	CString major;
	long birthdate;
	double phone;
	CString address;
	afx_msg void OnAdd();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	afx_msg void OnBnClickedButtonEnlargePicture();
	afx_msg void OnQuery();
};

#ifndef _DEBUG  // MFC-LMLView.cpp �еĵ��԰汾
inline CMFCLMLDoc* CMFCLMLView::GetDocument() const
   { return reinterpret_cast<CMFCLMLDoc*>(m_pDocument); }
#endif

