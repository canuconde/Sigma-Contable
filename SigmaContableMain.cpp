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
const wxWindowID SigmaContableFrame::idMenuQuit = wxNewId();
const wxWindowID SigmaContableFrame::idMenuAbout = wxNewId();
const wxWindowID SigmaContableFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SigmaContableFrame,wxFrame)
    //(*EventTable(SigmaContableFrame)
    //*)
END_EVENT_TABLE()

SigmaContableFrame::SigmaContableFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SigmaContableFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SigmaContableFrame::OnQuit);
    Connect(idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&SigmaContableFrame::OnAbout);
    //*)
}

SigmaContableFrame::~SigmaContableFrame()
{
    //(*Destroy(SigmaContableFrame)
    //*)
}

void SigmaContableFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SigmaContableFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
