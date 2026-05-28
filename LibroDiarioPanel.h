#ifndef LIBRODIARIOPANEL_H
#define LIBRODIARIOPANEL_H

//(*Headers(LibroDiarioPanel)
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class LibroDiarioPanel: public wxPanel
{
    public:

        LibroDiarioPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~LibroDiarioPanel();
        void ActualizarLista();
        //(*Declarations(LibroDiarioPanel)
        wxListCtrl* ListCtrl1;
        //*)

    protected:

        //(*Identifiers(LibroDiarioPanel)
        static const wxWindowID ID_LISTCTRL1;
        //*)

    private:

        //(*Handlers(LibroDiarioPanel)
        //*)

        DECLARE_EVENT_TABLE()
};


#endif
