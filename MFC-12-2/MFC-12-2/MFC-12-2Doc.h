
// MFC-12-2Doc.h : CMFC122Doc ��Ľӿ�
//


#pragma once
#include "MFC-12-2Set.h"


class CMFC122Doc : public CDocument
{
protected: // �������л�����
	CMFC122Doc();
	DECLARE_DYNCREATE(CMFC122Doc)

// ����
public:
	CMFC122Set m_MFC122Set;

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
	virtual ~CMFC122Doc();
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
