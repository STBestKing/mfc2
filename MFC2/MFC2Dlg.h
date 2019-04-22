
// MFC2Dlg.h: 头文件
//

#pragma once


// CMFC2Dlg 对话框
class CMFC2Dlg : public CDialogEx
{
// 构造
public:
	CMFC2Dlg(CWnd* pParent = nullptr);	// 标准构造函数
	int m_Listid;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CListBox m_ListCon;
	afx_msg void SELCHANGE();
	afx_msg void OnBnClickedDel();
	CString m_Name;
	CString m_Sid;
	CString m_Value;
	afx_msg void OnBnClickedShow();
	afx_msg void SHOWSCORE();
	afx_msg void DELETESCORE();
	afx_msg void OnLbnDblclkList1();
};
