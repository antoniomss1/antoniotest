
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char titulo[40];
	char autor[40];
	int codigo;
	int ano;
	int totalExemplares;
	int exemplaresDisponiveis;
}livro;

int main() {
	livro biblioteca[100];
	int escolha, i=0, j, k=0, codigo, quant;
	FILE *f;
    int n;
    char procurar[40];

    f = fopen("Livros.txt", "r+");

    if(!f){
        printf ("no foi possivel abrir o arquivo\n");
    }
    else{
        while(!feof(f)){
            fscanf(f, "%s", biblioteca[i].titulo);
            fscanf(f, "%s", biblioteca[i].autor);
            fscanf (f, "%d", &biblioteca[i].codigo);
            fscanf (f, "%d", &biblioteca[i].ano);
            fscanf (f, "%d", &biblioteca[i].totalExemplares);
            fscanf (f, "%d", &biblioteca[i].exemplaresDisponiveis);
            i++;
        }
    }
    i--;
    n = i;
    fclose(f);
    
	do{
        system("cls");
		printf("====Escolha uma opcao====\n");
		printf("1- Verificar lista\n2- Incluir livro\n3- excluir livro\n4- Atualizar informacoes do livro\n5- Gerenciar emprestimos\n6- buscar livro\n7- Sair\n");
		scanf("%d", &escolha);
		system("cls");
		switch(escolha){
			case 1:
				for(j=0; j<i; j++){
					printf("Titulo do livro: %s\n", biblioteca[j].titulo);
					printf("Autor: %s\n", biblioteca[j].autor);
					printf("Codigo do livro: %d\n", biblioteca[j].codigo);
					printf("Ano de publicacao: %d\n", biblioteca[j].ano);
					printf("Total de exemplares: %d\n", biblioteca[j].totalExemplares);
					printf("Total disponivel: %d\n", biblioteca[j].exemplaresDisponiveis);
					printf("============================================================\n");
				}
				
				system("pause");
				system("cls");
				break;
			case 2:
				if(i==100){
        			printf ("nao ha mais espaco na biblioteca\n");
        			continue;
  				}
  				// fflush(stdin);
			    printf ("\tIncluindo um livro\t\n");
			    printf ("digite:\nO titulo do livro:\n");
			    scanf(" %39[^\n]", biblioteca[i].titulo);
                for(j=0; biblioteca[i].titulo[j]!='\0'; j++){
                    if(biblioteca[i].titulo[j]==32) biblioteca[i].titulo[j]= 95;
                }
			    // fflush(stdin);
			    printf ("Nome do autor:\n");
			    scanf (" %39[^\n]", biblioteca[i].autor);
                for(j=0; biblioteca[i].autor[j]!='\0'; j++){
                    if(biblioteca[i].autor[j]==32) biblioteca[i].autor[j] = 95;
                }
			    // fflush(stdin);
			    printf ("Codigo do livro:\n");
			    scanf (" %d", &biblioteca[i].codigo);
			    // fflush(stdin);
			    printf ("Ano de publicacao:\n");
			    scanf (" %d", &biblioteca[i].ano);
			    printf ("Total de exemplares:\n");
    			scanf (" %d", &biblioteca[i].totalExemplares);
    			biblioteca[i].exemplaresDisponiveis = biblioteca[i].totalExemplares;
    			system("cls");
    			printf("Livro adicionado com sucesso!\n");
    			i++;
				system("pause");
				system("cls");
				break;
			case 3:
				printf("Escolha uma opcao\n1- Excluir um livro do catalogo\n2- Dar baixa em certa quantidade\n");
				scanf("%d", &escolha);
				switch(escolha){
					case 1:
						printf("Digite o codigo do livro que deseja excluir: ");
						scanf("%d", &codigo);

						for(j=0; j<i; j++){
							if(biblioteca[j].codigo==codigo){
								for(k=j; k<i-1; k++) biblioteca[k]=biblioteca[k+1];
								i--;
							}
						}
						if(i==j)printf("Livro nao encontrado!\n");
						
						
						break;
					case 2:
						printf("Digite o codigo do livro que deseja excluir: ");
						scanf("%d", &codigo);
						for(j=0; j<i; j++){
							if(biblioteca[j].codigo==codigo){
								printf("Digite a quantia de unidades que deseja excluir: ");
								scanf("%d", &quant);
								biblioteca[j].totalExemplares-=quant;
								biblioteca[j].exemplaresDisponiveis-=quant;
								if(biblioteca[j].exemplaresDisponiveis==0){
									for(k=j; k<i-1; k++) biblioteca[k]=biblioteca[k+1];
									i--;
								}
							}
						}
						break;
					default: printf("Opcao invalida!\n");	
				}
				
				printf("Livro excluido com sucesso!\n");
				system("pause");
				system("cls");
				break;
			case 4:
				printf ("\tatualizacao dos dados de um livro\n");
			    printf ("digite o codigo do livro que deseja atualizar:\n");
			    scanf ("%d", &codigo);
			
			    for(j=0;codigo != biblioteca[j].codigo && j<100; j++){}

			    if(j>99){
			        printf ("o livro nao foi localizado\n");
			        system("pause");
			        system("cls");
			        continue;
			    }
                printf("Titulo do livro: %s\n", biblioteca[j].titulo);
                printf("Autor: %s\n", biblioteca[j].autor);
                printf("Codigo do livro: %d\n", biblioteca[j].codigo);
                printf("Ano de publicacao: %d\n", biblioteca[j].ano);
                printf("Total de exemplares: %d\n", biblioteca[j].totalExemplares);
                printf("Total disponivel: %d\n", biblioteca[j].exemplaresDisponiveis);
                printf("============================================================\n");   

			    printf ("escolha o que quer alterar do livro:\n");
			    printf ("1 - nome do livro\n");
			    printf ("2 - nome do autor\n");
			    printf ("3 - codigo\n");
			    printf ("4 - ano\n");

			    scanf ("%d", &escolha);

			    switch (escolha){
			        case 1:
			            printf ("digite o novo nome do Livro:\n");
			            fflush (stdin);
			            scanf (" %40[^\n]", biblioteca[j].titulo);

                        for(k=0; biblioteca[j].titulo[k]!='\0'; k++){
                            if(biblioteca[j].titulo[k]==32) biblioteca[j].titulo[k]= 95;
                        }
			            break;
			            
			        case 2:
			            printf ("digite o novo nome do autor:\n");
			            fflush (stdin);
			            scanf (" %40[^\n]", biblioteca[j].autor);

                        for(k=0; biblioteca[j].autor[k]!='\0'; k++){
                            if(biblioteca[j].autor[k]== ' ') biblioteca[j].autor[k]= '_';
                        }
			            break;
			        case 3:
			            printf ("digite o novo codigo:\n");
			            fflush (stdin);
			            scanf ("%d", &biblioteca[j].codigo);
			            break;
			        case 4:
			            printf ("digite o novo ano de publicacao do livro:\n");
			            fflush (stdin);
			            scanf ("%d", &biblioteca[j].ano);
			            break;
			    }
				system("pause");
				system("cls");
				break;
			case 5:
				printf ("\tGerenciando emprestimo\n");
                printf ("Escolha 1 ou 2\n1- Devolucao\n2- Realizar emprestimo\n");
                scanf ("%d", &escolha);
                switch(escolha){
                    case 1:
                        printf ("Digite o codigo do livro que deseja receber de volta:\n");
                        scanf ("%d", &codigo);
                        
                        for(j=0; codigo != biblioteca[j].codigo && j<100; j++){}
                        
                        if(j>99){
                            printf ("o livro nao foi localizado\n");
                            system("pause");
                            continue;
                        }
                        printf ("Livro: %s\n", biblioteca[j].titulo);
                        printf ("autor: %s\n", biblioteca[j].autor);
                        printf ("exemplares disponiveis: %d\n", biblioteca[j].exemplaresDisponiveis);
                        printf ("ano de publicacao: %d\n", biblioteca[j].ano);
                        printf ("confirma? 1(sim) ou 0(nao)\n");
                        scanf ("%d", &escolha);  
                        if(escolha==1){
                            if(biblioteca[j].totalExemplares != biblioteca[j].exemplaresDisponiveis){
                                system("cls");
                                printf ("Devolucao relizada com sucesso\n");
                                biblioteca[j].exemplaresDisponiveis++;
                            }
                            else{
                                system("cls");
                                printf ("a devolucao eh invalida\n");
                                system("pause");
                                continue;
                            }
                        }    
                        else{
                            system("cls");
                            printf ("o emprestimo foi cancelado\n");
                            system("pause");
                            continue;
                        }              

                        break;
                    case 2:
                        printf ("Digite o codigo do livro que deseja emprestar:\n");
                        scanf ("%d", &codigo);
                        
                        for(j=0; codigo != biblioteca[j].codigo && j<100; j++){}
                        
                        if(j>99){
                            printf ("o livro nao foi localizado\n");
                            system("pause");
                            continue;
                        }
                        printf ("Livro: %s\n", biblioteca[j].titulo);
                        printf ("autor: %s\n", biblioteca[j].autor);
                        printf ("exemplares disponiveis: %d\n", biblioteca[j].exemplaresDisponiveis);
                        printf ("ano de publicacao: %d\n", biblioteca[j].ano);
                        printf ("confirma? 1(sim) ou 0(nao)\n");
                        scanf ("%d", &escolha);
                    
                        if(!(biblioteca[j].exemplaresDisponiveis)){
                            system("cls");
                            printf ("nao ha mais desse livro no estoque\n");
                            system ("pause");
                            system("cls");
                            continue;
                        }
                        if(escolha){
                            system("cls");
                            printf ("O emprestimo foi relizado com sucesso\n");
                            biblioteca[j].exemplaresDisponiveis--;
                        }
                        else{
                            system("cls");
                            printf ("o emprestimo foi cancelado\n");
                            system("pause");
                            continue;
                        }
                        system("pause");
                        system("cls");    
                        break;
                }

			    
				break;
				
			case 6:
				printf ("digite o nome do livro que deseja buscar:\n");
                scanf (" %40[^\n]", procurar);

                for(j=0; procurar[j]!='\0'; j++){
                    if(procurar[j]==32) procurar[j]= 95;
                }

                printf ("procurando %s\n", procurar);
                printf ("Livro nao localizado\n");

                for(j=0; procurar[j]!='\0'; j++){
                    if(biblioteca[j].titulo[0]==procurar[0]) {
                        if(strcmp(biblioteca[j].titulo, procurar) == 0){
                            system("cls");
                            printf ("Livro: %s\n", biblioteca[j].titulo);
                            printf ("autor: %s\n", biblioteca[j].autor);
                            printf("Codigo do livro: %d\n", biblioteca[j].codigo);
                            printf ("ano de publicacao: %d\n", biblioteca[j].ano);
                            printf ("exemplares disponiveis: %d\n", biblioteca[j].exemplaresDisponiveis);
                                                        
                        } 
                    }
                }
                system("pause");
                system("cls");
                break;
			case 7:
				printf("Fechando o sistema e salvando alteracoes!\n");
				break;
			default:
				printf("Opcao invalida\n");
				system("pause");
				system("cls"); 
		}
	}while(escolha!=7);
	

    f = fopen("Livros.txt", "w");
    n=i;
    // printf ("%d", n);
    for (i=0; i<n; i++){
        fprintf(f, "%s\n", biblioteca[i].titulo);
        fprintf(f, "%s\n", biblioteca[i].autor);
        fprintf(f, "%d\n", biblioteca[i].codigo);
        fprintf(f, "%d\n", biblioteca[i].ano);
        fprintf(f, "%d\n", biblioteca[i].totalExemplares);
        fprintf(f, "%d\n", biblioteca[i].exemplaresDisponiveis);

    }
    fclose(f);
	
	return 0;
}
