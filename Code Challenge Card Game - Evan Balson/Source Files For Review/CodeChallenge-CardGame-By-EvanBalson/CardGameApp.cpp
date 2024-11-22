#include "CardGameApp.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CodeChallengeCardGame::CardGameApp form;
	Application::Run(% form);
}

