#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

//(*Headers(MenuPrincipal)
#include <wx/panel.h>
//*)

class MenuPrincipal: public wxPanel
{
    public:

        MenuPrincipal(wxWindow* parent,wxWindowID id=wxID_ANY);
        virtual ~MenuPrincipal();

        //(*Declarations(MenuPrincipal)
        //*)

    protected:

        //(*Identifiers(MenuPrincipal)
        //*)

    private:

        //(*Handlers(MenuPrincipal)
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
