// CChatDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFCHappyMachineRoom.h"
#include "afxdialogex.h"
#include "CChatDialog.h"


// CChatDialog 对话框

IMPLEMENT_DYNAMIC(CChatDialog, CDialogEx)

CChatDialog::CChatDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCHAPPYMACHINEROOM_DIALOG, pParent)
{

}

CChatDialog::~CChatDialog()
{
}

void CChatDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChatDialog, CDialogEx)
END_MESSAGE_MAP()


// CChatDialog 消息处理程序
