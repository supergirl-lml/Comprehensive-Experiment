
// MFC-LML.h : MFC-LML Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCLMLApp:
// �йش����ʵ�֣������ MFC-LML.cpp
//

class CMFCLMLApp : public CWinApp
{
public:
	CMFCLMLApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCLMLApp theApp;
