#ifndef LIBRODIARIOPANEL_H
#define LIBRODIARIOPANEL_H
#include "LibroContable.h"
//(*Headers(LibroDiarioPanel)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
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
        wxBitmapButton* BitmapButton1;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxDatePickerCtrl* DatePickerCtrl1;
        wxDatePickerCtrl* DatePickerCtrl2;
        wxListView* ListCtrl1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        //*)

    protected:

        //(*Identifiers(LibroDiarioPanel)
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_DATEPICKERCTRL1;
        static const wxWindowID ID_STATICTEXT3;
        static const wxWindowID ID_DATEPICKERCTRL2;
        static const wxWindowID ID_BITMAPBUTTON1;
        static const wxWindowID ID_LISTVIEW1;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_BUTTON3;
        //*)

    private:

        //(*Handlers(LibroDiarioPanel)
        void OnListCtrl1ItemSelect(wxListEvent& event);
        //*)

        DECLARE_EVENT_TABLE()
};


#endif
