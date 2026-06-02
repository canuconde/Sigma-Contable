/***************************************************************
 * Name:      SigmaContableMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Sebastián Bergara Conde (canu.conde@gmail.com)
 * Created:   2026-05-25
 * Copyright: Sebastián Bergara Conde (https://www.youtube.com/@canuconde)
 * License:
 **************************************************************/

#include "SigmaContableMain.h"

#include <vector>
#include <wx/msgdlg.h>
#include "LibroContable.h"

//(*InternalHeaders(SigmaContableFrame)
#include <wx/artprov.h>
#include <wx/icon.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SigmaContableFrame)
const wxWindowID SigmaContableFrame::ID_BUTTON5 = wxNewId();
const wxWindowID SigmaContableFrame::ID_BUTTON1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_BUTTON2 = wxNewId();
const wxWindowID SigmaContableFrame::ID_BUTTON3 = wxNewId();
const wxWindowID SigmaContableFrame::ID_BUTTON6 = wxNewId();
const wxWindowID SigmaContableFrame::ID_BUTTON4 = wxNewId();
const wxWindowID SigmaContableFrame::ID_HYPERLINKCTRL1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_PANEL1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_NOTEBOOK1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_PANEL2 = wxNewId();
const wxWindowID SigmaContableFrame::ID_SPLITTERWINDOW1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_MENUITEM1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_MENUITEM2 = wxNewId();
const wxWindowID SigmaContableFrame::idMenuQuit = wxNewId();
const wxWindowID SigmaContableFrame::ID_MENUITEM3 = wxNewId();
const wxWindowID SigmaContableFrame::ID_MENUITEM4 = wxNewId();
const wxWindowID SigmaContableFrame::ID_MENUITEM5 = wxNewId();
const wxWindowID SigmaContableFrame::ID_MENUITEM6 = wxNewId();
const wxWindowID SigmaContableFrame::ID_MENUITEM7 = wxNewId();
const wxWindowID SigmaContableFrame::idMenuAbout = wxNewId();
const wxWindowID SigmaContableFrame::ID_STATUSBAR1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_MESSAGEDIALOG1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_TOOLBARITEM1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_TOOLBARITEM4 = wxNewId();
const wxWindowID SigmaContableFrame::ID_TOOLBARITEM2 = wxNewId();
const wxWindowID SigmaContableFrame::ID_TOOLBARITEM3 = wxNewId();
const wxWindowID SigmaContableFrame::ID_TOOLBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SigmaContableFrame,wxFrame)
    //(*EventTable(SigmaContableFrame)
    //*)
END_EVENT_TABLE()


