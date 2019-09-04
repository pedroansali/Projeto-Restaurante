using namespace std;
const int password = 150;
struct estoque
{
    int id;
    float preco;
    char Nprato[20];
};

struct aluno
{
    char nome[50];
    int id;
    char curso[30];
};

void tela()
{
    for(int i=0; i<29; i++)
    {
        for(int j=0; j<80; j++)
        {
            gotoxy(5+j,2+i);
            textcolor(BLUE);
            printf("\xdb");
        }
    }
}

void telaCard()
{
    for(int i=0; i<29; i++)
    {
        for(int j=0; j<50; j++)
        {
            gotoxy(83+j,2+i);
            textcolor(WHITE);
            printf("\xdb");
        }
    }
}

void cardapio(struct estoque add,int opc);
void exibirPromo(int i);
void exibirRecursao(int f,int k,int j);
estoque *p = new estoque[4];
void pagamentoClientes(float preco);
void menuAdmin();
void cadastro();
void exibir();
void showHistoric();
void opcoeUsuario();
void coffeManha();
void lanch();
void almoc();
void opcRemover();
void alterPreco();
void jantar();

namespace cliente
{
void venda();
void Menu();
void pagamentoClientes(float preco)
{
    int op;
    float troco;
    tela();
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(14,5);
    cout << "Digite qual o tipo de pagamento desejado ";
    gotoxy(18,9);
    cout << " 1. Compra normal " ;
    gotoxy(18,10);
    cout << " 2. Beneficio Universidade ";
    gotoxy(20,12);
    cout << "   ";
    gotoxy(21,12);
    cin>>op;
    switch (op)
    {
    case 1:
    {
        gotoxy(18,16);
        cout << " Valor total da compra = "<< preco;
        gotoxy(18,18);
        cout << " Compra realizada com sucesso ";
        gotoxy(18,20);
        cout << " Volte sempre ";
        gotoxy(15,24);
        cout << " Digite qualquer tecla para voltar ao menu anterior";
        system("pause");
        cliente::venda();
        break;
    }
    case 2:
    {

        char escolha;
        gotoxy(18,16);
        cout << "Voce ja e cadastrado no sistema (s/n) ";
        do
        {
            gotoxy(18,18);
            cout << "   ";
            gotoxy(19,18);
            cin >> escolha;
            if (escolha == 'S' || escolha =='s')
            {
                ifstream verificar_aluno("aluno.txt", ios::in);
                aluno verify;
                aluno lista1; //aqui щ o nome que dei a struct pra ler os arquivos
                if(!verificar_aluno.is_open())
                {
                    cout << "Arquivo nao aberto";
                }

                gotoxy(18,20);
                cout << "Digite seu id de aluno " ;
                gotoxy(19,20);
                cout << "   ";
                cin >> verify.id;
                for(int man=1; man<=100; man++)
                {
                    verificar_aluno.seekg((man-1)*sizeof(estoque));
                    verificar_aluno.read((char *)(&lista1),sizeof(aluno));
                    if(verify.id == lista1.id)
                    {
                        if(lista1.nome != "")
                        {
                            preco==1.0;
                            tela();
                            textcolor(BLACK);
                            textbackground(WHITE);
                            gotoxy(18,14);
                            cout << "Valor total da compra = "<<preco;
                            gotoxy(18,16);
                            cout << "Compra realizada com sucesso";
                            gotoxy(18,18);
                            cout << " pressione qualquer tecla para voltar pro menu anterior";
                            getchar();
                            venda();
                        }
                    }
                }
                gotoxy(18,22);
                cout<<"Aluno nao cadastrado no sistema...Retornando a tela de venda!!!"<<endl;
                venda();
            }
            else if (escolha == 'N' || escolha =='n')
            {
                gotoxy(18,20);
                cout<<"Retornando a tela de venda";
                getchar();
                venda();
            }
        }
        while(escolha != 'S' || escolha != 's' || escolha != 'N' || escolha != 'n');
        break;
    }
    default:
    {
        gotoxy(18,16);
        cout << "Valor invalido Favor digitar novamente...";
        getchar();
        pagamentoClientes(preco);
        break;
    }
    }

}
void venda()
{
    estoque add,produto;
    int op,idvenda,qntvenda;
    char l;
    float pvenda;
    tela();
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(20,3);
    cout << " Qual a opcao ";
    gotoxy(16,8);
    cout<< "1. Cafe da manha ";
    gotoxy(40,8);
    cout<< "2. Almoco";
    gotoxy(16,10);
    cout<< "3. Jantar";
    gotoxy(40,10);
    cout<< "4. Lanche";
    gotoxy(16,12);
    cout << "5. Ver e comprar promocao do dia";
    gotoxy(16,14);
    cout<< "0. Encerrar o Programa";
    gotoxy(18,16);
    cout << "   ";
    gotoxy(19,16);
    cin>>op;
    switch(op)
    {
    case 1:
    {
        cardapio(add,1);
        textcolor(BLACK);
        textbackground(WHITE);
        gotoxy(16,18);
        cout<< "Digite o id do prato desejado: ";
        cin>> idvenda;
        gotoxy(16,20);
        cout<< "Digite a quantidade desejada: ";
        cin>>qntvenda;

        ifstream card("cafeManha.txt",ios::in | ios::ate);

        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));

        pvenda= pvenda + (qntvenda * produto.preco);

        gotoxy(16,22);
        cout << "Adicionar outro produto (s/n)?"<<endl;
        gotoxy(18,24);
        cout << "   ";
        gotoxy(19,24);
        cin >> l;
        l=toupper(l);
        if (l=='S')
        {
            ofstream historico("historico.txt",ios::app);
            historico << "Venda de " << qntvenda << " unidades de " << produto.Nprato;
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
        cliente::pagamentoClientes(pvenda);
        break;
    }
    case 2:
    {
        cardapio(add,2);
        gotoxy(16,18);
        cout<< "Digite o id do prato desejado: ";
        cin>> idvenda;
        gotoxy(16,20);
        cout<< "Digite a quantidade desejada: ";
        cin>>qntvenda;
        ifstream card("almoco.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo almoco nao aberto para compra!!!" << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);

        gotoxy(16,22);
        cout << "Adicionar outro produto (s/n)"<<endl;
        gotoxy(18,24);
        cout << "   ";
        gotoxy(19,24);
        cin >> l;
        l=toupper(l);
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
        cliente::pagamentoClientes(pvenda);
        break;
    }
    case 3:
    {
        cardapio(add,3);
        textcolor(BLACK);
        textbackground(WHITE);
        gotoxy(16,18);
        cout<< "Digite o id do prato desejado: ";
        cin>> idvenda;
        gotoxy(16,20);
        cout<< "Digite a quantidade desejada: ";
        cin>>qntvenda;
        ifstream card("jantar.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo janta nao aberto para compra " << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);

        gotoxy(16,22);
        cout << "Adicionar outro produto (s/n) ";
        gotoxy(18,24);
        cout << "   ";
        gotoxy(19,24);
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
        cliente::pagamentoClientes(pvenda);
        break;
    }
    case 4:
    {
        cardapio(add,4);
        textcolor(BLACK);
        textbackground(WHITE);
        gotoxy(16,18);
        cout<< "Digite o id do prato desejado: ";
        cin>> idvenda;
        gotoxy(16,20);
        cout<< "Digite a quantidade desejada: ";
        cin>>qntvenda;
        ifstream card("lanches.txt",ios::in | ios::ate);
        if (card.fail())
        {
            cerr << "Arquivo lanche nao aberto para compra " << endl;
        }
        card.seekg((idvenda-1)*sizeof(estoque));
        card.read((char *)(&produto),sizeof(estoque));
        pvenda= pvenda + (qntvenda * produto.preco);
        gotoxy(16,22);
        cout << "Adicionar outro produto (s/n) : "<<endl;
        gotoxy(18,24);
        cout << "   ";
        gotoxy(19,24);
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
        cliente::pagamentoClientes(pvenda);
        break;
    }
    case 5:
        {
        int i=0;
        srand(time(NULL));
        i=rand()%5;
        exibirPromo(i);
        break;
        }
    case 0:
        {
        break;
        }
    }

}
}

