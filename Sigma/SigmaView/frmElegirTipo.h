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
	/// Nuevo dispositivo
	/// </summary>
	public ref class frmElegirTipo : public System::Windows::Forms::Form
	{
	public:
		frmElegirTipo(void)
		{
			InitializeComponent();
			this->cmbTipo->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmElegirTipo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTipo;
	private: System::Windows::Forms::ComboBox^ cmbTipo;
	private: System::Windows::Forms::Button^ btnAceptar;
	private: System::Windows::Forms::Button^ btnCancelar;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblTipo = (gcnew System::Windows::Forms::Label());
			this->cmbTipo = (gcnew System::Windows::Forms::ComboBox());
			this->btnAceptar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblTipo
			// 
			this->lblTipo->AutoSize = true;
			this->lblTipo->Location = System::Drawing::Point(20, 23);
			this->lblTipo->Name = L"lblTipo";
			this->lblTipo->Size = System::Drawing::Size(96, 13);
			this->lblTipo->Text = L"Tipo de dispositivo";
			// 
			// cmbTipo
			// 
			this->cmbTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTipo->FormattingEnabled = true;
			this->cmbTipo->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"LED", L"VENTILADOR", L"SENSOR GAS", L"LECTOR RFID"});
			this->cmbTipo->Location = System::Drawing::Point(150, 20);
			this->cmbTipo->Name = L"cmbTipo";
			this->cmbTipo->Size = System::Drawing::Size(200, 21);
			this->cmbTipo->TabIndex = 0;
			// 
			// btnAceptar
			// 
			this->btnAceptar->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnAceptar->Location = System::Drawing::Point(150, 62);
			this->btnAceptar->Name = L"btnAceptar";
			this->btnAceptar->Size = System::Drawing::Size(95, 28);
			this->btnAceptar->TabIndex = 1;
			this->btnAceptar->Text = L"Aceptar";
			this->btnAceptar->UseVisualStyleBackColor = true;
			// 
			// btnCancelar
			// 
			this->btnCancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancelar->Location = System::Drawing::Point(255, 62);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(95, 28);
			this->btnCancelar->TabIndex = 2;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			// 
			// frmElegirTipo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AcceptButton = this->btnAceptar;
			this->CancelButton = this->btnCancelar;
			this->ClientSize = System::Drawing::Size(380, 110);
			this->Controls->Add(this->lblTipo);
			this->Controls->Add(this->cmbTipo);
			this->Controls->Add(this->btnAceptar);
			this->Controls->Add(this->btnCancelar);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmElegirTipo";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Nuevo dispositivo";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		/*Tipo elegido: LED, VENTILADOR, SENSOR GAS o LECTOR RFID*/
		String^ GetTipo() {
			return this->cmbTipo->SelectedItem->ToString();
		}
	};
}
