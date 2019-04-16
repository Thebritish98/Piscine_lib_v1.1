#include "main.h"

int main()
{
	std::string Name_File;
	/*std::cout << "Nom du modele:";
	std::cin >> Name_File;*/
	thg::Graph test("broadway");
	//test.show_svg();
	return 0;
}

namespace util
{
	void exec(LPCSTR FileName)
	{
		ShellExecute(NULL, "open", FileName, NULL, NULL, SW_SHOWNORMAL); //à l'aide https://docs.microsoft.com/en-us/windows/desktop/api/shellapi/nf-shellapi-shellexecutea
	}

}