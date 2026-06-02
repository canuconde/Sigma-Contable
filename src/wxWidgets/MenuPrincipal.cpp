#include "MenuPrincipal.h"

//(*InternalHeaders(MenuPrincipal)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(MenuPrincipal)
//*)

BEGIN_EVENT_TABLE(MenuPrincipal,wxPanel)
    //(*EventTable(MenuPrincipal)
    //*)
END_EVENT_TABLE()

MenuPrincipal::MenuPrincipal(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MenuPrincipal)
    Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
    //*)
}

MenuPrincipal::~MenuPrincipal()
{
    //(*Destroy(MenuPrincipal)
    //*)
}

