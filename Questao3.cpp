#include <stdio.h>
#include <stdlib.h>

#define N 10

float retornaMedia(float *array){
	float mediaArray=0;
	for(int i=0; i<N;i++){
		mediaArray+=array[i];		
	}
	
	return mediaArray/N;
}

float retornaMaior(float *array, float maior){
	
	for(int i=0; i<N;i++){
        if(array[i]>maior){
            maior=array[i];
        }
    }
    return maior;
}

float retornaMenor(float *array, float menor){
	
	for(int i=0; i<N;i++){
        if(array[i]<menor){
            menor=array[i];
        }
    }
    return menor;
}

int retornaNumeroPares(float *array){
	int ndePares=0;
	
	for(int i=0; i<N;i++){
        if((int)array[i]%2==0){
            ndePares++;
        }
    }
    return ndePares;
}

void alterarVetor(float newArray[], int newPosition, float *array){
	float arrayAux[newPosition];
	int j=0;
	
	for(int i=0; i<N; i++){
		if((int)array[i]%2==0){
        	newArray[j]=array[i];
        	j++;
        }
	}
 }
int main()
{
    float maior=0, menor=2147483646, mediaCalculada;
    float array[N];
    int newPosition=0;
    
    printf("EDUARDO CARDOSO, TESTE PARA EMPRESA ELECTROLUX\n");
    printf("EXERCICIO 3\n");
    
    printf("DIGITE OS VALORES DO ARRAY DE %d POSICOES", N);
    printf("\n");
    for (int i=0;i<N;i++)
    {
    	printf("POSICAO %d : \n", i+1);
    	scanf("%f", &array[i]);
	}

        
    maior = retornaMaior(array,maior); 
	menor = retornaMenor(array,menor); 
	mediaCalculada = retornaMedia(array);
	newPosition = retornaNumeroPares(array);
	float newArray[newPosition];
	alterarVetor(newArray, newPosition, array);
    printf("MAIOR VALOR: %f", maior);     
	printf("\nMENOR VALOR: %f", menor);	
	printf("\nVALOR MEDIO: %f", mediaCalculada);
	printf("\nQTD PARES (NOVO TAMANHO ARRAY): %d", newPosition);
	for(int i=0; i<newPosition; i++){
		printf("\nVALOR DA POSICAO %d DO NOVO ARRAY: %f", i+1, newArray[i]);
	}
	  

return 0;
}
