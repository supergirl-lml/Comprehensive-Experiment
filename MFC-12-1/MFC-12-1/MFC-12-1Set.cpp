
// MFC-12-1Set.cpp : CMFC121Set 类的实现
//

#include "stdafx.h"
#include "MFC-12-1.h"
#include "MFC-12-1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC121Set 实现

// 代码生成在 2020年5月18日, 11:25

IMPLEMENT_DYNAMIC(CMFC121Set, CRecordset)

CMFC121Set::CMFC121Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[字段1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC121Set 诊断

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

