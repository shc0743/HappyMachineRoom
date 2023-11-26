#pragma once
#include "afxdialogex.h"
#include "MFCHappyMachineRoomDlg.h"

// CDlgAddIps 对话框

class CDlgAddIps : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAddIps)

public:
	CDlgAddIps(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgAddIps();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADDIPS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CMFCHappyMachineRoomDlg* pwnd;
};
