
// MFCHappyMachineRoomDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCHappyMachineRoom.h"
#include "MFCHappyMachineRoomDlg.h"
#include "afxdialogex.h"
#include <string>
#include <locale>  
#include <codecvt> 
using std::string;
using std::wstring;
using std::ios;
using std::wfstream;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCHappyMachineRoomDlg 对话框



CMFCHappyMachineRoomDlg::CMFCHappyMachineRoomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCHAPPYMACHINEROOM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCHappyMachineRoomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCHappyMachineRoomDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCHappyMachineRoomDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCHappyMachineRoomDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON_CHAT, &CMFCHappyMachineRoomDlg::OnBnClickedButtonChat)
	ON_WM_QUERYENDSESSION()
//	ON_WM_ENDSESSION()
ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMFCHappyMachineRoomDlg::OnBnClickedButtonExit)
ON_BN_CLICKED(IDC_BUTTON_SMALLPLAY, &CMFCHappyMachineRoomDlg::OnBnClickedButtonSmallplay)
ON_BN_CLICKED(IDC_SPLIT_SAVEIP, &CMFCHappyMachineRoomDlg::OnBnClickedSplitSaveip)
ON_NOTIFY(BCN_DROPDOWN, IDC_SPLIT_SAVEIP, &CMFCHappyMachineRoomDlg::OnDropdownSplitSaveip)
ON_BN_CLICKED(IDC_BUTTON_IPTOOL, &CMFCHappyMachineRoomDlg::OnBnClickedButtonIptool)
END_MESSAGE_MAP()


// CMFCHappyMachineRoomDlg 消息处理程序

#include "VersionName.txt"

#include "../../resource/tool.h"
#include "CChatDialog.h"
#include "CPlayDialog.h"


std::vector<wstring> adsText;
bool appCanClose;
std::vector<wstring> ipList;


BOOL CMFCHappyMachineRoomDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);

			// 增加菜单
			pSysMenu->InsertMenuW(0, MF_BYPOSITION | MF_STRING | MF_ENABLED, 0xFF01, L"玩原 (&G)");
			pSysMenu->InsertMenuW(1, MF_BYPOSITION | MF_SEPARATOR, 0, L"");
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	{ // 加载版本名
		WCHAR szOriTitle[256]{};
		GetWindowTextW(szOriTitle, 128);
		wcscat_s(szOriTitle, L" " VERSION_NAME);
		SetWindowTextW(szOriTitle);
		wcscat_s(szOriTitle, L" 仍在运行！");
		ShutdownBlockReasonCreate(GetSafeHwnd(), szOriTitle);
		SetProcessShutdownParameters(0x3FF, 0);
	}
	{ // 加载广告
		string fn = (GetProgramInfo().name) + ".ads.data";
		FreeResFile(IDR_BIN_ADS, "BIN", fn);

#if 0
		wfstream fp(L"test.txt", ios::out); // ads.txt 采用 UTF-16 LE 编码
		/*wchar_t sbuffer[1024]{};
		while (fp.getline(sbuffer, 1024).eof() != true) {
			if (sbuffer[0] != L'\0') adsText.push_back(sbuffer);
		}*/fp.write(L"111原神00000",10);
		fp.close();
#else
		std::ifstream file(fn); // 打开文件  

		std::string line;
		while (std::getline(file, line)) { // 逐行读取文件内容  
			/*
			std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
			std::u32string u32line = converter.from_bytes(line); // 将读取的UTF-8编码转换为UTF-32编码  
			std::wcout << u32line << std::endl; // 输出UTF-32编码的字符串  */
			//std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			std::string utf8_str = line;
			//std::wstring wide_str = converter.from_bytes(utf8_str);
			int num_chars = MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, nullptr, 0);
			wchar_t* wide_str = new wchar_t[num_chars];
			MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, wide_str, num_chars);
			std::wstring wstr(wide_str, num_chars);
			delete[] wide_str;
			if (wstr[0] != L'\0') {
				/* 自动换行功能 */
				wstring newWstr;
				newWstr.reserve(wstr.size());
				unsigned int ll = 0;
				for (auto l = wstr.length(), i = l - l; i < l; ++i) {
					if (wstr[i] < (wchar_t)128) { // en
						ll += 1;
					}
					else {
						ll += 2;
					}
					newWstr += wstr[i];
					if (ll >= 32) {
						ll = 0; newWstr += L"\r\n";
					}
				}
				/* 自动换行功能 */
				adsText.push_back(newWstr);
			}
		}

		file.close(); // 关闭文件  
