#include "PlanCuentasPanel.h"

//(*InternalHeaders(PlanCuentasPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PlanCuentasPanel)
const wxWindowID PlanCuentasPanel::ID_LISTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PlanCuentasPanel,wxPanel)
    //(*EventTable(PlanCuentasPanel)
    //*)
END_EVENT_TABLE()

PlanCuentasPanel::PlanCuentasPanel(wxWindow* parent, LibroContable * lContable,wxWindowID id,const wxPoint& pos,const wxSize& size):lContable(lContable)
{
    //(*Initialize(PlanCuentasPanel)
    wxBoxSizer* BoxSizer1;

    Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(640,480), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer1->Add(ListCtrl1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);
    //*)
    Actualizar();
}

PlanCuentasPanel::~PlanCuentasPanel()
{
    //(*Destroy(PlanCuentasPanel)
    //*)
}

void PlanCuentasPanel::Actualizar(){

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
    for(Cuenta* r : lContable->cuentas){
        ListCtrl1->InsertItem(fila,std::to_string(r->getId()));
        ListCtrl1->SetItem(fila,1,std::to_string(r->getNumero()));
        ListCtrl1->SetItem(fila,2,r->getNombre());
        ListCtrl1->SetItem(fila,3,r->getRubro());

        fila++;
    }


}
