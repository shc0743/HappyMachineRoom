#pragma once
#include "afxdialogex.h"


// CPlayDialog 对话框

class CPlayDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPlayDialog)

public:
	CPlayDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CPlayDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
