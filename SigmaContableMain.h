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

//(*Headers(SigmaContableFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
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

private:

    //(*Handlers(SigmaContableFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    //*)

    //(*Identifiers(SigmaContableFrame)
    static const wxWindowID idMenuQuit;
    static const wxWindowID idMenuAbout;
    static const wxWindowID ID_STATUSBAR1;
    //*)

    //(*Declarations(SigmaContableFrame)
    wxStatusBar* StatusBar1;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // SIGMACONTABLEMAIN_H
