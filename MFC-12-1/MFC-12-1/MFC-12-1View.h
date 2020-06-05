
// MFC-12-1View.h : CMFC121View ��Ľӿ�
//

#pragma once

class CMFC121Set;

class CMFC121View : public CRecordView
{
protected: // �������л�����
	CMFC121View();
	DECLARE_DYNCREATE(CMFC121View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC121_FORM };
#endif
	CMFC121Set* m_pSet;
	CString path;
// ����
public:
	CMFC121Doc* GetDocument() const;
	void draw_pic(CString file);
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
	virtual ~CMFC121View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString picName;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFC-12-1View.cpp �еĵ��԰汾
inline CMFC121Doc* CMFC121View::GetDocument() const
   { return reinterpret_cast<CMFC121Doc*>(m_pDocument); }
#endif

