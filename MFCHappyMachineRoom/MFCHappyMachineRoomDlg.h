
// MFCHappyMachineRoomDlg.h: 头文件
//

#pragma once


// CMFCHappyMachineRoomDlg 对话框
class CMFCHappyMachineRoomDlg : public CDialogEx
{
// 构造
public:
	CMFCHappyMachineRoomDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCHAPPYMACHINEROOM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButtonChat();
	afx_msg BOOL OnQueryEndSession();
//	afx_msg void OnEndSession(BOOL bEnding);
	afx_msg void OnBnClickedButtonExit();
	virtual void OnCancel();
	afx_msg void OnBnClickedButtonSmallplay();
	afx_msg void OnBnClickedSplitSaveip();
	afx_msg void OnDropdownSplitSaveip(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonIptool();
	void ReloadIpData();
};