SigmaContableFrame::SigmaContableFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SigmaContableFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("Sigma Contable v1.0"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    {
        wxIcon FrameIcon;
        FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_PLUS")),wxART_FRAME_ICON));
        SetIcon(FrameIcon);
    }
    SplitterWindow1 = new wxSplitterWindow(this, ID_SPLITTERWINDOW1, wxPoint(216,280), wxSize(10,0), wxSP_3D, _T("ID_SPLITTERWINDOW1"));
    SplitterWindow1->SetMinimumPaneSize(150);
    SplitterWindow1->SetSashGravity(0.5);
    Panel1 = new wxPanel(SplitterWindow1, ID_PANEL1, wxPoint(234,175), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Button5 = new wxButton(Panel1, ID_BUTTON5, _("Nuevo Asiento"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON5"));
    Button5->SetToolTip(_("Nuevo"));
    Button5->SetHelpText(_("Asiento"));
    BoxSizer1->Add(Button5, 1, wxALL|wxEXPAND, 5);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Libro Diario"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(Button1, 1, wxALL|wxEXPAND, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Libro Mayor"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(Button2, 1, wxALL|wxEXPAND, 5);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Plan de Cuentas"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer1->Add(Button3, 1, wxALL|wxEXPAND, 5);
    Button6 = new wxButton(Panel1, ID_BUTTON6, _("Nueva Cuenta"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON6"));
    BoxSizer1->Add(Button6, 1, wxALL|wxEXPAND, 5);
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Balance"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer1->Add(Button4, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(-1,-1,10, wxALL|wxEXPAND, 5);
    HyperlinkCtrl1 = new wxHyperlinkCtrl(Panel1, ID_HYPERLINKCTRL1, _("CanuConde@2026"), _("https://canuconde.github.io"), wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU|wxHL_ALIGN_CENTRE, _T("ID_HYPERLINKCTRL1"));
    BoxSizer1->Add(HyperlinkCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer1);
    Panel2 = new wxPanel(SplitterWindow1, ID_PANEL2, wxPoint(152,176), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Notebook1 = new wxNotebook(Panel2, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, wxNB_TOP, _T("ID_NOTEBOOK1"));
    BoxSizer2->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
    Panel2->SetSizer(BoxSizer2);
    SplitterWindow1->SplitVertically(Panel1, Panel2);
    SplitterWindow1->SetSashPosition(1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Abrir"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, ID_MENUITEM2, _("Guardar"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Salir\tAlt-F4"), _("Salir de Sigma Contable"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Archivo"));
    Menu3 = new wxMenu();
    MenuBar1->Append(Menu3, _("Editar"));
    Menu6 = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu6, ID_MENUITEM3, _("Libro Diario"), wxEmptyString, wxITEM_NORMAL);
    Menu6->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu6, ID_MENUITEM4, _("Libro Mayor"), wxEmptyString, wxITEM_NORMAL);
    Menu6->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu6, ID_MENUITEM5, _("Plan de Cuentas"), wxEmptyString, wxITEM_NORMAL);
    Menu6->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu6, ID_MENUITEM6, _("Asientos"), wxEmptyString, wxITEM_NORMAL);
    Menu6->Append(MenuItem8);
    MenuItem9 = new wxMenuItem(Menu6, ID_MENUITEM7, _("Ejercicios"), wxEmptyString, wxITEM_NORMAL);
    Menu6->Append(MenuItem9);
    MenuBar1->Append(Menu6, _("Contabilidad"));
    Menu5 = new wxMenu();
    MenuBar1->Append(Menu5, _("Reportes"));
    Menu4 = new wxMenu();
    MenuBar1->Append(Menu4, _("Herramientas"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Acerca de..\tF1"), _("Información de la versión"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Ayuda"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    MessageDialog1 = new wxMessageDialog(this, _("Sigma Contable Desarrollado por  Sebastian Bergara Conde"), _("Message"), wxOK, wxDefaultPosition);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(ID_TOOLBARITEM1, _("Nuevo Asiento"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem4 = ToolBar1->AddTool(ID_TOOLBARITEM4, _("Actualizar"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CDROM")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem2 = ToolBar1->AddTool(ID_TOOLBARITEM2, _("Buscar"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FIND")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem3 = ToolBar1->AddTool(ID_TOOLBARITEM3, _("Reportes"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_EXECUTABLE_FILE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);
    HtmlEasyPrinting1 = new wxHtmlEasyPrinting(_T("wxHtmlEasyPrinting"), this);
    Image1 = new wxImage();
    Image1_BMP = new wxBitmap();
    Center();

    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SigmaContableFrame::OnButton5Click);
    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SigmaContableFrame::OnButton1Click);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SigmaContableFrame::OnButton2Click);
    Connect(ID_BUTTON3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SigmaContableFrame::OnButton3Click);
    Connect(ID_BUTTON6, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&SigmaContableFrame::OnButton6Click);
    Connect(idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SigmaContableFrame::OnQuit);
    Connect(idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SigmaContableFrame::OnAbout);
    Connect(ID_TOOLBARITEM4, wxEVT_COMMAND_TOOL_CLICKED, (wxObjectEventFunction)&SigmaContableFrame::OnToolBarItem4Clicked);
    //*)

    ActualizarPaneles();
    //Creamos las ventanas ahora


}

SigmaContableFrame::~SigmaContableFrame()
{
    //(*Destroy(SigmaContableFrame)
    MessageDialog1->Destroy();
    //*)
}

void SigmaContableFrame::ActualizarPaneles(int col = -1){
    //Primero deberiamos eliminar todo
    Notebook1->DeleteAllPages();

    //Cargamos panel Libro Diario y lo asignamos al primer notebook
    libroDiario = new LibroDiarioPanel(Notebook1,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    Notebook1->AddPage(libroDiario,"Libro Diario",true);

    //Cargamos panel Cuentas y lo asignamos al notebook
    planCuentas = new PlanCuentasPanel(Notebook1,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    Notebook1->AddPage(planCuentas,"Plande Cuentas",true);
    //Si recibimos una columna la mostramos
    if(col >= 0){
        //Seleccionamos el primer notebook
        Notebook1->SetSelection(col);
    }else{
        //Seleccionamos el primer notebook
        Notebook1->SetSelection(0);
    }



}
void SigmaContableFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SigmaContableFrame::OnAbout(wxCommandEvent& event)
{
    //wxString msg = wxbuildinfo(long_f);
    //wxMessageBox(msg, _("Welcome to.. ."));

    this->MessageDialog1->ShowModal();
}

void SigmaContableFrame::OnButton1Click(wxCommandEvent& event)
{

}



void SigmaContableFrame::OnButton2Click(wxCommandEvent& event)
{



  //  HtmlEasyPrinting1->SetName("Mufa");
  //  HtmlEasyPrinting1->PreviewText("esto es un texto",wxEmptyString);


}

void SigmaContableFrame::OnButton3Click(wxCommandEvent& event)
{

}

void SigmaContableFrame::OnToolBarItem4Clicked(wxCommandEvent& event)
{
    //Actualizamos la BD y Regeneramos paneles
    ActualizarPaneles();
}
//Nuevo Asiento
void SigmaContableFrame::OnButton5Click(wxCommandEvent& event)
{
        wxFrame* nuevoAsiento = new NuevoAsientoFrame(this);
        nuevoAsiento->GetParent()->Enable(false);
        nuevoAsiento->Show(true);
        Notebook1->SetSelection(0);
}

void SigmaContableFrame::OnButton6Click(wxCommandEvent& event)
{
        wxFrame* nuevaCuenta = new NuevaCuentaFrame(this);
        nuevaCuenta->GetParent()->Enable(false);
        nuevaCuenta->Show(true);
        Notebook1->SetSelection(1);
}
