/***************************************************************
 * Name:      SigmaContableApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Sebastián Bergara Conde (canu.conde@gmail.com)
 * Created:   2026-05-25
 * Copyright: Sebastián Bergara Conde (https://www.youtube.com/@canuconde)
 * License:
 **************************************************************/

#include "SigmaContableApp.h"

//(*AppHeaders
#include "SigmaContableMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SigmaContableApp);

bool SigmaContableApp::OnInit()
{
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
