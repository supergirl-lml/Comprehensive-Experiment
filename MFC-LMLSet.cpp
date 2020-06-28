
// MFC-LMLSet.cpp : CMFCLMLSet ���ʵ��
//

#include "stdafx.h"
#include "MFC-LML.h"
#include "MFC-LMLSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCLMLSet ʵ��

// ���������� 2020��6��6��, 20:11

IMPLEMENT_DYNAMIC(CMFCLMLSet, CRecordset)

CMFCLMLSet::CMFCLMLSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = 0;
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = 0;
	column6 = 0.0;
	column7 = L"";
	column8 = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCLMLSet::GetDefaultConnect()
{
	return _T("DSN=LML;DBQ=C:\\Students.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCLMLSet::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ����ϵͳ]");
}

void CMFCLMLSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[ѧ��]"), column1);
	RFX_Text(pFX, _T("[����]"), column2);
	RFX_Text(pFX, _T("[�Ա�]"), column3);
	RFX_Text(pFX, _T("[רҵ]"), column4);
	RFX_Long(pFX, _T("[��������]"), column5);
	RFX_Double(pFX, _T("[�ֻ�����]"), column6);
	RFX_Text(pFX, _T("[��ͥסַ]"), column7);
	RFX_Text(pFX, _T("[��Ƭ�ļ���]"), column8);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCLMLSet ���

#ifdef _DEBUG
void CMFCLMLSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCLMLSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

