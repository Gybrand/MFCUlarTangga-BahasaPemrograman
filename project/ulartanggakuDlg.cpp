
// Nama : Fikli Al Fa'iq Gyonanda
// NRP	: 3220600039
// ulartanggakuDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ulartanggaku.h"
#include "ulartanggakuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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

// CulartanggakuDlg dialog

CulartanggakuDlg::CulartanggakuDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECT_DIALOG, pParent)
	, m_display(_T("0"))
	, m_display2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

void CulartanggakuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_BUTTON1, m_tampil);
	DDX_Text(pDX, IDC_EDIT1, m_display);
	DDX_Text(pDX, IDC_EDIT2, m_display2);
	DDX_Control(pDX, IDC_BUTTON2, m_acak);
	DDX_Control(pDX, IDC_BUTTON3, m_acak2);
}

BEGIN_MESSAGE_MAP(CulartanggakuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CulartanggakuDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CulartanggakuDlg::OnBnClickedAcak)
	ON_BN_CLICKED(IDC_BUTTON3, &CulartanggakuDlg::OnBnClickedAcak2)
END_MESSAGE_MAP()

// CulartanggakuDlg message handlers

BOOL CulartanggakuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	UpdateData(TRUE);
	m_acak.EnableWindow(FALSE);
	m_acak2.EnableWindow(FALSE);
	//Membuat Pion Pertama
	x1 = 0;
	y1 = 240;
	x2 = 40;
	y2 = 280;
	pDCLingkaran = m_pic.GetDC();
	CDC dcMempiont;

	//Membuat Pion Kedua
	x3 = 0;
	y3 = 240;
	x4 = 40;
	y4 = 280;
	pDCLingkaran2 = m_pic.GetDC();
	CDC dcMemPiont2;

	//Membuat rectangle
	pDCRectangle = m_pic.GetDC();
	CDC dcMemRec;
	UpdateData(FALSE);
	return TRUE; 
}

void CulartanggakuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CulartanggakuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CulartanggakuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CulartanggakuDlg::OnBnClickedButton1()
{
	//Disable Tombol Play
	m_tampil.EnableWindow(FALSE);

	//Enable Tombol Pemain
	m_acak.EnableWindow(TRUE);
	m_acak2.EnableWindow(TRUE);

	// TODO: Add your control notification handler code here
	CDC* pDC = m_pic.GetDC();
	CDC dcMem;
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255)); //Warna Background
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->Rectangle(4, 4, 280, 280);

	CDC* pDC1 = m_pic.GetDC();
	CDC dcMem1;
	CPen pen1(PS_SOLID, 2, RGB(0, 0, 0)); //Warna Garis
	CPen* pOldPen1 = pDC1->SelectObject(&pen1);

	//Garis Vertikal
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(0, 280);
	pDC1->MoveTo(40, 0);
	pDC1->LineTo(40, 280);
	pDC1->MoveTo(80, 0);
	pDC1->LineTo(80, 280);
	pDC1->MoveTo(120, 0);
	pDC1->LineTo(120, 280);
	pDC1->MoveTo(160, 0);
	pDC1->LineTo(160, 280);
	pDC1->MoveTo(200, 0);
	pDC1->LineTo(200, 280);
	pDC1->MoveTo(240, 0);
	pDC1->LineTo(240, 280);
	pDC1->MoveTo(280, 0);
	pDC1->LineTo(280, 280);

	//Garis Horizontal
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(280, 0);
	pDC1->MoveTo(0, 40);
	pDC1->LineTo(280, 40);
	pDC1->MoveTo(0, 80);
	pDC1->LineTo(280, 80);
	pDC1->MoveTo(0, 120);
	pDC1->LineTo(280, 120);
	pDC1->MoveTo(0, 160);
	pDC1->LineTo(280, 160);
	pDC1->MoveTo(0, 200);
	pDC1->LineTo(280, 200);
	pDC1->MoveTo(0, 240);
	pDC1->LineTo(280, 240);
	pDC1->MoveTo(0, 280);
	pDC1->LineTo(280, 280);

	//Tampilan Pion 1
	CPen penpiont(PS_SOLID, 4, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran -> SelectObject(&penpiont);
	pDCLingkaran ->Ellipse(x1, y1, x2, y2);

	//Tampilan Pion 2
	CPen penpiont2(PS_SOLID, 4, RGB(0, 0, 255)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);

	//Tampilan Ular
	CDC* pDC2 = m_pic.GetDC();
	CDC dcMem2;
	CPen pen2(PS_SOLID, 10, RGB(255, 0, 0)); //Warna Garis
	CPen* pOldPen2 = pDC2->SelectObject(&pen2);

	//Membuat Ular
	pDC2->Ellipse(95, 145, 110, 130);
	pDC2->MoveTo(100, 150);
	pDC2->LineTo(60, 230);

	pDC2->Ellipse(215, 30, 230, 15);
	pDC2->MoveTo(220, 30);
	pDC2->LineTo(180, 70);

	pDC2->Ellipse(255, 190, 270, 175);
	pDC2->MoveTo(260, 190);
	pDC2->LineTo(220, 270);

	//Tampilan Tangga
	CDC* pDC3 = m_pic.GetDC();
	CDC dcMem3;
	CPen pen3(PS_SOLID, 4, RGB(157, 110, 254)); //Warna Garis
	CPen* pOldPen3 = pDC3->SelectObject(&pen3);

	//Membuat Tangga 1
	pDC3->MoveTo(170, 250);
	pDC3->LineTo(170, 150);
	pDC3->MoveTo(190, 250);
	pDC3->LineTo(190, 150);

	pDC3->MoveTo(170, 170);
	pDC3->LineTo(190, 170);
	pDC3->MoveTo(170, 190);
	pDC3->LineTo(190, 190);
	pDC3->MoveTo(170, 210);
	pDC3->LineTo(190, 210);
	pDC3->MoveTo(170, 230);
	pDC3->LineTo(190, 230);

	//Membuat Tangga 2
	pDC3->MoveTo(210, 150);
	pDC3->LineTo(210, 70);
	pDC3->MoveTo(230, 150);
	pDC3->LineTo(230, 60);

	pDC3->MoveTo(230, 82);
	pDC3->LineTo(210, 82);
	pDC3->MoveTo(230, 102);
	pDC3->LineTo(210, 102);
	pDC3->MoveTo(230, 130);
	pDC3->LineTo(210, 130);
}

