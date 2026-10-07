
#pragma once


namespace SigmaView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SigmaController;
	using namespace SigmaModel;

	/// <summary>
	/// Resumen de frmsupervisorLogin
	/// </summary>
	public ref class frmsupervisorLogin : public System::Windows::Forms::Form
	{
	public:
		frmsupervisorLogin(void)
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
		~frmsupervisorLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;

	protected:


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(120, 141);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Ingresar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmsupervisorLogin::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(89, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(165, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(89, 86);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(165, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Usuario";
			this->label2->Click += gcnew System::EventHandler(this, &frmsupervisorLogin::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(22, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Contraseña";
			this->label3->Click += gcnew System::EventHandler(this, &frmsupervisorLogin::label3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Location = System::Drawing::Point(53, 95);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(296, 170);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(166, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 41);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Login";
			this->label1->Click += gcnew System::EventHandler(this, &frmsupervisorLogin::label1_Click);
			// 
			// frmsupervisorLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(402, 321);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmsupervisorLogin";
			this->Text = L"Supervisor Login";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = this->textBox1->Text->Trim();
		String^ clave = this->textBox2->Text;
		if (usuario == "" || clave == "") {
			MessageBox::Show("Ingrese su usuario y su contraseña.", "Sigma", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		// El usuario puede escribir su id (supervisor01) o su nombre
		SupervisorController^ supervisorController = gcnew SupervisorController();
		Supervisor^ supervisor = supervisorController->Autenticar(usuario, clave);
		if (supervisor == nullptr) {
			MessageBox::Show("Usuario o contraseña incorrectos.", "Acceso denegado", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			this->textBox2->Clear();
			this->textBox2->Focus();
			return;
		}

		// El panel del supervisor todavia no existe: por ahora solo se verifica el acceso
		MessageBox::Show("Bienvenido, " + supervisor->GetNombre() + ".\n\nEl panel del supervisor aún está en desarrollo.",
			"Sigma", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->textBox2->Clear();
	}
	};
}
