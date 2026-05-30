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
#include "PlanCuentasPanel.h"
#include "NuevoAsientoFrame.h"
#include "NuevaCuentaFrame.h"
//(*Headers(SigmaContableFrame)
#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/html/htmprint.h>
#include <wx/hyperlink.h>
#include <wx/image.h>
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
    LibroDiarioPanel* libroDiario;
    PlanCuentasPanel* planCuentas;
    LibroContable* lContable;

    void ActualizarPaneles(int col = -1);
private:

    //(*Handlers(SigmaContableFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnButton2Click(wxCommandEvent& event);
    void OnButton3Click(wxCommandEvent& event);
    void OnToolBarItem4Clicked(wxCommandEvent& event);
    void OnButton5Click(wxCommandEvent& event);
    void OnButton6Click(wxCommandEvent& event);
    //*)

    //(*Identifiers(SigmaContableFrame)
    static const wxWindowID ID_BUTTON5;
    static const wxWindowID ID_BUTTON1;
    static const wxWindowID ID_BUTTON2;
    static const wxWindowID ID_BUTTON3;
    static const wxWindowID ID_BUTTON6;
    static const wxWindowID ID_BUTTON4;
    static const wxWindowID ID_HYPERLINKCTRL1;
    static const wxWindowID ID_PANEL1;
    static const wxWindowID ID_NOTEBOOK1;
    static const wxWindowID ID_PANEL2;
    static const wxWindowID ID_SPLITTERWINDOW1;
    static const wxWindowID ID_MENUITEM1;
    static const wxWindowID ID_MENUITEM2;
    static const wxWindowID idMenuQuit;
    static const wxWindowID ID_MENUITEM3;
    static const wxWindowID ID_MENUITEM4;
    static const wxWindowID ID_MENUITEM5;
    static const wxWindowID ID_MENUITEM6;
    static const wxWindowID ID_MENUITEM7;
    static const wxWindowID idMenuAbout;
    static const wxWindowID ID_STATUSBAR1;
    static const wxWindowID ID_MESSAGEDIALOG1;
    static const wxWindowID ID_TOOLBARITEM1;
    static const wxWindowID ID_TOOLBARITEM4;
    static const wxWindowID ID_TOOLBARITEM2;
    static const wxWindowID ID_TOOLBARITEM3;
    static const wxWindowID ID_TOOLBAR1;
    //*)

    //(*Declarations(SigmaContableFrame)
    wxBitmap              *Image1_BMP;
    wxButton* Button1;
    wxButton* Button2;
    wxButton* Button3;
    wxButton* Button4;
    wxButton* Button5;
    wxButton* Button6;
    wxHtmlEasyPrinting* HtmlEasyPrinting1;
    wxHyperlinkCtrl* HyperlinkCtrl1;
    wxImage               *Image1;
    wxMenu* Menu3;
    wxMenu* Menu4;
    wxMenu* Menu5;
    wxMenu* Menu6;
    wxMenuItem* MenuItem3;
    wxMenuItem* MenuItem4;
    wxMenuItem* MenuItem5;
    wxMenuItem* MenuItem6;
    wxMenuItem* MenuItem7;
    wxMenuItem* MenuItem8;
    wxMenuItem* MenuItem9;
    wxMessageDialog* MessageDialog1;
    wxNotebook* Notebook1;
    wxPanel* Panel1;
    wxPanel* Panel2;
    wxSplitterWindow* SplitterWindow1;
    wxStatusBar* StatusBar1;
    wxToolBar* ToolBar1;
    wxToolBarToolBase* ToolBarItem1;
    wxToolBarToolBase* ToolBarItem2;
    wxToolBarToolBase* ToolBarItem3;
    wxToolBarToolBase* ToolBarItem4;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // SIGMACONTABLEMAIN_H