#endif
		
		OnBnClickedButton9();
	}



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCHappyMachineRoomDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if ((nID) == 0xFF01)
	{
		PCWSTR wcs[] = {
			L"天空岛 (&1)", L"世界树 (&2)", L"国际服 (&3)",
		};
		PCWSTR dat[] = {
			L"https://ys.mihoyo.com/main/", L"https://ys.mihoyo.com/", L"https://ys.mihoyo.com/cloud/",

			L"https://space.bilibili.com/401742377/",
			L"https://www.biligame.com/detail/?id=105667",
			L"https://www.biligame.com/detail/?id=105667",

			L"https://genshin.hoyoverse.com/en/home", L"https://genshin.hoyoverse.com/", L"N/A",
		};
		HMENU menu = CreatePopupMenu();
		::AppendMenuW(menu, MF_STRING, 1, wcs[0]);
		::AppendMenuW(menu, MF_STRING, 2, wcs[1]);
		::AppendMenuW(menu, MF_SEPARATOR, 0, L"");
		::AppendMenuW(menu, MF_STRING, 3, wcs[2]); 
		POINT pt{}; GetCursorPos(&pt);
		auto v = ::TrackPopupMenu(menu, TPM_NONOTIFY | TPM_RETURNCMD | TPM_RIGHTBUTTON, pt.x, pt.y, 0, GetSafeHwnd(), 0);
		//MessageBox(std::to_wstring(GetLastError()).c_str());
		if (1 <= v && v <= 3) {
			HMENU menu = CreatePopupMenu();
			::AppendMenuW(menu, MF_STRING | MF_GRAYED, 1, wcs[v-1]);
			::AppendMenuW(menu, MF_SEPARATOR, 0, L"");
			::AppendMenuW(menu, MF_STRING, 2, L"官方网站 (&W)");
			::AppendMenuW(menu, MF_STRING, 3, L"下载 (&D)");
			::AppendMenuW(menu, MF_STRING | ((v == 3 && (!HIWORD(GetKeyState(VK_SHIFT)))) ? MF_GRAYED : 0), 4, L"《云·原神》 (&C)");

			auto v2 = ::TrackPopupMenu(menu, TPM_NONOTIFY | TPM_RETURNCMD | TPM_RIGHTBUTTON, pt.x, pt.y, 0, GetSafeHwnd(), 0);
			if (2 <= v2 && v2 <= 4) {
				auto v3 = v2 - 2;
				v3 += (v - 1) * 3;
				auto& str = dat[v3];
				if (wcscmp(str, L"N/A") == 0) MessageBoxW(L"Not Applicable", 0, MB_ICONERROR);
				else ShellExecuteW(0, L"open", str, NULL, NULL, SW_NORMAL);
			}
		}
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCHappyMachineRoomDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCHappyMachineRoomDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCHappyMachineRoomDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!appCanClose) {
		if ((HIWORD(GetKeyState(VK_CONTROL))) &&
			(HIWORD(GetKeyState(VK_SHIFT))) &&
			(HIWORD(GetKeyState(VK_MENU))) &&
			(HIWORD(GetKeyState(VK_F4)))) {
			HWND hwnd = GetSafeHwnd();
			HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)[](void*pv)->DWORD {
				HWND hw = (HWND)pv;
				if (::MessageBoxW(NULL, L"要启动强制退出过程吗？", L"强制退出过程启动器",
					MB_YESNO | MB_SERVICE_NOTIFICATION | MB_DEFBUTTON2 | MB_ICONWARNING) == IDYES) {
					/*appCanClose = true;
					::SendMessageW(hw, WM_CLOSE, 0, 0);*/
					ExitProcess(ERROR_FATAL_APP_EXIT);
				}
				return (DWORD)0;
				}, hwnd, 0, 0);
			if (hThread) CloseHandle(hThread);
		}
		return;
	}

	ShutdownBlockReasonDestroy(GetSafeHwnd());

	string fn = (GetProgramInfo().name) + ".ads.data";
	DeleteFileA(fn.c_str());

	CDialogEx::OnClose();
}


void CMFCHappyMachineRoomDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (adsText.size() > 0) {
		int rd = 0; static int prevRd = -1;
		srand(((UINT)time(0)) - rand());
		rd = rand() % adsText.size();
		if (rd == prevRd) {
			rd -= 1;
			if (rd < 0) rd += 2;
		} // 防止重复
		prevRd = rd;
		SetDlgItemTextW(IDC_EDIT_ADS, adsText.at(rd).c_str());
	}
}


void CMFCHappyMachineRoomDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	WCHAR wc[1024]{};
	GetDlgItemTextW(IDC_EDIT_ADS, wc, 1024);
	wstring ws = wc;
	str_replace(ws, L"\r\n", L""); // 去除换行
	auto pos = ws.find(L"https://");
	if (pos == ws.npos) {
		MessageBoxW(L"无法打开", L"错误", MB_ICONERROR); return;
	}
	ws.erase(0, pos);
	ShellExecuteW(0, L"open", ws.c_str(), 0, 0, SW_NORMAL);
}


CChatDialog* cchatdialog;
void CMFCHappyMachineRoomDlg::OnBnClickedButtonChat()
{
	// TODO: 在此添加控件通知处理程序代码
	if (cchatdialog) {
		cchatdialog->ShowWindow(SW_NORMAL);
		cchatdialog->SetForegroundWindow();
	}
	else {
		cchatdialog = new CChatDialog();
		cchatdialog->Create(IDD_DIALOG_CHAT);
		WCHAR wcText[256]{};
		GetWindowTextW(wcText, 256);
		cchatdialog->SetWindowTextW(wcText);
		::CenterWindow(cchatdialog->GetSafeHwnd(), GetSafeHwnd());
		cchatdialog->ShowWindow(SW_NORMAL);
	}
}


CPlayDialog* cplaydialog;
void CMFCHappyMachineRoomDlg::OnBnClickedButtonSmallplay()
{
	// TODO: 在此添加控件通知处理程序代码
	if (cplaydialog) {
		cplaydialog->ShowWindow(SW_NORMAL);
		cplaydialog->SetForegroundWindow();
	}
	else {
		cplaydialog = new CPlayDialog();
		cplaydialog->Create(IDD_DIALOG_PLAY);
		WCHAR wcText[256]{};
		GetWindowTextW(wcText, 256);
		cplaydialog->SetWindowTextW(wcText);
		::CenterWindow(cplaydialog->GetSafeHwnd(), GetSafeHwnd());
		cplaydialog->ShowWindow(SW_NORMAL);
	}
}


BOOL CMFCHappyMachineRoomDlg::OnQueryEndSession()
{
	return FALSE;

	if (!CDialogEx::OnQueryEndSession())
		return FALSE;

	// TODO:  在此添加专用的查询结束会话代码
	return TRUE;
}


//void CMFCHappyMachineRoomDlg::OnEndSession(BOOL bEnding)
//{
//	CDialogEx::OnEndSession(bEnding);
//
	// TODO: 在此处添加消息处理程序代码
//}


