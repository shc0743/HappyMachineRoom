// CDlgAddIps.cpp: 实现文件
//

#include "pch.h"
#include "MFCHappyMachineRoom.h"
#include "afxdialogex.h"
#include "CDlgAddIps.h"
#include <vector>
#include <string>
#include "../../resource/tool.h"
using namespace std;


// CDlgAddIps 对话框

IMPLEMENT_DYNAMIC(CDlgAddIps, CDialogEx)

CDlgAddIps::CDlgAddIps(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADDIPS, pParent)
{

}

CDlgAddIps::~CDlgAddIps()
{
}

void CDlgAddIps::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgAddIps, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgAddIps::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgAddIps 消息处理程序
extern std::vector<std::wstring> ipList;


void CDlgAddIps::OnBnClickedOk()
{
	if (IDCANCEL == MessageBox(L"在按下“确定”键之前，请确保您在【快乐课堂】IP 中保存了所有更改。\n"
		"在您按下“确定”键之后，未保存的更改将丢失。", L"", MB_OKCANCEL | MB_ICONINFORMATION)) return;
	CString str1, str2, str3;
	GetDlgItemText(IDC_EDIT_ADDIPS_1, str1);
	GetDlgItemText(IDC_EDIT_ADDIPS_2, str2);
	GetDlgItemText(IDC_EDIT_ADDIPS_3, str3);
	wstring s1; int n1, n2;
	n1 = atoi(ws2c(str2.GetBuffer()));
	n2 = atoi(ws2c(str3.GetBuffer()));
	s1 = str1.GetBuffer();
	if (s1.find(L"x") == s1.npos || !n1 || !n2) {
		MessageBox(L"参数错误。", L"", MB_ICONERROR);
		return;
	}
	size_t ncnt = 0;
	for (int i = n1; i <= n2; ++i) {
		wstring s = s1;
		str_replace(s, L"x", to_wstring(i));
		ipList.push_back(s);
		++ncnt;
	}
	pwnd->ReloadIpData();
	MessageBox((L"成功添加了 " + to_wstring(ncnt) + L" 个 IP 地址。").c_str(), L"OK", MB_ICONINFORMATION);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
