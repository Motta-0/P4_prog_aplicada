#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

struct tNo
{
  float info;
  tNo* proximo;
};

tNo* criarNo(float item)
{
  tNo* no = new tNo;

  no -> info = item;
  no -> proximo = NULL;

  return no;
} 

struct tLista
{
  tNo* primeiro;
  tNo* ultimo;
  tNo* marcador;
  int tamanho;
};

void startList(tLista* pList)
{
  pList -> primeiro = NULL;
  pList -> ultimo = NULL;
  pList -> marcador = NULL;
  pList -> tamanho = 0;
}

int obterTamanho(tLista* pList)
{
  return pList -> tamanho;
}

bool emptyList(tLista* pList)
{
  return (pList -> tamanho == 0);
}

bool endList(tLista* pList)
{
  return (pList -> marcador == NULL);
}

void includeEnd(tLista* pList, float info)
{
  tNo* no;
  no = criarNo(info);

  if(emptyList(pList))
  {
    pList -> primeiro = no;
  }
  else
  {
    pList -> ultimo -> proximo = no;
  }

  pList -> ultimo = no;
  pList -> marcador = no;
  pList -> tamanho ++;
}

void printList(tLista* pList)
{
    pLista->marcador = pLista->primeiro;
    int cont=0;
    while(!finalLista(pLista)){
      float informacao = pLista->marcador->info;
      if (cont==0){ 
        cout << "----PAR DE COMPLEXOS----" << endl;
        cout << "Z1: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if (cont==1){
        cout << "Z2: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==2){
        cout << "SOMA: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==3){
        cout << "SUBTRACAO: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==4){
        cout << "MULTIPLICACAO: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==5){
        cout << "DIVISAO: " << informacao;
        pLista->marcador = pLista->marcador->proximo;
        informacao = pLista->marcador->info;
        if (informacao >= 0){
          cout << "+" << informacao << "i" << endl;
        }else{
          cout << informacao << "i" << endl;
        }
      }else if(cont==6){
        cout << "MODULO Z1: " << informacao << endl;;
      }else if(cont==7){
        cout << "MODULO Z2: " << informacao << endl;
        cont=-1;
      }
      pLista->marcador = pLista->marcador->proximo;
      cont++;
    }
    cout << endl;
}
  

void readFile(tLista* pList)
{
  pList -> marcador = pList -> primeiro;

  ifstream RFILE;
  RFILE.open("Arquivo.txt", ios::in);
  float read;

  while (!RFILE.eof())
  {
    RFILE >> read;
    includeEnd(pList, read);
  }
  RFILE.close();
}

void writeFile(tLista*, pList)
{
  pList -> marcador = pList -> primeiro;

  ofstream WFILE;
  WFILE.open("Arquivo.txt", ios::out);

   while(!endList(pList))
   {
    float information = pList -> marcador -> info;
    WFILE << information << " ";
    pList -> marcador = pList -> marcador -> proximo;
   }
  WFILE.close();
}



//--------------------------------------------------------------------------\\


struct tComplexos
{
  float real;
  float imaginario;
  float mod1;
  float mod2;

}Ncomplex[3];

void add(tLista*, complex)
{
  Ncomplex[2].real = Ncomplex[0].real + Ncomplex[1].real;
  includeEnd(complex, Ncomplex[2].real);
  Ncomplex[2].imaginario = Ncomplex[0].imaginario + Ncomplex[1].imaginario;
  includeEnd(complex, Ncomplex[2].imaginario);
}

void sub(tLista*, complex)
{
  Ncomplex[2].real = Ncomplex[0].real - Ncomplex[1].real;
  includeEnd(complex, Ncomplex[2].real);
  Ncomplex[2].imaginario = Ncomplex[0].imaginario - Ncomplex[1].imaginario;
  includeEnd(complex, Ncomplex[2].imaginario);
}

