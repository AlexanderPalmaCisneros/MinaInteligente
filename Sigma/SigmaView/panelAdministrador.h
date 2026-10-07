#pragma once
#include "frmMantZonas.h"
#include "frmMantTrabajadores.h"
#include "frmMantSupervisores.h"
#include "frmMantAdministradores.h"
#include "frmMantTiposGas.h"
#include "frmMantUmbrales.h"
#include "frmMantDispositivos.h"

namespace SigmaView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de panelAdministrador
	/// </summary>
	public ref class panelAdministrador : public System::Windows::Forms::Form
	{
	public:
		panelAdministrador(void)
		{
			InitializeComponent();
			// La imagen de fondo no debe tapar el menu ni los botones
			this->pictureBox1->SendToBack();
			this->menuStrip1->BringToFront();
			this->button1->BringToFront();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~panelAdministrador()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ zonasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ suToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ obreroToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ umbralToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dispositivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tipoDeGasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ administradoresToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	protected:

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(panelAdministrador::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->zonasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->suToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->obreroToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->umbralToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dispositivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeGasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administradoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->zonasToolStripMenuItem,
					this->suToolStripMenuItem, this->obreroToolStripMenuItem, this->administradoresToolStripMenuItem,
					this->umbralToolStripMenuItem, this->dispositivoToolStripMenuItem,
					this->tipoDeGasToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(886, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// zonasToolStripMenuItem
			// 
			this->zonasToolStripMenuItem->Name = L"zonasToolStripMenuItem";
			this->zonasToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->zonasToolStripMenuItem->Text = L"Zonas";
			this->zonasToolStripMenuItem->Click += gcnew System::EventHandler(this, &panelAdministrador::zonasToolStripMenuItem_Click);
			// 
			// suToolStripMenuItem
			// 
			this->suToolStripMenuItem->Name = L"suToolStripMenuItem";
			this->suToolStripMenuItem->Size = System::Drawing::Size(74, 20);
			this->suToolStripMenuItem->Text = L"Supervisor";
			this->suToolStripMenuItem->Click += gcnew System::EventHandler(this, &panelAdministrador::suToolStripMenuItem_Click);
			// 
			// obreroToolStripMenuItem
			// 
			this->obreroToolStripMenuItem->Name = L"obreroToolStripMenuItem";
			this->obreroToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->obreroToolStripMenuItem->Text = L"Obrero";
			this->obreroToolStripMenuItem->Click += gcnew System::EventHandler(this, &panelAdministrador::obreroToolStripMenuItem_Click);
			// 
			// umbralToolStripMenuItem
			// 
			this->umbralToolStripMenuItem->Name = L"umbralToolStripMenuItem";
			this->umbralToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->umbralToolStripMenuItem->Text = L"Umbral";
			this->umbralToolStripMenuItem->Click += gcnew System::EventHandler(this, &panelAdministrador::umbralItems_Click);
			// 
			// dispositivoToolStripMenuItem
			// 
			this->dispositivoToolStripMenuItem->Name = L"dispositivoToolStripMenuItem";
			this->dispositivoToolStripMenuItem->Size = System::Drawing::Size(77, 20);
			this->dispositivoToolStripMenuItem->Text = L"Dispositivo";
			this->dispositivoToolStripMenuItem->Click += gcnew System::EventHandler(this, &panelAdministrador::dispositivoToolStripMenuItem_Click);
			// 
			// tipoDeGasToolStripMenuItem
			// 
			this->tipoDeGasToolStripMenuItem->Name = L"tipoDeGasToolStripMenuItem";
			this->tipoDeGasToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->tipoDeGasToolStripMenuItem->Text = L"Tipo de gas";
			this->tipoDeGasToolStripMenuItem->Click += gcnew System::EventHandler(this, &panelAdministrador::tipoDeGasToolStripMenuItem_Click);
			// 
			// administradoresToolStripMenuItem
			// 
			this->administradoresToolStripMenuItem->Name = L"administradoresToolStripMenuItem";
			this->administradoresToolStripMenuItem->Size = System::Drawing::Size(104, 20);
			this->administradoresToolStripMenuItem->Text = L"Administradores";
			this->administradoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &panelAdministrador::administradoresToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Location = System::Drawing::Point(715, 549);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Cambiar Contraseña";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(886, 598);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// panelAdministrador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(886, 598);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"panelAdministrador";
			this->Text = L"panelAdministrador";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dispositivoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMantenimiento(gcnew frmMantDispositivos());
}
private: System::Void zonasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMantenimiento(gcnew frmMantZonas());
}
private: System::Void suToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMantenimiento(gcnew frmMantSupervisores());
}
private: System::Void obreroToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMantenimiento(gcnew frmMantTrabajadores());
}
private: System::Void administradoresToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMantenimiento(gcnew frmMantAdministradores());
}
private: System::Void tipoDeGasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMantenimiento(gcnew frmMantTiposGas());
}
private: System::Void umbralItems_Click(System::Object^ sender, System::EventArgs^ e) {
	mostrarMantenimiento(gcnew frmMantUmbrales());
}
private: void mostrarMantenimiento(System::Windows::Forms::Form^ ventana) {
	/*La ventana se abre como hijo del formulario principal (ventana MDI)*/
	System::Windows::Forms::Form^ contenedor = this->MdiParent;
	if (contenedor != nullptr && contenedor->IsMdiContainer) {
		ventana->MdiParent = contenedor;
	}
	ventana->Show();
}
};
}
