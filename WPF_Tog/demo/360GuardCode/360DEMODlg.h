// 360DEMODlg.h : ͷ�ļ�
//

#pragma once
#include "HealCheck.h"
#include "KillHorse.h"
#include "ClearCard.h"
#include "FillHole.h"
#include "Repair.h"
#include "CputerClear.h"
#include "Function.h"
#include "Patient.h"
#include "ReplaceSkin.h"


// CMy360DEMODlg �Ի���
class CMy360DEMODlg : public CDialog
{
// ����
public:
	CMy360DEMODlg(CWnd* pParent = NULL);	// ��׼���캯��
	
// �Ի�������
	enum { IDD = IDD_MY360DEMO_DIALOG };
	  IDUIHwndObj*   m_pHwndObjBody;
	  CKillHorse     m_KillHorse;
	  CCustomForm    m_Custom;
	

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg  LRESULT  OnDUILButtonUP(WPARAM wparam,LPARAM lparam);
	afx_msg  LRESULT  OnDUILButtonDBClick(WPARAM wpatam,LPARAM lparam);
	IDirectUI*     m_pDirectUI;
	ICmdButton*    m_pBtnClose;
	IDUICheckBox*  m_pCheckMax;
	ICmdButton*    m_pBtnMin;
	ICmdButton*    m_pBtnMenu;
	ICmdButton*    m_pBtnSkin;
	
	
	ICmdButton*    m_pBtnIcon;
  
	RadioBox*      m_pRadioHealCheck;
	RadioBox*      m_pRadioKillHorse;
	RadioBox*      m_pRadioClearCard;
	RadioBox*      m_pRadioFillHole;
	RadioBox*      m_pRadioSysRepair;
	RadioBox*      m_pRadioComputeClear;
    RadioBox*      m_pRadioFunction;
	ICmdButton*    m_pButtonOptatient;
    IDUIPopupMenu* m_pMenuMainMenu;

	CHealCheck     m_HealCheck;

	CClearCard     m_ClearCard;
	CFillHole      m_FillHole;
	CRepair        m_SysRepair;
	CCputerClear   m_CputerClear;
	CFunction      m_Function;
	CPatient       m_Otpatient;
	CReplaceSkin   m_ReplaceSkin;


		      
};
