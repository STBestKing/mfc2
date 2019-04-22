
// MFC2Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC2.h"
#include "MFC2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC2Dlg 对话框


CMFC2Dlg::CMFC2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC2_DIALOG, pParent)
	, m_Name(_T(""))
	, m_Sid(_T(""))
	, m_Value(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCon);
	DDX_Text(pDX, NAME, m_Name);
	DDX_Text(pDX, UID, m_Sid);
	DDX_Text(pDX, SCORE, m_Value);
}

BEGIN_MESSAGE_MAP(CMFC2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFC2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFC2Dlg::OnBnClickedCancel)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFC2Dlg::SELCHANGE)
	ON_BN_CLICKED(DEL, &CMFC2Dlg::OnBnClickedDel)
	ON_BN_CLICKED(SHOW, &CMFC2Dlg::OnBnClickedShow)
	ON_COMMAND(ID_32772, &CMFC2Dlg::SHOWSCORE)
	ON_COMMAND(ID_32773, &CMFC2Dlg::DELETESCORE)
	ON_LBN_DBLCLK(IDC_LIST1, &CMFC2Dlg::OnLbnDblclkList1)
END_MESSAGE_MAP()


// CMFC2Dlg 消息处理程序

BOOL CMFC2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC2Dlg::OnPaint()
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
HCURSOR CMFC2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	UpdateData();
	CString str = CString("姓名：") + this->m_Name + CString("学号：") + this->m_Sid + CString("成绩：") + this->m_Value;
	this->m_ListCon.AddString(str);
}


void CMFC2Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMFC2Dlg::SELCHANGE()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Listid = this->m_ListCon.GetCurSel();
}


void CMFC2Dlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
	this->m_ListCon.DeleteString(this->m_Listid);
}


void CMFC2Dlg::OnBnClickedShow()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	this->m_ListCon.GetText(this->m_Listid, str);
	str = str.Right(str.GetLength() - str.Find(CString("成绩"), 0));
	MessageBox(str, CString("显示成绩"));
}


void CMFC2Dlg::SHOWSCORE()
{
	// TODO: 在此添加命令处理程序代码
	CString str;
	this->m_ListCon.GetText(this->m_Listid, str);
	str = str.Right(str.GetLength() - str.Find(CString("成绩"), 0));
	MessageBox(str, CString("显示成绩"));
}


void CMFC2Dlg::DELETESCORE()
{
	// TODO: 在此添加命令处理程序代码
	this->m_ListCon.DeleteString(this->m_Listid);
}


void CMFC2Dlg::OnLbnDblclkList1()  //双击弹出菜单
{
	// TODO: 在此添加控件通知处理程序代码
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pContextMenu = menu.GetSubMenu(0);
	CPoint point;
	GetCursorPos(&point);
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
}
