#include "App.h"


using namespace System::Windows::Forms;
using namespace client;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew App);
}
