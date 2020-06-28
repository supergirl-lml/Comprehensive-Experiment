
// MFC-LMLView.h : CMFCLMLView 类的接口
//

#pragma once

class CMFCLMLSet;

class CMFCLMLView : public CRecordView
{
protected: // 仅从序列化创建
	CMFCLMLView();
	DECLARE_DYNCREATE(CMFCLMLView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCLML_FORM };
#endif
	CMFCLMLSet* m_pSet;

// 特性
public:
	CMFCLMLDoc* GetDocument() const;

// 操作
public:
	CString s;
	CString QueryStr;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCLMLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFC-LMLView.cpp 中的调试版本
inline CMFCLMLDoc* CMFCLMLView::GetDocument() const
   { return reinterpret_cast<CMFCLMLDoc*>(m_pDocument); }
#endif

