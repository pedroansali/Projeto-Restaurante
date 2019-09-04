#ifndef SELLINGFUNCTIONS_H_INCLUDED
#define SELLINGFUNCTIONS_H_INCLUDED
#include <iostream>
#include "FuncoesEstoque.h"
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "DefStudent.h"
struct estoque
{
    int id;
    float preco;
    char Nprato[20];
};
void telFuncionario(void);
void cardapio(struct estoque add);
estoque vazio= {0,0.0,' '};
void coffeManha(struct estoque add);
void lanch(struct estoque add);
void almoc(struct estoque add);
void jantar(struct estoque add);
void removerPrato(struct estoque add);
void alterPreco(struct estoque add);
void opcoeUsuario(void);
using namespace std;
const int Gsenha=150;
void Menu();
void exibirPromo(int i);
int sorteio();
void exibirRecursao(int f);
estoque *p = new estoque[4];
int v;
namespace cliente
{
void pagamento(float preco);
void venda()
{
    estoque add,produto;
    cardapio(add);
    int op,idvenda,qntvenda;
    char l;
    float pvenda;
    system("COLOR F0");
    setlocale(LC_ALL,"portuguese");
    gotoxy(35,3);
    cout << "Qual tipo de produto deseja comprar?"<<endl;
    gotoxy(35,5);
    cout<< "1. Cafe da manha" << endl;
    gotoxy(35,6);
    cout<< "2. Almoco" << endl;
    gotoxy(35,7);
    cout<< "3. Jantar" << endl;
    gotoxy(35,8);
    cout<< "4. Lanche" << endl;
    gotoxy(35,9);
    cout << "5. Ver e comprar promocao do dia"<<endl;
    gotoxy(35,10);
    cout<< "0. Voltar para menu"<<endl;
    gotoxy(35,11);
    textbackground(BLACK);
    cout << "Escolha a opcao : ";
    cin>>op;
    switch(op)
    {
    case 1:
    {
        gotoxy(35,12);
        cout<< "Digite o id do prato desejado: ";
        cin>> idvenda;
        gotoxy(35,13);
        cout<< "Digite a quantidade desejada: ";
        cin>>qntvenda;
        ifstream card("cafeManha.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo cafe da manha nao aberto para compra!!!" << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);
        gotoxy(2,15);
        cout << "Deseja adicionar algum outro produto ao carrinho? 'S' para <sim> ou qualquer outra letra para seguir ao pagamento..."<<endl;
        cin >> l;
        l=toupper(l);
        if (l=='S')
        {
            ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cerr<<"Historico nao aberto!!!"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();
            venda();
        }else{
        ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cerr<<"Historico nao aberto!!!"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();

        }
        card.close();
        system("CLS");
        system("COLOR F0");
        cliente::pagamento(pvenda);
        break;
    }
    case 2:
    {
        gotoxy(35,12);
        cout<< "Digite o id do prato desejado: "<<endl;
        cin>> idvenda;
        gotoxy(35,13);
        cout<< "Digite a quantidade desejada: "<<endl;
        cin>>qntvenda;
        ifstream card("almoco.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo almoco nao aberto para compra!!!" << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);
        gotoxy(2,15);
        cout << "Deseja adicionar algum outro produto ao carrinho? 'S' para <sim> ou qualquer outra letra para seguir ao pagamento..."<<endl;
        cin >> l;
        if (l=='S' || l=='s')
        {
            ofstream historico("historico.txt",ios::out|ios::app);
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();
            venda();
        }else{
        ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cerr<<"Historico nao aberto!!!"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();

        }
        card.close();
        cliente::pagamento(pvenda);
        break;
    }
    case 3:
    {
        gotoxy(35,12);
        cout<< "Digite o id do prato desejado: "<<endl;
        cin>> idvenda;
        gotoxy(35,13);
        cout<< "Digite a quantidade desejada: "<<endl;
        cin>>qntvenda;
        ifstream card("jantar.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo janta nao aberto para compra!!!" << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);
        gotoxy(2,15);
        cout << "Deseja adicionar algum outro produto ao carrinho? 'S' para <sim> ou qualquer outra letra para seguir ao pagamento..."<<endl;
        cin >> l;
        if (l=='S' || l=='s')
        {
            ofstream historico("historico.txt",ios::out|ios::app);
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();
        }else{
        ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cerr<<"Historico nao aberto!!!"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();

        }
        card.close();
        cliente::pagamento(pvenda);
        break;
    }
    case 4:
    {
        gotoxy(35,12);
        cout<< "Digite o id do prato desejado: "<<endl;
        cin>> idvenda;
        gotoxy(35,13);
        cout<< "Digite a quantidade desejada: "<<endl;
        cin>>qntvenda;
        ifstream card("lanches.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo lanche nao aberto para compra!!!" << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);
        gotoxy(2,15);
        cout << "Deseja adicionar algum outro produto ao carrinho? 'S' para <sim> ou qualquer outra letra para seguir ao pagamento..."<<endl;
        cin >> l;
        if (l==toupper('s'))
        {
            ofstream historico("historico.txt",ios::out|ios::app);
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato  << endl;
            historico.close();
        }else{
        ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cerr<<"Historico nao aberto!!!"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();

        }
        card.close();
        cliente::pagamento(pvenda);
        break;
    }
    case 5:
    {
        int z=sorteio();
        exibirPromo(z);
    }
    case 0:
    {
        system("CLS");
        system("COLOR F0");
        Menu();
        break;
    }
    default:
        gotoxy(35,16);
        cout << "Opcao invalida!!! Retornando ao menu...";
        Menu();
        break;
    }
}

void pagamento(float preco)
{
    int op;
    float troco;
    gotoxy(35,8);
    cout << "Digite qual o tipo de pagamento desejado: "<<endl;
    gotoxy(35,9);
    cout << "1. Compra normal"<<endl;
    gotoxy(35,10);
    cout << "2. Beneficio Universidade"<<endl;
    textbackground(BLACK);
    gotoxy(35,12);
    cout << "Opcao : ";
    cin>>op;
    system("COLOR F0");
    system("cls");
    switch (op)
    {
    case 1:
    {
        system("CLS");
        system("COLOR F0");
        gotoxy(35,5);
        cout << "Valor total da compra = "<<preco<<endl;
        gotoxy(35,7);
        cout << "Compra realizada com sucesso!"<<endl;
        gotoxy(35,8);
        cout << "Volte sempre!!! :3 <3"<<endl;
        gotoxy(35,9);
        cout << "Voltando ao menu inicial..."<<endl;
        system("PAUSE>NULL");
        system("cls");
        Menu();

        break;
    }
    case 2:
    {
        system("COLOR F0");
        char escolha;
        gotoxy(35,7);
        cout << "Voce ja e cadastrado no sistema?"<<endl;
        gotoxy(35,8);
        cout<< "S = SIM // N = NAO"<<endl;
        do
        {
            cin >> escolha;
            if (escolha == 'S' || escolha =='s')
            {
ifstream verificar_aluno("aluno.txt", ios::in);
        aluno verify;
        aluno lista1; //aqui é o nome que dei a struct pra ler os arquivos
        if(!verificar_aluno.is_open()){
            cout << "Arquivo nao aberto";
        }

        cout << "Digite seu id de aluno: " << endl;
        cin >> verify.id;

//        verificar_aluno.seekg((verify.id-1)*sizeof(estoque));
//        verificar_aluno.read((char *)(&lista1),sizeof(aluno));
        for(int man=1;man<=100;man++){
                verificar_aluno.seekg((man-1)*sizeof(estoque));
                verificar_aluno.read((char *)(&lista1),sizeof(aluno));
            if(verify.id == lista1.id){
                if(lista1.nome != ""){

        preco==1.0;
        cout << "Valor total da compra = "<<preco<<endl;
            cout << "Compra realizada com sucesso! Voltando ao menu inicial..."<<endl;
            system("PAUSE>NULL");
            system("cls");
            Menu();
        }

                }
//            }else{
//            cout<<"Aluno nao cadastrado no sistema...Retornando a tela de venda!!!"<<endl;
//            system("pause");
//            system("cls");
//            venda();
          }


            cout<<"Aluno nao cadastrado no sistema...Retornando a tela de venda!!!"<<endl;
            system("pause");
            system("cls");
            venda();





            }else if (escolha == 'N' || escolha =='n')
            {
                 cout<<"Retornando a tela de venda!!!"<<endl;
            system("pause");
            system("cls");
            venda();

            }
        }
        while(escolha != 'S' || escolha != 's' || escolha != 'N' || escolha != 'n');
//       if(v==1){ preco==1.0;
//        cout << "Valor total da compra = "<<preco<<endl;
//            cout << "Compra realizada com sucesso! Voltando ao menu inicial..."<<endl;
//            system("PAUSE>NULL");
//            system("cls");
//            Menu();
//       }else{
//
////                   cout<<"Aluno nao cadastrado no sistema...Retornando a tela de venda!!!"<<endl;
////            system("pause");
////            system("cls");
////            venda();
//      }
        break;
    }
    default:
    {
        cout << "Valor invalido!!! Favor digitar novamente..."<<endl;
        system("pause");
        system("cls");
        pagamento(preco);
        break;
    }
    }

}
void Menu()
{
    system("cls");
    gotoxy(35,3);
    cout<< "Seja bem vindo ao IQFome!!!"<<endl;
    gotoxy(35,5);
    cout << "1. Compra"<<endl;
    gotoxy(35,9);
    cout << "0. Encerrar sistema"<<endl;
    int m;
    gotoxy(35,11);
    cout<<"Digite a opcao desejada (Entre 1 e 0): "<<endl;
    gotoxy(35,12);
    cin >> m;

    if(m==1)
    {
        cliente::venda();
    }
    else
    {
        gotoxy(35,12);
        cout<<"Encerrando programa..."<<endl;
        system("pause");
    }
}
}
void pagamento(float preco);
void venda()
{
    char l;
    estoque add,produto;
    cardapio(add);
    int op,idvenda,qntvenda;
    float pvenda=0.0;
    cout << "Qual tipo de produto deseja vender?"<<endl;
    cout<< "1. Cafe da manha" << endl;
    cout<< "2. Almoco" << endl;
    cout<< "3. Jantar" << endl;
    cout<< "4. Lanche" << endl;
    cout<< "5. Ver e comprar promocao do dia"<<endl;
    cout<< "0. Voltar para menu"<<endl;
    cin>>op;

    switch(op)
    {
    case 1:
    {
        cout<< "Digite o id do prato desejado: "<<endl;
        cin>> idvenda;
        cout<< "Digite a quantidade desejada: "<<endl;
        cin>>qntvenda;
        ifstream card("cafeManha.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo cafe da manha nao aberto na venda!!!" << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);
        cout << "Deseja adicionar algum outro produto? 'S' para <sim> ou qualquer outra letra para seguir ao pagamento..."<<endl;
        cin >> l;
        if (toupper(l)=='S')
        {
            ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cout<<"Arquivo historico nao aberto"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato  << endl;
            historico.close();
        }else{
        ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cerr<<"Historico nao aberto!!!"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();

        }
        card.close();
        pagamento(pvenda);
        break;
    }
    case 2:
    {
        cout<< "Digite o id do prato desejado: "<<endl;
        cin>> idvenda;
        cout<< "Digite a quantidade desejada: "<<endl;
        cin>>qntvenda;
        ifstream card("almoco.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo almoco nao aberto na venda!!!" << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);
        cout << "Deseja adicionar algum outro produto? 'S' para <sim> ou qualquer outra letra para seguir ao pagamento..."<<endl;
        cin >> l;
        if (l=='S' || l=='s')
        {
            ofstream historico("historico.txt",ios::out|ios::app);
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();
        }else{
        ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cerr<<"Historico nao aberto!!!"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();

        }
        card.close();
        pagamento(pvenda);
        break;
    }
    case 3:
    {
        cout<< "Digite o id do prato desejado: "<<endl;
        cin>> idvenda;
        cout<< "Digite a quantidade desejada: "<<endl;
        cin>>qntvenda;
        ifstream card("jantar.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo janta nao aberto na venda!!!" << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);
        cout << "Deseja adicionar algum outro produto? 'S' para <sim> ou qualquer outra letra para seguir ao pagamento..."<<endl;
        cin >> l;
        if (l=='S' || l=='s')
        {
            ofstream historico("historico.txt",ios::out|ios::app);
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato  << endl;
            historico.close();
        }else{
        ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cerr<<"Historico nao aberto!!!"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();

        }
        card.close();
        pagamento(pvenda);
        break;
    }
    case 4:
    {
        cout<< "Digite o id do prato desejado: "<<endl;
        cin>> idvenda;
        cout<< "Digite a quantidade desejada: "<<endl;
        cin>>qntvenda;
        ifstream card("lanches.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo lanche nao aberto na venda!!!" << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);
        cout << "Deseja adicionar algum outro produto? 'S' para <sim> ou qualquer outra letra para seguir ao pagamento..."<<endl;
        cin >> l;
        if (l=='S' || l=='s')
        {
            ofstream historico("historico.txt",ios::out|ios::app);
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato  << endl;
            historico.close();
        }else{
        ofstream historico("historico.txt",ios::out|ios::app);
            if(!historico.is_open()){
                cerr<<"Historico nao aberto!!!"<<endl;
            }
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato << endl;
            historico.close();

        }
        card.close();
        pagamento(pvenda);
        break;
    }
    case 5:
    {
        int z=sorteio();
        exibirPromo(z);
        break;
    }
    case 0:
        Menu();
        break;
    default:
        cout << "Opcao invalida!!! Retornando ao menu...";
        Menu();
        break;
    }
}

