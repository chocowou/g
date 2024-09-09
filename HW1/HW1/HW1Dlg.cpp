
// HW1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "HW1.h"
#include "HW1Dlg.h"
#include "afxdialogex.h"
#include "time.h""
#include "stdlib.h"


#ifdef _DEBUG
#define new DEBUG_NEW
//#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
#define COLOR_RED   RGB(0xff, 0x00, 0x00)
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CHW1Dlg 대화 상자



CHW1Dlg::CHW1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HW1_DIALOG, pParent)

	, x1(0)
	, y1(0)
	, x2(0)
	, y2(0)
	, Center_point(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHW1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, x1);
	DDX_Text(pDX, IDC_EDIT2, y1);
	DDX_Text(pDX, IDC_EDIT3, x2);
	DDX_Text(pDX, IDC_EDIT4, y2);
}

BEGIN_MESSAGE_MAP(CHW1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CHW1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON3, &CHW1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CHW1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CHW1Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CHW1Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CHW1Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CHW1Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CHW1Dlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CHW1Dlg 메시지 처리기

BOOL CHW1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CHW1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CHW1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CHW1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHW1Dlg::OnEnChangeEdit1()
{

}


void CHW1Dlg::OnEnChangeEdit2()
{

}


void CHW1Dlg::OnEnChangeEdit3()
{

}


void CHW1Dlg::OnEnChangeEdit4()
{

}


void CHW1Dlg::OnEnChangeEdit5()
{

}



void CHW1Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	if (m_image != NULL) {
		m_image.Destroy();
	}
	srand((unsigned int)time(NULL));
	nRandNum = rand() % 30 + 5;
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;
	m_image.Create(nWidth, -nHeight, nBpp);

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = i;
			rgb[i].rgbGreen = 0;
			rgb[i].rgbBlue = 0;
		}
		rgb[0xff].rgbGreen = 0xff; rgb[0xff].rgbBlue = 0xff;
		m_image.SetColorTable(0, 256, rgb);
	}
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	memset(fm, 0xff, nWidth * nHeight);

	int x = x1, y = y1;
	drawCircle(fm, x, y, nRandNum, 0);
	UpdateDisplay();
	
}


void CHW1Dlg::OnBnClickedButton2()
{
	int ver = 0;
	CString g_strFileImage;
	CString str_ver;
	TCHAR path[256] = { 0, };
	GetModuleFileName(NULL, path, 256);
	CString folderPath(path);
	folderPath = folderPath.Left(folderPath.ReverseFind('\\'));
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	//연속 그리기
	int a = x1, b = y1, c = x2, d = y2;
	int dx = (c - a) / 5, dy = (d - b) / 5;
	int next_x = a + dx * ver, next_y = b + dx * ver;
	for (; ver <= 4; ver++) {
		g_strFileImage.Format(_T("%s\\circleImage_%d.bmp"), folderPath, ver);
		m_image.Save(g_strFileImage);
		moveCircle(a, b, a + dx, b + dy);
		a += dx; b += dy;
		Sleep(1000);
		
	}
	moveCircle(a, b, c, d);
	g_strFileImage.Format(_T("%s\\circleImage_%d.bmp"), folderPath, ver);	
	m_image.Save(g_strFileImage);
}

#include <iostream>
void CHW1Dlg::OnBnClickedButton3()
{
	if (m_image != NULL) {
		m_image.Destroy();
	}

	//image load 
	CString Filename;
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, Filename);

	if (dlg.DoModal() == IDOK){
			CString strPathName = dlg.GetPathName();
			m_image.Load(strPathName);
	}
	UpdateDisplay();
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nHeight = 480; int nWidth = 640;
	int tarX = 0, tarY = 0, tarR = 0, max = 0;
	int count = -1,ya;
	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (fm[j * nPitch + i] == 0) {
				if (count == -1)ya = j;
				count++; break;}
		}
	}
	tarR = count / 2; tarY = ya + tarR;
	for (int i = 0; i < nWidth; i++)
		if (fm[tarY * nPitch + i] == 0) {
			tarX = i + tarR; break;
		}
	drawX(fm, tarX, tarY, 250);
	CString center;
	center.Format(_T("( %d , %d )"), tarX, tarY);
	SetDlgItemText(IDC_STATIC_result, center);
	UpdateData(false);
}

void CHW1Dlg::UpdateDisplay() {
	CClientDC dc(this);
	m_image.Draw(dc, 0, 120);
}

void CHW1Dlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray) {
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + 2 * nRadius; j++) {
		for (int i = x; i < x + 2 * nRadius; i++) {
			if(isInCircle(i,j,nCenterX,nCenterY,nRadius))
				fm[j * nPitch + i] = nGray;
		}
	}
}
void CHW1Dlg::drawX(unsigned char* fm, int x, int y, int nGray) {
	int nPitch = m_image.GetPitch();
	static RGBQUAD rgb[256];
	//for (int i = 0; i < 256; i++)
	//	rgb[i].rgbRed = i;// rgb[i].rgbGreen = rgb[i].rgbBlue = i;
	//m_image.SetColorTable(0, 256, rgb);
	int color = nGray;
	/*fm[(y - 2) * nPitch + (x - 2)] = color;
	fm[(y - 1) * nPitch + (x - 1)] = color;
	fm[(y - 0) * nPitch + (x - 0)] = color;
	fm[(y - 1) * nPitch + (x + 1)] = color;
	fm[(y - 2) * nPitch + (x + 2)] = color;
	fm[(y + 1) * nPitch + (x - 1)] = color;
	fm[(y + 2) * nPitch + (x - 2)] = color;
	fm[(y + 1) * nPitch + (x + 1)] = color;
	fm[(y + 2) * nPitch + (x + 2)] = color;*/
	m_image.SetPixel(x, y, color);
	m_image.SetPixel(x - 1, y - 1, color);
	m_image.SetPixel(x - 2, y - 2, color);
	m_image.SetPixel(x + 1, y - 1, color);
	m_image.SetPixel(x + 2, y - 2, color);
	m_image.SetPixel(x - 1, y + 1, color);
	m_image.SetPixel(x - 2, y + 2, color);
	m_image.SetPixel(x + 1, y + 1, color);
	m_image.SetPixel(x + 2, y + 2, color);
	
	UpdateDisplay();
}

bool CHW1Dlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius) {
	bool bRet = false;
	double dx = i - nCenterX;
	double dy = j - nCenterY;
	double dDist = dx * dx + dy * dy;
	if (nRadius * nRadius > dDist)
		bRet = true;
	return bRet;
}

void CHW1Dlg::moveCircle(int x1, int y1, int x2, int y2)
{
	int nGray = 0;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = nRandNum;
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	//memset(fm, 0xff, nWidth*nHeight);
	drawCircle(fm, x1, y1, nRadius, 0xff);
	drawCircle(fm, x2, y2, nRadius, nGray);

	UpdateDisplay();
	//CString strFile;
	//strFile.Format(_T("C:\\image\\image%d.jpg"), nSttX);
	//m_image.Save(strFile);
}
