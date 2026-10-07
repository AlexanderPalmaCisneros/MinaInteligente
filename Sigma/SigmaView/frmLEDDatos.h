#pragma once
#include "Utilidades.h"

namespace SigmaView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SigmaController;
	using namespace SigmaModel;

	/// <summary>
	/// Datos del LED
	/// </summary>
	public ref class frmLEDDatos : public System::Windows::Forms::Form
	{
	public:
		frmLEDDatos(String^ id, LED^ led, List<Zona^>^ zonas)
		{
			InitializeComponent();
			this->Text = (led == nullptr) ? "Nuevo LED" : "Modificar LED";
			this->zonas = zonas;
			this->cmbZona->Items->Add("(Sin zona)");
			for each (Zona^ zona in zonas) {
				this->cmbZona->Items->Add(zona->GetId() + " - " + zona->GetNombre());
			}
			this->cmbZona->SelectedIndex = 0;
			this->cmbEstado->SelectedIndex = 0;
			this->txtId->Text = id;
			if (led != nullptr) {
				this->cmbEstado->SelectedIndex = static_cast<int>(led->GetEstado());
				if (led->GetZonaAsociada() != nullptr) {
					int posicion = this->cmbZona->Items->IndexOf(led->GetZonaAsociada()->GetId() + " - " + led->GetZonaAsociada()->GetNombre());
					this->cmbZona->SelectedIndex = (posicion < 0) ? 0 : posicion;
				}
			}
			// LED bicolor: el color lo decide el sistema segun el riesgo de la zona, el administrador solo lo ve
			this->txtColor->Text = (led != nullptr) ? led->GetColor().ToString() : ColorLED::ROJO.ToString();
			this->txtEncendido->Text = (led != nullptr && led->GetEncendido()) ? "Sí" : "No";
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmLEDDatos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblId;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::Label^ lblZona;
	private: System::Windows::Forms::ComboBox^ cmbZona;
	private: System::Windows::Forms::Label^ lblEstado;
	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::Label^ lblColor;
	private: System::Windows::Forms::TextBox^ txtColor;
	private: System::Windows::Forms::Label^ lblEncendido;
	private: System::Windows::Forms::TextBox^ txtEncendido;
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Button^ btnCancelar;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

	private:
		List<Zona^>^ zonas;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblId = (gcnew System::Windows::Forms::Label());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->lblZona = (gcnew System::Windows::Forms::Label());
			this->cmbZona = (gcnew System::Windows::Forms::ComboBox());
			this->lblEstado = (gcnew System::Windows::Forms::Label());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->lblColor = (gcnew System::Windows::Forms::Label());
			this->txtColor = (gcnew System::Windows::Forms::TextBox());
			this->lblEncendido = (gcnew System::Windows::Forms::Label());
			this->txtEncendido = (gcnew System::Windows::Forms::TextBox());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblId
			// 
			this->lblId->AutoSize = true;
			this->lblId->Location = System::Drawing::Point(20, 23);
			this->lblId->Name = L"lblId";
			this->lblId->Size = System::Drawing::Size(12, 13);
			this->lblId->Text = L"Id";
			// 
			// txtId
			// 
			this->txtId->Location = System::Drawing::Point(210, 20);
			this->txtId->Name = L"txtId";
			this->txtId->ReadOnly = true;
			this->txtId->Size = System::Drawing::Size(250, 20);
			this->txtId->TabIndex = 0;
			this->txtId->TabStop = false;
			// 
			// lblZona
			// 
			this->lblZona->AutoSize = true;
			this->lblZona->Location = System::Drawing::Point(20, 57);
			this->lblZona->Name = L"lblZona";
			this->lblZona->Size = System::Drawing::Size(24, 13);
			this->lblZona->Text = L"Zona";
			// 
			// cmbZona
			// 
			this->cmbZona->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbZona->FormattingEnabled = true;
			this->cmbZona->Location = System::Drawing::Point(210, 54);
			this->cmbZona->Name = L"cmbZona";
			this->cmbZona->Size = System::Drawing::Size(250, 21);
			this->cmbZona->TabIndex = 1;
			// 
			// lblEstado
			// 
			this->lblEstado->AutoSize = true;
			this->lblEstado->Location = System::Drawing::Point(20, 91);
			this->lblEstado->Name = L"lblEstado";
			this->lblEstado->Size = System::Drawing::Size(36, 13);
			this->lblEstado->Text = L"Estado";
			// 
			// cmbEstado
			// 
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEstado->FormattingEnabled = true;
			this->cmbEstado->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"ACTIVO", L"INACTIVO", L"FALLA"});
			this->cmbEstado->Location = System::Drawing::Point(210, 88);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(250, 21);
			this->cmbEstado->TabIndex = 2;
			// 
			// lblColor
			// 
			this->lblColor->AutoSize = true;
			this->lblColor->Location = System::Drawing::Point(20, 125);
			this->lblColor->Name = L"lblColor";
			this->lblColor->Size = System::Drawing::Size(150, 13);
			this->lblColor->Text = L"Color actual (automático)";
			// 
			// txtColor
			// 
			this->txtColor->Location = System::Drawing::Point(210, 122);
			this->txtColor->Name = L"txtColor";
			this->txtColor->ReadOnly = true;
			this->txtColor->Size = System::Drawing::Size(250, 20);
			this->txtColor->TabIndex = 3;
			this->txtColor->TabStop = false;
			// 
			// lblEncendido
			// 
			this->lblEncendido->AutoSize = true;
			this->lblEncendido->Location = System::Drawing::Point(20, 159);
			this->lblEncendido->Name = L"lblEncendido";
			this->lblEncendido->Size = System::Drawing::Size(54, 13);
			this->lblEncendido->Text = L"Encendido";
			// 
			// txtEncendido
			// 
			this->txtEncendido->Location = System::Drawing::Point(210, 156);
			this->txtEncendido->Name = L"txtEncendido";
			this->txtEncendido->ReadOnly = true;
			this->txtEncendido->Size = System::Drawing::Size(250, 20);
			this->txtEncendido->TabIndex = 4;
			this->txtEncendido->TabStop = false;
			// 
			// btnGuardar
			// 
			this->btnGuardar->Location = System::Drawing::Point(250, 200);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(100, 30);
			this->btnGuardar->TabIndex = 5;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = true;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmLEDDatos::btnGuardar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancelar->Location = System::Drawing::Point(360, 200);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(100, 30);
			this->btnCancelar->TabIndex = 6;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			// 
			// frmLEDDatos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AcceptButton = this->btnGuardar;
			this->CancelButton = this->btnCancelar;
			this->ClientSize = System::Drawing::Size(490, 250);
			this->Controls->Add(this->lblId);
			this->Controls->Add(this->txtId);
			this->Controls->Add(this->lblZona);
			this->Controls->Add(this->cmbZona);
			this->Controls->Add(this->lblEstado);
			this->Controls->Add(this->cmbEstado);
			this->Controls->Add(this->lblColor);
			this->Controls->Add(this->txtColor);
			this->Controls->Add(this->lblEncendido);
			this->Controls->Add(this->txtEncendido);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->btnCancelar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmLEDDatos";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Datos del LED";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		String^ GetId() {
			return this->txtId->Text->Trim();
		}

		/*Zona elegida, o nullptr si se dejo "(Sin zona)"*/
		Zona^ GetZona() {
			int posicion = this->cmbZona->SelectedIndex;
			return (posicion > 0) ? this->zonas[posicion - 1] : nullptr;
		}

		EstadoDispositivo GetEstado() {
			return static_cast<EstadoDispositivo>(this->cmbEstado->SelectedIndex);
		}

	private:
		void Avisar(String^ mensaje, Control^ control) {
			MessageBox::Show(mensaje, "Datos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			control->Focus();
		}

	/*Valida que lo obligatorio este lleno y que los numeros sean numeros; recien ahi cierra*/
	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->cmbEstado->SelectedIndex < 0) {
				Avisar("Seleccione una opción en 'Estado'.", this->cmbEstado);
				return;
			}
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
	};
}
