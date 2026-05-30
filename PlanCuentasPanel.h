#ifndef PLANCUENTASPANEL_H
#define PLANCUENTASPANEL_H
#include "LibroContable.h"
//(*Headers(PlanCuentasPanel)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class PlanCuentasPanel: public wxPanel
{
    public:

        PlanCuentasPanel(wxWindow* parent,LibroContable* lContable,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~PlanCuentasPanel();
        LibroContable* lContable;
        wxWindow* parent;
        void Actualizar();

        //(*Declarations(PlanCuentasPanel)
        wxButton* Button1;
        wxButton* ButtonGuardar;
        wxChoice* ChoiceRubro;
        wxListCtrl* ListCtrl1;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxSplitterWindow* SplitterWindow1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxTextCtrl* TextCtrlCodigo;
        wxTextCtrl* TextCtrlNombre;
        //*)

    protected:

        //(*Identifiers(PlanCuentasPanel)
        static const wxWindowID ID_LISTCTRL1;
        static const wxWindowID ID_PANEL1;
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_TEXTCTRL2;
        static const wxWindowID ID_STATICTEXT3;
        static const wxWindowID ID_CHOICE1;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_PANEL2;
        static const wxWindowID ID_SPLITTERWINDOW1;
        //*)

    private:

        //(*Handlers(PlanCuentasPanel)
        void OnButton1Click(wxCommandEvent& event);
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
