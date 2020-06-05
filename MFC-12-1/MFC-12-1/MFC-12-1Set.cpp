
// MFC-12-1Set.cpp : CMFC121Set ���ʵ��
//

#include "stdafx.h"
#include "MFC-12-1.h"
#include "MFC-12-1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC121Set ʵ��

// ���������� 2020��5��18��, 11:25

IMPLEMENT_DYNAMIC(CMFC121Set, CRecordset)

CMFC121Set::CMFC121Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC121Set::GetDefaultConnect()
{
	return _T("DSN=Pictures;DBQ=C:\\Books.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC121Set::GetDefaultSQL()
{
	return _T("[pic]");
}

void CMFC121Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC121Set ���

#ifdef _DEBUG
void CMFC121Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC121Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

