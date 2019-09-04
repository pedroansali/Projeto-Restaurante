#include <iostream>
#include <fstream>
#include <windows.h>
#include <locale>
#include <iomanip>
#include <conio2.h>
#include "FuncoesEstoque.h"
#include "SellingFunctions.h"
#include "DefStudent.h"
using std::cout;
using std::cin;
//a senha para entrar na parte de administrador é 150
int main()
{
    system("COLOR F0");
    setlocale(LC_ALL,"portuguese");
    Menu();
    return 0;
}

