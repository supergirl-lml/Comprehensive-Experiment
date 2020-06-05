
// MFC-12-3View.h : CMFC123View 类的接口
//

#pragma once

class CMFC123Set;

class CMFC123View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC123View();
	DECLARE_DYNCREATE(CMFC123View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC123_FORM };
#endif
	CMFC123Set* m_pSet;

// 特性
public:
	CMFC123Doc* GetDocument() const;

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
	virtual ~CMFC123View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long show;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedRenew();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnEnChangeEdit1();
};

#ifndef _DEBUG  // MFC-12-3View.cpp 中的调试版本
inline CMFC123Doc* CMFC123View::GetDocument() const
   { return reinterpret_cast<CMFC123Doc*>(m_pDocument); }
#endif

