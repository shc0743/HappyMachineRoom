#pragma once
#include "afxdialogex.h"


// CChatDialog 对话框

class CChatDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CChatDialog)

public:
	CChatDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChatDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CHAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
