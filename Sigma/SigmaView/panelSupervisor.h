#pragma once
#include "frmGrafoZonas.h"

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
	/// Panel del supervisor
	/// </summary>
	public ref class panelSupervisor : public System::Windows::Forms::Form
	{
	public:
		panelSupervisor(String^ nombreSupervisor)
		{
			InitializeComponent();
			this->lblBienvenida->Text = "Bienvenido, " + nombreSupervisor;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~panelSupervisor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlEncabezado;
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblSubtitulo;
	private: System::Windows::Forms::Panel^ pnlTarjeta;
	private: System::Windows::Forms::Label^ lblBienvenida;
	private: System::Windows::Forms::Label^ lblIndicacion;
	private: System::Windows::Forms::Button^ btnAbrirGrafo;

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
			this->pnlEncabezado = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->pnlTarjeta = (gcnew System::Windows::Forms::Panel());
			this->lblBienvenida = (gcnew System::Windows::Forms::Label());
			this->lblIndicacion = (gcnew System::Windows::Forms::Label());
			this->btnAbrirGrafo = (gcnew System::Windows::Forms::Button());
			this->pnlEncabezado->SuspendLayout();
			this->pnlTarjeta->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlEncabezado
			// 
			this->pnlEncabezado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pnlEncabezado->Controls->Add(this->lblTitulo);
			this->pnlEncabezado->Controls->Add(this->lblSubtitulo);
			this->pnlEncabezado->Location = System::Drawing::Point(0, 0);
			this->pnlEncabezado->Name = L"pnlEncabezado";
			this->pnlEncabezado->Size = System::Drawing::Size(886, 64);
			this->pnlEncabezado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(22, 8);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(300, 30);
			this->lblTitulo->Text = L"Sigma · Panel del supervisor";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->lblSubtitulo->Location = System::Drawing::Point(25, 40);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(420, 15);
			this->lblSubtitulo->Text = L"Monitoreo y control de ventilación de la mina subterránea";
			// 
			// pnlTarjeta
			// 
			this->pnlTarjeta->BackColor = System::Drawing::Color::White;
			this->pnlTarjeta->Controls->Add(this->lblBienvenida);
			this->pnlTarjeta->Controls->Add(this->lblIndicacion);
			this->pnlTarjeta->Controls->Add(this->btnAbrirGrafo);
			this->pnlTarjeta->Location = System::Drawing::Point(40, 96);
			this->pnlTarjeta->Name = L"pnlTarjeta";
			this->pnlTarjeta->Size = System::Drawing::Size(440, 190);
			// 
			// lblBienvenida
			// 
			this->lblBienvenida->AutoSize = true;
			this->lblBienvenida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblBienvenida->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblBienvenida->Location = System::Drawing::Point(22, 18);
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(150, 30);
			this->lblBienvenida->Text = L"Bienvenido";
			// 
			// lblIndicacion
			// 
			this->lblIndicacion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->lblIndicacion->ForeColor = System::Drawing::Color::DimGray;
			this->lblIndicacion->Location = System::Drawing::Point(24, 58);
			this->lblIndicacion->Name = L"lblIndicacion";
			this->lblIndicacion->Size = System::Drawing::Size(390, 44);
			this->lblIndicacion->Text = L"Arme el grafo de zonas de la mina y vea en tiempo real el nivel de emergencia de cada zona.";
			// 
			// btnAbrirGrafo
			// 
			this->btnAbrirGrafo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btnAbrirGrafo->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btnAbrirGrafo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAbrirGrafo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnAbrirGrafo->ForeColor = System::Drawing::Color::White;
			this->btnAbrirGrafo->Location = System::Drawing::Point(26, 122);
			this->btnAbrirGrafo->Name = L"btnAbrirGrafo";
			this->btnAbrirGrafo->Size = System::Drawing::Size(220, 40);
			this->btnAbrirGrafo->TabIndex = 0;
			this->btnAbrirGrafo->Text = L"Abrir grafo de zonas";
			this->btnAbrirGrafo->UseVisualStyleBackColor = false;
			this->btnAbrirGrafo->Click += gcnew System::EventHandler(this, &panelSupervisor::btnAbrirGrafo_Click);
			// 
			// panelSupervisor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(886, 598);
			this->Controls->Add(this->pnlEncabezado);
			this->Controls->Add(this->pnlTarjeta);
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->Name = L"panelSupervisor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Panel del supervisor";
			this->pnlEncabezado->ResumeLayout(false);
			this->pnlTarjeta->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAbrirGrafo_Click(System::Object^ sender, System::EventArgs^ e) {
			MostrarVentana(gcnew frmGrafoZonas());
		}

	private:
		/*La ventana se abre como hijo del formulario principal (ventana MDI)*/
		void MostrarVentana(System::Windows::Forms::Form^ ventana) {
			System::Windows::Forms::Form^ contenedor = this->MdiParent;
			if (contenedor != nullptr && contenedor->IsMdiContainer) {
				ventana->MdiParent = contenedor;
			}
			ventana->Show();
		}
	};
}
