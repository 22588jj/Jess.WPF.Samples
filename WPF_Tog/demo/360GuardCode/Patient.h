#pragma once


// CPatient �Ի���

class CPatient : public CDialog
{
	DECLARE_DYNAMIC(CPatient)

public:
	CPatient(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPatient();
    virtual void     OnOK();
// �Ի�������
	enum { IDD = IDD_DIALOG_OPatient };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	IDirectUI*    m_pIDirectUI;
	ICmdButton*   m_pBtnClose;
	ICmdButton*   m_pBtnMax;
	ICmdButton*   m_pBtnFeedBack;
	ICmdButton*   m_pBtnCancel;
	afx_msg LRESULT OnDUILButtonUp(WPARAM wparam,LPARAM lparam);


protected:
	virtual void OnCancel();
};
