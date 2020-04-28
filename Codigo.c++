/*
 * Titulo:   Trabalho de estrutura de dados
 * Author: Alesson Sousa
 * Github: https://github.com/alessonsousa
 * Created on 6 de Março de 2020, 19:16
 *
 * Trabalho feito na diciplina de estrutura de dados no IFCE-Campus Cedro
 *
 * Desenvolver um caixa comercial com cadastro de
produtos, onde cada produto deve ter nome, preço,
código e quantidade. Deve permitir ainda a venda
de produto, listar os produtos cadastrados e buscar
um produto pelo código.
 *Inicio: 08/03/20
 *Fim: 12/03/20
 */
// BIBLIOTECAS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <locale.h>
#define NUM 30

using namespace std;

//REGISTRO DOS PRODUTOS
struct Produtos
{
    char nomeProduto[40];
    float precoProduto;
    int codigoProduto;
    int quantidadeProduto;

};

//VARIAVEIS GLOBAIS
int Dig = 0;
int contProdu = 0;
int valor;
int qtdtotal;


//FUNÇÕES
void inicio();
int cadastraProdu(Produtos *Produto,int contProdu);
void listaproduto(Produtos *Produto);
void buscarProduto(Produtos *Produto, int contProdu);
void vendaProduto(Produtos *Produto);


//FUNÇÃO PRINCIPAL MAIN
int main()
{


    Produtos Produto[NUM];
    do
    {

        cout << "\n\t\tOPCOES" << endl;
        cout << "-----------------------------------\n";
        cout << "[1]Venda de Produtos" << endl;
        cout << "[2]Produtos Cadastrados" << endl;
        cout << "[3]Buscar Produtos" << endl;
        cout << "[4]Cadastra Produtos" << endl;
        cout << "[5]Sair" << endl;
        cout << "Escolha a opcao e digite o numero: ";
        cin >> Dig;
        cout << "-----------------------------------\n";
        fflush(stdin);
        system("cls");
        switch (Dig)
        {

        case 1:
            vendaProduto(Produto);
            break;
        case 2:
            listaproduto(Produto);
            break;
        case 3:
            buscarProduto(Produto, contProdu);
            break;
        case 4:
            contProdu = cadastraProdu(Produto, contProdu);
            break;
        case 5:
            cout << "\n\n\t\tSair\n\n";
            break;
        }
    }
    while(Dig != 5);
    return 0;
}
//FUNÇÃO DE CADASTRA OS PRODUTOS

int cadastraProdu(Produtos *Produto,int contProdu)
{
    int op, i;
    system("cls");
    cout << "\n\tCadastra Produtos" << endl;
    cout << "------------------------------------\n";
    cout << "Nome do Produto: ";
    cin >> Produto[contProdu].nomeProduto;

    cout << "Codigo do Produto: ";
    cin >> Produto[contProdu].codigoProduto;

    cout << "Preco do Produto:R$";
    cin >> Produto[contProdu].precoProduto;

    cout << "Quantidade do Produto: ";
    cin >> Produto[contProdu].quantidadeProduto;

    system("cls");
    contProdu++;
    return contProdu;

}

//FUNÇÃO DE LISTAR TODOS PRODUTOS CADASTRADO
void listaproduto(Produtos *Produto)
{
    int op;
    do
    {

        system("cls");
        cout << "\t\tProdutos Cadastrados";
        for (int i = 0; i < contProdu; i++)
        {
            cout << "\n\n";
            cout << "-----------------------------------------------------\n";
            cout << "Nome do Produto: " << Produto[i].nomeProduto << endl;
            cout << "Codigo do Produto: " << Produto[i].codigoProduto << endl;
            cout << "Preco do Produto:R$" << Produto[i].precoProduto << endl;
            cout << "Quantidade do Produto: " << Produto[i].quantidadeProduto << "\n\n";


        }
        cout << "Volta para o menu [1]SIM: ";
        cin >> op;
        system("cls");
    }
    while(op != 1);
}

//FUNÇÃO DE BUSCAR PRODUTOS PELO CODIGO
void buscarProduto(Produtos *Produto, int contProdu)
{
    int Num;

    cout << "Digite o codigo do produto: ";
    cin >> Num;

    for (int i = 0; i < contProdu; i++)
    {

        if (Num == Produto[i].codigoProduto)
        {
            cout << "\t\tProduto do codigo: " << Produto[i].codigoProduto << endl;
            cout << "--------------------------------------------------------\n";
            cout << "Produto: " << Produto[i].nomeProduto << endl;
            cout << "Preco:R$" << Produto[i].precoProduto << endl;
            cout << "Quantidade: " << Produto[i].quantidadeProduto << endl;
            cout << "--------------------------------------------------------\n\n";
            system("pause");
        }

    }
    system("cls");
}
//FUNÇÃO DE VENDAS DOS PRODUTOS
void vendaProduto(Produtos *Produto)
{
    int ven, total, val;
    cout << "Digite o codigo do produto: ";
    cin >> ven;

    for(int i=0; i < contProdu; i++)
    {
        if(ven == Produto[i].codigoProduto && Produto[i].quantidadeProduto > 0)
        {
            Produto[i].quantidadeProduto--;
            cout << "\n\n\tProduto '" << Produto[i].nomeProduto << "' vendido com sucesso.\n";
            system("pause");
            system("cls");
        }

    }
    system("cls");
}
