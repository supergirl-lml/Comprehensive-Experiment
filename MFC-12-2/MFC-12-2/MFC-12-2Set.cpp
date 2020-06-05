
// MFC-12-2Set.cpp : CMFC122Set ���ʵ��
//

#include "stdafx.h"
#include "MFC-12-2.h"
#include "MFC-12-2Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC122Set ʵ��

// ���������� 2020��5��25��, 11:33

IMPLEMENT_DYNAMIC(CMFC122Set, CRecordset)

CMFC122Set::CMFC122Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC122Set::GetDefaultConnect()
{
	return _T("DSN=Pictures;DBQ=C:\\Books.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFC122Set::GetDefaultSQL()
{
	return _T("[pic]");
}

void CMFC122Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC122Set ���

#ifdef _DEBUG
void CMFC122Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC122Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

