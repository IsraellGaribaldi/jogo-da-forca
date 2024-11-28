#include <iostream> // biblioteca de entrada e saída (cin, cout)
#include <stdlib.h> // biblioteca de funções como rand(), srand(), e system()
#include <time.h> // bibloteca para inicializar o gerador de números aleatórios com a função time()
#include <string.h> // biblioteca para gerenciar e manipular strings
#include <ctype.h> // biblioteca para funções como tolower(), que converte caracteres para minúsculos

	//entrada: sortear uma das palavras do banco de palavras e inserir uma letra no espaço "_"
   
    //processamento: armazenar e verificar se a letra está presente na palavra e se ela ja foi previamente digitada ou não, 
	//				 exibir as letras ja digitadas e calcular a quantidade de tentativas restantes, 
	//				 e imprimir a forca de acordo com os erros do usuário
   
    //saida: decidir o final do jogo de acordo com os acertos e erros do jogador, exibindo o resultado na tela


using namespace std; // evita a necessidade de prefixar funções e objetos da biblioteca padrão com std

const int quant_palavras = 6; // define a constante quantidade de palavras no banco como variável

char banco[quant_palavras][30]={ // define quais palavras serão adivinhadas no banco de palavras
"papel",
"celular",
"pato",
"sorvete",
"livro",
"sapato"};

char dicas[quant_palavras][100] = {//defini as dicas para cada palavra
    "Material usado para escrever.",
    "Objeto usado para se comunicar.",
    "Animal que gosta de nadar.",
    "Doce gelado.",
    "Objeto cheio de páginas.",
    "Objeto usado nos pés."};


// define uma matriz de strings com o banco
char palavra_sort[30];  // armazena a palavra sorteada
char palavra_dig[30]; // armazena a palavra sendo adivinhada pelo jogador com as letras reveladas até o momento

// sorteia uma palavra definida no banco de palavras para ser adivinhada no jogo
int sorteia(){
    srand(time(NULL)); // inicializa o gerador de números aleatórios
    return rand() % (quant_palavras); // retorna um índice aleatório entre 0 e quant_palavras-1.
}

// imprime a quantidade de letras da palavra referente e a palavra oculta com letras reveladas e com "_" para as não descobertas até o momento
void imprime_palavra_dig(){
    cout<<"\n     "<<strlen(palavra_sort)<<" letras \n\n    ";
    for(int i=0;i < strlen(palavra_sort) ;i++){
        cout<<palavra_dig[i]<<" ";
    }
}

// copia a palavra sorteada do banco de palavras para palavra_sort
void copia(int ind){
    for(int i=0;i<30;i++){
        palavra_sort[i] = banco[ind][i];
    }
}

// preenche palavra_dig com "_" para indicar que nenhuma letra foi descoberta
void limpa_palavra_dig(){
    for(int i=0;i < strlen(palavra_sort);i++){
        palavra_dig[i] = '_';
    }
}

// desenha a forca com switch case de acordo com a quantidade de erros (let_erro)
void imprime_forca(int let_erro){
    switch(let_erro){
         case 0:
            cout<<"  ___ "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 1:
            cout<<"  ___ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 2:
            cout<<"  ___ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |    | "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 3:
            cout<<"  ___ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |   /| "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 4:
            cout<<"  ___ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |   /|\\"<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 5:
            cout<<"  ___ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |   /|\\"<<endl;
            cout<<" |   /  "<<endl;
            cout<<" |      "<<endl;
            break;
        case 6:
            cout<<"  ___ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |   /|\\"<<endl;
            cout<<" |   / \\"<<endl;
            cout<<" |       "<<endl;
            break;
    }
}

// verifica se a letra já foi digitada com for e if else
bool verifica_letra(char letra, char vetor[26]){
    for(int i=0;i<strlen(vetor);i++){
        if(letra==vetor[i]){
            return true; // se retornar verdadeira, a letra já foi usada
        }
    }
    return false; // se retornar falsa a letra ainda não foi usada
}

// substitui a letra (caso for a correta) na palavra para ser adivinhada
void substitui(char letra){
    for(int i=0;i<strlen(palavra_sort);i++){
        if(palavra_sort[i]==letra){
            palavra_dig[i] = letra; // revela a letra
        }
    }
}

