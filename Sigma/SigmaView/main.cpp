#include "frmPrincipal.h"

using namespace SigmaView;
using namespace System;
using namespace System;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	frmPrincipal ventana;
	Application::Run(% ventana);
}