/***************************************************************
 * Name:      SigmaContableApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Sebastián Bergara Conde (canu.conde@gmail.com)
 * Created:   2026-05-25
 * Copyright: Sebastián Bergara Conde (https://www.youtube.com/@canuconde)
 * License:
 **************************************************************/

#include "SigmaContableApp.h"
#include "LibroContable.h"
#include <wx/splash.h>
#include <string>
//(*AppHeaders
#include "SigmaContableMain.h"
#include <wx/image.h>
//*)

//ver SigmaContableApp.h
wxIMPLEMENT_APP(SigmaContableApp);

bool SigmaContableApp::OnInit()
{
    //Inicializamos Locale
    static wxLocale locale;
    // Español Argentina
    locale.Init(wxLANGUAGE_SPANISH_ARGENTINA);
    wxBitmap bitmap;
    if (bitmap.LoadFile("SigmaContable.png", wxBITMAP_TYPE_PNG))
    {
        wxSplashScreen* splash = new wxSplashScreen(bitmap,
            wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
            3000, NULL, -1, wxDefaultPosition, wxDefaultSize,
            wxFRAME_NO_TASKBAR |
            wxSTAY_ON_TOP |
            wxBORDER_NONE);
    }
    wxYield();
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        SigmaContableFrame* Frame = new SigmaContableFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
