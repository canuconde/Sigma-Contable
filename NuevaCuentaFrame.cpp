#include "NuevaCuentaFrame.h"

//(*InternalHeaders(NuevaCuentaFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NuevaCuentaFrame)
const wxWindowID NuevaCuentaFrame::ID_STATICTEXT1 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_STATICTEXT2 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_STATICTEXT3 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_TEXTCTRL1 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_TEXTCTRL2 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_TEXTCTRL3 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_BUTTON1 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_BUTTON2 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NuevaCuentaFrame,wxFrame)
    //(*EventTable(NuevaCuentaFrame)
    //*)
END_EVENT_TABLE()

NuevaCuentaFrame::NuevaCuentaFrame(wxWindow* parent,LibroContable* lContable,wxWindowID id,const wxPoint& pos,const wxSize& size):lContable(lContable)
{
    //(*Initialize(NuevaCuentaFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(192,248), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_BOTTOM, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_BOTTOM, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer2->Add(StaticText3, 1, wxALL|wxALIGN_BOTTOM, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer3->Add(TextCtrl1, 1, wxALL|wxALIGN_TOP, 5);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer3->Add(TextCtrl2, 1, wxALL|wxALIGN_TOP, 5);
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    BoxSizer3->Add(TextCtrl3, 1, wxALL|wxALIGN_TOP, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Guardar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Cancelar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(Button2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 0, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    //*)
}

NuevaCuentaFrame::~NuevaCuentaFrame()
{
    this->GetParent()->Enable(true);

    //(*Destroy(NuevaCuentaFrame)
    //*)
}