// exibe as letras já digitadas anteriormente
void imprime_let_dig(char letras[], int tam){
    cout<<"\n\n Letras digitadas: ";
    for(int i=0;i < tam ;i++){
        cout<<letras[i]<<", ";
    }
    cout<<"\n";
}

// verifica se a palavra ja foi completada com for e if else
bool palavra_completa(){
    for(int i=0;i<strlen(palavra_sort);i++){
        if(palavra_dig[i]=='_'){
            return false; // ainda restam letras para serem adivinhadas
        }
    }
    return true; // todas as letras já foram reveladas
}

void jogar(){
	int cont_erros=0; //quantidade de erros
	
	int ind_palavra = sorteia(); //sortea uma palavra do banco

    copia(ind_palavra); // copia a palavra para palavra_sort

    limpa_palavra_dig(); // inicializa palavra_dig
    
    cout << "Dica: " << dicas[ind_palavra] << endl; // Mostra a dica correspondente à palavra sorteada

    int cont_let_dig=0; // contador de letras digitadas

    char letras_digitadas[26]; // vetor contendo letras digitadas

    char letra; // letra digitada
    
	    while(cont_erros<6){
	        system("cls"); // comando do sistema para limpar a tela
	        cout << "Dica: " << dicas[ind_palavra] << endl; // exibe a dica sempre antes da forca
	        imprime_forca(cont_erros); // imprime a forca
	        imprime_palavra_dig(); // apresenta o progresso da palavra
	        imprime_let_dig(letras_digitadas,cont_let_dig); // mostra letras utilizadas
	        
			// bloco de tentativas restantes
			cout<<"\n\n Tentativas restantes: "<<6-cont_erros<<"\n\n";
	        cout<<"\n\n";
	        cout<<"Digite uma letra: ";
	        cin>>letra;
	        letra = tolower(letra); // função para converter a letra para minúscula
	        
			// bloco para verificar se a letra ja foi digitada na palavra ou não
			if(verifica_letra(letra,letras_digitadas)){
	            cout<<"Letra ja foi digitada! Tente novamente!\n\n";
	            system("pause");
	        }else{
	            letras_digitadas[cont_let_dig] = letra;
	            cont_let_dig++;
				
				// bloco incluso para verificar se a letra deverá ser revelada ou não 
	            if(verifica_letra(letra,palavra_sort)){
	                substitui(letra); // revela a letra
	            }else{
	                cout<<"\nLetra incorreta! Tente novamente\n\n";
	                cont_erros++; // adiciona erro
	                system("pause");
	
	            }
	        }
	        
	        // bloco para decidir o final do jogo (se o usuário errou em adivinhar a palavra nas tentativas, imprime que as tentativas acabaram)
	        if(cont_erros>=6){
	            system("cls");
	            cout<<"\n\n\tSuas tentativas acabaram!\n Reinicie o software para tentar novamente!\n";
	            system("pause");
	            return;
	        }
	        
	        // bloco para decidir o final do jogo (se o usuário acertou em adivinhar a palavra nas tentativas, imprime que o usuário acertou a palavra)
	        if(palavra_completa()){
	            cout<<"\n\tPARABENS!!!\n Voce acertou a palavra!\n\n";
	            system("pause");
	            return;
	        }
	    }
	}

void menu(int escolha){	
	do {
		printf("Menu\n1- Jogar\n2- Creditos\n3- Sair\n");
		scanf("%i", &escolha);
		
		switch(escolha) {
			case 1:
				system("cls");
				printf("Iniciando jogo...\n");
				jogar();
			break;
			
			case 2:
				system("cls");
				printf("\nCreditos\n\nAna Beatriz Silva - 38640805\nAna Beatriz Costa - 38488612\nAna Luiza Brandao - 39233545\nIsraell Garibaldi - 38968169\n\n");
			break;
			
			case 3:
				exit(0);
			break;
			
			default:
				printf("Escolha uma opção válida");
			break;
		}
	} while (escolha != 3);
}

// função principal
int main(){
    int escolha;
    
	menu(escolha);

    return 0;
}
