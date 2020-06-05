
// MFC-12-2.h : MFC-12-2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFC122App:
// 有关此类的实现，请参阅 MFC-12-2.cpp
//

class CMFC122App : public CWinApp
{
public:
	CMFC122App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC122App theApp;
