#pragma once


// CTabIDlg �Ի���

class CTabIDlg : public CDialog
{
	DECLARE_DYNAMIC(CTabIDlg)

public:
	CTabIDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTabIDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_TAB1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	IDirectUI* m_pDirectUI;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
