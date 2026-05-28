#include "LibroDiarioPanel.h"

//(*InternalHeaders(LibroDiarioPanel)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(LibroDiarioPanel)
const wxWindowID LibroDiarioPanel::ID_STATICTEXT1 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_DATEPICKERCTRL1 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_STATICTEXT2 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_DATEPICKERCTRL2 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_SEARCHCTRL1 = wxNewId();
const wxWindowID LibroDiarioPanel::ID_LISTVIEW1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(LibroDiarioPanel,wxPanel)
    //(*EventTable(LibroDiarioPanel)
    //*)
END_EVENT_TABLE()

LibroDiarioPanel::LibroDiarioPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(LibroDiarioPanel)
    wxBoxSizer* BoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, wxEmptyString);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Filtrar desde:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT1"));
    StaticBoxSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerCtrl1 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    StaticBoxSizer1->Add(DatePickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Hasta:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT2"));
    StaticBoxSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerCtrl2 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
    StaticBoxSizer1->Add(DatePickerCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SearchCtrl1 = new wxSearchCtrl(this, ID_SEARCHCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SEARCHCTRL1"));
    StaticBoxSizer1->Add(SearchCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer1, 0, wxBOTTOM|wxEXPAND, 5);
    ListCtrl1 = new wxListView(this, ID_LISTVIEW1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTVIEW1"));
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
    ListCtrl1->SetColumnWidth(0,100);
    ListCtrl1->SetColumnWidth(1,100);
    ListCtrl1->SetColumnWidth(2,0100);

    ListCtrl1->SetColumnWidth(3,320);
    ListCtrl1->SetColumnWidth(4,320);
    ListCtrl1->SetColumnWidth(5,160);
    ListCtrl1->SetColumnWidth(6,160);



}
