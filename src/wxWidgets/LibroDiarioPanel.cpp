#include "LibroDiarioPanel.h"
#include "SigmaContableApp.h"

//(*InternalHeaders(LibroDiarioPanel)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(LibroDiarioPanel)
const wxWindowID LibroDiarioPanel::ID_STATICTEXT1 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_STATICTEXT2 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_DATEPICKERCTRL1 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_STATICTEXT3 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_DATEPICKERCTRL2 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_BITMAPBUTTON1 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_LISTVIEW1 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_BUTTON1 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_BUTTON2 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LibroDiarioPanel,wxPanel)
    //(*EventTable(LibroDiarioPanel)
    //*)
END_EVENT_TABLE()

LibroDiarioPanel::LibroDiarioPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size):parent(parent)
{
    //(*Initialize(LibroDiarioPanel)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Filtrar por fecha"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Desde:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerCtrl1 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    BoxSizer2->Add(DatePickerCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Hasta:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer2->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerCtrl2 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
    BoxSizer2->Add(DatePickerCtrl2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BoxSizer2->Add(BitmapButton1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    ListCtrl1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW1"));
    BoxSizer1->Add(ListCtrl1, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Editar Seleccionado"));
    StaticBoxSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Modificar Asiento"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->Disable();
    StaticBoxSizer1->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Editar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->Disable();
    StaticBoxSizer1->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Eliminar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->Disable();
    StaticBoxSizer1->Add(Button3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_LISTVIEW1, wxEVT_COMMAND_LIST_ITEM_SELECTED, (wxObjectEventFunction)&LibroDiarioPanel::OnListCtrl1ItemSelect);
    //*)

    ActualizarLista();
}

LibroDiarioPanel::~LibroDiarioPanel()
{
    //(*Destroy(LibroDiarioPanel)
    //*)
}

void LibroDiarioPanel::ActualizarLista(){
    ListCtrl1->Enable(false);
    //Creamos las columnas
    ListCtrl1->InsertColumn(0,"id_asiento");
    ListCtrl1->InsertColumn(1,"id_cuenta");
    ListCtrl1->InsertColumn(2,"id_registro");
    ListCtrl1->InsertColumn(3,"Cuenta");
    ListCtrl1->InsertColumn(4,"Desglose");
    ListCtrl1->InsertColumn(5,"Debe");
    ListCtrl1->InsertColumn(6,"Haber");
    //Escondemos los ID. Hay otra forma de recuperar ids, pero ahora lo dejo asi
    ListCtrl1->SetColumnWidth(0,0);
    ListCtrl1->SetColumnWidth(1,0);
    ListCtrl1->SetColumnWidth(2,0);

    ListCtrl1->SetColumnWidth(3,320);
    ListCtrl1->SetColumnWidth(4,320);
    ListCtrl1->SetColumnWidth(5,160);
    ListCtrl1->SetColumnWidth(6,160);
    /**< Generamos las filas */
    int fila=0;
    int asiento=0;
    for(const Registro& r : wxGetApp().libroContable->registros){
        if(r.getAsientoId()!=asiento){ //es un nuevo asiento, asi que lo mostramos
            asiento=r.getAsientoId();
            for(const Asiento& a : wxGetApp().libroContable->asientos){
                if(a.getId()==asiento){
                    ListCtrl1->InsertItem(fila,""); //Agregamos una fila vacia
                    fila++;
                    ListCtrl1->InsertItem(fila,std::to_string(r.getAsientoId()));
                    ListCtrl1->SetItem(fila,1,std::to_string(r.getCuentaId()));
                    ListCtrl1->SetItem(fila,2,std::to_string(r.getId()));
                    ListCtrl1->SetItem(fila,3,a.getFecha());
                    fila++;
                }
            }

        }
        ListCtrl1->InsertItem(fila,std::to_string(r.getAsientoId()));
        ListCtrl1->SetItem(fila,1,std::to_string(r.getCuentaId()));
        ListCtrl1->SetItem(fila,2,std::to_string(r.getId()));
        ListCtrl1->SetItem(fila,3,wxGetApp().libroContable->getNombreCuenta(r.getCuentaId()));
        ListCtrl1->SetItem(fila,4,r.getNotas());

        double importe = r.getDebe() / 100.0;
        wxString texto = wxString::Format("$\t\t\t %.2f", importe);
        ListCtrl1->SetItem(fila,5,texto);

        importe = r.getHaber() / 100.0;
        texto = wxString::Format("$\t\t\t %.2f", importe);
        ListCtrl1->SetItem(fila,6,texto);

        fila++;
    }
    ListCtrl1->Enable(true);
}

void LibroDiarioPanel::OnListCtrl1ItemSelect(wxListEvent& event)
{
    long seleccion=ListCtrl1->GetFirstSelected();
    //Si no hay nada en la celda 3 CUENTA deshabilitamos los botones de edicion y eliminacion
    if(ListCtrl1->GetItemText(seleccion,3)==""){
            Button2->Disable();
            Button3->Disable();
    }else{
            Button2->Enable();
            Button3->Enable();
    }
}
