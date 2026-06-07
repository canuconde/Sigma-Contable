#include "NuevoAsientoFrame.h"
#include "SigmaContableApp.h"

//(*InternalHeaders(NuevoAsientoFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NuevoAsientoFrame)
const wxWindowID NuevoAsientoFrame::ID_STATICTEXT3 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_TEXTCTRL2 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_STATICTEXT1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_DATEPICKERCTRL1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_STATICTEXT2 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_TEXTCTRL1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_GRID1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_BUTTON1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_BUTTON2 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_PANEL1 = wxNewId();
const wxWindowID NuevoAsientoFrame::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NuevoAsientoFrame,wxFrame)
    //(*EventTable(NuevoAsientoFrame)
    //*)
END_EVENT_TABLE()

NuevoAsientoFrame::NuevoAsientoFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(NuevoAsientoFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;

    Create(parent, id, _("Nuevo Asiento"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxDEFAULT_FRAME_STYLE|wxFRAME_NO_TASKBAR|wxFRAME_FLOAT_ON_PARENT, _T("id"));
    SetClientSize(wxSize(800,480));
    Move(wxDefaultPosition);
    SetFocus();
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(192,176), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Asiento Nº:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer4->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlNroAsiento = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrlNroAsiento->Disable();
    BoxSizer4->Add(TextCtrlNroAsiento, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Fecha:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer4->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerCtrl1 = new wxDatePickerCtrl(Panel1, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    DatePickerCtrl1->SetFocus();
    BoxSizer4->Add(DatePickerCtrl1, 0, wxALL|wxALIGN_TOP, 5);
    BoxSizer2->Add(BoxSizer4, 0, wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Descripción:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer5->Add(StaticText2, 0, wxLEFT|wxALIGN_LEFT, 5);
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer5->Add(TextCtrl1, 1, wxLEFT|wxRIGHT|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer5, 0, wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND, 5);
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
    BoxSizer1->Add(BoxSizer3, 1, wxLEFT|wxRIGHT|wxEXPAND, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer6->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonGuardar = new wxButton(Panel1, ID_BUTTON1, _("Guardar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer6->Add(ButtonGuardar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonCancelar = new wxButton(Panel1, ID_BUTTON2, _("Cancelar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer6->Add(ButtonCancelar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer6, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    MessageDialog1 = new wxMessageDialog(this, _("Mufaaa"), _("Message"), wxOK|wxICON_EXCLAMATION, wxDefaultPosition);
    Center();

    Connect(ID_GRID1, wxEVT_GRID_SELECT_CELL, (wxObjectEventFunction)&NuevoAsientoFrame::OnGrid1CellSelect);
    Grid1->Connect(wxEVT_KEY_DOWN, (wxObjectEventFunction)&NuevoAsientoFrame::OnGrid1KeyDown, NULL, this);
    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&NuevoAsientoFrame::OnButtonGuardarClick);
    Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&NuevoAsientoFrame::OnButtonCancelarClick);
    //*)
    //Cargamos el siguiente Nro de asiento
    int64_t numeroAsiento=wxGetApp().libroContable->asientos.size();
    numeroAsiento++;
    TextCtrlNroAsiento->SetValue(std::to_string(numeroAsiento));
    //Modificamos el estilo del grid
    Grid1->HideRowLabels();
    Grid1->SetColSize(1,325);

    //Creamos atributos de celda |
    // Necesitamos usar attrColumna->IncRef(); por cada uso
    wxGridCellAttr*   attrColumna = new wxGridCellAttr();
    wxGridCellAttr*   attrColumnaDebeHaber = new wxGridCellAttr();
    // Definimos las opciones de la lista
    wxArrayString opciones;
    for(auto c : wxGetApp().libroContable->cuentas)
    {
        opciones.Add(c.getNombre());
    }
    // Asignamos el Editor de tipo Choice a la columna (el false evita que escriban texto libre)
    attrColumna->SetEditor(new wxGridCellChoiceEditor(opciones, false));
    Grid1->SetColAttr(0, attrColumna);

    //DEBE | HABER se muestran como float con 2 decimales
    attrColumnaDebeHaber->SetEditor(new wxGridCellFloatEditor (-1,2,	wxGRID_FLOAT_FORMAT_DEFAULT));
    attrColumnaDebeHaber->SetAlignment(wxALIGN_RIGHT,wxALIGN_CENTER_VERTICAL);

    Grid1->SetColAttr(2,attrColumnaDebeHaber);
    attrColumnaDebeHaber->IncRef();
    Grid1->SetColAttr(3,attrColumnaDebeHaber);
    attrColumnaDebeHaber->IncRef();
    //attrColumna->DecRef();
}

NuevoAsientoFrame::~NuevoAsientoFrame()
{
    this->GetParent()->Enable(true);
    //(*Destroy(NuevoAsientoFrame)
    MessageDialog1->Destroy();
    //*)
}

void NuevoAsientoFrame::OnGrid1KeyDown(wxKeyEvent& event)
{   //Saltamos a la fila siguiente cuando llegamos al final
    if(event.GetKeyCode()==WXK_TAB && Grid1->GetGridCursorCol()+1==Grid1->GetNumberCols()){
             Grid1->SetGridCursor(Grid1->GetGridCursorRow()+1,0);
    }else{
        event.Skip(true);
    }

}

void NuevoAsientoFrame::OnGrid1CellSelect(wxGridEvent& event)
{   //Agregamos nuevas filas
    if(Grid1->GetGridCursorRow()+1==Grid1->GetNumberRows()) Grid1->AppendRows(1,true);
    event.Skip(true);
}

void NuevoAsientoFrame::OnButtonCancelarClick(wxCommandEvent& event)
{
    this->Destroy();
}

void NuevoAsientoFrame::OnButtonGuardarClick(wxCommandEvent& event)
{
    if (!DatePickerCtrl1->GetValue().IsValid())
    {
        MessageDialog1->Show();
        return;
    }
    if (TextCtrl1->GetValue().IsEmpty())
    {
        MessageDialog1->ShowModal();
        TextCtrl1->SetFocus();
        return;
    }
    int asientoID=wxGetApp().libroContable->GuardarAsiento(DatePickerCtrl1->GetValue().FormatISODate().ToStdString(),TextCtrl1->GetValue().ToStdString());
    int filas = Grid1->GetNumberRows();
    for(int f=0;f<filas;f++){
            if(Grid1->GetCellValue(f,2).IsEmpty() && !Grid1->GetCellValue(f,0).IsEmpty()){
                Grid1->SetGridCursor(f,2);
                Grid1->SetFocus();
                MessageDialog1->ShowModal();
                return;
            }
        wxGetApp().libroContable->GuardarRegistro(1,asientoID,"-",2,2);
    }
}
