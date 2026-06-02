#ifndef NUEVACUENTAFRAME_H
#define NUEVACUENTAFRAME_H

//(*Headers(NuevaCuentaFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class NuevaCuentaFrame: public wxFrame
{
    public:

        NuevaCuentaFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~NuevaCuentaFrame();

        //(*Declarations(NuevaCuentaFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxChoice* ChoiceRubro;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxTextCtrl* TextCtrlCodigo;
        wxTextCtrl* TextCtrlNombre;
        //*)

    protected:

        //(*Identifiers(NuevaCuentaFrame)
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_TEXTCTRL2;
        static const wxWindowID ID_STATICTEXT3;
        static const wxWindowID ID_CHOICE1;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_PANEL1;
        //*)

    private:

        //(*Handlers(NuevaCuentaFrame)
        void OnButton2Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
