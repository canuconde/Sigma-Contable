#ifndef PLANCUENTASPANEL_H
#define PLANCUENTASPANEL_H
#include "LibroContable.h"
//(*Headers(PlanCuentasPanel)
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class PlanCuentasPanel: public wxPanel
{
    public:

        PlanCuentasPanel(wxWindow* parent,LibroContable* lContable,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~PlanCuentasPanel();
        LibroContable* lContable;
        void Actualizar();

        //(*Declarations(PlanCuentasPanel)
        wxListCtrl* ListCtrl1;
        //*)

    protected:

        //(*Identifiers(PlanCuentasPanel)
        static const wxWindowID ID_LISTCTRL1;
        //*)

    private:

        //(*Handlers(PlanCuentasPanel)
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