void CulartanggakuDlg::OnBnClickedAcak()
{
	// TODO: Add your control notification handler code here
	int random = 0;
	srand(time(0));
	random = rand() % 6 + 1;
	m_display.Format(_T("%d"), random);
	CPen penrec(PS_SOLID, 2, RGB(0, 0, 0));
	CPen* pOldePenrectangle = pDCRectangle->SelectObject(&penrec);
	pDCRectangle->Rectangle(x1, y1, x2, y2);
	geser(random);
	Tangga();
	Ular();
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);
	reset();
	if (x1 == 240 && x2 == 280 && y1 == 0 && y2 == 40) {
		UpdateData(TRUE);
		m_acak.EnableWindow(FALSE);
	}
	UpdateData(FALSE);
}

void CulartanggakuDlg::OnBnClickedAcak2()
{
	// TODO: Add your control notification handler code here
	int random = 0;
	srand(time(0));
	random = rand() % 6 + 1;
	m_display2.Format(_T("%d"), random);
	CPen penrec(PS_SOLID, 0, RGB(0, 0, 0));
	CPen* pOldePenrectangle = pDCRectangle->SelectObject(&penrec);
	pDCRectangle->Rectangle(x3, y3, x4, y4);
	geser2(random);
	Tangga2();
	Ular2();
	CPen penpiont2(PS_SOLID, 5, RGB(0, 0, 255)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);
	reset();
	if (x3 == 240 && x4 == 280 && y3 == 0 && y4 == 40) {
		UpdateData(TRUE);
		m_acak2.EnableWindow(FALSE);
	}
	UpdateData(FALSE);
}

