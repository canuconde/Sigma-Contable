#include "PlanCuentasPanel.h"
#include "SigmaContableMain.h"
#include "SigmaContableApp.h"
#include <wx/valtext.h>
//(*InternalHeaders(PlanCuentasPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PlanCuentasPanel)
const wxWindowID PlanCuentasPanel::ID_LISTCTRL1 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_PANEL1 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_STATICTEXT2 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_TEXTCTRL1 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_STATICTEXT1 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_TEXTCTRL2 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_STATICTEXT3 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_CHOICE1 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_BUTTON1 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_BUTTON2 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_PANEL2 = wxNewId();
const wxWindowID PlanCuentasPanel::ID_SPLITTERWINDOW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PlanCuentasPanel,wxPanel)
    //(*EventTable(PlanCuentasPanel)
    //*)
END_EVENT_TABLE()

PlanCuentasPanel::PlanCuentasPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size):parent(parent)
{
    //(*Initialize(PlanCuentasPanel)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    SplitterWindow1 = new wxSplitterWindow(this, ID_SPLITTERWINDOW1, wxDefaultPosition, wxDefaultSize, wxSP_3D, _T("ID_SPLITTERWINDOW1"));
    SplitterWindow1->SetMinimumPaneSize(300);
    SplitterWindow1->SetSashGravity(0.9);
    Panel1 = new wxPanel(SplitterWindow1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    ListCtrl1 = new wxListCtrl(Panel1, ID_LISTCTRL1, wxDefaultPosition, wxSize(640,480), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer2->Add(ListCtrl1, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer2);
    Panel2 = new wxPanel(SplitterWindow1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, Panel2, _("Añadir Nueva Cuenta"));
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Código:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlCodigo = new wxTextCtrl(Panel2, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrlCodigo->SetMaxLength(5);
    BoxSizer3->Add(TextCtrlCodigo, 3, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Nombre:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer4->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlNombre = new wxTextCtrl(Panel2, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer4->Add(TextCtrlNombre, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer4, 0, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Tipo:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer5->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ChoiceRubro = new wxChoice(Panel2, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    ChoiceRubro->Append(_("ACTIVO"));
    ChoiceRubro->Append(_("PASIVO"));
    ChoiceRubro->Append(_("PATRIMONIO"));
    ChoiceRubro->Append(_("INGRESOS"));
    ChoiceRubro->Append(_("EGRESOS"));
    BoxSizer5->Add(ChoiceRubro, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer5, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel2, ID_BUTTON1, _("Guardar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer6->Add(Button1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonGuardar = new wxButton(Panel2, ID_BUTTON2, _("Cancelar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer6->Add(ButtonGuardar, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(BoxSizer6, 0, wxALL|wxEXPAND, 5);
    Panel2->SetSizer(StaticBoxSizer1);
    SplitterWindow1->SplitVertically(Panel1, Panel2);
    SplitterWindow1->SetSashPosition(-1);
    BoxSizer1->Add(SplitterWindow1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&PlanCuentasPanel::OnButton1Click);
    //*)
    Actualizar();
    //VALIDACIONES requiere #include <wx/valtext.h>
    TextCtrlCodigo->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
    TextCtrlNombre->SetValidator(wxTextValidator(wxFILTER_ALPHA));
}

PlanCuentasPanel::~PlanCuentasPanel()
{
    //(*Destroy(PlanCuentasPanel)
    //*)
}

void PlanCuentasPanel::Actualizar(){
    ListCtrl1->Show(false);
    ListCtrl1->DeleteAllItems();
    ListCtrl1->DeleteAllColumns();

    //Creamos las columnas
    ListCtrl1->InsertColumn(0,"id_cuenta");
    ListCtrl1->InsertColumn(1,"Nº");
    ListCtrl1->InsertColumn(2,"Cuenta");
    ListCtrl1->InsertColumn(3,"Rubro");

    //Escondemos los ID. Hay otra forma de recuperar ids, pero ahora lo dejo asi
    ListCtrl1->SetColumnWidth(0,100);
    ListCtrl1->SetColumnWidth(1,100);
    ListCtrl1->SetColumnWidth(2,0100);
    ListCtrl1->SetColumnWidth(3,320);

    /**< Generamos las filas */
    int fila=0;
    for(Cuenta* r : wxGetApp().libroContable->cuentas){
        ListCtrl1->InsertItem(fila,std::to_string(r->getId()));
        ListCtrl1->SetItem(fila,1,std::to_string(r->getNumero()));
        ListCtrl1->SetItem(fila,2,r->getNombre());
        ListCtrl1->SetItem(fila,3,r->getRubro());

        fila++;
    }

    ListCtrl1->Show(true);
}

void PlanCuentasPanel::OnButton1Click(wxCommandEvent& event)
{
    int numero, id;
    std::string nombre, rubro;


    if(!TextCtrlNombre->IsEmpty()&&!TextCtrlCodigo->IsEmpty()&& ChoiceRubro->GetSelection()!=wxNOT_FOUND){
            nombre=TextCtrlNombre->GetValue().ToStdString();
            rubro=ChoiceRubro->GetString(ChoiceRubro->GetSelection()).ToStdString();
            numero=std::stoi(TextCtrlCodigo->GetValue().ToStdString());
            id=wxGetApp().libroContable->GuardarCuenta(nombre,"-",rubro,numero);
            //Lo cargamos manualmente en la lista, por alguna razon crashea al actualizar
           if(id!=0){
                int fila = ListCtrl1->GetItemCount();
                ListCtrl1->InsertItem(fila,std::to_string(id));
                ListCtrl1->SetItem(fila,1,std::to_string(numero));
                ListCtrl1->SetItem(fila,2,nombre);
                ListCtrl1->SetItem(fila,3,rubro);
            //Borramos los controles
                TextCtrlCodigo->SetValue("");
                TextCtrlNombre->SetValue("");
                ChoiceRubro->SetSelection(-1);

           }

    }
}
