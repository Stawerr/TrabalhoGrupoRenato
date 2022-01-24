#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>

using namespace std;

/* Fun��o menu principal */

void menu(){
    cout << "----------------------------------------------" << "\n";
    cout << "------------Bem Vindo R&M Store---------------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [1] para Venda de Produto---------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [2] para Compra de Stock----------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [3] para Relat�rios---------------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [4] para novo login---------------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [9] para Sair---------------------" << "\n";
    cout << "----------------------------------------------" << "\n";
}

/* Fun��o selec��o de cliente */

int user(int* vecIdCliente,string* vecNomes,int login){
    system("CLS");
    cout << "ID | " << "Nome "  << endl;
    for (int i = 0; i < 4; i++) {

        cout << vecIdCliente[i] << "  | ";
        cout << vecNomes[i] << endl;
    }
        cout << "Por Favor identifique-se pelo seu ID" << endl;
        cin >> login;

        /* Valida��o de cliente correcto */

        if(login < 1 || login >4){
             do {
             cout << "Login Inv�lido, introduza de novo" << endl;
             cin >> login;

            } while (login < 1 || login >4);
         }

    system("CLS");
    return login;
}

/* Fun��o de venda */

void venda(string* vecNomes, int* vecIdCliente,int* vecIdProduto, string* vecNomesProduto,int* vecPreco,int* vecQuantidade,int loginFunc,int** matVenda,int* cont) {
    system("CLS");

    char valid;
    int choose = 0;

    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [1] para Comprar Artigos----------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [2] para Gerar Relat�rio de venda-" << "\n";
    cout << "----------------------------------------------" << "\n";
    cin >> choose;

    /* Valida��o de introdu��o correcta */

    if (choose < 1 || choose >2) {
    
        do {
            cout << "Escolha Inv�lida, introduza de novo" << endl;
            cin >> choose;

        } while (choose < 1 || choose >2);
    }

    switch (choose) {
    case 1:
        system("CLS");
        do {
                cout << "ID | " << "Nome | " << "Quantidade | " << "Pre�o | "<<endl;
                for (int i = 0; i < 5; i++) {
        
                        cout << vecIdProduto[i] <<" | ";
                        cout << vecNomesProduto[i]<<"\t" << "|";
                        cout << vecQuantidade[i] << " | ";
                        cout << vecPreco[i] << "\t" << " | "<<endl;
                }

                int id;
                cout<<"\n" << "Qual o produto que pretende comprar?"<<"\n";
                cin >> id;
                if (id < 1 || id >5) {

                    do {
                        cout << "Artigo indisponivel, introduza de novo" << endl;
                        cin >> id;

                    } while (id < 1 || id >5);
                }
                int quantidade = 0;
                int total = 0;
                int pagamento=0;

                for (int i = 0; i < 5; i++) {
                    if (vecIdProduto[i] == id) {

                        cout << "Indique a quantidade a comprar?" << "\n";
                        cin >> quantidade;

                        /* valida��o da quantidade de stocks com o pedido*/

                        if (quantidade > vecQuantidade[i] || quantidade<=0) {
                            do {
                                cout << "Quantidade inexistente, introduza de novo" << endl;
                                cout << "Quantidade disponivel "<<vecQuantidade[i] << endl;
                                cin >> quantidade;

                            } while (quantidade > vecQuantidade[i] || quantidade <= 0);
                        }
                        vecQuantidade[i] = vecQuantidade[i] - quantidade;
                        total = ((vecPreco[i]*1.23)*1.30) * quantidade;
                        *cont = *cont + 1;
                        SetConsoleOutputCP(1252);
                        cout << "Valor a pagar "<< total << "\u20AC" <<"\n";
                        cout << "Valor entregue " << "\u20AC" << "\n";
                        cin >> pagamento;

                        /* valida��o do pagamento*/

                        if (pagamento < total) {
                            do {

                                cout << "O valor a pagar � mais alto do que introduziu, tem de pagar "<< total << "\u20AC" << "\n";
                                cin >> pagamento;
                            }
                             while (pagamento<total);
                        }
                        system("CLS");

                        /* Impress�o do tal�o de venda */

                        cout << "----------------------------------------------" << "\n";
                        cout << "-------------------Tal�o----------------------" << "\n";
                        cout << "         N�mero do Cliente " << loginFunc << endl;
                        cout << "         Nome do Cliente " << vecNomes[i] << endl;
                        cout << "         Numero de linha " << *cont << endl;
                        cout << "         Nome do produto " << vecNomesProduto[i] << endl;
                        cout << "         Quantidade " << quantidade << endl;
                        cout << "         Pre�o s/IVA " << (vecPreco[i]*1.3) <<"\u20AC" << endl;
                        cout << "         IVA " << vecPreco[i]*0.23 << "\u20AC" << endl;
                        cout << "         Total C/iva " << total << "\u20AC" << endl;
                        cout << "         Valor entregue " << pagamento << "\u20AC" << endl;
                        cout << "         Troco " << pagamento- total << "\u20AC" << endl;
                        cout << "----------------------------------------------" << "\n";
                        cout << "----------------------------------------------" << "\n";
                    }
                }

                matVenda[*cont][0] = loginFunc;
                matVenda[*cont][1] = quantidade;
                matVenda[*cont][2] = total;

                cout << "\n" << "Pretende comprar mais artigos? S/N" << "\n";
                cin >> valid;
                if (valid == 'n') {
                    valid = 'N';
                }
                system("CLS");

            } while (valid != 'N');   

    case 2:
        
           system("CLS");
           cout << "ID | " << "Quantidade | " << "Total | " << "\t" << endl;
           for (int i = 0; i <= *cont; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << matVenda[i][j] << "\t";
                }
                cout << endl;
           }
           system("PAUSE");
           system("CLS");

    }   
}

