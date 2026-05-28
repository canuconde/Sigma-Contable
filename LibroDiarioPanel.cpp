#include "LibroDiarioPanel.h"

//(*InternalHeaders(LibroDiarioPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(LibroDiarioPanel)
const wxWindowID LibroDiarioPanel::ID_LISTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LibroDiarioPanel,wxPanel)
    //(*EventTable(LibroDiarioPanel)
    //*)
END_EVENT_TABLE()

LibroDiarioPanel::LibroDiarioPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(LibroDiarioPanel)
    wxBoxSizer* BoxSizer1;

    Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_LISTCTRL1"));
    BoxSizer1->Add(ListCtrl1, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);
    //*)
    ActualizarLista();
}

LibroDiarioPanel::~LibroDiarioPanel()
{
    //(*Destroy(LibroDiarioPanel)
    //*)
}

void LibroDiarioPanel::ActualizarLista(){
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

}
