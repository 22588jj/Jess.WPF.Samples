#pragma once


// CReplaceSkin �Ի���

class CReplaceSkin : public CDialog
{
	DECLARE_DYNAMIC(CReplaceSkin)

public:
	CReplaceSkin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CReplaceSkin();

// �Ի�������
	enum { IDD = IDD_DIALOGReplaceSkin };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	IDirectUI*    m_pIDirectUI;
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnKillFocus(CWnd* pNewWnd);

};
