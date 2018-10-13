#pragma once


// CTab2Dlg �Ի���

class CTab2Dlg : public CDialog
{
	DECLARE_DYNAMIC(CTab2Dlg)

public:
	CTab2Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTab2Dlg();
	IDirectUI* m_pDirectUI;

// �Ի�������
	enum { IDD = IDD_DIALOG_TAB2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnSMLButtonUp(WPARAM wParam,LPARAM lParam);
	IDUIListView* m_pListView;
	IDUICheckBox	*m_pHideBtn;
	IUIFormObj		*m_pLeftForm;
	IUIFormObj		*m_pRightForm;
	IDUISplitter	*m_pSplitBar;

};