/* Fun��o renova��o de stock*/

void compraStock(int* vecIdProduto,int* vecQuantidade, string* vecNomesProduto){
    int produto=0;
    int qtd = 0;

    system("CLS");

    cout << "ID | " << "Nome | " << "Quantidade | " << endl;

    for (int i = 0; i < 5; i++) {

        cout << vecIdProduto[i] << " | ";
        cout << vecNomesProduto[i] << "\t" << "|";
        cout << vecQuantidade[i] << " | "<<"\n";
        
    }

    cout << "\n" << "Indique o ID do produto que pretende comprar?" << "\n";
    cin >> produto;

    for (int i = 0; i < 5; i++) {
        if (vecIdProduto[i] == produto) {
        cout << "\n" << "Indique a quantidade de " << vecNomesProduto[i] <<" que pretende comprar ? " << "\n";
        cin >> qtd;
        vecQuantidade[i] = vecQuantidade[i] + qtd;
        }
    }

    system("CLS");
}

/* Fun��o para apresenta��o dos relat�rios*/

void relatorio(int* vecIdProduto,string* vecNomesProduto, int* vecPreco,int* vecQuantidade) {
    int select = 0;
    int total = 0;
    int produto ;

    system("CLS");
    
    do {
        cout << "------Prima [1] para Relat�rio de stock total----------------" << "\n";
        cout << "-------------------------------------------------------------" << "\n";
        cout << "------Prima [2] para Relatorio de stock por produto----------" << "\n";
        cout << "-------------------------------------------------------------" << "\n";
        cout << "------Prima [3] para voltar atr�s----------------------------" << "\n";
        cout << "-------------------------------------------------------------" << "\n";
        cin >> select;

        /* Valida��o de introdu��o correcta */

        if (select < 1 || select >3) {

            do {
                cout << "Op��o indisponivel, introduza de novo" << endl;
                cin >> select;

            } while (select < 1 || select >3);
        }
        system("CLS");

        /* Indica��o do stock total */

        if (select==1) {
            for (int i = 0; i < 5; i++) {
                total = total + vecQuantidade[i];
            }
            cout << "O total de stock de produtos no invent�rio � de: " << total<<"\n";
            cout << "\n";
        }

        /* Indica��o do stock por produto */
        int sair=0;
        if (select == 2) {

            cout << "ID | " << "Nome | " << endl;
            for (int i = 0; i < 5; i++) {
                cout << vecIdProduto[i] << " | ";
                cout << vecNomesProduto[i] << "\t" << "|"<<"\n";
            }
            cout << "\n" << "Indique qual o Id do produto que pretende ver o stock?" << "\n";
            cin >> produto;
            cout << "\n";
            for (int i = 0; i < 5; i++) {
                
                if (produto == vecIdProduto[i]){
                    cout << "ID | " << "Nome | " << endl;
                    cout << vecIdProduto[i] << " | ";
                    cout << vecNomesProduto[i] << "\t" << "|";
                    cout << vecQuantidade[i] << " | ";
                }
            }
            cout << "\n";
            system("pause");
            system("CLS");
         
            /*for (int i = 0; i < 5; i++) {
                if (produto.compare(vecNomesProduto[i])!=0) {
                            cout << "ID | " << "Nome | " << "Quantidade | " << endl;
                            cout << vecIdProduto[i] << " | " << "\t";
                            cout << vecNomesProduto[i] << "\t" << "|";
                            cout << vecQuantidade[i] << " | " << "\n";
                            cout << "\n";
                }
                else {
                    cout << "Produto inexistente escolha de novo"<<"\n";
                    cin >> produto;
                }
            }*/
        }

    } while (select != 3);

    system("CLS");
}

int main()
{
    setlocale(LC_ALL, ("portuguese"));
    int escolha=0;

    /* Vetores Cliente */

    int vecIdCliente[] = { 1,2,3,4 };
    string vecNomes[] = { "Ana","Joel","Paulo","Maria" };
   
    /* Vetores Produto */
 
    int vecIdProduto[] = { 1,2,3,4,5 };
    string vecNomesProduto[] = { "Monitor","Teclado","Rato","Webcam","Colunas" };
    int vecPreco[] = { 120,22,13,40,25 };
    int vecQuantidade[] = { 10,10,10,10,10 };
  
    /* Matriz Venda */

    int login=0;
    int cont = -1;

    int** matVenda = new int* [10];
    for (int i = 0; i < 10; i++) {
        matVenda[i] = new int[3];
    }

    int loginFunc= user(vecIdCliente,vecNomes,login);

    system("CLS");

            do {
                
                menu();
                
                cout << "\n" << "Indique a opera��o a realizar?" << endl;
                cin >> escolha;

                switch (escolha) {
                case 1:
                    venda(vecNomes,vecIdCliente,vecIdProduto, vecNomesProduto, vecPreco, vecQuantidade, loginFunc, matVenda, &cont);
                    break;
                case 2:
                    compraStock(vecIdProduto, vecQuantidade,vecNomesProduto);
                    break;
                case 3:
                    relatorio(vecIdProduto, vecNomesProduto, vecPreco, vecQuantidade);
                    break;
                case 4:
                    user(vecIdCliente, vecNomes, login);
                    break;
                }
                
            } while (escolha != 9);
        }