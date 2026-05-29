#include "NuevoAsientoFrame.h"

//(*InternalHeaders(NuevoAsientoFrame)
#include <wx/button.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NuevoAsientoFrame)
const wxWindowID NuevoAsientoFrame::ID_STATICTEXT1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_DATEPICKERCTRL1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_STATICTEXT2 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_TEXTCTRL1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_GRID1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NuevoAsientoFrame,wxFrame)
    //(*EventTable(NuevoAsientoFrame)
    //*)
END_EVENT_TABLE()

NuevoAsientoFrame::NuevoAsientoFrame(wxWindow* parent,LibroContable* lContable,wxWindowID id,const wxPoint& pos,const wxSize& size):lContable(lContable)
{
    //(*Initialize(NuevoAsientoFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxStdDialogButtonSizer* StdDialogButtonSizer1;

    Create(parent, id, _("Nuevo Asiento"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxFRAME_NO_TASKBAR|wxFRAME_FLOAT_ON_PARENT, _T("id"));
    SetClientSize(wxSize(800,480));
    Move(wxDefaultPosition);
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(192,176), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Fecha:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer4->Add(StaticText1, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerCtrl1 = new wxDatePickerCtrl(Panel1, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    BoxSizer4->Add(DatePickerCtrl1, 0, wxLEFT|wxALIGN_TOP, 5);
    BoxSizer2->Add(BoxSizer4, 0, wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Descripción:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer5->Add(StaticText2, 0, wxLEFT|wxALIGN_LEFT, 5);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer5->Add(TextCtrl1, 1, wxLEFT|wxRIGHT|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer5, 0, wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Grid1 = new wxGrid(Panel1, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    Grid1->CreateGrid(1,4);
    Grid1->EnableEditing(true);
    Grid1->EnableGridLines(true);
    Grid1->SetDefaultColSize(150, true);
    Grid1->SetColLabelValue(0, _("CUENTA"));
    Grid1->SetColLabelValue(1, _("DESGLOSE"));
    Grid1->SetColLabelValue(2, _("DEBE"));
    Grid1->SetColLabelValue(3, _("HABER"));
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    BoxSizer3->Add(Grid1, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
    StdDialogButtonSizer1->AddButton(new wxButton(Panel1, wxID_OK, wxEmptyString));
    StdDialogButtonSizer1->AddButton(new wxButton(Panel1, wxID_CANCEL, wxEmptyString));
    StdDialogButtonSizer1->Realize();
    dynamic_cast <wxButton *> (Panel1->FindWindow(wxID_OK))->SetDefault();
    BoxSizer1->Add(StdDialogButtonSizer1, 0, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    Center();

    Connect(ID_GRID1, wxEVT_GRID_SELECT_CELL, (wxObjectEventFunction)&NuevoAsientoFrame::OnGrid1CellSelect);
    //*)
    //Modificamos el estilo del grid
    Grid1->HideRowLabels();
    Grid1->SetColSize(1,325);

    //Creamos atributos de celda
    wxGridCellAttr* attrColumna = new wxGridCellAttr();

    // Definimos las opciones de la lista
    wxArrayString opciones;
    for(auto c : lContable->cuentas)
    {
        opciones.Add(c->getNombre());
    }
    // Asignamos el Editor de tipo Choice a la columna (el false evita que escriban texto libre)
    attrColumna->SetEditor(new wxGridCellChoiceEditor(opciones, true));

    Grid1->SetColAttr(0, attrColumna);
    //attrColumna->DecRef(); // No olvidar el DecRef()
}

NuevoAsientoFrame::~NuevoAsientoFrame()
{
    this->GetParent()->Enable(true);
    //(*Destroy(NuevoAsientoFrame)
    //*)
}



//Necesitamos agregar mas filas al precionar ENTER o TAB en el ultimo elemento
//void NuevoAsientoFrame::OnGrid1KeyDown(wxKeyEvent& event)
//{
////    if(event.GetKeyCode()==WXK_TAB){
////            if(Grid1->GetGridCursorRow()+1==Grid1->GetNumberRows()) Grid1->AppendRows(1,true);
////    }
//
//}

void NuevoAsientoFrame::OnGrid1CellSelect(wxGridEvent& event)
{

            if(Grid1->GetGridCursorRow()+1==Grid1->GetNumberRows()) Grid1->AppendRows(1,true);

}
