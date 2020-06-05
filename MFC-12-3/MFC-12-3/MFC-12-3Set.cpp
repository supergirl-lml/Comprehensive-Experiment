
// MFC-12-3Set.cpp : CMFC123Set ���ʵ��
//

#include "stdafx.h"
#include "MFC-12-3.h"
#include "MFC-12-3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC123Set ʵ��

// ���������� 2020��5��19��, 22:07

IMPLEMENT_DYNAMIC(CMFC123Set, CRecordset)

CMFC123Set::CMFC123Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC123Set::GetDefaultConnect()
{
	return _T("// DSN = \x5b66\x4e60\x8868; DBQ = D:\\Documents\\studay.accdb; DriverId = 25; FIL = MS Access; MaxBufferSize = 2048; PageTimeout = 5; UID = admin; ");
	//DSN=\x5b66\x4e60\x8868;DBQ=D:\\Documents\\studay.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;"
}

CString CMFC123Set::GetDefaultSQL()
{
	return _T("[study]");
}

void CMFC123Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC123Set ���

#ifdef _DEBUG
void CMFC123Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC123Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