void CulartanggakuDlg::geser(int x)
{
	// TODO: Add your implementation code here.
	if (y1 == 240 && y2 == 280) {
		while (x) {
			if (x1 != 240 && x != 280) {

				x1 += 40;
				x2 += 40;
				x--;


			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 200 && y2 == 240) {
		while (x) {
			if (x1 != 0 && x != 40) {

				x1 -= 40;
				x2 -= 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 160 && y2 == 200) {
		while (x) {
			if (x1 != 240 && x != 280) {

				x1 += 40;
				x2 += 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 120 && y2 == 160) {
		while (x) {
			if (x1 != 0 && x != 40) {

				x1 -= 40;
				x2 -= 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 80 && y2 == 120) {
		while (x) {
			if (x1 != 240 && x != 280) {

				x1 += 40;
				x2 += 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 40 && y2 == 80) {
		while (x) {
			if (x1 != 0 && x != 40) {

				x1 -= 40;
				x2 -= 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 0 && y2 == 40) {
		while (x) {
			if (x1 != 240 && x != 280) {

				x1 += 40;
				x2 += 40;
				x--;

			}
			else {
				x1 = 240;
				x2 = 280;
				y1 = 0;
				y2 = 40;
				break;
			}
		}
	}
}
void CulartanggakuDlg::Tangga()
{
	// TODO: Add your implementation code here.
	if (x1 == 160 && y1 == 240 && x2 == 200 && y2 == 280) {
		y1 = 120;
		y2 = 160;
		x1 = 160;
		x2 = 200;
	}
	else if (x1 == 200 && y1 == 120 && x2 == 240 && y2 == 160) {
		y1 = 40;
		y2 = 80;
		x1 = 40;
		x2 = 80;
	}
}

void CulartanggakuDlg::Ular() {
	if (x1 == 80 && y1 == 120 && x2 == 120 && y2 == 160) {
		y1 = 200;
		y2 = 240;
		x1 = 40;
		x2 = 80;
	}
	else if (x1 == 200 && y1 == 0 && x2 == 240 && y2 == 40) {
		y1 = 40;
		y2 = 80;
		x1 = 160;
		x2 = 200;
	}
	else if (x1 == 160 && y1 == 240 && x2 == 200 && y2 == 280) {
		y1 = 240;
		y2 = 280;
		x1 = 200;
		x2 = 240;
	}
}


int CulartanggakuDlg::Tangga2()
{
	// TODO: Add your implementation code here.
	if (x3 == 160 && y3 == 240 && x4 == 200 && y4 == 280) {
		x3 = 120;
		x4 = 160;
		y3 = 120;
		y4 = 160;
	}
	else if (x3 == 200 && y3 == 120 && x4 == 240 && y4 == 160) {
		x3 = 200;
		x4 = 240;
		y3 = 40;
		y4 = 80;
	}
	return 0;
}

int CulartanggakuDlg::Ular2() {
	if (x3 == 80 && y3 == 120 && x4 == 120 && y4 == 160) {
		y3 = 200;
		y4 = 240;
		x3 = 40;
		x4 = 80;
	}
	else if (x3 == 200 && y3 == 0 && x4 == 240 && y4 == 40) {
		y3 = 40;
		y4 = 80;
		x3 = 160;
		x4 = 200;
	}
	else if (x3 == 160 && y3 == 240 && x4 == 200 && y4 == 280) {
		y3 = 240;
		y4 = 280;
		x3 = 200;
		x4 = 240;
	}
	return 0;
}
void CulartanggakuDlg::reset() {
	
	// TODO: Add your control notification handler code here
	CDC* pDC = m_pic.GetDC();
	CDC dcMem;
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255)); //warna background
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->Rectangle(4, 4, 280, 280);

	CDC* pDC1 = m_pic.GetDC();
	CDC dcMem1;
	CPen pen1(PS_SOLID, 2, RGB(0, 0, 0)); //warna Garis
	CPen* pOldPen1 = pDC1->SelectObject(&pen1);

	//Garis Vertikal
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(0, 280);
	pDC1->MoveTo(40, 0);
	pDC1->LineTo(40, 280);
	pDC1->MoveTo(80, 0);
	pDC1->LineTo(80, 280);
	pDC1->MoveTo(120, 0);
	pDC1->LineTo(120, 280);
	pDC1->MoveTo(160, 0);
	pDC1->LineTo(160, 280);
	pDC1->MoveTo(200, 0);
	pDC1->LineTo(200, 280);
	pDC1->MoveTo(240, 0);
	pDC1->LineTo(240, 280);
	pDC1->MoveTo(280, 0);
	pDC1->LineTo(280, 280);

	//Garis Horizontal
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(280, 0);
	pDC1->MoveTo(0, 40);
	pDC1->LineTo(280, 40);
	pDC1->MoveTo(0, 80);
	pDC1->LineTo(280, 80);
	pDC1->MoveTo(0, 120);
	pDC1->LineTo(280, 120);
	pDC1->MoveTo(0, 160);
	pDC1->LineTo(280, 160);
	pDC1->MoveTo(0, 200);
	pDC1->LineTo(280, 200);
	pDC1->MoveTo(0, 240);
	pDC1->LineTo(280, 240);
	pDC1->MoveTo(0, 280);
	pDC1->LineTo(280, 280);

	//Tampilan Pion 1
	CPen penpiont(PS_SOLID, 4, RGB(255, 0, 0)); //warna garis pion 1
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);

	//Tampilan Pion 2
	CPen penpiont2(PS_SOLID, 4, RGB(0, 0, 255)); //warna garis pion 2
	CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);

	//Tampilan Ular
	CDC* pDC2 = m_pic.GetDC();
	CDC dcMem2;
	CPen pen2(PS_SOLID, 10, RGB(255, 0, 0)); //Warna Garis
	CPen* pOldPen2 = pDC2->SelectObject(&pen2);

	//Membuat Ular
	pDC2->Ellipse(95, 145, 110, 130);
	pDC2->MoveTo(100, 150);
	pDC2->LineTo(60, 230);

	pDC2->Ellipse(215, 30, 230, 15);
	pDC2->MoveTo(220, 30);
	pDC2->LineTo(180, 70);

	pDC2->Ellipse(255, 190, 270, 175);
	pDC2->MoveTo(260, 190);
	pDC2->LineTo(220, 270);

	//Tampilan Tangga
	CDC* pDC3 = m_pic.GetDC();
	CDC dcMem3;
	CPen pen3(PS_SOLID, 4, RGB(157, 110, 254)); //warna garis
	CPen* pOldPen3 = pDC3->SelectObject(&pen3);

	//Membuat Tangga 1
	pDC3->MoveTo(170, 250);
	pDC3->LineTo(170, 150);
	pDC3->MoveTo(190, 250);
	pDC3->LineTo(190, 150);

	pDC3->MoveTo(170, 170);
	pDC3->LineTo(190, 170);
	pDC3->MoveTo(170, 190);
	pDC3->LineTo(190, 190);
	pDC3->MoveTo(170, 210);
	pDC3->LineTo(190, 210);
	pDC3->MoveTo(170, 230);
	pDC3->LineTo(190, 230);

	//Membuat Tangga 2
	pDC3->MoveTo(210, 150);
	pDC3->LineTo(210, 70);
	pDC3->MoveTo(230, 150);
	pDC3->LineTo(230, 60);

	pDC3->MoveTo(230, 82);
	pDC3->LineTo(210, 82);
	pDC3->MoveTo(230, 102);
	pDC3->LineTo(210, 102);
	pDC3->MoveTo(230, 130);
	pDC3->LineTo(210, 130);
}

void CulartanggakuDlg::geser2(int x12)
{
	// TODO: Add your implementation code here.
	if (y3 == 240 && y4 == 280) {
		while (x12) {
			if (x3 != 240 && x4 != 280) {

				x3 += 40;
				x4 += 40;
				x12--;
			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 200 && y4 == 240) {
		while (x12) {
			if (x3 != 0 && x4 != 40) {
				x3 -= 40;
				x4 -= 40;
				x12--;

			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 160 && y4 == 200) {
		while (x12) {
			if (x3 != 240 && x4 != 280) {

				x3 += 40;
				x4 += 40;
				x12--;
			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 120 && y4 == 160) {
		while (x12) {
			if (x3 != 0 && x4 != 40) {

				x3 -= 40;
				x4 -= 40;
				x12--;
			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 80 && y4 == 120) {
		while (x12) {
			if (x3 != 240 && x4 != 280) {

				x3 += 40;
				x4 += 40;
				x12--;
			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 40 && y4 == 80) {
		while (x12) {
			if (x3 != 0 && x4 != 40) {

				x3 -= 40;
				x4 -= 40;
				x12--;

			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 0 && y4 == 40) {
		while (x12) {
			if (x3 != 240 && x4 != 280) {

				x3 += 40;
				x4 += 40;
				x12--;
			}
			else {
				x3 = 240;
				x4 = 280;
				y3 = 0;
				y4 = 40;
				break;
			}
		}
	}

}