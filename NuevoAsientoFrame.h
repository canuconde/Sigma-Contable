#ifndef NUEVOASIENTOFRAME_H
#define NUEVOASIENTOFRAME_H
#include "LibroContable.h"
//(*Headers(NuevoAsientoFrame)
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class NuevoAsientoFrame: public wxFrame
{
    public:

        NuevoAsientoFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~NuevoAsientoFrame();

        //(*Declarations(NuevoAsientoFrame)
        wxDatePickerCtrl* DatePickerCtrl1;
        wxGrid* Grid1;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxTextCtrl* TextCtrl1;
        //*)

    protected:

        //(*Identifiers(NuevoAsientoFrame)
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_DATEPICKERCTRL1;
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_GRID1;
        static const wxWindowID ID_PANEL1;
        //*)

    private:

        //(*Handlers(NuevoAsientoFrame)
        void OnGrid1CellLeftClick(wxGridEvent& event);
        void OnGrid1KeyDown(wxKeyEvent& event);
        void OnGrid1CellSelect(wxGridEvent& event);
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