void pagamento(float preco)
{
    system("COLOR F0");
    int op;
    float troco;
    cout << "Digite qual o tipo de pagamento desejado: "<<endl;
    cout << "1. Venda normal"<<endl;
    cout << "2. Beneficio Universidade"<<endl;
    cin>>op;
    system("cls");
    switch (op)
    {
    case 1:
        cout << "Valor total da venda = "<<preco<<endl;
        cout << "Digite o valor recebido do cliente: "<<endl;
        cin >> troco;
        system("cls");

        if(troco>=preco)
        {
            troco=troco-preco;
            cout<< "Troco de: " << troco << endl << "Favor devolver tal valor ao cliente! " << endl;
            cout << "Venda realizada com sucesso! Voltando ao menu inicial..."<<endl;
                        system("pause");
            system("cls");
            Menu();
        }
        else
        {
            cout<< "Valor recebido nao aceitavel!!! Favor repetir a acao..."<<endl;
            system("pause");
            system("cls");
            pagamento(preco);
        }
        break;
    case 2:
    {
 ifstream verificar_aluno("aluno.txt", ios::in);
        aluno verify;
        aluno lista1; //aqui é o nome que dei a struct pra ler os arquivos
        if(!verificar_aluno.is_open()){
            cout << "Arquivo nao aberto";
        }

        cout << "Digite o id do aluno: " << endl;
        cin >> verify.id;

//        verificar_aluno.seekg((verify.id-1)*sizeof(estoque));
//        verificar_aluno.read((char *)(&lista1),sizeof(aluno));
        for(int man=1;man<=100;man++){
                verificar_aluno.seekg((man-1)*sizeof(estoque));
                verificar_aluno.read((char *)(&lista1),sizeof(aluno));
            if(verify.id == lista1.id){
                if(lista1.nome != ""){

        preco==1.0;
        cout << "Valor total da venda = "<<preco<<endl;
        cout << "Digite o valor recebido do cliente: "<<endl;
        cin >> troco;
        if(troco>=preco)
        {
            troco=troco-preco;
            cout<< "Troco de: " << troco << endl << "Favor devolver tal valor ao cliente! " << endl;
            cout << "Venda realizada com sucesso! Voltando ao menu inicial..."<<endl;
            system("PAUSE>NULL");
            system("cls");
            Menu();
        }
        else
        {
            cout<< "Valor recebido nao aceitavel!!! Favor repetir a acao..."<<endl;
            system("pause");
            system("cls");
            pagamento(preco);
        }
                }
//            }else{
//            cout<<"Aluno nao cadastrado no sistema...Retornando a tela de venda!!!"<<endl;
//            system("pause");
//            system("cls");
//            venda();
          }
        }

            cout<<"Aluno nao cadastrado no sistema...Retornando a tela de venda!!!"<<endl;
            system("pause");
            system("cls");
            venda();

        break;
    }
    default:
        cout << "Valor invalido!!! Favor digitar novamente..."<<endl;
        system("pause");
        system("cls");
        pagamento(preco);
        break;
    }
}

