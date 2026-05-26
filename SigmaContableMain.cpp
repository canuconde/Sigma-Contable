/***************************************************************
 * Name:      SigmaContableMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Sebastián Bergara Conde (canu.conde@gmail.com)
 * Created:   2026-05-25
 * Copyright: Sebastián Bergara Conde (https://www.youtube.com/@canuconde)
 * License:
 **************************************************************/

#include "SigmaContableMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(SigmaContableFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
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
const wxWindowID SigmaContableFrame::ID_BUTTON1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_BUTTON2 = wxNewId();
const wxWindowID SigmaContableFrame::ID_PANEL1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_NOTEBOOK1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_PANEL2 = wxNewId();
const wxWindowID SigmaContableFrame::ID_SPLITTERWINDOW1 = wxNewId();
const wxWindowID SigmaContableFrame::idMenuQuit = wxNewId();
const wxWindowID SigmaContableFrame::idMenuAbout = wxNewId();
const wxWindowID SigmaContableFrame::ID_STATUSBAR1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_MESSAGEDIALOG1 = wxNewId();
const wxWindowID SigmaContableFrame::ID_TOOLBARITEM1 = wxNewId();
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
    SetClientSize(wxSize(800,600));
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
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(Button1, 1, wxALL|wxEXPAND, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer1->Add(Button2, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(0,0,10, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    Panel2 = new wxPanel(SplitterWindow1, ID_PANEL2, wxPoint(152,176), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Notebook1 = new wxNotebook(Panel2, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    BoxSizer2->Add(Notebook1, 1, wxALL|wxEXPAND, 5);
    Panel2->SetSizer(BoxSizer2);
    SplitterWindow1->SplitVertically(Panel1, Panel2);
    SplitterWindow1->SetSashPosition(1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Salir\tAlt-F4"), _("Salir de Sigma Contable"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Archivo"));
    Menu3 = new wxMenu();
    MenuBar1->Append(Menu3, _("Editar"));
    Menu4 = new wxMenu();
    MenuBar1->Append(Menu4, _("Herramientas"));
    Menu5 = new wxMenu();
    MenuBar1->Append(Menu5, _("Ayuda"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Acerca de..\tF1"), _("Información de la versión"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    MessageDialog1 = new wxMessageDialog(this, _("Sigma Contable Desarrollado por  Sebastian Bergara Conde"), _("Message"), wxOK, wxDefaultPosition);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(ID_TOOLBARITEM1, _("Nuevo"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);

    Connect(idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SigmaContableFrame::OnQuit);
    Connect(idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SigmaContableFrame::OnAbout);
    //*)
}

SigmaContableFrame::~SigmaContableFrame()
{
    //(*Destroy(SigmaContableFrame)
    MessageDialog1->Destroy();
    //*)
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
