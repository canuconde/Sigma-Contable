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
//(*AppHeaders
#include "SigmaContableMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SigmaContableApp);

bool SigmaContableApp::OnInit()
{
    //Inicializamos Locale
    static wxLocale locale;
    // Español Argentina
    locale.Init(wxLANGUAGE_SPANISH_ARGENTINA);



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