void showHistoric()
{

    ifstream historic("historico.txt", ios::in);
    string s;
    if (!historic.is_open())
    {
        cerr << "Arquivo nao aberto!!!" << endl;
    }
    while (getline(historic, s))
    {
        cout << s << endl;
    }
    historic.close();
    system("PAUSE>NULL");

    system("cls");
    cout<<"Retornando ao Menu..."<<endl;
        system("PAUSE>NULL");

    system("cls");
    Menu();
}

void Menu()
{
    estoque add;
    int esc=0;
    gotoxy(35,7);
    cout << "Bem - Vindo"<<endl;
    gotoxy(35,8);
    cout << "Para a interface do cliente, digite 1"<<endl;
    gotoxy(35,9);
    cout << "Para a interface do administrador, digite 2"<<endl;
    gotoxy(35,10);
    cin >> esc;

    if(esc==2)
    {
        system("cls");
        int senha;
            gotoxy(20,7);
cout<<"Senha requerida!!!"<<endl<<"Acesso temporariamente bloqueado. Favor digitar senha para acesso: "<<endl;
    gotoxy(20,9);

        cin>>senha;
        if(senha ==Gsenha)
        {

            system("cls");
        }
        else
        {
            gotoxy(35,12);
            cout<<"Senha incorreta!!! Retornando ao menu..."<<endl;
            system("PAUSE>NULL");
            system("cls");
            Menu();
        }
        gotoxy(35,5);
        cout << "Para venda de produtos, digite 1"<<endl;
                gotoxy(35,6);

        cout << "Para o cadastro de alunos para beneficio, digite 2"<<endl;
        gotoxy(35,7);

        cout << "Para visualizar o cardapio de produtos, digite 3"<<endl;
        gotoxy(35,8);

        cout << "Para o cadastro ou exclusao de produtos no sistema, digite 4"<<endl;
        gotoxy(35,9);
        cout << "Para visualizar os alunos cadastrados no beneficio, digite 5"<<endl;

        gotoxy(35,10);
        cout << "Para visualizar o historico de venda, digite 6"<<endl;
        gotoxy(35,11);
        cout << "Para ir a interface de cliente, digite 7"<<endl;
        gotoxy(35,12);
        cout << "Para encerrar o sistema, digite 0"<<endl;
        gotoxy(35,13);
        cout << "Digite a opcao desejada: "<<endl;
        int opcao;
        gotoxy(35,14);
        cin>>opcao;
        switch (opcao)
        {

        case 1:
        {

            venda();
            break;
        }
        case 2:
        {

            system("cls");
            cadastro();
            Menu();
            break;
        }
        case 3:
        {
            cardapio(add);
            cout<<"Retornando ao Menu Inicial"<<endl;
            Menu();
            break;
        }
        case 4:
        {
            system("cls");
            system("COLOR F0");
            textcolor(BLACK);
            textbackground(WHITE);
            setlocale(LC_ALL,"portuguese");
            char *p1,escolha;
            p1=new char;
            p1=&escolha;
            gotoxy(37,11);
            cout << "Remover todos os pratos ??? S/N" << endl;
            gotoxy(37,12);
            cin >> escolha;
            escolha=toupper(escolha);
            if(*p1=='S')
            {
                ofstream cafeManaha("cafeManha.txt",ios::out|ios::trunc);
                ofstream lanches("lanches.txt",ios::out|ios::trunc);
                ofstream almoco("almoco.txt",ios::out|ios::trunc);
                ofstream jantar("jantar.txt",ios::out|ios::trunc);
                if(cafeManaha.fail() || lanches.fail() || almoco.fail() || jantar.fail())
                {
                    cout << "Erro ao criar arquivo!!!" << endl;
                    exit(1);
                }
                for(int i=0 ; i<25 ; i++)
                {
                    cafeManaha.write((const char*)(&vazio),sizeof(estoque));
                    lanches.write((const char*)(&vazio),sizeof(estoque));
                    almoco.write((const char*)(&vazio),sizeof(estoque));
                    jantar.write((const char*)(&vazio),sizeof(estoque));
                }
                cafeManaha.close();
                lanches.close();
                almoco.close();
                jantar.close();
                gotoxy(37,14);
                cout << "Ação concluida" << endl;
                system("PAUSE>NULL");
            }
            delete p1;
            p1=NULL;
            //struct
            estoque add;
            int *p2;
            p2=new int;
            int opc;
            do
            {
                system("CLS");
                opcoeUsuario();
                gotoxy(45,16);
                cout << "Escolha uma opcao : "<<endl;
                cin >> opc;
                p2=&opc;
                switch(*p2)
                {
                case 1:
                {
                    coffeManha(add);
                    break;
                }
                case 2:
                {
                    lanch(add);
                    break;
                }
                case 3:
                {
                    almoc(add);
                    break;
                }
                case 4:
                {
                    jantar(add);
                    break;
                }
                case 5:
                {
                    cardapio(add);
                    telFuncionario();
                    break;
                }
                case 6:
                {
                    removerPrato(add);
                    break;
                }
                case 7:
                {
                    alterPreco(add);
                    break;
                }
                case 8:
                {
                    system("cls");
                    Menu();
                }
                case 0:
                {
                    exit(1);
                }
                default:
                {
                    gotoxy(45,16);
                    cout << "Opcao invalida!!!" << endl;
                    system("PAUSE>NULL");
                }
                }
            }
            while(*p2 != 0);
            delete p2;
            p2=NULL;
        }
        case 5:
        {
            system("cls");
            exibir();
            break;
        }
        case 6:
        {
            system("cls");
            showHistoric();
            break;
        }
        case 7:
        {
            system("cls");
            cliente::Menu();
            break;
        }
        case 0:
        {
            break;
        }
        default:
            break;
        }
    }
    else if(esc==1)
    {

        cliente::Menu();

    }
    else
    {
        system("cls");
        Menu();
    }


}
int sorteio()
{

    int i=0;
    srand(time(NULL));
    i=rand()%5;
    return i;
}
void exibirPromo(int i)
{

    fstream cafeManaha("cafeManha.txt",ios::out|ios::ate|ios::in);
    fstream lanches("lanches.txt",ios::out|ios::ate|ios::in);
    fstream almoco("almoco.txt",ios::out|ios::ate|ios::in);
    fstream jantar("jantar.txt",ios::out|ios::ate|ios::in);
    p[1].id=i;
    p[2].id=i;
    p[3].id=i;
    p[4].id=i;
    int choice;
    cafeManaha.seekg((i)*sizeof(estoque));
    cafeManaha.read((char*)(&p[1]),sizeof(estoque));
    p[1].preco=1;
    lanches.seekg((i)*sizeof(estoque));
    lanches.read((char*)(&p[2]),sizeof(estoque));
    p[2].preco=1;
    almoco.seekg((i)*sizeof(estoque));
    almoco.read((char*)(&p[3]),sizeof(estoque));
    p[3].preco=1;
    jantar.seekg((i)*sizeof(estoque));
    jantar.read((char*)(&p[4]),sizeof(estoque));
    p[4].preco=1;
    cafeManaha.close();
    lanches.close();
    almoco.close();
    jantar.close();
    int qntvenda;
    do
    {
        system("cls");
        cout<<"Promocao do dia!!!"<<endl;
        exibirRecursao(4);
        cout<<endl<<"Digite 1 para comprar/vender a primeira opcao!"<<endl;
        cout <<"Digite 2 para comprar/vender a segunda opcao!"<<endl;
        cout <<"Digite 3 para comprar/vender a terceira opcao!"<<endl;
        cout <<"Digite 4 para comprar/vender a quarta opcao!"<<endl;
        cout <<"Ou digite 0 para voltar ao menu inicial..."<<endl;
        cin>>choice;
        system("cls");
    }
    while(choice<0||choice>4);
    if (choice==0){
        Menu();
    }else{
    do
    {
        cout<<"Digite quantas unidades deseja: "<<endl;
        cin>>qntvenda;
    }
    while(qntvenda<=0);

    ofstream historico("historico.txt",ios::out|ios::app);
    if(choice==1)
    {
        historico << "Venda de " << qntvenda << " unidades de " << p[1].Nprato << endl;
    }
    if(choice==2)
    {
        historico << "Venda de " << qntvenda << " unidades de " << p[2].Nprato << endl;
    }
    if(choice==3)
    {
        historico << "Venda de " << qntvenda << " unidades de " << p[3].Nprato << endl;
    }
    if(choice==4)
    {
        historico << "Venda de " << qntvenda << " unidades de " << p[4].Nprato << endl;
    }

    historico.close();
    pagamento(qntvenda);
}
}

void exibirRecursao(int f){
    if(f==0){

    }else{
        cout << "Promocao "<<f<<" : "<< (*(p+ f)).Nprato << " por apenas 1 real!!!"<<endl;
        exibirRecursao(f-1);
    }
}
#endif // SELLINGFUNCTIONS_H_INCLUDED
