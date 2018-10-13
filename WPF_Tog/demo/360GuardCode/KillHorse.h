#pragma once
#include "Patient.h"
#include "CustomForm.h"

class  CMy360DEMODlg;
class  CCustomForm;

// CKillHorse �Ի���

class CKillHorse : public CDialog
{
	DECLARE_DYNAMIC(CKillHorse)

public:
	CKillHorse(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CKillHorse();
	CCustomForm     m_Custom;
	CKillHorse*     m_pKillHorse;
	virtual void     OnOK();

	BOOL   m_bCustomCreat;


// �Ի�������
	enum { IDD = IDD_DIALOG_KillHouse };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	IDirectUI*    m_pIDirectUI;
	CPatient       m_Otpatient;
	ICmdButton*   m_pBtnStart;
	ICmdButton*   m_pBtnQiuckScan;
	ICmdButton*   m_pBtnAllScan;
	ICmdButton*   m_pBtnCustomScan;
   
	CMy360DEMODlg*  m_pMainDlg; 

	
	afx_msg LRESULT OnDUILButtonUp(WPARAM wparam,LPARAM lparam);

protected:
	virtual void OnCancel();
};
