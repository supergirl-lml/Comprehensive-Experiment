
// MFC-12-3Doc.h : CMFC123Doc ��Ľӿ�
//


#pragma once
#include "MFC-12-3Set.h"


class CMFC123Doc : public CDocument
{
protected: // �������л�����
	CMFC123Doc();
	DECLARE_DYNCREATE(CMFC123Doc)

// ����
public:
	CMFC123Set m_MFC123Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC123Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
