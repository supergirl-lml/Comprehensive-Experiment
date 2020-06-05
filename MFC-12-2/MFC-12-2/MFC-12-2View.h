
// MFC-12-2View.h : CMFC122View 类的接口
//

#pragma once

class CMFC122Set;

class CMFC122View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC122View();
	DECLARE_DYNCREATE(CMFC122View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC122_FORM };
#endif
	CMFC122Set* m_pSet;
	CString path;
	CString filename, s;
// 特性
public:
	CMFC122Doc* GetDocument() const;
	void draw_pic(CString file);
// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC122View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	CString show;
	afx_msg void OnBnClickedButtonEnlarge();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFC-12-2View.cpp 中的调试版本
inline CMFC122Doc* CMFC122View::GetDocument() const
   { return reinterpret_cast<CMFC122Doc*>(m_pDocument); }
#endif

