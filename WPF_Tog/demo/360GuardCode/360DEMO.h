// 360DEMO.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "Include/OfficeAll.h"


// CMy360DEMOApp:
// �йش����ʵ�֣������ 360DEMO.cpp
//

class CMy360DEMOApp : public CWinApp
{
public:
	CMy360DEMOApp();
	IDUIRes*     m_pDUIRes;


// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��
public:
	int ExitInstance(void);

	DECLARE_MESSAGE_MAP()
};

extern CMy360DEMOApp theApp;