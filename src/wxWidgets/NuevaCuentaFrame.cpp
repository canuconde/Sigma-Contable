#include "NuevaCuentaFrame.h"
#include  "SigmaContableMain.h"
#include <wx/valtext.h>
#include "SigmaContableApp.h"

//(*InternalHeaders(NuevaCuentaFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NuevaCuentaFrame)
const wxWindowID NuevaCuentaFrame::ID_STATICTEXT1 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_TEXTCTRL1 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_STATICTEXT2 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_TEXTCTRL2 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_STATICTEXT3 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_CHOICE1 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_BUTTON1 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_BUTTON2 = wxNewId();
const wxWindowID NuevaCuentaFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NuevaCuentaFrame,wxFrame)
    //(*EventTable(NuevaCuentaFrame)
    //*)
END_EVENT_TABLE()
NuevaCuentaFrame::NuevaCuentaFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(NuevaCuentaFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;

    Create(parent, id, _("Nueva Cuenta"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxFRAME_NO_TASKBAR|wxFRAME_FLOAT_ON_PARENT, _T("id"));
    SetClientSize(wxSize(600,128));
    Move(wxDefaultPosition);
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(192,248), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Código:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_LEFT, 5);
    TextCtrlCodigo = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer1->Add(TextCtrlCodigo, 0, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer1, 0, wxALL|wxALIGN_TOP, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Nombre:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer5->Add(StaticText2, 0, wxALL|wxALIGN_LEFT, 5);
    TextCtrlNombre = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer5->Add(TextCtrlNombre, 0, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxALIGN_TOP, 5);
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Tipo:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer6->Add(StaticText3, 0, wxALL|wxALIGN_LEFT, 5);
    ChoiceRubro = new wxChoice(Panel1, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, wxWANTS_CHARS, wxDefaultValidator, _T("ID_CHOICE1"));
    ChoiceRubro->Append(_("ACTIVO"));
    ChoiceRubro->Append(_("PASIVO"));
    ChoiceRubro->Append(_("PATRIMONIO"));
    ChoiceRubro->Append(_("INGRESOS"));
    ChoiceRubro->Append(_("EGRESOS"));
    BoxSizer6->Add(ChoiceRubro, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer6, 1, wxALL|wxALIGN_TOP, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Guardar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Cancelar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(Button2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer4, 0, wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer2);

    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&NuevaCuentaFrame::OnButton1Click);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&NuevaCuentaFrame::OnButton2Click);
    //*)
    //VALIDACIONES
    TextCtrlCodigo->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
    TextCtrlNombre->SetValidator(wxTextValidator(wxFILTER_ALPHA));
}

NuevaCuentaFrame::~NuevaCuentaFrame()
{
    this->GetParent()->Enable(true);

    //(*Destroy(NuevaCuentaFrame)
    //*)
}


void NuevaCuentaFrame::OnButton2Click(wxCommandEvent& event)
{
    this->Close();
}

void NuevaCuentaFrame::OnButton1Click(wxCommandEvent& event)
{
    int numero, id;
    std::string nombre, rubro;

    if(!TextCtrlNombre->IsEmpty()&&!TextCtrlCodigo->IsEmpty()&& ChoiceRubro->GetSelection()!=wxNOT_FOUND){
            nombre=TextCtrlNombre->GetValue().ToStdString();
            rubro=ChoiceRubro->GetString(ChoiceRubro->GetSelection()).ToStdString();
            numero=std::stoi(TextCtrlCodigo->GetValue().ToStdString());
            id= wxGetApp().libroContable->GuardarCuenta(nombre,"-",rubro,numero);
            // Llamamos a actualizar en la ventana principal
            // Necesitamos hacer el cast
            // seleccionamos la ficha CUENTAS en el notebook (columna 1)
            dynamic_cast<SigmaContableFrame*>(this->GetParent())->ActualizarPaneles(1);
            // Si se pudo guardar cerramos este frame.
            if(id!=0) this->Close();
    }

}
