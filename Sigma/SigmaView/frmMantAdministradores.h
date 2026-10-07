#pragma once
#include "Utilidades.h"
#include "frmAdministradorDatos.h"

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
	/// Gestión de administradores
	/// </summary>
	public ref class frmMantAdministradores : public System::Windows::Forms::Form
	{
	public:
		frmMantAdministradores(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantAdministradores()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblBuscar;
	private: System::Windows::Forms::TextBox^ txtBuscar;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::DataGridView^ dgvDatos;
	private: System::Windows::Forms::Button^ btnCrear;
	private: System::Windows::Forms::Button^ btnModificar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCorreo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTelefono;

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
			this->lblBuscar = (gcnew System::Windows::Forms::Label());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->dgvDatos = (gcnew System::Windows::Forms::DataGridView());
			this->btnCrear = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCorreo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTelefono = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDatos))->BeginInit();
			this->SuspendLayout();
			// 
			// lblBuscar
			// 
			this->lblBuscar->AutoSize = true;
			this->lblBuscar->Location = System::Drawing::Point(20, 24);
			this->lblBuscar->Name = L"lblBuscar";
			this->lblBuscar->Size = System::Drawing::Size(162, 13);
			this->lblBuscar->Text = L"Buscar por nombre o correo:";
			// 
			// txtBuscar
			// 
			this->txtBuscar->Location = System::Drawing::Point(240, 20);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(220, 20);
			this->txtBuscar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left));
			this->txtBuscar->TabIndex = 0;
			this->txtBuscar->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMantAdministradores::txtBuscar_KeyDown);
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(480, 18);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(100, 28);
			this->btnBuscar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left));
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantAdministradores::btnBuscar_Click);
			// 
			// dgvDatos
			// 
			this->dgvDatos->AllowUserToAddRows = false;
			this->dgvDatos->AllowUserToDeleteRows = false;
			this->dgvDatos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvDatos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDatos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewTextBoxColumn^  >(4) {this->colId, this->colNombre, this->colCorreo, this->colTelefono});
			this->dgvDatos->Location = System::Drawing::Point(20, 60);
			this->dgvDatos->MultiSelect = false;
			this->dgvDatos->Name = L"dgvDatos";
			this->dgvDatos->ReadOnly = true;
			this->dgvDatos->RowHeadersVisible = false;
			this->dgvDatos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvDatos->Size = System::Drawing::Size(840, 390);
			this->dgvDatos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvDatos->TabIndex = 3;
			this->dgvDatos->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMantAdministradores::dgvDatos_CellDoubleClick);
			// 
			// colId
			// 
			this->colId->HeaderText = L"Id";
			this->colId->Name = L"colId";
			this->colId->ReadOnly = true;
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Nombre";
			this->colNombre->Name = L"colNombre";
			this->colNombre->ReadOnly = true;
			// 
			// colCorreo
			// 
			this->colCorreo->HeaderText = L"Correo";
			this->colCorreo->Name = L"colCorreo";
			this->colCorreo->ReadOnly = true;
			// 
			// colTelefono
			// 
			this->colTelefono->HeaderText = L"Teléfono";
			this->colTelefono->Name = L"colTelefono";
			this->colTelefono->ReadOnly = true;
			// 
			// btnCrear
			// 
			this->btnCrear->Location = System::Drawing::Point(20, 468);
			this->btnCrear->Name = L"btnCrear";
			this->btnCrear->Size = System::Drawing::Size(120, 32);
			this->btnCrear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnCrear->TabIndex = 4;
			this->btnCrear->Text = L"Crear";
			this->btnCrear->UseVisualStyleBackColor = true;
			this->btnCrear->Click += gcnew System::EventHandler(this, &frmMantAdministradores::btnCrear_Click);
			// 
			// btnModificar
			// 
			this->btnModificar->Location = System::Drawing::Point(150, 468);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(120, 32);
			this->btnModificar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnModificar->TabIndex = 5;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = true;
			this->btnModificar->Click += gcnew System::EventHandler(this, &frmMantAdministradores::btnModificar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Location = System::Drawing::Point(280, 468);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(120, 32);
			this->btnEliminar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnEliminar->TabIndex = 6;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = true;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantAdministradores::btnEliminar_Click);
			// 
			// frmMantAdministradores
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 520);
			this->Controls->Add(this->lblBuscar);
			this->Controls->Add(this->txtBuscar);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->dgvDatos);
			this->Controls->Add(this->btnCrear);
			this->Controls->Add(this->btnModificar);
			this->Controls->Add(this->btnEliminar);
			this->MinimumSize = System::Drawing::Size(700, 400);
			this->Name = L"frmMantAdministradores";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Gestión de administradores";
			this->Load += gcnew System::EventHandler(this, &frmMantAdministradores::frmMantAdministradores_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDatos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		/*Llena la lista con los objetos que coincidan con el texto y el filtro*/
		void Cargar(String^ texto, String^ filtro) {
			AdministradorController^ controller = gcnew AdministradorController();
			for each (Administrador^ usuario in controller->BuscarAdministradores(texto)) {
				array<String^>^ fila = gcnew array<String^>(4);
				fila[0] = usuario->GetId();
				fila[1] = usuario->GetNombre();
				fila[2] = usuario->GetCorreo();
				fila[3] = usuario->GetTelefono();
				AgregarFila(fila);
			}
		}

		/*Abre el formulario de datos vacio (con el id autogenerado) y registra el objeto*/
		void Crear() {
			AdministradorController^ controller = gcnew AdministradorController();
			frmAdministradorDatos^ formulario = gcnew frmAdministradorDatos(controller->GenerarId(), nullptr);

			// Si el sistema rechaza los datos se vuelve a mostrar el mismo formulario con lo ya escrito
			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				Administrador^ objeto = gcnew Administrador(formulario->GetId(), formulario->GetNombre(), formulario->GetClave(), formulario->GetCorreo(), formulario->GetTelefono());

				String^ error = controller->RegistrarAdministrador(objeto);
				if (error == nullptr) {
					MostrarExito("Administrador registrado correctamente.");
					return;
				}
				MostrarError("No se pudo registrar", error);
			}
		}

		/*Abre el mismo formulario con los datos del objeto elegido y guarda los cambios*/
		void Modificar(String^ id) {
			AdministradorController^ controller = gcnew AdministradorController();
			Administrador^ original = controller->ConsultarAdministrador(id);
			if (original == nullptr) {
				MostrarError("No se pudo modificar", "El administrador ya no existe.");
				return;
			}
			frmAdministradorDatos^ formulario = gcnew frmAdministradorDatos(id, original);

			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				Administrador^ objeto = gcnew Administrador(id, formulario->GetNombre(), formulario->GetClave(), formulario->GetCorreo(), formulario->GetTelefono());

				String^ error = controller->ModificarAdministrador(objeto);
				if (error == nullptr) {
					MostrarExito("Administrador modificado correctamente.");
					return;
				}
				MostrarError("No se pudo modificar", error);
			}
		}

		/*Elimina el objeto; devuelve el motivo del rechazo o nullptr si se elimino*/
		String^ Eliminar(String^ id) {
			AdministradorController^ controller = gcnew AdministradorController();
			return controller->EliminarAdministrador(id);
		}

		/*Texto que aparece en la pregunta de confirmacion antes de eliminar*/
		String^ Describir(String^ id) {
			AdministradorController^ controller = gcnew AdministradorController();
			auto objeto = controller->ConsultarAdministrador(id);
			if (objeto == nullptr) {
				return "el administrador " + id;
			}
			return "al administrador " + objeto->GetNombre() + " (" + id + ")";
		}

		String^ FiltroActual() {
			return "";
		}

		void Refrescar() {
			this->dgvDatos->Rows->Clear();
			Cargar(this->txtBuscar->Text->Trim(), FiltroActual());
		}

		/*Id (primera columna) de la fila elegida, o nullptr si no hay ninguna*/
		String^ IdSeleccionado() {
			if (this->dgvDatos->SelectedRows->Count == 0) {
				return nullptr;
			}
			Object^ valor = this->dgvDatos->SelectedRows[0]->Cells[0]->Value;
			if (valor == nullptr) {
				return nullptr;
			}
			return valor->ToString();
		}

		void AgregarFila(array<String^>^ celdas) {
			this->dgvDatos->Rows->Add(celdas);
		}

		static void MostrarError(String^ titulo, String^ mensaje) {
			MessageBox::Show(mensaje, titulo, MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		static void MostrarExito(String^ mensaje) {
			MessageBox::Show(mensaje, "Sigma", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	private: System::Void frmMantAdministradores_Load(System::Object^ sender, System::EventArgs^ e) {
			Refrescar();
		}

		// La busqueda es manual: solo se ejecuta con el boton Buscar o con Enter (una consulta por accion)
	private: System::Void txtBuscar_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
				e->SuppressKeyPress = true;
				Refrescar();
			}
		}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
			Refrescar();
		}

	private: System::Void dgvDatos_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			if (e->RowIndex >= 0) {
				btnModificar_Click(sender, e);
			}
		}

	private: System::Void btnCrear_Click(System::Object^ sender, System::EventArgs^ e) {
			Crear();
			Refrescar();
		}

	private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ id = IdSeleccionado();
			if (id == nullptr) {
				MessageBox::Show("Seleccione un registro de la lista para modificarlo.", "Sigma", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			Modificar(id);
			Refrescar();
		}

	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ id = IdSeleccionado();
			if (id == nullptr) {
				MessageBox::Show("Seleccione un registro de la lista para eliminarlo.", "Sigma", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			// Confirmacion de advertencia: el boton por defecto es "No" para evitar borrados por accidente
			System::Windows::Forms::DialogResult respuesta = MessageBox::Show(
				"¿Está seguro de que desea eliminar " + Describir(id) + "?\n\nEsta acción no se puede deshacer.",
				"Confirmar eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button2);
			if (respuesta != System::Windows::Forms::DialogResult::Yes) {
				return;
			}

			String^ error = Eliminar(id);
			if (error != nullptr) {
				MostrarError("No se pudo eliminar", error);
				return;
			}
			MostrarExito("Se eliminó correctamente.");
			Refrescar();
		}
	};
}
