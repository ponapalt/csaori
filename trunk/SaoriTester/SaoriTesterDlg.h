// SaoriTesterDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_SAORITESTERDLG_H__152C015F_AB75_495A_A460_F724B449DDBB__INCLUDED_)
#define AFX_SAORITESTERDLG_H__152C015F_AB75_495A_A460_F724B449DDBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSaoriTesterDlg �_�C�A���O

typedef BOOL (__cdecl *SPM_load)(HGLOBAL h, long len);
typedef BOOL (__cdecl *SPM_unload)();
typedef HGLOBAL (__cdecl *SPM_request)(HGLOBAL h, long* len);

class CSaoriTesterDlg : public CDialog
{
// �\�z
public:
	virtual void OnCancel();
	virtual void OnOK();
	CSaoriTesterDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSaoriTesterDlg)
	enum { IDD = IDD_SAORITESTER_DIALOG };
	CString	m_a1;
	CString	m_a2;
	CString	m_a3;
	CString	m_a4;
	CString	m_a5;
	CString	m_a6;
	CString	m_a7;
	CString	m_a8;
	CString	m_path;
	CString	m_request;
	CString	m_response;
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CSaoriTesterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HMODULE m_hModule;
	SPM_load load;
	SPM_unload unload;
	SPM_request request;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSaoriTesterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnExecute();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SAORITESTERDLG_H__152C015F_AB75_495A_A460_F724B449DDBB__INCLUDED_)