#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED
#include <iostream>
#include "SellingFunctions.h"
using namespace std;
void cardapio(struct estoque add);

void opcoeUsuario(void)
{
    system("COLOR F0");
    gotoxy(45,7);
    cout << "1 - Adicionar café da manhã." << endl;
    gotoxy(45,8);
    cout << "2 - Adicionar lanche/Bebida." << endl;
    gotoxy(45,9);
    cout << "3 - Adicionar almoço/Sobremesa." << endl;
    gotoxy(45,10);
    cout << "4 - Adicionar jantar." << endl;
    gotoxy(45,11);
    cout << "5 - Cardápio." << endl;
    gotoxy(45,12);
    cout << "6 - Remover do cardápio." << endl;
    gotoxy(45,13);
    cout << "7 - Alterar preço." << endl;
    gotoxy(45,14);
    cout<<"8 - Voltar para o menu"<<endl;
        gotoxy(45,15);
    cout << "0 - Sair." << endl;
    textcolor(WHITE);
    textbackground(BLACK);
}
void opcRemover(void)
{
    system("COLOR F0");
    textcolor(WHITE);
    textbackground(BLACK);
    gotoxy(45,7);
    cout << "1 - café da manhã.   " << endl;
    gotoxy(45,8);
    cout << "2 - lanche/Bebida.   " << endl;
    gotoxy(45,9);
    cout << "3 - almoço/Sobremesa." << endl;
    gotoxy(45,10);
    cout << "4 - jantar.          " << endl;
    gotoxy(45,11);
    cout << "5 - Ver cardápio.    " << endl;
    gotoxy(45,12);
    cout << "0 - Sair.            " << endl;
}
void Variedade(void)
{
    textbackground(BLUE);
    gotoxy(7,1);
    cout << setiosflags(ios::left) << setw(5)
         << "ID" << setw(15)
         << "Café/manhã" << setw(6)
         << resetiosflags(ios::left)
         << "Preços" << endl << endl;
    gotoxy(34,1);
    cout << setiosflags(ios::left) << setw(5)
         << "ID" << setw(15)
         << "Lanche/Bebida" << setw(6)
         << resetiosflags(ios::left)
         << "Preços" << endl << endl;
    gotoxy(61,1);
    cout << setiosflags(ios::left) << setw(5)
         << "ID" << setw(15)
         << "Almoço/Sb.mesa" << setw(6)
         << resetiosflags(ios::left)
         << "Preços" << endl << endl;
    gotoxy(88,1);
    cout << setiosflags(ios::left) << setw(5)
         << "ID" << setw(15)
         << "Jantar" << setw(6)
         << resetiosflags(ios::left)
         << "Preços" << endl << endl;
    textbackground(BLACK);
}
void telFuncionario(void)
{
    setlocale(LC_ALL,"C");
    for(int i=1 ; i<=28 ; i++)
    {
        textbackground(BLACK);
        gotoxy(6,i);
        cout << '\xb1';
    }
    for(int i=6 ; i<=114 ; i++)
    {
        gotoxy(i,28);
        cout << '\xb1';
    }
    for(int i=27 ; i>0 ; i--)
    {
        gotoxy(114,i);
        cout << '\xb1';
    }
    for(int i=1 ; i<=27 ; i++)
    {
        gotoxy(33,i);
        cout << '\xb1';
    }
    for(int i=1 ; i<=27 ; i++)
    {
        gotoxy(60,i);
        cout << '\xb1';
    }
    for(int i=1 ; i<=27 ; i++)
    {
        gotoxy(87,i);
        cout << '\xb1';
    }
    for(int i=7 ; i<=113 ; i++)
    {
        gotoxy(i,2);
        cout << '\xb1';
    }
    textbackground(WHITE);
    setlocale(LC_ALL,"portuguese");
}
void coffeManha(struct estoque add)
{
    estoque ad;
    system("COLOR F0");
    fstream cafe("cafeManha.txt",ios::ate|ios::out|ios::in);
    system("CLS");
    textcolor(WHITE);
    textbackground(BLACK);
    cout << "Adicionar variedades de café da manhã: "  << endl;
    cout << "Obs: o estoque armazena \'25\' tipos." << endl;
    cout << "\nDigite o ID do prato : (entre 1 e 25)";
    cin >> add.id;
    while(add.id>0 && add.id<=25)
    {
        cout << "\nDigite o nome do café da manhã: " << endl;
        cin >> add.Nprato;
        cout << "Digite o preço do café da manhã: " << endl;
        cin >> add.preco;
        cafe.seekp((add.id-1)*sizeof(estoque));
        cafe.write((const char*)(&add),sizeof(estoque));
        system("CLS");
        system("COLOR F0");
        textcolor(WHITE);
        textbackground(BLACK);
        break;
    }
    system("CLS");
        system("COLOR F0");
        textcolor(WHITE);
        textbackground(BLACK);
    cout<<"Retornando ao menu..."<<endl;
        system("PAUSE>NULL");
    system("cls");
    cafe.close();
        Menu();
}
void lanch(struct estoque add)
{
        estoque ad;

    system("COLOR F0");
    fstream lanches("lanches.txt",ios::ate|ios::out|ios::in);
    system("CLS");
    textcolor(WHITE);
    textbackground(BLACK);
    cout << "Adicionar variedades de lanche: " << endl << endl;
    cout << "Obs: o estoque armazena \'25\' tipos." << endl;
    cout << "\nDigite o ID do prato : (entre 1 e 25)";
    cin >> add.id;
    while(add.id>0 && add.id<=25)
    {
        cout << "\nDigite o nome do lanche: " << endl;
        cin >> add.Nprato;
        cout << "Digite o preço do lanche: " << endl;
        cin >> add.preco;
        lanches.seekp((add.id-1)*sizeof(estoque));
        lanches.write((const char*)(&add),sizeof(estoque));
        system("CLS");
        system("COLOR F0");
        textcolor(WHITE);
        textbackground(BLACK);
    break;
    }
    system("CLS");
        system("COLOR F0");
        textcolor(WHITE);
        textbackground(BLACK);
        cout<<"Retornando ao menu..."<<endl;
        system("PAUSE>NULL");
    system("cls");
    lanches.close();
    Menu();
}
void almoc(struct estoque add)
{
        estoque ad;

    system("COLOR F0");
    fstream almoco("almoco.txt",ios::ate|ios::out|ios::in);
    system("CLS");
    textcolor(WHITE);
    textbackground(BLACK);
    cout << "Adicionar variedades de almoco: " << endl << endl;
    cout << "Obs: o estoque armazena \'25\' tipos." << endl;
    cout << "\nDigite o ID do prato : (entre 1 e 25)";
    cin >> add.id;
    while(add.id>0 && add.id<=25)
    {
        cout << "\nDigite o nome do almoco: " << endl;
        cin >> add.Nprato;
        cout << "Digite o preco do almoco: " << endl;
        cin >> add.preco;
        almoco.seekp((add.id-1)*sizeof(estoque));
        almoco.write((const char*)(&add),sizeof(estoque));
        system("CLS");
        system("COLOR F0");
        textcolor(WHITE);
        textbackground(BLACK);
    break;
    }
    system("CLS");
        system("COLOR F0");
        textcolor(WHITE);
        textbackground(BLACK);
            cout<<"Retornando ao menu..."<<endl;

            system("PAUSE>NULL");
    system("cls");
    almoco.close();
        Menu();

}
void jantar(struct estoque add)
{
    estoque ad;
    system("COLOR F0");
    fstream janta("jantar.txt",ios::ate|ios::out|ios::in);
    system("CLS");
    textcolor(WHITE);
    textbackground(BLACK);
    cout << "Adicionar variedades de jantar: " << endl << endl;
    cout << "Obs: o estoque armazena \'25\' tipos." << endl;
    cout << "\nDigite o ID do jantar: ";
    cin >> add.id;
    while(add.id>0 && add.id<=25)
    {
        cout << "\nDigite o nome do jantar: " << endl;
        cin >> add.Nprato;
        cout << "Digite o preço do jantar: " << endl;
        cin >> add.preco;
        janta.seekp((add.id-1)*sizeof(estoque));
        janta.write((const char*)(&add),sizeof(estoque));
        system("CLS");
        system("COLOR F0");
        textcolor(WHITE);
        textbackground(BLACK);
break;

    }
    system("CLS");
        system("COLOR F0");
        textcolor(WHITE);
        textbackground(BLACK);
            cout<<"Retornando ao menu..."<<endl;

            system("PAUSE>NULL");
    system("cls");
    janta.close();
        Menu();

}
void removerPrato(struct estoque add)
{
    system("CLS");
    fstream cafeManaha("cafeManha.txt",ios::out|ios::ate|ios::in);
    fstream lanches("lanches.txt",ios::out|ios::ate|ios::in);
    fstream almoco("almoco.txt",ios::out|ios::ate|ios::in);
    fstream jantar("jantar.txt",ios::out|ios::ate|ios::in);
    int opc;
    do
    {
        system("CLS");
        opcRemover();
        gotoxy(45,14);
        textcolor(BLACK);
        textbackground(WHITE);
        cout << "Escolha a Opção : ";
        cin >> opc;
        switch(opc)
        {
        case 1:
        {
            gotoxy(45,15);
            cout << "ID : ";
            cin >> add.id;
            cafeManaha.seekp((add.id-1)*sizeof(estoque));
            cafeManaha.write((const char*)(&vazio),sizeof(estoque));
            break;
        }
        case 2:
        {
            gotoxy(45,15);
            cout << "ID : ";
            cin >> add.id;
            lanches.seekp((add.id-1)*sizeof(estoque));
            lanches.write((const char*)(&vazio),sizeof(estoque));
            break;
        }
        case 3:
        {
            gotoxy(45,15);
            cout << "ID : ";
            cin >> add.id;
            almoco.seekp((add.id-1)*sizeof(estoque));
            almoco.write((const char*)(&vazio),sizeof(estoque));
            break;
        }
        case 4:
        {
            gotoxy(45,15);
            cout << "ID : ";
            cin >> add.id;
            jantar.seekp((add.id-1)*sizeof(estoque));
            jantar.write((const char*)(&vazio),sizeof(estoque));
            break;
        }
        case 5:
        {
            textcolor(WHITE);
            cardapio(add);
            telFuncionario();
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            gotoxy(45,16);
            cout << "Opção invalida!!!" << endl;
            system("PAUSE>NULL");
            break;
        }
        }
    }
    while(opc!=0);
    cafeManaha.close();
    lanches.close();
    almoco.close();
    jantar.close();
    system("CLS");
}
void cardapio(struct estoque add)
{
    system("COLOR F0");
    int *p2,*p3,*p4,*p5;
    int cont1=3,cont2=3,cont3=3,cont4=3;
    p2=new int;
    p3=new int;
    p4=new int;
    p5=new int;
    p2=&cont1;
    p3=&cont2;
    p4=&cont3;
    p5=&cont4;
    ifstream CardapioCafe("cafeManha.txt",ios::in);
    ifstream CardapioLanches("lanches.txt",ios::in);
    ifstream CardapioAlmoco("almoco.txt",ios::in);
    ifstream CardapioJantar("jantar.txt",ios::in);
    system("CLS");
    telFuncionario();
    Variedade();
    while((CardapioCafe && !CardapioCafe.eof())
            &&(CardapioLanches && !CardapioLanches.eof())
            &&(CardapioAlmoco && !CardapioAlmoco.eof())
            &&(CardapioJantar && !CardapioJantar.eof()))
    {
        textbackground(6);
        textcolor(BLACK);
        CardapioCafe.read((char*)(&add),sizeof(estoque));
        if(add.id!=0)
        {
            gotoxy(7,cont4++);
            cout << setiosflags(ios::left) <<setw(5)
                 << add.id << setw(15)
                 << add.Nprato << resetiosflags(ios::left) << setw(6)
                 << setiosflags(ios::fixed) << setprecision(2)
                 << add.preco << endl;
        }
        CardapioLanches.read((char*)(&add),sizeof(estoque));
        if(add.id!=0)
        {
            gotoxy(34,cont1++);
            cout << setiosflags(ios::left) <<setw(5)
                 << add.id << setw(15)
                 << add.Nprato << resetiosflags(ios::left) << setw(6)
                 << setiosflags(ios::fixed) << setprecision(2)
                 << add.preco << endl;
        }
        CardapioAlmoco.read((char*)(&add),sizeof(estoque));
        if(add.id!=0)
        {
            gotoxy(61,cont2++);
            cout << setiosflags(ios::left) <<setw(5)
                 << add.id << setw(15)
                 << add.Nprato << resetiosflags(ios::left) << setw(6)
                 << setiosflags(ios::fixed) << setprecision(2)
                 << add.preco << endl;

        }
        CardapioJantar.read((char*)(&add),sizeof(estoque));
        if(add.id!=0)
        {
            gotoxy(88,cont3++);
            cout << setiosflags(ios::left) <<setw(5)
                 << add.id << setw(15)
                 << add.Nprato << resetiosflags(ios::left) << setw(6)
                 << setiosflags(ios::fixed) << setprecision(2)
                 << add.preco << endl;
        }
    }
    textbackground(BLACK);
    textcolor(WHITE);
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    p2=NULL;
    p3=NULL;
    p4=NULL;
    p5=NULL;
    CardapioCafe.close();
    CardapioAlmoco.close();
    CardapioJantar.close();
    CardapioLanches.close();
    system("PAUSE>NULL");
    system("cls");
}
void alterPreco(struct estoque add)
{
    fstream cafeManaha("cafeManha.txt",ios::out|ios::ate|ios::in);
    fstream lanches("lanches.txt",ios::out|ios::ate|ios::in);
    fstream almoco("almoco.txt",ios::out|ios::ate|ios::in);
    fstream jantar("jantar.txt",ios::out|ios::ate|ios::in);
    int opc;
    do
    {
        system("CLS");
        opcRemover();
        textcolor(BLACK);
        textbackground(WHITE);
        gotoxy(45,14);
        cout << "Escolha opção : ";
        cin >> opc;
        switch(opc)
        {
        case 1:
        {
            gotoxy(45,15);
            cout << "ID : ";
            cin >> add.id;
            cafeManaha.seekg((add.id-1)*sizeof(estoque));
            cafeManaha.read((char*)(&add),sizeof(estoque));
            gotoxy(45,16);
            cout << "Valor da alteração : ";
            cin >> add.preco;
            cafeManaha.seekp((add.id-1)*sizeof(estoque));
            cafeManaha.write((const char*)(&add),sizeof(estoque));
            break;
        }
        case 2:
        {
            gotoxy(45,15);
            cout << "ID : ";
            cin >> add.id;
            lanches.seekg((add.id-1)*sizeof(estoque));
            lanches.read((char*)(&add),sizeof(estoque));
            gotoxy(45,16);
            cout << "Valor da alteração : ";
            cin >> add.preco;
            lanches.seekp((add.id-1)*sizeof(estoque));
            lanches.write((const char*)(&add),sizeof(estoque));
            break;
        }
        case 3:
        {
            gotoxy(45,15);
            cout << "ID : ";
            cin >> add.id;
            almoco.seekg((add.id-1)*sizeof(estoque));
            almoco.read((char*)(&add),sizeof(estoque));
            gotoxy(45,16);
            cout << "Valor da alteração : ";
            cin >> add.preco;
            almoco.seekp((add.id-1)*sizeof(estoque));
            almoco.write((const char*)(&add),sizeof(estoque));
            break;
        }
        case 4:
        {
            gotoxy(45,15);
            cout << "ID : ";
            cin >> add.id;
            jantar.seekg((add.id-1)*sizeof(estoque));
            jantar.read((char*)(&add),sizeof(estoque));
            gotoxy(45,16);
            cout << "Valor da alteração : ";
            cin >> add.preco;
            jantar.seekp((add.id-1)*sizeof(estoque));
            jantar.write((const char*)(&add),sizeof(estoque));
            break;
        }
        case 5:
        {
            textcolor(WHITE);
            cardapio(add);
            telFuncionario();
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            gotoxy(45,16);
            cout << "Opção invalida!!!" << endl;
            system("PAUSE>NULL");
        }
        }
    }
    while(opc!=0);
}


#endif // BIBLIOTECA_H_INCLUDED
