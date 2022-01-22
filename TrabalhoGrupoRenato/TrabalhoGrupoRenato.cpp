#include <iostream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

void menu(){
    cout << "----------------------------------------------" << "\n";
    cout << "------------Bem Vindo R&M Store---------------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [1] para Venda de Produto---------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [2] para Compra de Stock----------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [3] para Relatórios---------------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [9] para Sair---------------------" << "\n";
    cout << "----------------------------------------------" << "\n";

}
int user(int* vecIdCliente,string* vecNomes,int login){

    cout << "ID | " << "Nome "  << endl;
    for (int i = 0; i < 4; i++) {

        cout << vecIdCliente[i] << "  | ";
        cout << vecNomes[i] << endl;
    }

    cout << "Por Favor identifique-se pelo seu ID" << endl;
    cin >> login;

    return login;

}

void venda(int* vecIdCliente,int* vecIdProduto, string* vecNomesProduto,int* vecPreco,int* vecQuantidade,int loginFunc,int** matVenda) {
    system("CLS");

    char valid;
    int cont = -1;
    int choose = 0;

    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [1] para Comprar Artigos----------" << "\n";
    cout << "----------------------------------------------" << "\n";
    cout << "------Prima [2] para Gerar Relatório de venda-" << "\n";
    cout << "----------------------------------------------" << "\n";
    cin >> choose;
    if (choose==1) {
        system("CLS");
        do {
                cout << "ID | " << "Nome | " << "Quantidade | " << "Preço | "<<endl;
                for (int i = 0; i < 5; i++) {
        
                        cout << vecIdProduto[i] <<" | ";
                        cout << vecNomesProduto[i]<<"\t" << "|";
                        cout << vecQuantidade[i] << " | ";
                        cout << vecPreco[i] << "\t" << " | "<<endl;
                }
    


                int id;
                cout<<"\n" << "Qual o produto que pretende comprar?"<<"\n";
                cin >> id;

                int quantidade = 0;
                int total = 0;
                int pagamento=0;

                for (int i = 0; i < 5; i++) {
                    if (vecIdProduto[i] == id) {

                        cout << "Indique a quantidade a comprar?" << "\n";
                        cin >> quantidade;

                        vecQuantidade[i] = vecQuantidade[i] - quantidade;
                        total = ((vecPreco[i]*1.23)*1.30) * quantidade;
                        cont = cont + 1;
                        SetConsoleOutputCP(1252);
                        cout << "Valor a pagar "<< total << "\u20AC" <<"\n";
                        cout << "Valor entregue " << "\u20AC" << "\n";
                        cin >> pagamento;
                        if (pagamento < total) {
                            do {

                                cout << "O valor a pagar é mais alto do que introduziu, tem de pagar "<< total << "\u20AC" << "\n";
                                cin >> pagamento;
                            }
                             while (pagamento<total);
                        }
                        system("CLS");

                        cout << "----------------------------------------------" << "\n";
                        cout << "-------------------Talão----------------------" << "\n";
                        cout << "         Número do Cliente " << loginFunc << endl;
                        cout << "         Numero de linha " << cont << endl;
                        cout << "         Nome do produto " << vecNomesProduto[i] << endl;
                        cout << "         Quantidade " << quantidade << endl;
                        cout << "         Preço s/IVA " << (vecPreco[i]*1.3) <<"\u20AC" << endl;
                        cout << "         IVA " << vecPreco[i]*0.23 << "\u20AC" << endl;
                        cout << "         Total C/iva " << total << "\u20AC" << endl;
                        cout << "         Valor entregue " << pagamento << "\u20AC" << endl;
                        cout << "         Troco " << pagamento- total << "\u20AC" << endl;
                        cout << "----------------------------------------------" << "\n";
                        cout << "----------------------------------------------" << "\n";
                    }
                }

                matVenda[cont][0] = loginFunc;
                matVenda[cont][1] = quantidade;
                matVenda[cont][2] = total;

                cout << "\n" << "Pretende comprar mais artigos? S/N" << "\n";
                cin >> valid;

                system("CLS");

            } while (valid != 'N');
    }
    if(choose==2) {
       system("CLS");
       for (int i = 0; i <= cont; i++) {
            for (int j = 0; j < 3; j++) {
                cout << matVenda[i][j];
            }
            cout << endl;
        }
    }   
}
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
void relatorio(int* vecIdProduto,string* vecNomesProduto, int* vecPreco,int* vecQuantidade) {
    int select = 0;
    int total = 0;
    string produto ;

    system("CLS");
    
    do {
        cout << "------Prima [1] para Relatório de stock total----------------" << "\n";
        cout << "-------------------------------------------------------------" << "\n";
        cout << "------Prima [2] para Relatorio de stock por produto----------" << "\n";
        cout << "-------------------------------------------------------------" << "\n";
        cout << "------Prima [3] para voltar atrás----------------------------" << "\n";

        cin >> select;

        system("CLS");

        if (select==1) {
            for (int i = 0; i < 5; i++) {
                total = total + vecQuantidade[i];
            }
            cout << "O total de stock de produtos no inventário é de: " << total<<"\n";
            cout << "\n";
        }

        if (select == 2) {
            cout << "\n" << "Indique qual nome do produto que pretende ver o stock?" << "\n";
            cin >> produto;

            system("CLS");

            for (int i = 0; i < 5; i++) {
                if (vecNomesProduto[i]== produto) {
                    cout << "ID | " << "Nome | " << "Quantidade | " << endl;
                    cout << vecIdProduto[i] << " | " << "\t";
                    cout << vecNomesProduto[i] << "\t" << "|";
                    cout << vecQuantidade[i] << " | " << "\n";
                    cout << "\n";
                }
            }
        }

    } while (select != 3);

    system("CLS");
}

int main()
{
    setlocale(LC_ALL, ("portuguese"));
    int escolha;
    //Vetor Clientes

    int vecIdCliente[] = { 1,2,3,4 };
    string vecNomes[] = { "Ana","Joel","Paulo","Maria" };

    //----------------------------------------------------------------
    
    //Vetor Produto

    int vecIdProduto[] = { 1,2,3,4,5 };
    string vecNomesProduto[] = { "Monitor","Teclado","Rato","Webcam","Colunas" };
    int vecPreco[] = { 120,22,13,40,25 };
    int vecQuantidade[] = { 10,10,10,10,10 };

    //--------------------------------------------------------------
    
    //Matriz Venda

    int login=0;


    int** matVenda = new int* [10];
    for (int i = 0; i < 10; i++) {
        matVenda[i] = new int[3];
    }

    int loginFunc= user(vecIdCliente,vecNomes,login);


    system("CLS");

            do {

                menu();
                
                cout << "\n" << "Indique a operação a realizar?" << endl;
                cin >> escolha;

                switch (escolha) {
                case 1:
                    venda(vecIdCliente,vecIdProduto, vecNomesProduto, vecPreco, vecQuantidade, loginFunc, matVenda);
                    break;
                case 2:
                    compraStock(vecIdProduto, vecQuantidade,vecNomesProduto);
                    break;
                case 3:
                    relatorio(vecIdProduto, vecNomesProduto, vecPreco, vecQuantidade);
                    break;
                }

            } while (escolha != 9);

        }