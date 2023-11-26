// CPlayDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFCHappyMachineRoom.h"
#include "afxdialogex.h"
#include "CPlayDialog.h"


// CPlayDialog 对话框

IMPLEMENT_DYNAMIC(CPlayDialog, CDialogEx)

CPlayDialog::CPlayDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PLAY, pParent)
{

}

CPlayDialog::~CPlayDialog()
{
}

void CPlayDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPlayDialog, CDialogEx)
END_MESSAGE_MAP()


// CPlayDialog 消息处理程序
