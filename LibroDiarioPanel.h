#ifndef LIBRODIARIOPANEL_H
#define LIBRODIARIOPANEL_H
#include "LibroContable.h"
//(*Headers(LibroDiarioPanel)
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/srchctrl.h>
#include <wx/stattext.h>
//*)

class LibroDiarioPanel: public wxPanel
{
    public:

        LibroDiarioPanel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, LibroContable* lContable=nullptr);
        virtual ~LibroDiarioPanel();
        void ActualizarLista();
        LibroContable* lContable;
        //(*Declarations(LibroDiarioPanel)
        wxDatePickerCtrl* DatePickerCtrl1;
        wxDatePickerCtrl* DatePickerCtrl2;
        wxListView* ListCtrl1;
        wxSearchCtrl* SearchCtrl1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        //*)

    protected:

        //(*Identifiers(LibroDiarioPanel)
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_DATEPICKERCTRL1;
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_DATEPICKERCTRL2;
        static const wxWindowID ID_SEARCHCTRL1;
        static const wxWindowID ID_LISTVIEW1;
        //*)

    private:

        //(*Handlers(LibroDiarioPanel)
        //*)

        DECLARE_EVENT_TABLE()
};


#endif