#include "captchaAPI.h"
#include "CDlgAddIps.h"
using namespace CaptchaEmbedded;
void CMFCHappyMachineRoomDlg::OnBnClickedButtonExit()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_BUTTON_EXIT)->EnableWindow(0);

	string fn = (GetProgramInfo().name) + ".libcaptcha.dll";
	FreeResFile(IDR_BIN_CAPTCHA, "BIN", fn);
	HMODULE hcaptcha = LoadLibraryA(fn.c_str());

	if (!hcaptcha) {
	errhand:
		HANDLE hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)[](void*)->DWORD {
			if (::MessageBoxW(NULL, L"文件已损坏，这可能是某些恶意软件攻击所致。\n"
				"不过，您可以选择强制退出此程序。\n\n要那样做吗？", L"",
				MB_YESNO | MB_SERVICE_NOTIFICATION | MB_DEFBUTTON2 | MB_ICONWARNING) == IDYES) {
				ExitProcess(ERROR_FILE_CORRUPT);
			}
			return (DWORD)0;
		}, 0, 0, 0);
		if (hThread) CloseHandle(hThread);
		GetDlgItem(IDC_BUTTON_EXIT)->EnableWindow(1);
		return;
	}

	void (WINAPI *CaptchaUtil_generateMathProblem)(CaptchaEmbedded::PCAPTCHADATA data) =
		(decltype(CaptchaUtil_generateMathProblem))GetProcAddress(hcaptcha,
			"CaptchaUtil_generateMathProblem");
	void (WINAPI *CaptchaUtil_drawMathProblem)(HDC hdc, CaptchaEmbedded::PCAPTCHADATA data) =
		(decltype(CaptchaUtil_drawMathProblem))GetProcAddress(hcaptcha,
			"CaptchaUtil_drawMathProblem");
	bool (WINAPI *CaptchaUtil_validateMathProblem)(CaptchaEmbedded::PCAPTCHADATA data) =
		(decltype(CaptchaUtil_validateMathProblem))GetProcAddress(hcaptcha,
			"CaptchaUtil_validateMathProblem");
	HWND(__stdcall * CreateCaptcha)(CAPTCHAWINDOWDATA * wd, CAPTCHADATA * data) =
		(decltype(CreateCaptcha))GetProcAddress(hcaptcha, "CreateCaptcha");
	int(__stdcall * RunCaptcha)(CAPTCHADATA * data) =
		(decltype(RunCaptcha))GetProcAddress(hcaptcha, "RunCaptcha");
	using INIT_API = bool(__stdcall*)(void* data);
	
	if (!(CaptchaUtil_generateMathProblem &&
		CaptchaUtil_drawMathProblem &&
		CaptchaUtil_validateMathProblem &&
		CreateCaptcha && RunCaptcha)
	) {
		goto errhand;
		return;
	}


	CAPTCHAWINDOWDATA wd{};
	CAPTCHADATA d{};
	d.cb = sizeof(d);
	d.wData = &wd;
	d.data_type = CAPTCHADATA::T_data_type::OwnerDraw;
	d.data.pGenerateFunction = CaptchaUtil_generateMathProblem;
	d.data.pDrawFunction = CaptchaUtil_drawMathProblem;
	d.data.pValidateFunc = CaptchaUtil_validateMathProblem;
	d.difficulty = CAPTCHADATA::T_difficulty::Easy;

	wd.cb = sizeof wd;
	wcscpy_s(wd.caption, L"请输入验证码");
	wd.size.cx = 500; wd.size.cy = 300;
	wd.centerWindow = true;
	wd.resizable = false;
	wd.ctls_data.text0 = L"请输入验证码，以证明您是人。";
	wd.ctls_data.text_question = L"请在下面输入结果。";
	HWND hfFg = GetSafeHwnd();
	if (!CreateCaptcha(&wd, &d)) {
		::MessageBoxW(0, LastErrorStrW().c_str(), L"Failed to load CAPTCHA", MB_ICONHAND);

		FreeLibrary(hcaptcha);
		return;
	}


	int rcc = RunCaptcha(&d);
	FreeLibrary(hcaptcha);
	DeleteFileA(fn.c_str());
	
	if (rcc == 0) {
		GetDlgItem(IDC_BUTTON_EXIT)->EnableWindow(1);
		appCanClose = true;
		::SendMessageW(GetSafeHwnd(), WM_CLOSE, 0, 0);
		return;
	}
	MessageBoxW(L"验证失败!", L"CAPTCHA FAILED", MB_ICONERROR);
	GetDlgItem(IDC_BUTTON_EXIT)->EnableWindow(1);
}


void CMFCHappyMachineRoomDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	if (appCanClose)

	CDialogEx::OnCancel();
}


void CMFCHappyMachineRoomDlg::OnBnClickedSplitSaveip()
{
	// TODO: 在此添加控件通知处理程序代码
	CString csz;
	GetDlgItemText(IDC_EDIT1, csz);
	wstring szval = csz.GetBuffer();
	ipList.clear();
	std::vector<wstring> ss;
	str_split(szval, L"\r\n", ss);
	for (auto& i : ss) {
		if (i.empty() || i[0] == L'\0') continue;
		ipList.push_back(i);
	}
	wstring szText = L"完成。有效数据数量：" + std::to_wstring(ipList.size());
	MessageBoxTimeoutW(GetSafeHwnd(), szText.c_str(), L"SUCCESS", MB_ICONINFORMATION, 0, 1000);
}


void CMFCHappyMachineRoomDlg::ReloadIpData()
{
	// TODO: 在此处添加实现代码.
	wstring szResult;
	for (auto& i : ipList) {
		szResult += i + L"\r\n";
	}
	SetDlgItemText(IDC_EDIT1, szResult.c_str());
}


void CMFCHappyMachineRoomDlg::OnDropdownSplitSaveip(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMBCDROPDOWN pDropDown = reinterpret_cast<LPNMBCDROPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	HMENU menu = CreatePopupMenu();
	::AppendMenuW(menu, MF_STRING, 1, L"撤销更改 (&U)");
	POINT pt{}; GetCursorPos(&pt);
	auto v = ::TrackPopupMenu(menu, TPM_NONOTIFY | TPM_RETURNCMD | TPM_RIGHTBUTTON, pt.x, pt.y, 0, GetSafeHwnd(), 0);
	if (v == 1) {
		ReloadIpData();
	}
}


CDlgAddIps* cdlgaddips;
void CMFCHappyMachineRoomDlg::OnBnClickedButtonIptool()
{
	// TODO: 在此添加控件通知处理程序代码	
	HMENU menu = CreatePopupMenu();
	::AppendMenuW(menu, MF_STRING, 1, L"本机IP");
	::AppendMenuW(menu, MF_STRING, 2, L"IP扫描");
	::AppendMenuW(menu, MF_STRING, 3, L"IP批量添加");
	::AppendMenuW(menu, MF_SEPARATOR, 0, L"");
	::AppendMenuW(menu, MF_STRING, 4, L"清除重复IP");
	::AppendMenuW(menu, MF_STRING, 5, L"清除无效IP");
	::AppendMenuW(menu, MF_STRING, 6, L"ping并清除无响应IP");
	POINT pt{}; GetCursorPos(&pt);
	auto v = ::TrackPopupMenu(menu, TPM_NONOTIFY | TPM_RETURNCMD | TPM_RIGHTBUTTON, pt.x, pt.y, 0, GetSafeHwnd(), 0);
	switch (v)
	{
	case 3:
	{
		if (cdlgaddips) {
			cdlgaddips->pwnd = this;
			cdlgaddips->ShowWindow(SW_NORMAL);
			cdlgaddips->SetForegroundWindow();
		}
		else {
			cdlgaddips = new CDlgAddIps();
			cdlgaddips->Create(IDD_DIALOG_ADDIPS);
			cdlgaddips->pwnd = this;
			WCHAR wcText[256]{};
			GetWindowTextW(wcText, 256);
			cdlgaddips->SetWindowTextW(wcText);
			::CenterWindow(cdlgaddips->GetSafeHwnd(), GetSafeHwnd());
			cdlgaddips->ShowWindow(SW_NORMAL);
		}


	}
		break;
	default:
		break;
	}
}
