/***************************************************************
 * Name:      SigmaContableMain.h
 * Purpose:   Defines Application Frame
 * Author:    Sebastián Bergara Conde (canu.conde@gmail.com)
 * Created:   2026-05-25
 * Copyright: Sebastián Bergara Conde (https://www.youtube.com/@canuconde)
 * License:
 **************************************************************/

#ifndef SIGMACONTABLEMAIN_H
#define SIGMACONTABLEMAIN_H
#include "LibroDiarioPanel.h"
//(*Headers(SigmaContableFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/html/htmprint.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
//*)
/** \brief no sabemos nada
 *
 * \param algo que hace alguna cosa
 * \param
 * \return no retorna nada
 *
 */

class SigmaContableFrame: public wxFrame
{
public:

    SigmaContableFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~SigmaContableFrame();
    LibroDiarioPanel* libro;

private:

    //(*Handlers(SigmaContableFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnButton2Click(wxCommandEvent& event);
    //*)

    //(*Identifiers(SigmaContableFrame)
    static const wxWindowID ID_BUTTON1;
    static const wxWindowID ID_BUTTON2;
    static const wxWindowID ID_PANEL1;
    static const wxWindowID ID_NOTEBOOK1;
    static const wxWindowID ID_PANEL2;
    static const wxWindowID ID_SPLITTERWINDOW1;
    static const wxWindowID idMenuQuit;
    static const wxWindowID idMenuAbout;
    static const wxWindowID ID_STATUSBAR1;
    static const wxWindowID ID_MESSAGEDIALOG1;
    static const wxWindowID ID_TOOLBARITEM1;
    static const wxWindowID ID_TOOLBAR1;
    //*)

    //(*Declarations(SigmaContableFrame)
    wxButton* Button1;
    wxButton* Button2;
    wxHtmlEasyPrinting* HtmlEasyPrinting1;
    wxMenu* Menu3;
    wxMenu* Menu4;
    wxMenu* Menu5;
    wxMessageDialog* MessageDialog1;
    wxNotebook* Notebook1;
    wxPanel* Panel1;
    wxPanel* Panel2;
    wxSplitterWindow* SplitterWindow1;
    wxStatusBar* StatusBar1;
    wxToolBar* ToolBar1;
    wxToolBarToolBase* ToolBarItem1;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // SIGMACONTABLEMAIN_H
