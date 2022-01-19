#include <iostream>
#include <stdlib.h>

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

            cout << "Valor a pagar "<< total;
            cout << "Valor entregue " << "\n";
            cin >> pagamento;

            system("CLS");

            cout << "----------------------------------------------" << "\n";
            cout << "-------------------Talão----------------------" << "\n";
            cout <<"Número do Cliente " << loginFunc << endl;
            cout << "Numero de linha " << cont << endl;
            cout << "Nome do produto " << vecNomesProduto[i] << endl;
            cout << "Quantidade " << quantidade << endl;
            cout << "Preço s/IVA " << (vecPreco[i]*1.3) << endl;
            cout << "IVA " << vecPreco[i]*0.23 << endl;
            cout << "Total C/iva " << total << endl;
            cout << "Valor entregue " << pagamento << endl;
            cout << "Troco " << pagamento- total << endl;
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

    for (int i = 0; i <= cont; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matVenda[i][j];
        }
        cout << endl;
    }


    } while (valid != 'N');


    
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
                    // code block
                    break;
                case 3:
                    // code block
                    break;
                }

            } while (escolha != 9);



        }