void Menu()
{
    estoque add;
    int esc=0;
    tela();
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(25,7);
    cout << " BEM - VINDO "<<endl;
    gotoxy(20,13);
    cout << " 1 - CLIENTES "<<endl;
    gotoxy(20,15);
    cout << " 2 - ADMINISTRADOR "<<endl;
    gotoxy(20,17);
    cout << "   ";
    gotoxy(21,17);
    cin >> esc;

    if(esc == 1)
    {
        cliente::venda();
    }
    else
    {
        if(esc == 2)
        {
            tela();
            int senha;
            gotoxy(20,5);
            cout<<" Bem - vindo ";
            gotoxy(20,10);
            cout<<" Informe a sua senha: ";
            cin >> senha;
            if(senha != password)
            {
                gotoxy(18,14);
                cout<<"Senha incorreta - Tente novamente"<<endl;
                getchar();
                Menu();
            }
            else
            {
                menuAdmin();
            }

        }
    }
}

void cardapio(struct estoque add,int opc)
{
    int *p2,*p3,*p4,*p5,i=0;
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

    telaCard();
    textcolor(BLACK);

    while((CardapioCafe && !CardapioCafe.eof())
            &&(CardapioLanches && !CardapioLanches.eof())
            &&(CardapioAlmoco && !CardapioAlmoco.eof())
            &&(CardapioJantar && !CardapioJantar.eof()))
    {
        CardapioCafe.read((char*)(&add),sizeof(estoque));
        if(add.id!=0 && opc == 1)
        {
            gotoxy(85,8+i);
            cout << add.id << " - ";
            cout << add.Nprato << " R\x24 ";
            cout << add.preco << ' ' << endl;
        }
        CardapioLanches.read((char*)(&add),sizeof(estoque));
        if(add.id!=0 && opc == 2)
        {
            gotoxy(85,8+i);
            cout << add.id << " - "
                 << add.Nprato << " R\x24 "
                 << add.preco << endl;
        }
        CardapioAlmoco.read((char*)(&add),sizeof(estoque));
        if(add.id!=0 && opc == 3)
        {
            gotoxy(85,8+i);
            cout << add.id << " - "
                 << add.Nprato << " R\x24 "
                 << add.preco << endl;
        }
        CardapioJantar.read((char*)(&add),sizeof(estoque));
        if(add.id!=0 && opc == 4)
        {
            gotoxy(85,8+i);
            cout << add.id << " - "
                 << add.Nprato << " R\x24 "
                 << add.preco << endl;
        }
        i = i+2;
    }
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

    tela();
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(25,5);
    cout<<" Promocao do dia ";
    telaCard();
    exibirRecursao(4,0,4);
    do
    {
        textcolor(BLACK);
        textbackground(WHITE);
        gotoxy(14,10);
        cout <<" Digite para comprar a primeira opcao ";
        gotoxy(20,12);
        cout << "     ";
        gotoxy(23,12);
        cin>>choice;
    }
    while(choice<0||choice>4);
    if (choice!=0)
    {
        do
        {
            textcolor(BLACK);
            textbackground(WHITE);
            gotoxy(18,14);
            cout<<" Digite quantas unidades deseja ";
            gotoxy(20,16);
            cout << "   ";
            gotoxy(21,16);
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
    }
}

void exibirRecursao(int f,int k,int j)
{
    if(f==0)
    {

    }
    else
    {
        gotoxy(85,5+k);
        textcolor(BLACK);
        cout << j << " - " << (*(p+ f)).Nprato << " por apenas 1 real ";
        k = k+2;
        j = j -1;
        exibirRecursao(f-1,k,j);

    }
}

void menuAdmin()
{
    int opc;
    tela();
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(16,5);
    cout << " 1 - CADASTRAR ALUNOS ";
    gotoxy(16,7);
    cout << " 2 - GERENCIAR PRODUTOS ";
    gotoxy(16,9);
    cout << " 3 - VIZUALIZAR ALUNOS CADASTRADOS ";
    gotoxy(16,11);
    cout << " 4 - VIZUALIZAR HISTORICO DE VENDAS ";
    gotoxy(16,13);
    cout << " 5 - REALIZAR VENDA ";
    gotoxy(16,15);
    cout << " 0 - ENCERRAR O SISTEMA";
    gotoxy(20,19);
    cout << "   ";
    gotoxy(21,19);
    cin >> opc;
    switch (opc)
    {
    case 0:
    {

        system("cls");
        exit(1);
        break;
    }
    case 1:
    {
        cadastro();
        break;
    }
    case 2:
    {
        opcoeUsuario();
        break;
    }
    case 3:
    {
        exibir();
        break;
    }
    case 4:
    {
        showHistoric();
        break;
    }
    case 5:
    {
        cliente::venda();
        break;
    }
    }
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
    tela();
    textbackground(WHITE);
    textcolor(BLACK);
    gotoxy(16,10);
    cout << "Digite o id do aluno: (Entre 1 e 100)";
    gotoxy(16,12);
    cout << "       ";
    gotoxy(17,12);
    cin >> a.id;

    while(a.id > 0 && a.id < 100)
    {
        gotoxy(16,14);
        cout << "Digite o  nome do aluno: ";
        fflush(stdin);
        gotoxy(16,16);
        cout << "   ";
        gotoxy(17,16);
        cin.getline(a.nome,50);
        gotoxy(14,18);
        cout << "Digite a sigla do curso do aluno: ";
        cin>>a.curso;

        lista.seekp((a.id - 1)*sizeof(aluno));
        lista.write((const char *)(&a),sizeof(aluno));

        lista.close();

        int i;
        gotoxy(8,20);
        cout << " Realizar outro cadastro digite 1 ou 0 para voltar: ";
        cin >> i;
        if(i == 1)
        {
            cadastro();
        }
        else
        {
            menuAdmin();
        }
    }
}

void exibir()
{
    int r = 0;
    aluno lista;
    ifstream exibir("aluno.txt", ios::in);
    if(!exibir.is_open())
    {
        cout <<"arquivo nao aberto com sucesso";
    }

    tela();
    gotoxy(12,5);
    cout << " ID ";
    gotoxy(18,5);
    cout << " Nome ";
    gotoxy(50,5);
    cout << " Curso ";

    exibir.read((char *)(&lista),sizeof(aluno));
    while(exibir && !exibir.eof())
    {
        if(lista.id != 0)
        {
            gotoxy(12,7+r);
            cout << lista.id ;
            gotoxy(18,7+r);
            cout << lista.nome ;
            gotoxy(50,7+r);
            cout << lista.curso;
            r = r+2;
        }
        exibir.read((char *)(&lista),sizeof(aluno));
    }
    exibir.close();
    gotoxy(12,24);
    system("pause");
    menuAdmin();
}

void showHistoric()
{

    ifstream historic("historico.txt", ios::in);
    string s;
    int r=0;
    if (!historic.is_open())
    {
        cerr << "Arquivo nao aberto!!!" << endl;
    }
    tela();
    while (getline(historic, s))
    {
        gotoxy(10,5+r);
        cout << s << endl;
        r++;
    }
    historic.close();
    system("PAUSE>NULL");
    menuAdmin();
}

void opcoeUsuario(void)
{
    int opc;
    tela();
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(12,5);
    cout << "1 - Adicionar Cafe da manha." << endl;
    gotoxy(12,7);
    cout << "2 - Adicionar Lanche / Bebida." << endl;
    gotoxy(12,9);
    cout << "3 - Adicionar Almoco / Sobremesa." << endl;
    gotoxy(12,11);
    cout << "4 - Adicionar Jantar." << endl;
    gotoxy(12,13);
    cout << "5 - Remover do Cardapio." << endl;
    gotoxy(12,15);
    cout << "6 - Alterar Preco." << endl;
    gotoxy(12,17);
    cout << "7 - Voltar para o menu"<<endl;
    gotoxy(12,21);
    cin >> opc;
    switch(opc)
    {
    case 1:
        coffeManha();
        break;
    case 2:
        lanch();
        break;
    case 3:
        almoc();
        break;
    case 4:
        jantar();
        break;
    case 5:
        opcRemover();
        break;
    case 6:
        alterPreco();
    }
    menuAdmin();
}

void coffeManha()
{
    estoque ad, add;
    int opc;
    fstream cafe("cafeManha.txt",ios::ate|ios::out|ios::in);
    tela();
    do
    {
        fstream cafe("cafeManha.txt",ios::ate|ios::out|ios::in);
        textcolor(BLACK);
        textbackground(WHITE);
        gotoxy(12,5);
        cout << " Adicionar variedades de cafe da manha ";
        gotoxy(12,7);
        cout << " Digite o ID do prato : (entre 1 e 25): ";
        cin >> add.id;
        if(add.id>0 && add.id<=25)
        {
            gotoxy(12,9);
            cout << " Digite o nome do prato: ";
            cin >> add.Nprato;
            gotoxy(12,11);
            cout << " Digite o preco do prato: ";
            cin >> add.preco;
            cafe.seekp((add.id-1)*sizeof(estoque));
            cafe.write((const char*)(&add),sizeof(estoque));
        }
        else{
            gotoxy(12,9);
            cout << " Id fora do padrao solicitado ";
        }
        cafe.close();
        gotoxy(12,12);
        cout << " Deseja cadastrar outro prato se sim digite 1: ";
        cin >> opc;

    }while(opc == 1);
    system("PAUSE>NULL");
    opcoeUsuario();
}

void lanch()
{
    int opc;
    estoque ad, add;
    tela();
    do{
    fstream lanches("lanches.txt",ios::ate|ios::out|ios::in);
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(12,5);
    cout << " Adicionar variedades de lanche ";
    gotoxy(12,7);
    cout << " Digite o ID do prato (entre 1 e 25): ";
    cin >> add.id;
    if(add.id>0 && add.id<=25)
    {
        gotoxy(12,9);
        cout << " Digite o nome do lanche: " ;
        cin >> add.Nprato;
        gotoxy(12,11);
        cout << "Digite o preco do lanche: ";
        cin >> add.preco;
        lanches.seekp((add.id-1)*sizeof(estoque));
        lanches.write((const char*)(&add),sizeof(estoque));
        lanches.close();
        gotoxy(12,12);
        cout << " Deseja cadastrar outro prato se sim digite 1: ";
        cin >> opc;

        lanches.close();
    }
    }while(opc == 1);
    system("pause");
    opcoeUsuario();
}

void almoc()
{
    estoque ad, add;
    int opc;
    tela();
    do{
    fstream almoco("almoco.txt",ios::ate|ios::out|ios::in);

    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(12,5);
    cout << " Adicionar variedades de almoco ";
    gotoxy(12,7);
    cout << " Digite o ID do prato (entre 1 e 25): ";
    cin >> add.id;
    if(add.id>0 && add.id<=25)
    {
        gotoxy(12,9);
        cout << " Digite o nome do almoco: " ;
        cin >> add.Nprato;
        gotoxy(12,11);
        cout << " Digite o preco do almoco: ";
        cin >> add.preco;
        almoco.seekp((add.id-1)*sizeof(estoque));
        almoco.write((const char*)(&add),sizeof(estoque));
    }gotoxy(12,12);
        cout << " Deseja cadastrar outro prato se sim digite 1: ";
        cin >> opc;

        almoco.close();
    }while(opc == 1);

    system("pause");
    opcoeUsuario();
}

void jantar()
{
    estoque ad, add;
    int opc;
    tela();
    do{
    fstream janta("jantar.txt",ios::ate|ios::out|ios::in);
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(12,5);
    cout << "Adicionar variedades de jantar ";
    gotoxy(12,7);
    cout << " Digite o ID do jantar: ";
    cin >> add.id;
    if(add.id>0 && add.id<=25)
    {
        gotoxy(12,9);
        cout << " Digite o nome do jantar: " ;
        cin >> add.Nprato;
        gotoxy(12,11);
        cout << " Digite o preço do jantar: ";
        cin >> add.preco;
        janta.seekp((add.id-1)*sizeof(estoque));
        janta.write((const char*)(&add),sizeof(estoque));
    }
    janta.close();
    gotoxy(12,12);
        cout << " Deseja cadastrar outro prato se sim digite 1: ";
        cin >> opc;
    }while(opc == 1);

    system("pause");
    opcoeUsuario();

}

void opcRemover()
{
    estoque add;

    estoque vazio = {0,0.0," "};

    int opc;

    fstream cafeManaha("cafeManha.txt",ios::out|ios::ate|ios::in);
    fstream lanches("lanches.txt",ios::out|ios::ate|ios::in);
    fstream almoco("almoco.txt",ios::out|ios::ate|ios::in);
    fstream jantar("jantar.txt",ios::out|ios::ate|ios::in);

    tela();
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(16,5);
    cout << " 1 - cafe da manha.   " ;
    gotoxy(16,7);
    cout << " 2 - lanche/Bebida.   " ;
    gotoxy(16,9);
    cout << " 3 - almoco/Sobremesa." ;
    gotoxy(16,11);
    cout << " 4 - jantar.          " ;
    gotoxy(16,13);
    cout << " 0 - Sair.            " ;
    gotoxy(18,15);
    cout << "   ";
    gotoxy(19,15);
    cin >> opc;

        switch(opc)
        {
        case 1:
        {
            tela();
            gotoxy(12,10);
            cout << "ID : ";
            cin >> add.id;
            cafeManaha.seekp((add.id-1)*sizeof(estoque));
            cafeManaha.write((const char*)(&vazio),sizeof(estoque));
            break;
        }
        case 2:
        {
            tela();
            gotoxy(12,15);
            cout << "ID : ";
            cin >> add.id;
            lanches.seekp((add.id-1)*sizeof(estoque));
            lanches.write((const char*)(&vazio),sizeof(estoque));
            break;
        }
        case 3:
        {
            tela();
            gotoxy(12,15);
            cout << "ID : ";
            cin >> add.id;
            almoco.seekp((add.id-1)*sizeof(estoque));
            almoco.write((const char*)(&vazio),sizeof(estoque));
            break;
        }
        case 4:
        {
            tela();
            gotoxy(12,15);
            cout << "ID : ";
            cin >> add.id;
            jantar.seekp((add.id-1)*sizeof(estoque));
            jantar.write((const char*)(&vazio),sizeof(estoque));
            break;
        }
        case 0:
        {
            opcoeUsuario();
            break;
        }
        default:
        {
            tela();
            gotoxy(45,16);
            cout << "Opção invalida!!!" << endl;
            system("PAUSE>NULL");
            opcRemover();
            break;
        }
        }
        cafeManaha.close();
        lanches.close();
        almoco.close();
        jantar.close();

}

void alterPreco()
{
    estoque add;

    fstream cafeManaha("cafeManha.txt",ios::out|ios::ate|ios::in);
    fstream lanches("lanches.txt",ios::out|ios::ate|ios::in);
    fstream almoco("almoco.txt",ios::out|ios::ate|ios::in);
    fstream jantar("jantar.txt",ios::out|ios::ate|ios::in);
    int opc;

    tela();
    textcolor(BLACK);
    textbackground(WHITE);
    gotoxy(16,5);
    cout << " 1 - cafe da manha.   " ;
    gotoxy(16,7);
    cout << " 2 - lanche/Bebida.   " ;
    gotoxy(16,9);
    cout << " 3 - almoco/Sobremesa." ;
    gotoxy(16,11);
    cout << " 4 - jantar.          " ;
    gotoxy(16,13);
    cout << " 0 - Sair.            " ;
    gotoxy(18,15);
    cout << "   ";
    gotoxy(19,15);
    cin >> opc;
    switch(opc)
    {
    case 1:
    {
        tela();
        gotoxy(12,15);
        cout << "ID : ";
        cin >> add.id;
        cafeManaha.seekg((add.id-1)*sizeof(estoque));
        cafeManaha.read((char*)(&add),sizeof(estoque));
        gotoxy(12,17);
        cout << "Valor da alteracao : ";
        cin >> add.preco;
        cafeManaha.seekp((add.id-1)*sizeof(estoque));
        cafeManaha.write((const char*)(&add),sizeof(estoque));
        break;
    }
    case 2:
    {
        tela();
        gotoxy(12,15);
        cout << "ID : ";
        cin >> add.id;
        lanches.seekg((add.id-1)*sizeof(estoque));
        lanches.read((char*)(&add),sizeof(estoque));
        gotoxy(12,17);
        cout << "Valor da alteracao : ";
        cin >> add.preco;
        lanches.seekp((add.id-1)*sizeof(estoque));
        lanches.write((const char*)(&add),sizeof(estoque));
        break;
    }
    case 3:
    {
        tela();
        gotoxy(12,15);
        cout << "ID : ";
        cin >> add.id;
        almoco.seekg((add.id-1)*sizeof(estoque));
        almoco.read((char*)(&add),sizeof(estoque));
        gotoxy(12,17);
        cout << "Valor da alteracao : ";
        cin >> add.preco;
        almoco.seekp((add.id-1)*sizeof(estoque));
        almoco.write((const char*)(&add),sizeof(estoque));
        break;
    }
    case 4:
    {
        tela();
        gotoxy(12,15);
        cout << "ID : ";
        cin >> add.id;
        jantar.seekg((add.id-1)*sizeof(estoque));
        jantar.read((char*)(&add),sizeof(estoque));
        gotoxy(12,17);
        cout << "Valor da alteracao : ";
        cin >> add.preco;
        jantar.seekp((add.id-1)*sizeof(estoque));
        jantar.write((const char*)(&add),sizeof(estoque));
        break;
    }
    }
    cafeManaha.close();
    lanches.close();
    almoco.close();
    jantar.close();
    opcoeUsuario();

}

