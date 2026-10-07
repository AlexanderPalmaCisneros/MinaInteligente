#pragma once
#include "Utilidades.h"
#include "frmElegirTipo.h"
#include "frmLEDDatos.h"
#include "frmVentiladorDatos.h"
#include "frmSensorGasDatos.h"
#include "frmLectorRFIDDatos.h"

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
	/// Gestión de dispositivos
	/// </summary>
	public ref class frmMantDispositivos : public System::Windows::Forms::Form
	{
	public:
		frmMantDispositivos(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantDispositivos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblBuscar;
	private: System::Windows::Forms::TextBox^ txtBuscar;
	private: System::Windows::Forms::Label^ lblFiltro;
	private: System::Windows::Forms::ComboBox^ cmbFiltro;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::DataGridView^ dgvDatos;
	private: System::Windows::Forms::Button^ btnCrear;
	private: System::Windows::Forms::Button^ btnModificar;
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colZona;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDetalle;

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
			this->lblFiltro = (gcnew System::Windows::Forms::Label());
			this->cmbFiltro = (gcnew System::Windows::Forms::ComboBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->dgvDatos = (gcnew System::Windows::Forms::DataGridView());
			this->btnCrear = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colZona = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDetalle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDatos))->BeginInit();
			this->SuspendLayout();
			// 
			// lblBuscar
			// 
			this->lblBuscar->AutoSize = true;
			this->lblBuscar->Location = System::Drawing::Point(20, 24);
			this->lblBuscar->Name = L"lblBuscar";
			this->lblBuscar->Size = System::Drawing::Size(162, 13);
			this->lblBuscar->Text = L"Buscar por id, zona o tipo:";
			// 
			// txtBuscar
			// 
			this->txtBuscar->Location = System::Drawing::Point(240, 20);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(220, 20);
			this->txtBuscar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left));
			this->txtBuscar->TabIndex = 0;
			this->txtBuscar->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMantDispositivos::txtBuscar_KeyDown);
			// 
			// lblFiltro
			// 
			this->lblFiltro->AutoSize = true;
			this->lblFiltro->Location = System::Drawing::Point(480, 24);
			this->lblFiltro->Name = L"lblFiltro";
			this->lblFiltro->Size = System::Drawing::Size(28, 13);
			this->lblFiltro->Text = L"Tipo:";
			// 
			// cmbFiltro
			// 
			this->cmbFiltro->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbFiltro->FormattingEnabled = true;
			this->cmbFiltro->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"TODOS", L"LED", L"VENTILADOR", L"SENSOR GAS", L"LECTOR RFID"});
			this->cmbFiltro->Location = System::Drawing::Point(540, 20);
			this->cmbFiltro->Name = L"cmbFiltro";
			this->cmbFiltro->Size = System::Drawing::Size(150, 21);
			this->cmbFiltro->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left));
			this->cmbFiltro->TabIndex = 1;
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(710, 18);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(100, 28);
			this->btnBuscar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left));
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantDispositivos::btnBuscar_Click);
			// 
			// dgvDatos
			// 
			this->dgvDatos->AllowUserToAddRows = false;
			this->dgvDatos->AllowUserToDeleteRows = false;
			this->dgvDatos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvDatos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDatos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewTextBoxColumn^  >(5) {this->colId, this->colTipo, this->colZona, this->colEstado, this->colDetalle});
			this->dgvDatos->Location = System::Drawing::Point(20, 60);
			this->dgvDatos->MultiSelect = false;
			this->dgvDatos->Name = L"dgvDatos";
			this->dgvDatos->ReadOnly = true;
			this->dgvDatos->RowHeadersVisible = false;
			this->dgvDatos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvDatos->Size = System::Drawing::Size(840, 390);
			this->dgvDatos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->dgvDatos->TabIndex = 3;
			this->dgvDatos->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMantDispositivos::dgvDatos_CellDoubleClick);
			// 
			// colId
			// 
			this->colId->HeaderText = L"Id";
			this->colId->Name = L"colId";
			this->colId->ReadOnly = true;
			// 
			// colTipo
			// 
			this->colTipo->HeaderText = L"Tipo";
			this->colTipo->Name = L"colTipo";
			this->colTipo->ReadOnly = true;
			// 
			// colZona
			// 
			this->colZona->HeaderText = L"Zona";
			this->colZona->Name = L"colZona";
			this->colZona->ReadOnly = true;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->Name = L"colEstado";
			this->colEstado->ReadOnly = true;
			// 
			// colDetalle
			// 
			this->colDetalle->HeaderText = L"Detalle";
			this->colDetalle->Name = L"colDetalle";
			this->colDetalle->ReadOnly = true;
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
			this->btnCrear->Click += gcnew System::EventHandler(this, &frmMantDispositivos::btnCrear_Click);
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
			this->btnModificar->Click += gcnew System::EventHandler(this, &frmMantDispositivos::btnModificar_Click);
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
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantDispositivos::btnEliminar_Click);
			// 
			// frmMantDispositivos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 520);
			this->Controls->Add(this->lblBuscar);
			this->Controls->Add(this->txtBuscar);
			this->Controls->Add(this->lblFiltro);
			this->Controls->Add(this->cmbFiltro);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->dgvDatos);
			this->Controls->Add(this->btnCrear);
			this->Controls->Add(this->btnModificar);
			this->Controls->Add(this->btnEliminar);
			this->MinimumSize = System::Drawing::Size(700, 400);
			this->Name = L"frmMantDispositivos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Gestión de dispositivos";
			this->Load += gcnew System::EventHandler(this, &frmMantDispositivos::frmMantDispositivos_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDatos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		/*Llena la lista con los objetos que coincidan con el texto y el filtro*/
		void Cargar(String^ texto, String^ filtro) {
			DispositivoController^ dispositivoController = gcnew DispositivoController();
			for each (Dispositivo^ dispositivo in dispositivoController->BuscarDispositivos(texto, filtro)) {
				array<String^>^ fila = gcnew array<String^>(5);
				fila[0] = dispositivo->GetId();
				fila[1] = dispositivoController->ObtenerTipo(dispositivo);
				fila[2] = (dispositivo->GetZonaAsociada() != nullptr) ? dispositivo->GetZonaAsociada()->GetId() + " - " + dispositivo->GetZonaAsociada()->GetNombre() : "Sin zona";
				fila[3] = dispositivo->GetEstado().ToString();
				fila[4] = dispositivoController->ObtenerDetalle(dispositivo);
				AgregarFila(fila);
			}
		}

		/*Abre el formulario de datos vacio (con el id autogenerado) y registra el objeto*/
		void Crear() {
			DispositivoController^ dispositivoController = gcnew DispositivoController();

			// Si la lista esta filtrada por un tipo se crea de ese tipo; si no, primero se pregunta cual
			String^ tipo = FiltroActual();
			if (String::IsNullOrEmpty(tipo) || tipo == "TODOS") {
				frmElegirTipo^ formularioTipo = gcnew frmElegirTipo();
				if (formularioTipo->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
					return;
				}
				tipo = formularioTipo->GetTipo();
			}

			List<Zona^>^ zonas = (gcnew ZonaController())->ListarZonas();
			List<TipoGas^>^ tiposGas = (gcnew TipoGasController())->ListarTiposGas();
			if (tipo == "SENSOR GAS" && tiposGas->Count == 0) {
				MostrarError("No se pudo crear", "Primero debe registrar al menos un tipo de gas.");
				return;
			}

			if (tipo == "LED") CrearLED(zonas);
			else if (tipo == "VENTILADOR") CrearVentilador(zonas);
			else if (tipo == "SENSOR GAS") CrearSensorGas(zonas, tiposGas);
			else CrearLectorRFID(zonas);
		}

		/*Abre el mismo formulario con los datos del objeto elegido y guarda los cambios*/
		void Modificar(String^ id) {
			DispositivoController^ dispositivoController = gcnew DispositivoController();
			Dispositivo^ original = dispositivoController->ConsultarDispositivo(id);
			if (original == nullptr) {
				MostrarError("No se pudo modificar", "El dispositivo ya no existe.");
				return;
			}
			String^ tipo = dispositivoController->ObtenerTipo(original);

			List<Zona^>^ zonas = (gcnew ZonaController())->ListarZonas();
			List<TipoGas^>^ tiposGas = (gcnew TipoGasController())->ListarTiposGas();
			if (tipo == "LED") ModificarLED(safe_cast<LED^>(original), zonas);
			else if (tipo == "VENTILADOR") ModificarVentilador(safe_cast<Ventilador^>(original), zonas);
			else if (tipo == "SENSOR GAS") ModificarSensorGas(safe_cast<SensorGas^>(original), zonas, tiposGas);
			else ModificarLectorRFID(safe_cast<LectorRFID^>(original), zonas);
		}

		/*Elimina el objeto; devuelve el motivo del rechazo o nullptr si se elimino*/
		String^ Eliminar(String^ id) {
			DispositivoController^ dispositivoController = gcnew DispositivoController();
			return dispositivoController->EliminarDispositivo(id);
		}

		/*Texto que aparece en la pregunta de confirmacion antes de eliminar*/
		String^ Describir(String^ id) {
			DispositivoController^ dispositivoController = gcnew DispositivoController();
			Dispositivo^ dispositivo = dispositivoController->ConsultarDispositivo(id);
			if (dispositivo == nullptr) {
				return "el dispositivo " + id;
			}
			return "el dispositivo " + id + " (" + dispositivoController->ObtenerTipo(dispositivo) + ")";
		}

		void CrearLED(List<Zona^>^ zonas) {
			LEDController^ controller = gcnew LEDController();
			frmLEDDatos^ formulario = gcnew frmLEDDatos(controller->GenerarId(), nullptr, zonas);

			// Si el sistema rechaza los datos se vuelve a mostrar el mismo formulario con lo ya escrito
			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				LED^ dispositivo = gcnew LED(formulario->GetId(), formulario->GetZona(), ColorLED::ROJO, false);
				dispositivo->SetEstado(formulario->GetEstado());
				String^ error = controller->RegistrarLED(dispositivo);
				if (error == nullptr) {
					MostrarExito("Dispositivo registrado correctamente.");
					return;
				}
				MostrarError("No se pudo registrar", error);
			}
		}

		void ModificarLED(LED^ original, List<Zona^>^ zonas) {
			LEDController^ controller = gcnew LEDController();
			frmLEDDatos^ formulario = gcnew frmLEDDatos(original->GetId(), original, zonas);

			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				// El color y el encendido los decide el sistema: se conservan los del LED original
				LED^ dispositivo = gcnew LED(original->GetId(), formulario->GetZona(), original->GetColor(), original->GetEncendido());
				dispositivo->SetEstado(formulario->GetEstado());
				String^ error = controller->ModificarLED(dispositivo);
				if (error == nullptr) {
					MostrarExito("Dispositivo modificado correctamente.");
					return;
				}
				MostrarError("No se pudo modificar", error);
			}
		}

		void CrearVentilador(List<Zona^>^ zonas) {
			VentiladorController^ controller = gcnew VentiladorController();
			frmVentiladorDatos^ formulario = gcnew frmVentiladorDatos(controller->GenerarId(), nullptr, zonas);

			// Si el sistema rechaza los datos se vuelve a mostrar el mismo formulario con lo ya escrito
			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				Ventilador^ dispositivo = gcnew Ventilador(formulario->GetId(), formulario->GetZona(), formulario->GetCaudal(), formulario->GetEstado());
				String^ error = controller->RegistrarVentilador(dispositivo);
				if (error == nullptr) {
					MostrarExito("Dispositivo registrado correctamente.");
					return;
				}
				MostrarError("No se pudo registrar", error);
			}
		}

		void ModificarVentilador(Ventilador^ original, List<Zona^>^ zonas) {
			VentiladorController^ controller = gcnew VentiladorController();
			frmVentiladorDatos^ formulario = gcnew frmVentiladorDatos(original->GetId(), original, zonas);

			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				Ventilador^ dispositivo = gcnew Ventilador(original->GetId(), formulario->GetZona(), formulario->GetCaudal(), formulario->GetEstado());
				String^ error = controller->ModificarVentilador(dispositivo);
				if (error == nullptr) {
					MostrarExito("Dispositivo modificado correctamente.");
					return;
				}
				MostrarError("No se pudo modificar", error);
			}
		}

		void CrearSensorGas(List<Zona^>^ zonas, List<TipoGas^>^ tiposGas) {
			SensorGasController^ controller = gcnew SensorGasController();
			frmSensorGasDatos^ formulario = gcnew frmSensorGasDatos(controller->GenerarId(), nullptr, zonas, tiposGas);

			// Si el sistema rechaza los datos se vuelve a mostrar el mismo formulario con lo ya escrito
			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				SensorGas^ dispositivo = gcnew SensorGas(formulario->GetId(), formulario->GetZona(), formulario->GetEstado(), formulario->GetTipoGas());
				String^ error = controller->RegistrarSensorGas(dispositivo);
				if (error == nullptr) {
					MostrarExito("Dispositivo registrado correctamente.");
					return;
				}
				MostrarError("No se pudo registrar", error);
			}
		}

		void ModificarSensorGas(SensorGas^ original, List<Zona^>^ zonas, List<TipoGas^>^ tiposGas) {
			SensorGasController^ controller = gcnew SensorGasController();
			frmSensorGasDatos^ formulario = gcnew frmSensorGasDatos(original->GetId(), original, zonas, tiposGas);

			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				SensorGas^ dispositivo = gcnew SensorGas(original->GetId(), formulario->GetZona(), formulario->GetEstado(), formulario->GetTipoGas());
				String^ error = controller->ModificarSensorGas(dispositivo);
				if (error == nullptr) {
					MostrarExito("Dispositivo modificado correctamente.");
					return;
				}
				MostrarError("No se pudo modificar", error);
			}
		}

		void CrearLectorRFID(List<Zona^>^ zonas) {
			LectorRFIDController^ controller = gcnew LectorRFIDController();
			frmLectorRFIDDatos^ formulario = gcnew frmLectorRFIDDatos(controller->GenerarId(), nullptr, zonas);

			// Si el sistema rechaza los datos se vuelve a mostrar el mismo formulario con lo ya escrito
			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				LectorRFID^ dispositivo = gcnew LectorRFID(formulario->GetId(), formulario->GetZona(), formulario->GetEstado());
				String^ error = controller->RegistrarLectorRFID(dispositivo);
				if (error == nullptr) {
					MostrarExito("Dispositivo registrado correctamente.");
					return;
				}
				MostrarError("No se pudo registrar", error);
			}
		}

		void ModificarLectorRFID(LectorRFID^ original, List<Zona^>^ zonas) {
			LectorRFIDController^ controller = gcnew LectorRFIDController();
			frmLectorRFIDDatos^ formulario = gcnew frmLectorRFIDDatos(original->GetId(), original, zonas);

			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				LectorRFID^ dispositivo = gcnew LectorRFID(original->GetId(), formulario->GetZona(), formulario->GetEstado());
				String^ error = controller->ModificarLectorRFID(dispositivo);
				if (error == nullptr) {
					MostrarExito("Dispositivo modificado correctamente.");
					return;
				}
				MostrarError("No se pudo modificar", error);
			}
		}

		String^ FiltroActual() {
			if (this->cmbFiltro->SelectedItem != nullptr) {
				return this->cmbFiltro->SelectedItem->ToString();
			}
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

	private: System::Void frmMantDispositivos_Load(System::Object^ sender, System::EventArgs^ e) {
			this->cmbFiltro->SelectedIndex = 0;
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
