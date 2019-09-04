#ifndef DEFINICOES_H_INCLUDED
#define DEFINICOES_H_INCLUDED
#include "SellingFunctions.h"
#include <fstream>
#include <iostream>
using namespace std;
void Menu();
struct aluno
{
    char nome[50];
    int id;
    char curso[30];
};
void criar()
{
    ofstream lista;
    aluno alunovazio = {"",0, ""};
    lista.open("aluno.txt", ios::out | ios::trunc);
    if(!lista.is_open())
    {
        cout << "Arquivo nao aberto!!!";
    }
    for(int i=0; i<100; i++)
    {
        lista.write((const char*)(&alunovazio),sizeof(aluno));
    }
    lista.close();

}
void cadastro()
{
    aluno a;
    ofstream lista;
    lista.open("aluno.txt", ios::out | ios::in |ios::ate);

    if(!lista.is_open())
    {
        cout << "Arquivo nao aberto com sucesso"<<endl;
    }
    system("CLS");
    system("COLOR F0");
    cout << "Digite o id do aluno: (Entre 1 e 100)"<<endl;
    cin >> a.id;

    while(a.id > 0 && a.id < 100)
    {
        cout << "Digite o  nome do aluno: "<<endl;
        fflush(stdin);
        cin.getline(a.nome,50);
        cout << "Digite a sigla do curso do aluno: "<<endl;
        cin>>a.curso;

        lista.seekp((a.id - 1)*sizeof(aluno));
        lista.write((const char *)(&a),sizeof(aluno));

        int i;
        cout << "Processo concluido!!!"<<endl<<"Deseja realizar outro cadastro? Se sim, digite 1:"<<endl;
        cin >> i;
        if(i != 1)
        {
            cout <<"Retornando ao Menu..."<<endl;
            system("PAUSE>NULL");
            system("cls");
            break;
        }
        cout << "digite o id do aluno";
        cin >> a.id;
    }
    lista.close();

}
void exibir()
{
    aluno lista;
    ifstream exibir("aluno.txt", ios::in);
    if(!exibir.is_open())
    {
        cout <<"arquivo nao aberto com sucesso";
    }

    cout << setiosflags(ios::left) <<setw(7) << "ID" << setw(50)
         << "Nome" << setw(5) << "Curso" << resetiosflags(ios::left) << endl;

    exibir.read((char *)(&lista),sizeof(aluno));
    while(exibir && !exibir.eof())
    {
        if(lista.id != 0)
        {
             cout<<setiosflags(ios::left)
                <<setw(7)<< lista.id << setw(50) << lista.nome << setw(5) << lista.curso
                << resetiosflags(ios::left)<<setw(10)<< setprecision(2)
                << setiosflags(ios::fixed)<<setiosflags(ios::showpoint)<<endl;

    system("pause");
            system("CLS");

        }
    exibir.read((char *)(&lista),sizeof(aluno));
    }
    exibir.close();
        cout << "Retornando ao Menu..." << endl;
    system("pause");
            system("CLS");
    Menu();
}

#endif // DEFINICOES_H_INCLUDED
