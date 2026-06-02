/***************************************************************
 * Name:      SigmaContableApp.h
 * Purpose:   Defines Application Class
 * Author:    Sebastián Bergara Conde (canu.conde@gmail.com)
 * Created:   2026-05-25
 * Copyright: Sebastián Bergara Conde (https://www.youtube.com/@canuconde)
 * License:
 **************************************************************/

#ifndef SIGMACONTABLEAPP_H
#define SIGMACONTABLEAPP_H
#include "LibroContable.h"
#include <wx/app.h>


class SigmaContableApp : public wxApp
{
public:
    virtual bool OnInit();
    //con la macro wxDECLARE_APP podemos acceder a libroContable con wxGetApp().libroContable desde toda la app
    LibroContable* libroContable= new LibroContable("SigmaContableDB.scdb");
};
//Necesitamos esta macro para poder acceder a miembros de wxApp desde todoslos frames
wxDECLARE_APP(SigmaContableApp);

#endif // SIGMACONTABLEAPP_H