void mult(tLista*, complex)
{
  Ncomplex[2].real = (Ncomplex[0].real * Ncomplex[1].real) - (Ncomplex[0].imaginario * Ncomplex[1].imaginario);
  includeEnd(complex, Ncomplex[2].real);

  Ncomplex[2].imaginario = (Ncomplex[1].imaginario * Ncomplex[0].real) + (Ncomplex[0].imaginario * Ncomplex[1].real);
  includeEnd(complex, Ncomplex[2].imaginario);
}

void div(tLista*, complex)
{
  Ncomplex[2].real = (Ncomplex[0].real * Ncomplex[1].real) + (Ncomplex[0].imaginario * Ncomplex[1].imaginario);
  includeEnd(complex, Ncomplex[2].real);

  Ncomplex[2].imaginario = (Ncomplex[0].imaginario * Ncomplex[1].real) - (Ncomplex[1].imaginario * Ncomplex[0].real);
  includeEnd(complex, Ncomplex[2].imaginario);

  float denominador = (Ncomplex[1].real * Ncomplex[1].real) + (Ncomplex[1].imaginario * Ncomplex[1].imaginario);
  includeEnd(complex, denominador);

  cout << "\n\nO resultado é: " << Ncomplex[2].real << "/" << denominador;

  if (Ncomplex[2].imaginario >= 0)
  {
    cout << "+" << Ncomplex[2].imaginario << "j/" << denominador << endl;
  }
  else
  cout << Ncomplex[2].imaginario << "j/" << denominador << endl;
}

void module(tLista*, complex)
{
  Ncomplex[2].mod1 = sqrt(pow(Ncomplex[0].real,2) + pow(Ncomplex[0].imaginario,2));
  includeEnd(complex, Ncomplex[2].mod1);

  cout << "\n\n\nO modulo do primeiro número complexo é: " << Ncomplex[2].mod1 << endl;

  Ncomplex[2].mod2 = pow(pow(Ncomplex[1].real,2) + pow(Ncomplex[1].imaginario,2), 0.5);
  includeEnd(complex, Ncomplex[2].mod2);

  cout << "O modulo do segundo número complexo é: " << Ncomplex[2].mod2 << endl;
}

void print_result()
{ 
  cout << endl << "O resultado da operação é: ";
  cout << Ncomplex[2].real;
  
  if (Ncomplex[2].imaginario > 0)
    {
      cout << "+" << Ncomplex[2].imaginario << "j" << endl;
    }
    else 
    cout << Ncomplex[2].imaginario << "j" << endl << endl;
}
#endif

void Keep(tLista* complex, tComplexos Comp)
{
  cout << "Digite parte real 1: ";
	cin >> Comp.real;
  endList(complex, Comp.real);
	cout<<"Digite imaginaria 1: ";
	cin>> Comp.imaginario;
  endList(complex, Comp.imaginario);
	cout<<"Digite parte real 2: ";
	cin>> Comp.real;
  endList(complex, Comp.real);
	cout<<"Digite imaginaria 2: ";
	cin>>Comp.imaginario;
  endList(complex, Comp.imaginario);
}

//--------------------------------------------------------------------------\\

int main ()
{
  tLista* complex = new tLista; 

  CriaListaNull(complexo); 

	tComplexo Comp; 
 
  int opcao=0;
  while(true){
    cout << "O QUE VOCE DESEJA: " << endl;
    cout << "1) Escrever no arquivo." << endl;
    cout << "2) Ler o arquivo." << endl;
    cout << "3) SAIR." << endl;
    cout << "Opcao: ";
    cin >> opcao;
    if (opcao == 3){ 
      break;
    }
    else{
      if (opcao == 1){ 
        int quant=0;
        cout << "Quantos números complexos voce deseja?";
        cin >> quant;
        for (int i=0; i<quant; i++){
          Gravar(nComplexo,Comp);
          cout << "------------------" << endl;
        }
        gravarArquivo(nComplexo);
        CriaListaNull(nComplexo);
      }
      else if (opcao == 2){ 
        lerArquivo(nComplexo);
        mostrarLista(nComplexo);
      }
    }
  }
}