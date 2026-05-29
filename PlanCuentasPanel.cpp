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
    ListCtrl1 = new wxListCtrl(this, ID_LISTCTRL1, wxDefaultPosition, wxSize(640,480), wxLC_LIST, wxDefaultValidator, _T("ID_LISTCTRL1"));
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




}
