#pragma once

#include "frmadministradorLogin.h"
#include "frmsupervisorLogin.h"

namespace SigmaView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ supervisorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ administradorToolStripMenuItem;



	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->supervisorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administradorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->supervisorToolStripMenuItem,
					this->administradorToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1024, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// supervisorToolStripMenuItem
			// 
			this->supervisorToolStripMenuItem->Name = L"supervisorToolStripMenuItem";
			this->supervisorToolStripMenuItem->Size = System::Drawing::Size(74, 20);
			this->supervisorToolStripMenuItem->Text = L"Supervisor";
			this->supervisorToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::supervisorToolStripMenuItem_Click);
			// 
			// administradorToolStripMenuItem
			// 
			this->administradorToolStripMenuItem->Name = L"administradorToolStripMenuItem";
			this->administradorToolStripMenuItem->Size = System::Drawing::Size(95, 20);
			this->administradorToolStripMenuItem->Text = L"Administrador";
			this->administradorToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::administradorToolStripMenuItem_Click);
			// 
			// frmPrincipal
			// 

			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1024, 583);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"frmPrincipal";
			this->Text = L"Ventana de Usuario";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void administradorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmadministradorLogin^ ventanaAdministrador = gcnew frmadministradorLogin();
		ventanaAdministrador->MdiParent = this; // Establecer el formulario principal como padre
		ventanaAdministrador->Show();
	}
	private: System::Void supervisorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmsupervisorLogin^ ventanaSupervisor = gcnew frmsupervisorLogin();
		ventanaSupervisor->MdiParent = this; // Establecer el formulario principal como padre
		ventanaSupervisor->Show();
	}
	};
}
