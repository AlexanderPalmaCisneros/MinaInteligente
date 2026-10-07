#pragma once
#include "Utilidades.h"
#include "frmZonaDatos.h"

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
	/// Grafo de zonas
	/// </summary>
	public ref class frmGrafoZonas : public System::Windows::Forms::Form
	{
	public:
		frmGrafoZonas(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmGrafoZonas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlEncabezado;
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblSubtitulo;
	private: System::Windows::Forms::Panel^ pnlGrafo;
	private: System::Windows::Forms::PictureBox^ picGrafo;
	private: System::Windows::Forms::GroupBox^ grpSeleccion;
	private: System::Windows::Forms::Label^ lblSeleccion;
	private: System::Windows::Forms::Label^ lblDetalle;
	private: System::Windows::Forms::GroupBox^ grpAgregar;
	private: System::Windows::Forms::Label^ lblDisponible;
	private: System::Windows::Forms::ComboBox^ cmbZonaDisponible;
	private: System::Windows::Forms::Button^ btnNuevaZona;
	private: System::Windows::Forms::Button^ btnAgregarSalida;
	private: System::Windows::Forms::Label^ lblCaras;
	private: System::Windows::Forms::Button^ btnAgregarArriba;
	private: System::Windows::Forms::Label^ lblSalidaIzquierda;
	private: System::Windows::Forms::Label^ lblCentro;
	private: System::Windows::Forms::Button^ btnAgregarDerecha;
	private: System::Windows::Forms::Button^ btnAgregarAbajo;
	private: System::Windows::Forms::Button^ btnQuitar;
	private: System::Windows::Forms::GroupBox^ grpLeyenda;
	private: System::Windows::Forms::Label^ lblColorBajo;
	private: System::Windows::Forms::Label^ lblBajo;
	private: System::Windows::Forms::Label^ lblColorMedio;
	private: System::Windows::Forms::Label^ lblMedio;
	private: System::Windows::Forms::Label^ lblColorAlto;
	private: System::Windows::Forms::Label^ lblAlto;
	private: System::Windows::Forms::Label^ lblColorCritico;
	private: System::Windows::Forms::Label^ lblCritico;
	private: System::Windows::Forms::Label^ lblColorAislada;
	private: System::Windows::Forms::Label^ lblAislada;
	private: System::Windows::Forms::Timer^ tmrActualizar;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

	private:
		// Medidas del dibujo: todos los cuadrados son del mismo tamano
		static const int TAMANO = 100;
		static const int SEPARACION = 50;
		static const int MARGEN_IZQUIERDO = 140;
		static const int MARGEN_SUPERIOR = 16;
		static const int ALTO_CABECERA = 24;

		GrafoZonas^ grafo;
		List<Zona^>^ disponibles;
		String^ idSeleccionada;
		int filaMinima;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pnlEncabezado = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->pnlGrafo = (gcnew System::Windows::Forms::Panel());
			this->picGrafo = (gcnew System::Windows::Forms::PictureBox());
			this->grpSeleccion = (gcnew System::Windows::Forms::GroupBox());
			this->lblSeleccion = (gcnew System::Windows::Forms::Label());
			this->lblDetalle = (gcnew System::Windows::Forms::Label());
			this->grpAgregar = (gcnew System::Windows::Forms::GroupBox());
			this->lblDisponible = (gcnew System::Windows::Forms::Label());
			this->cmbZonaDisponible = (gcnew System::Windows::Forms::ComboBox());
			this->btnNuevaZona = (gcnew System::Windows::Forms::Button());
			this->btnAgregarSalida = (gcnew System::Windows::Forms::Button());
			this->lblCaras = (gcnew System::Windows::Forms::Label());
			this->btnAgregarArriba = (gcnew System::Windows::Forms::Button());
			this->lblSalidaIzquierda = (gcnew System::Windows::Forms::Label());
			this->lblCentro = (gcnew System::Windows::Forms::Label());
			this->btnAgregarDerecha = (gcnew System::Windows::Forms::Button());
			this->btnAgregarAbajo = (gcnew System::Windows::Forms::Button());
			this->btnQuitar = (gcnew System::Windows::Forms::Button());
			this->grpLeyenda = (gcnew System::Windows::Forms::GroupBox());
			this->lblColorBajo = (gcnew System::Windows::Forms::Label());
			this->lblBajo = (gcnew System::Windows::Forms::Label());
			this->lblColorMedio = (gcnew System::Windows::Forms::Label());
			this->lblMedio = (gcnew System::Windows::Forms::Label());
			this->lblColorAlto = (gcnew System::Windows::Forms::Label());
			this->lblAlto = (gcnew System::Windows::Forms::Label());
			this->lblColorCritico = (gcnew System::Windows::Forms::Label());
			this->lblCritico = (gcnew System::Windows::Forms::Label());
			this->lblColorAislada = (gcnew System::Windows::Forms::Label());
			this->lblAislada = (gcnew System::Windows::Forms::Label());
			this->tmrActualizar = (gcnew System::Windows::Forms::Timer(this->components));
			this->pnlEncabezado->SuspendLayout();
			this->pnlGrafo->SuspendLayout();
			this->grpSeleccion->SuspendLayout();
			this->grpAgregar->SuspendLayout();
			this->grpLeyenda->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGrafo))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlEncabezado
			// 
			this->pnlEncabezado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pnlEncabezado->Controls->Add(this->lblTitulo);
			this->pnlEncabezado->Controls->Add(this->lblSubtitulo);
			this->pnlEncabezado->Location = System::Drawing::Point(0, 0);
			this->pnlEncabezado->Name = L"pnlEncabezado";
			this->pnlEncabezado->Size = System::Drawing::Size(1100, 56);
			this->pnlEncabezado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(14, 6);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(260, 28);
			this->lblTitulo->Text = L"Grafo de zonas de la mina";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->lblSubtitulo->Location = System::Drawing::Point(17, 34);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(620, 15);
			this->lblSubtitulo->Text = L"Seleccione una zona y haga clic en un cuadro punteado (o use los botones) para colgar otra. La salida está a la izquierda.";
			// 
			// pnlGrafo
			// 
			this->pnlGrafo->AutoScroll = true;
			this->pnlGrafo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->pnlGrafo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlGrafo->Controls->Add(this->picGrafo);
			this->pnlGrafo->Location = System::Drawing::Point(16, 72);
			this->pnlGrafo->Name = L"pnlGrafo";
			this->pnlGrafo->Size = System::Drawing::Size(760, 592);
			this->pnlGrafo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) | System::Windows::Forms::AnchorStyles::Left) | System::Windows::Forms::AnchorStyles::Right));
			this->pnlGrafo->TabIndex = 0;
			// 
			// picGrafo
			// 
			this->picGrafo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(250)));
			this->picGrafo->Location = System::Drawing::Point(0, 0);
			this->picGrafo->Name = L"picGrafo";
			this->picGrafo->Size = System::Drawing::Size(758, 590);
			this->picGrafo->TabStop = false;
			this->picGrafo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmGrafoZonas::picGrafo_Paint);
			this->picGrafo->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmGrafoZonas::picGrafo_MouseClick);
			this->picGrafo->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmGrafoZonas::picGrafo_MouseMove);
			// 
			// grpSeleccion
			// 
			this->grpSeleccion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->grpSeleccion->Controls->Add(this->lblSeleccion);
			this->grpSeleccion->Controls->Add(this->lblDetalle);
			this->grpSeleccion->Location = System::Drawing::Point(792, 66);
			this->grpSeleccion->Name = L"grpSeleccion";
			this->grpSeleccion->Size = System::Drawing::Size(292, 120);
			this->grpSeleccion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->grpSeleccion->Text = L"Zona seleccionada";
			this->grpSeleccion->TabStop = false;
			// 
			// lblSeleccion
			// 
			this->lblSeleccion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblSeleccion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblSeleccion->Location = System::Drawing::Point(12, 24);
			this->lblSeleccion->Name = L"lblSeleccion";
			this->lblSeleccion->Size = System::Drawing::Size(268, 22);
			this->lblSeleccion->Text = L"(haga clic en un cuadrado)";
			// 
			// lblDetalle
			// 
			this->lblDetalle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblDetalle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(110)));
			this->lblDetalle->Location = System::Drawing::Point(12, 50);
			this->lblDetalle->Name = L"lblDetalle";
			this->lblDetalle->Size = System::Drawing::Size(268, 62);
			this->lblDetalle->Text = L"";
			// 
			// grpAgregar
			// 
			this->grpAgregar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->grpAgregar->Controls->Add(this->lblDisponible);
			this->grpAgregar->Controls->Add(this->cmbZonaDisponible);
			this->grpAgregar->Controls->Add(this->btnNuevaZona);
			this->grpAgregar->Controls->Add(this->btnAgregarSalida);
			this->grpAgregar->Controls->Add(this->lblCaras);
			this->grpAgregar->Controls->Add(this->btnAgregarArriba);
			this->grpAgregar->Controls->Add(this->lblSalidaIzquierda);
			this->grpAgregar->Controls->Add(this->lblCentro);
			this->grpAgregar->Controls->Add(this->btnAgregarDerecha);
			this->grpAgregar->Controls->Add(this->btnAgregarAbajo);
			this->grpAgregar->Location = System::Drawing::Point(792, 192);
			this->grpAgregar->Name = L"grpAgregar";
			this->grpAgregar->Size = System::Drawing::Size(292, 268);
			this->grpAgregar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->grpAgregar->Text = L"Agregar zona";
			this->grpAgregar->TabStop = false;
			// 
			// lblDisponible
			// 
			this->lblDisponible->AutoSize = true;
			this->lblDisponible->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblDisponible->Location = System::Drawing::Point(12, 24);
			this->lblDisponible->Name = L"lblDisponible";
			this->lblDisponible->Size = System::Drawing::Size(90, 15);
			this->lblDisponible->Text = L"Zona a colgar:";
			// 
			// cmbZonaDisponible
			// 
			this->cmbZonaDisponible->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbZonaDisponible->FormattingEnabled = true;
			this->cmbZonaDisponible->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->cmbZonaDisponible->Location = System::Drawing::Point(12, 44);
			this->cmbZonaDisponible->Name = L"cmbZonaDisponible";
			this->cmbZonaDisponible->Size = System::Drawing::Size(268, 23);
			this->cmbZonaDisponible->TabIndex = 1;
			this->cmbZonaDisponible->SelectedIndexChanged += gcnew System::EventHandler(this, &frmGrafoZonas::cmbZonaDisponible_SelectedIndexChanged);
			// 
			// btnNuevaZona
			// 
			this->btnNuevaZona->BackColor = System::Drawing::Color::White;
			this->btnNuevaZona->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btnNuevaZona->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNuevaZona->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnNuevaZona->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btnNuevaZona->Location = System::Drawing::Point(12, 75);
			this->btnNuevaZona->Name = L"btnNuevaZona";
			this->btnNuevaZona->Size = System::Drawing::Size(268, 30);
			this->btnNuevaZona->TabIndex = 2;
			this->btnNuevaZona->Text = L"+  Crear zona nueva...";
			this->btnNuevaZona->UseVisualStyleBackColor = false;
			this->btnNuevaZona->Click += gcnew System::EventHandler(this, &frmGrafoZonas::btnNuevaZona_Click);
			// 
			// btnAgregarSalida
			// 
			this->btnAgregarSalida->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btnAgregarSalida->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btnAgregarSalida->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAgregarSalida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btnAgregarSalida->ForeColor = System::Drawing::Color::White;
			this->btnAgregarSalida->Location = System::Drawing::Point(12, 113);
			this->btnAgregarSalida->Name = L"btnAgregarSalida";
			this->btnAgregarSalida->Size = System::Drawing::Size(268, 32);
			this->btnAgregarSalida->TabIndex = 3;
			this->btnAgregarSalida->Text = L"Agregar como salida";
			this->btnAgregarSalida->UseVisualStyleBackColor = false;
			this->btnAgregarSalida->Click += gcnew System::EventHandler(this, &frmGrafoZonas::btnAgregarSalida_Click);
			// 
			// lblCaras
			// 
			this->lblCaras->AutoSize = true;
			this->lblCaras->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblCaras->Location = System::Drawing::Point(12, 154);
			this->lblCaras->Name = L"lblCaras";
			this->lblCaras->Size = System::Drawing::Size(110, 15);
			this->lblCaras->Text = L"Colgar en la cara:";
			// 
			// btnAgregarArriba
			// 
			this->btnAgregarArriba->BackColor = System::Drawing::Color::White;
			this->btnAgregarArriba->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->btnAgregarArriba->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAgregarArriba->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnAgregarArriba->Location = System::Drawing::Point(104, 174);
			this->btnAgregarArriba->Name = L"btnAgregarArriba";
			this->btnAgregarArriba->Size = System::Drawing::Size(84, 28);
			this->btnAgregarArriba->TabIndex = 4;
			this->btnAgregarArriba->Text = L"▲ Arriba";
			this->btnAgregarArriba->UseVisualStyleBackColor = false;
			this->btnAgregarArriba->Click += gcnew System::EventHandler(this, &frmGrafoZonas::btnAgregarArriba_Click);
			// 
			// lblSalidaIzquierda
			// 
			this->lblSalidaIzquierda->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->lblSalidaIzquierda->ForeColor = System::Drawing::Color::Gray;
			this->lblSalidaIzquierda->Location = System::Drawing::Point(8, 211);
			this->lblSalidaIzquierda->Name = L"lblSalidaIzquierda";
			this->lblSalidaIzquierda->Size = System::Drawing::Size(92, 15);
			this->lblSalidaIzquierda->Text = L"◀ hacia la salida";
			// 
			// lblCentro
			// 
			this->lblCentro->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(236)));
			this->lblCentro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblCentro->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lblCentro->Location = System::Drawing::Point(104, 206);
			this->lblCentro->Name = L"lblCentro";
			this->lblCentro->Size = System::Drawing::Size(84, 24);
			this->lblCentro->Text = L"—";
			this->lblCentro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnAgregarDerecha
			// 
			this->btnAgregarDerecha->BackColor = System::Drawing::Color::White;
			this->btnAgregarDerecha->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->btnAgregarDerecha->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAgregarDerecha->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnAgregarDerecha->Location = System::Drawing::Point(196, 204);
			this->btnAgregarDerecha->Name = L"btnAgregarDerecha";
			this->btnAgregarDerecha->Size = System::Drawing::Size(84, 28);
			this->btnAgregarDerecha->TabIndex = 5;
			this->btnAgregarDerecha->Text = L"Derecha ▶";
			this->btnAgregarDerecha->UseVisualStyleBackColor = false;
			this->btnAgregarDerecha->Click += gcnew System::EventHandler(this, &frmGrafoZonas::btnAgregarDerecha_Click);
			// 
			// btnAgregarAbajo
			// 
			this->btnAgregarAbajo->BackColor = System::Drawing::Color::White;
			this->btnAgregarAbajo->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->btnAgregarAbajo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAgregarAbajo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnAgregarAbajo->Location = System::Drawing::Point(104, 234);
			this->btnAgregarAbajo->Name = L"btnAgregarAbajo";
			this->btnAgregarAbajo->Size = System::Drawing::Size(84, 28);
			this->btnAgregarAbajo->TabIndex = 6;
			this->btnAgregarAbajo->Text = L"▼ Abajo";
			this->btnAgregarAbajo->UseVisualStyleBackColor = false;
			this->btnAgregarAbajo->Click += gcnew System::EventHandler(this, &frmGrafoZonas::btnAgregarAbajo_Click);
			// 
			// btnQuitar
			// 
			this->btnQuitar->BackColor = System::Drawing::Color::White;
			this->btnQuitar->FlatAppearance->BorderColor = System::Drawing::Color::Firebrick;
			this->btnQuitar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnQuitar->ForeColor = System::Drawing::Color::Firebrick;
			this->btnQuitar->Location = System::Drawing::Point(792, 468);
			this->btnQuitar->Name = L"btnQuitar";
			this->btnQuitar->Size = System::Drawing::Size(292, 32);
			this->btnQuitar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnQuitar->TabIndex = 7;
			this->btnQuitar->Text = L"Quitar zona del grafo";
			this->btnQuitar->UseVisualStyleBackColor = false;
			this->btnQuitar->Click += gcnew System::EventHandler(this, &frmGrafoZonas::btnQuitar_Click);
			// 
			// grpLeyenda
			// 
			this->grpLeyenda->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->grpLeyenda->Controls->Add(this->lblColorBajo);
			this->grpLeyenda->Controls->Add(this->lblBajo);
			this->grpLeyenda->Controls->Add(this->lblColorMedio);
			this->grpLeyenda->Controls->Add(this->lblMedio);
			this->grpLeyenda->Controls->Add(this->lblColorAlto);
			this->grpLeyenda->Controls->Add(this->lblAlto);
			this->grpLeyenda->Controls->Add(this->lblColorCritico);
			this->grpLeyenda->Controls->Add(this->lblCritico);
			this->grpLeyenda->Controls->Add(this->lblColorAislada);
			this->grpLeyenda->Controls->Add(this->lblAislada);
			this->grpLeyenda->Location = System::Drawing::Point(792, 508);
			this->grpLeyenda->Name = L"grpLeyenda";
			this->grpLeyenda->Size = System::Drawing::Size(292, 156);
			this->grpLeyenda->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->grpLeyenda->Text = L"Nivel de emergencia";
			this->grpLeyenda->TabStop = false;
			// 
			// lblColorBajo
			// 
			this->lblColorBajo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->lblColorBajo->Location = System::Drawing::Point(12, 24);
			this->lblColorBajo->Name = L"lblColorBajo";
			this->lblColorBajo->Size = System::Drawing::Size(18, 18);
			this->lblColorBajo->Text = L"";
			// 
			// lblBajo
			// 
			this->lblBajo->AutoSize = true;
			this->lblBajo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblBajo->Location = System::Drawing::Point(38, 25);
			this->lblBajo->Name = L"lblBajo";
			this->lblBajo->Size = System::Drawing::Size(200, 15);
			this->lblBajo->Text = L"BAJO — menor que desactivación";
			// 
			// lblColorMedio
			// 
			this->lblColorMedio->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->lblColorMedio->Location = System::Drawing::Point(12, 48);
			this->lblColorMedio->Name = L"lblColorMedio";
			this->lblColorMedio->Size = System::Drawing::Size(18, 18);
			this->lblColorMedio->Text = L"";
			// 
			// lblMedio
			// 
			this->lblMedio->AutoSize = true;
			this->lblMedio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblMedio->Location = System::Drawing::Point(38, 49);
			this->lblMedio->Name = L"lblMedio";
			this->lblMedio->Size = System::Drawing::Size(200, 15);
			this->lblMedio->Text = L"MEDIO — menor que activación";
			// 
			// lblColorAlto
			// 
			this->lblColorAlto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->lblColorAlto->Location = System::Drawing::Point(12, 72);
			this->lblColorAlto->Name = L"lblColorAlto";
			this->lblColorAlto->Size = System::Drawing::Size(18, 18);
			this->lblColorAlto->Text = L"";
			// 
			// lblAlto
			// 
			this->lblAlto->AutoSize = true;
			this->lblAlto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblAlto->Location = System::Drawing::Point(38, 73);
			this->lblAlto->Name = L"lblAlto";
			this->lblAlto->Size = System::Drawing::Size(200, 15);
			this->lblAlto->Text = L"ALTO — menor que crítico";
			// 
			// lblColorCritico
			// 
			this->lblColorCritico->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(215)), static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->lblColorCritico->Location = System::Drawing::Point(12, 96);
			this->lblColorCritico->Name = L"lblColorCritico";
			this->lblColorCritico->Size = System::Drawing::Size(18, 18);
			this->lblColorCritico->Text = L"";
			// 
			// lblCritico
			// 
			this->lblCritico->AutoSize = true;
			this->lblCritico->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblCritico->Location = System::Drawing::Point(38, 97);
			this->lblCritico->Name = L"lblCritico";
			this->lblCritico->Size = System::Drawing::Size(200, 15);
			this->lblCritico->Text = L"CRÍTICO — umbral crítico o más";
			// 
			// lblColorAislada
			// 
			this->lblColorAislada->BackColor = System::Drawing::Color::OrangeRed;
			this->lblColorAislada->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblColorAislada->ForeColor = System::Drawing::Color::White;
			this->lblColorAislada->Location = System::Drawing::Point(12, 122);
			this->lblColorAislada->Name = L"lblColorAislada";
			this->lblColorAislada->Size = System::Drawing::Size(18, 18);
			this->lblColorAislada->Text = L"!";
			this->lblColorAislada->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblAislada
			// 
			this->lblAislada->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblAislada->Location = System::Drawing::Point(38, 120);
			this->lblAislada->Name = L"lblAislada";
			this->lblAislada->Size = System::Drawing::Size(248, 32);
			this->lblAislada->Text = L"Aislada: su ruta de escape pasa por una zona crítica";
			// 
			// tmrActualizar
			// 
			this->tmrActualizar->Interval = 3000;
			this->tmrActualizar->Tick += gcnew System::EventHandler(this, &frmGrafoZonas::tmrActualizar_Tick);
			// 
			// frmGrafoZonas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1100, 680);
			this->Controls->Add(this->pnlEncabezado);
			this->Controls->Add(this->pnlGrafo);
			this->Controls->Add(this->grpSeleccion);
			this->Controls->Add(this->grpAgregar);
			this->Controls->Add(this->btnQuitar);
			this->Controls->Add(this->grpLeyenda);
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(244)));
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->MinimumSize = System::Drawing::Size(1000, 620);
			this->Name = L"frmGrafoZonas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Grafo de zonas";
			this->Load += gcnew System::EventHandler(this, &frmGrafoZonas::frmGrafoZonas_Load);
			this->pnlEncabezado->ResumeLayout(false);
			this->pnlGrafo->ResumeLayout(false);
			this->grpSeleccion->ResumeLayout(false);
			this->grpSeleccion->PerformLayout();
			this->grpAgregar->ResumeLayout(false);
			this->grpAgregar->PerformLayout();
			this->grpLeyenda->ResumeLayout(false);
			this->grpLeyenda->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGrafo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		/*Vuelve a leer el grafo (y las concentraciones) y redibuja*/
		void RecargarGrafo() {
			GrafoZonasController^ grafoController = gcnew GrafoZonasController();
			this->grafo = grafoController->CargarGrafo();
			if (ZonaSeleccionada() == nullptr) {
				this->idSeleccionada = nullptr;
			}

			// Se deja una fila libre arriba, una abajo y una columna a la derecha para los cuadros punteados
			int filaMenor = 0;
			int filaMayor = 0;
			int columnaMayor = 0;
			for each (Zona^ zona in this->grafo->ObtenerZonas()) {
				filaMenor = Math::Min(filaMenor, zona->GetFila());
				filaMayor = Math::Max(filaMayor, zona->GetFila());
				columnaMayor = Math::Max(columnaMayor, zona->GetColumna());
			}
			this->filaMinima = filaMenor - 1;
			int ancho = MARGEN_IZQUIERDO + (columnaMayor + 2) * (TAMANO + SEPARACION);
			int alto = MARGEN_SUPERIOR + (filaMayor - this->filaMinima + 2) * (TAMANO + SEPARACION);
			this->picGrafo->Size = System::Drawing::Size(Math::Max(ancho, this->pnlGrafo->ClientSize.Width),
				Math::Max(alto, this->pnlGrafo->ClientSize.Height));

			ActualizarBotones();
			this->picGrafo->Invalidate();
		}

		/*Zonas que todavia no estan en el grafo (se elige una para colgarla)*/
		void RecargarDisponibles(String^ idElegir) {
			GrafoZonasController^ grafoController = gcnew GrafoZonasController();
			this->disponibles = grafoController->ZonasDisponibles();
			this->cmbZonaDisponible->Items->Clear();
			for each (Zona^ zona in this->disponibles) {
				this->cmbZonaDisponible->Items->Add(zona->GetId() + " - " + zona->GetNombre());
			}
			for (int i = 0; i < this->disponibles->Count; i++) {
				if (this->disponibles[i]->GetId() == idElegir) {
					this->cmbZonaDisponible->SelectedIndex = i;
				}
			}
			if (this->cmbZonaDisponible->SelectedIndex < 0 && this->cmbZonaDisponible->Items->Count > 0) {
				this->cmbZonaDisponible->SelectedIndex = 0;
			}
		}

		Zona^ ZonaSeleccionada() {
			if (this->grafo == nullptr || this->idSeleccionada == nullptr) {
				return nullptr;
			}
			for each (Zona^ zona in this->grafo->ObtenerZonas()) {
				if (zona->GetId() == this->idSeleccionada) {
					return zona;
				}
			}
			return nullptr;
		}

		Zona^ ZonaElegida() {
			int posicion = this->cmbZonaDisponible->SelectedIndex;
			if (this->disponibles == nullptr || posicion < 0 || posicion >= this->disponibles->Count) {
				return nullptr;
			}
			return this->disponibles[posicion];
		}

		/*Fila y columna de la celda que queda en esa cara de la zona*/
		static void CeldaDeCara(Zona^ zona, CaraZona cara, int% fila, int% columna) {
			fila = zona->GetFila();
			columna = zona->GetColumna();
			if (cara == CaraZona::ARRIBA) fila = fila - 1;
			else if (cara == CaraZona::ABAJO) fila = fila + 1;
			else columna = columna + 1;
		}

		bool CaraLibre(Zona^ zona, CaraZona cara) {
			int fila;
			int columna;
			CeldaDeCara(zona, cara, fila, columna);
			return this->grafo->ObtenerZonaEn(fila, columna) == nullptr;
		}

		/*Cada boton de cara solo se habilita si esa celda esta libre*/
		void ActualizarBotones() {
			bool vacio = (this->grafo == nullptr || this->grafo->ObtenerZonas()->Count == 0);
			bool hayElegida = (ZonaElegida() != nullptr);
			Zona^ seleccionada = ZonaSeleccionada();

			this->btnAgregarSalida->Enabled = vacio && hayElegida;
			this->btnAgregarSalida->BackColor = this->btnAgregarSalida->Enabled ? Color::FromArgb(0, 120, 215) : Color::FromArgb(200, 208, 216);
			this->btnAgregarArriba->Enabled = seleccionada != nullptr && hayElegida && CaraLibre(seleccionada, CaraZona::ARRIBA);
			this->btnAgregarDerecha->Enabled = seleccionada != nullptr && hayElegida && CaraLibre(seleccionada, CaraZona::DERECHA);
			this->btnAgregarAbajo->Enabled = seleccionada != nullptr && hayElegida && CaraLibre(seleccionada, CaraZona::ABAJO);
			this->btnQuitar->Enabled = (seleccionada != nullptr);

			if (seleccionada == nullptr) {
				this->lblSeleccion->Text = vacio ? "(el grafo está vacío)" : "(haga clic en un cuadrado)";
				this->lblDetalle->Text = vacio ? "Elija una zona en \"Zona a colgar\" y pulse \"Agregar como salida\"." : "";
				this->lblCentro->Text = "—";
				return;
			}

			GrafoZonasController^ grafoController = gcnew GrafoZonasController();
			this->lblSeleccion->Text = seleccionada->GetId() + " - " + seleccionada->GetNombre();
			this->lblCentro->Text = seleccionada->GetId();

			// Ruta de escape: de la zona elegida hasta la salida
			String^ ruta = "";
			for each (Zona^ paso in this->grafo->ObtenerRutaEscape(seleccionada)) {
				ruta = (ruta == "") ? paso->GetId() : ruta + L" → " + paso->GetId();
			}
			String^ detalle = "Nivel " + NombreNivel(grafoController->ObtenerNivelRiesgo(seleccionada)) + "  ·  " +
				Utilidades::FormatoDouble(seleccionada->GetConcentracionActual()) + " ppm\nRuta de escape: " + ruta;
			if (grafoController->EstaAislada(this->grafo, seleccionada)) {
				detalle = detalle + "\n¡Aislada! Su ruta pasa por una zona crítica.";
			}
			this->lblDetalle->Text = detalle;
		}

		/*Rectangulo del cuadrado de una celda dentro del dibujo*/
		System::Drawing::Rectangle Celda(int fila, int columna) {
			int x = MARGEN_IZQUIERDO + columna * (TAMANO + SEPARACION);
			int y = MARGEN_SUPERIOR + (fila - this->filaMinima) * (TAMANO + SEPARACION);
			return System::Drawing::Rectangle(x, y, TAMANO, TAMANO);
		}

		System::Drawing::Rectangle Cuadrado(Zona^ zona) {
			return Celda(zona->GetFila(), zona->GetColumna());
		}

		static RectangleF AFlotante(System::Drawing::Rectangle r) {
			return RectangleF((float)r.X, (float)r.Y, (float)r.Width, (float)r.Height);
		}

		static String^ NombreNivel(NivelRiesgo nivel) {
			if (nivel == NivelRiesgo::CRITICO) return "CRÍTICO";
			return nivel.ToString();
		}

		static Color ColorNivel(NivelRiesgo nivel) {
			if (nivel == NivelRiesgo::CRITICO) return Color::FromArgb(215, 45, 45);
			if (nivel == NivelRiesgo::ALTO) return Color::FromArgb(240, 130, 30);
			if (nivel == NivelRiesgo::MEDIO) return Color::FromArgb(240, 190, 40);
			return Color::FromArgb(46, 160, 90);
		}

		/*Mezcla el color con blanco (cantidad 0 = igual, 1 = blanco)*/
		static Color Aclarar(Color color, double cantidad) {
			return Color::FromArgb((int)(color.R + (255 - color.R) * cantidad), (int)(color.G + (255 - color.G) * cantidad),
				(int)(color.B + (255 - color.B) * cantidad));
		}

		static Color Oscurecer(Color color, double factor) {
			return Color::FromArgb((int)(color.R * factor), (int)(color.G * factor), (int)(color.B * factor));
		}

		/*Rectangulo con esquinas redondeadas*/
		static System::Drawing::Drawing2D::GraphicsPath^ Redondeado(System::Drawing::Rectangle r, int radio) {
			System::Drawing::Drawing2D::GraphicsPath^ camino = gcnew System::Drawing::Drawing2D::GraphicsPath();
			int d = radio * 2;
			camino->AddArc(r.X, r.Y, d, d, 180.0F, 90.0F);
			camino->AddArc(r.Right - d, r.Y, d, d, 270.0F, 90.0F);
			camino->AddArc(r.Right - d, r.Bottom - d, d, d, 0.0F, 90.0F);
			camino->AddArc(r.X, r.Bottom - d, d, d, 90.0F, 90.0F);
			camino->CloseFigure();
			return camino;
		}

		void Agregar(CaraZona cara) {
			Zona^ elegida = ZonaElegida();
			Zona^ seleccionada = ZonaSeleccionada();
			if (seleccionada == nullptr) {
				return;
			}
			if (elegida == nullptr) {
				MessageBox::Show("Elija primero en \"Zona a colgar\" la zona que desea agregar, o cree una nueva.", "Sigma",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			GrafoZonasController^ grafoController = gcnew GrafoZonasController();
			String^ error = grafoController->AgregarZona(elegida->GetId(), seleccionada->GetId(), cara);
			if (error != nullptr) {
				MessageBox::Show(error, "No se pudo agregar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			// La zona nueva queda seleccionada para seguir armando desde ella
			this->idSeleccionada = elegida->GetId();
			RecargarDisponibles(nullptr);
			RecargarGrafo();
		}

		/*Cara libre de la zona seleccionada cuyo cuadro punteado contiene el punto, o -1 si ninguna*/
		int CaraFantasmaEn(Point punto) {
			Zona^ seleccionada = ZonaSeleccionada();
			if (seleccionada == nullptr) {
				return -1;
			}
			array<CaraZona>^ caras = gcnew array<CaraZona> { CaraZona::ARRIBA, CaraZona::DERECHA, CaraZona::ABAJO };
			for each (CaraZona cara in caras) {
				int fila;
				int columna;
				CeldaDeCara(seleccionada, cara, fila, columna);
				if (CaraLibre(seleccionada, cara) && Celda(fila, columna).Contains(punto)) {
					return static_cast<int>(cara);
				}
			}
			return -1;
		}

	private: System::Void frmGrafoZonas_Load(System::Object^ sender, System::EventArgs^ e) {
			RecargarDisponibles(nullptr);
			RecargarGrafo();
			this->tmrActualizar->Start();
		}

		// Cada pocos segundos se releen las concentraciones para que los colores reaccionen
	private: System::Void tmrActualizar_Tick(System::Object^ sender, System::EventArgs^ e) {
			RecargarGrafo();
		}

	private: System::Void picGrafo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			Graphics^ g = e->Graphics;
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
			g->TextRenderingHint = System::Drawing::Text::TextRenderingHint::ClearTypeGridFit;
			System::Drawing::Font^ letra = gcnew System::Drawing::Font("Segoe UI", 8.5F);
			System::Drawing::Font^ letraId = gcnew System::Drawing::Font("Segoe UI", 9.0F, FontStyle::Bold);
			System::Drawing::Font^ letraValor = gcnew System::Drawing::Font("Segoe UI", 13.0F, FontStyle::Bold);
			System::Drawing::Font^ letraChica = gcnew System::Drawing::Font("Segoe UI", 7.0F, FontStyle::Bold);
			Color oscuro = Color::FromArgb(37, 50, 64);
			StringFormat^ centrado = gcnew StringFormat();
			centrado->Alignment = StringAlignment::Center;
			centrado->LineAlignment = StringAlignment::Center;
			centrado->Trimming = StringTrimming::EllipsisCharacter;
			centrado->FormatFlags = StringFormatFlags::NoWrap;

			// Puntos de fondo, como papel cuadriculado
			SolidBrush^ punto = gcnew SolidBrush(Color::FromArgb(214, 220, 228));
			for (int x = 12; x < this->picGrafo->Width; x += 25) {
				for (int y = 12; y < this->picGrafo->Height; y += 25) {
					g->FillEllipse(punto, x, y, 2, 2);
				}
			}

			if (this->grafo == nullptr || this->grafo->ObtenerZonas()->Count == 0) {
				System::Drawing::Rectangle aviso(40, 40, 420, 110);
				g->FillPath(Brushes::White, Redondeado(aviso, 10));
				g->DrawPath(gcnew Pen(Color::FromArgb(200, 208, 216)), Redondeado(aviso, 10));
				g->DrawString("El grafo está vacío", gcnew System::Drawing::Font("Segoe UI", 13.0F, FontStyle::Bold),
					gcnew SolidBrush(oscuro), 60.0F, 56.0F);
				g->DrawString("1. Elija una zona en \"Zona a colgar\" (o cree una nueva).\n2. Pulse \"Agregar como salida\": será la entrada de la mina.\n3. Seleccione la zona y cuelgue otras arriba, a la derecha o abajo.",
					letra, Brushes::DimGray, 60.0F, 88.0F);
				return;
			}

			GrafoZonasController^ grafoController = gcnew GrafoZonasController();
			Zona^ seleccionada = ZonaSeleccionada();

			// 1) Uniones entre la cara del padre y la cara de la zona que cuelga
			Pen^ lapizUnion = gcnew Pen(Color::FromArgb(160, 170, 182), 6.0F);
			lapizUnion->StartCap = System::Drawing::Drawing2D::LineCap::Round;
			lapizUnion->EndCap = System::Drawing::Drawing2D::LineCap::Round;
			for each (Zona^ zona in this->grafo->ObtenerZonas()) {
				if (zona->GetZonaPadre() == nullptr) {
					continue;
				}
				System::Drawing::Rectangle hijo = Cuadrado(zona);
				System::Drawing::Rectangle padre = Cuadrado(zona->GetZonaPadre());
				if (zona->GetCaraConexion() == CaraZona::DERECHA) {
					g->DrawLine(lapizUnion, padre.Right, padre.Top + TAMANO / 2, hijo.Left, hijo.Top + TAMANO / 2);
				}
				else if (zona->GetCaraConexion() == CaraZona::ARRIBA) {
					g->DrawLine(lapizUnion, padre.Left + TAMANO / 2, padre.Top, hijo.Left + TAMANO / 2, hijo.Bottom);
				}
				else {
					g->DrawLine(lapizUnion, padre.Left + TAMANO / 2, padre.Bottom, hijo.Left + TAMANO / 2, hijo.Top);
				}
			}

			// 2) Cuadros punteados en las caras libres de la zona seleccionada (clic = agregar ahi)
			if (seleccionada != nullptr) {
				Pen^ lapizFantasma = gcnew Pen(Color::FromArgb(140, 155, 170), 2.0F);
				lapizFantasma->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;
				array<CaraZona>^ caras = gcnew array<CaraZona> { CaraZona::ARRIBA, CaraZona::DERECHA, CaraZona::ABAJO };
				array<String^>^ nombres = gcnew array<String^> { "+ Arriba", "+ Derecha", "+ Abajo" };
				for (int i = 0; i < caras->Length; i++) {
					if (!CaraLibre(seleccionada, caras[i])) {
						continue;
					}
					int fila;
					int columna;
					CeldaDeCara(seleccionada, caras[i], fila, columna);
					System::Drawing::Rectangle fantasma = Celda(fila, columna);
					g->FillPath(gcnew SolidBrush(Color::FromArgb(150, 255, 255, 255)), Redondeado(fantasma, 10));
					g->DrawPath(lapizFantasma, Redondeado(fantasma, 10));
					String^ texto = nombres[i] + "\n" + ((ZonaElegida() != nullptr) ? ZonaElegida()->GetId() : "(elija una zona)");
					g->DrawString(texto, letra, gcnew SolidBrush(Color::FromArgb(110, 125, 140)), AFlotante(fantasma), centrado);
				}
			}

			// 3) Tarjetas de cada zona con el color de su nivel de emergencia
			StringFormat^ conSalto = gcnew StringFormat();
			conSalto->Alignment = StringAlignment::Center;
			conSalto->LineAlignment = StringAlignment::Center;
			conSalto->Trimming = StringTrimming::EllipsisCharacter;
			for each (Zona^ zona in this->grafo->ObtenerZonas()) {
				System::Drawing::Rectangle cuadro = Cuadrado(zona);
				NivelRiesgo nivel = grafoController->ObtenerNivelRiesgo(zona);
				Color colorNivel = ColorNivel(nivel);
				bool aislada = grafoController->EstaAislada(this->grafo, zona);

				// Sombra
				System::Drawing::Rectangle sombra = cuadro;
				sombra.Offset(3, 4);
				g->FillPath(gcnew SolidBrush(Color::FromArgb(40, 0, 0, 0)), Redondeado(sombra, 10));

				// Cuerpo claro y cabecera con el color del nivel
				System::Drawing::Drawing2D::GraphicsPath^ forma = Redondeado(cuadro, 10);
				g->FillPath(gcnew SolidBrush(Aclarar(colorNivel, 0.78)), forma);
				g->SetClip(forma);
				g->FillRectangle(gcnew SolidBrush(colorNivel), cuadro.X, cuadro.Y, cuadro.Width, ALTO_CABECERA);
				g->ResetClip();
				g->DrawPath(gcnew Pen(Oscurecer(colorNivel, 0.8), 1.5F), forma);

				Color colorCabecera = (nivel == NivelRiesgo::MEDIO) ? Color::FromArgb(70, 50, 0) : Color::White;
				g->DrawString(zona->GetId(), letraId, gcnew SolidBrush(colorCabecera),
					RectangleF((float)cuadro.X, (float)cuadro.Y, (float)TAMANO, (float)ALTO_CABECERA), centrado);
				g->DrawString(zona->GetNombre(), letra, gcnew SolidBrush(oscuro),
					RectangleF((float)cuadro.X + 4, (float)cuadro.Y + ALTO_CABECERA + 2, (float)TAMANO - 8, 18.0F), centrado);
				g->DrawString(Utilidades::FormatoDouble(zona->GetConcentracionActual()) + " ppm", letraValor, gcnew SolidBrush(oscuro),
					RectangleF((float)cuadro.X, (float)cuadro.Y + ALTO_CABECERA + 18, (float)TAMANO, 28.0F), centrado);
				g->DrawString(NombreNivel(nivel), letraChica, gcnew SolidBrush(Oscurecer(colorNivel, 0.7)),
					RectangleF((float)cuadro.X, (float)cuadro.Y + ALTO_CABECERA + 45, (float)TAMANO, 14.0F), centrado);

				// Etiqueta de salida
				if (zona->GetZonaPadre() == nullptr) {
					System::Drawing::Rectangle etiqueta(cuadro.X + 22, cuadro.Bottom - 15, TAMANO - 44, 15);
					g->FillPath(gcnew SolidBrush(oscuro), Redondeado(etiqueta, 7));
					g->DrawString("SALIDA", letraChica, Brushes::White, AFlotante(etiqueta), centrado);
				}

				// Zona aislada: anillo punteado y marca "!"
				if (aislada) {
					System::Drawing::Rectangle anillo = cuadro;
					anillo.Inflate(5, 5);
					Pen^ lapizAislada = gcnew Pen(Color::OrangeRed, 3.0F);
					lapizAislada->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;
					g->DrawPath(lapizAislada, Redondeado(anillo, 13));
					g->FillEllipse(Brushes::OrangeRed, cuadro.Right - 12, cuadro.Y - 10, 22, 22);
					g->DrawString("!", letraId, Brushes::White, RectangleF((float)cuadro.Right - 12, (float)cuadro.Y - 10, 22.0F, 22.0F), centrado);
				}

				// Zona seleccionada: anillo azul
				if (zona->GetId() == this->idSeleccionada) {
					System::Drawing::Rectangle anillo = cuadro;
					anillo.Inflate(aislada ? 10 : 6, aislada ? 10 : 6);
					g->DrawPath(gcnew Pen(Color::FromArgb(0, 120, 215), 3.0F), Redondeado(anillo, aislada ? 17 : 14));
				}
			}

			// 4) La cara izquierda de la salida da al exterior
			for each (Zona^ zona in this->grafo->ObtenerZonas()) {
				if (zona->GetZonaPadre() != nullptr) {
					continue;
				}
				System::Drawing::Rectangle salida = Cuadrado(zona);
				int y = salida.Top + TAMANO / 2;
				Pen^ flecha = gcnew Pen(oscuro, 4.0F);
				flecha->CustomEndCap = gcnew System::Drawing::Drawing2D::AdjustableArrowCap(4.0F, 4.0F);
				g->DrawLine(flecha, salida.Left - 4, y, salida.Left - 44, y);
				System::Drawing::Rectangle exterior(salida.Left - 124, y - 14, 74, 28);
				g->FillPath(gcnew SolidBrush(oscuro), Redondeado(exterior, 14));
				g->DrawString("EXTERIOR", letraChica, Brushes::White, AFlotante(exterior), centrado);
			}
		}

	private: System::Void picGrafo_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (this->grafo == nullptr) {
				return;
			}
			// Clic en un cuadro punteado: se cuelga ahi la zona elegida
			int cara = CaraFantasmaEn(e->Location);
			if (cara >= 0) {
				Agregar(static_cast<CaraZona>(cara));
				return;
			}
			this->idSeleccionada = nullptr;
			for each (Zona^ zona in this->grafo->ObtenerZonas()) {
				if (Cuadrado(zona).Contains(e->Location)) {
					this->idSeleccionada = zona->GetId();
				}
			}
			ActualizarBotones();
			this->picGrafo->Invalidate();
		}

		// Cursor de mano sobre lo que se puede pulsar
	private: System::Void picGrafo_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			bool sobreAlgo = (CaraFantasmaEn(e->Location) >= 0);
			if (!sobreAlgo && this->grafo != nullptr) {
				for each (Zona^ zona in this->grafo->ObtenerZonas()) {
					if (Cuadrado(zona).Contains(e->Location)) {
						sobreAlgo = true;
					}
				}
			}
			this->picGrafo->Cursor = sobreAlgo ? Cursors::Hand : Cursors::Default;
		}

	private: System::Void cmbZonaDisponible_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			ActualizarBotones();
			this->picGrafo->Invalidate();
		}

		/*Mismo formulario que usa el administrador para crear zonas*/
	private: System::Void btnNuevaZona_Click(System::Object^ sender, System::EventArgs^ e) {
			ZonaController^ zonaController = gcnew ZonaController();
			frmZonaDatos^ formulario = gcnew frmZonaDatos(zonaController->GenerarId(), nullptr);

			// Si el sistema rechaza los datos se vuelve a mostrar el mismo formulario con lo ya escrito
			while (formulario->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				Zona^ zona = gcnew Zona(formulario->GetId(), formulario->GetNombre(), formulario->GetVolumen());
				zona->SetEsZonaSalida(formulario->GetEsZonaSalida());
				String^ error = zonaController->RegistrarZona(zona);
				if (error == nullptr) {
					MessageBox::Show("Zona registrada correctamente. Ya puede agregarla al grafo.", "Sigma", MessageBoxButtons::OK, MessageBoxIcon::Information);
					RecargarDisponibles(zona->GetId());
					ActualizarBotones();
					this->picGrafo->Invalidate();
					return;
				}
				MessageBox::Show(error, "No se pudo registrar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

	private: System::Void btnAgregarSalida_Click(System::Object^ sender, System::EventArgs^ e) {
			Zona^ elegida = ZonaElegida();
			if (elegida == nullptr) {
				return;
			}
			GrafoZonasController^ grafoController = gcnew GrafoZonasController();
			String^ error = grafoController->AgregarZonaSalida(elegida->GetId());
			if (error != nullptr) {
				MessageBox::Show(error, "No se pudo agregar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			this->idSeleccionada = elegida->GetId();
			RecargarDisponibles(nullptr);
			RecargarGrafo();
		}

	private: System::Void btnAgregarArriba_Click(System::Object^ sender, System::EventArgs^ e) {
			Agregar(CaraZona::ARRIBA);
		}

	private: System::Void btnAgregarDerecha_Click(System::Object^ sender, System::EventArgs^ e) {
			Agregar(CaraZona::DERECHA);
		}

	private: System::Void btnAgregarAbajo_Click(System::Object^ sender, System::EventArgs^ e) {
			Agregar(CaraZona::ABAJO);
		}

	private: System::Void btnQuitar_Click(System::Object^ sender, System::EventArgs^ e) {
			Zona^ seleccionada = ZonaSeleccionada();
			if (seleccionada == nullptr) {
				return;
			}
			// Confirmacion de advertencia: el boton por defecto es "No"
			System::Windows::Forms::DialogResult respuesta = MessageBox::Show(
				"¿Está seguro de que desea quitar la zona " + seleccionada->GetId() + " del grafo?\n\nLa zona no se elimina, solo deja de estar en el grafo.",
				"Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Warning, MessageBoxDefaultButton::Button2);
			if (respuesta != System::Windows::Forms::DialogResult::Yes) {
				return;
			}
			GrafoZonasController^ grafoController = gcnew GrafoZonasController();
			String^ error = grafoController->QuitarZona(seleccionada->GetId());
			if (error != nullptr) {
				MessageBox::Show(error, "No se pudo quitar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			this->idSeleccionada = nullptr;
			RecargarDisponibles(seleccionada->GetId());
			RecargarGrafo();
		}
	};
}
