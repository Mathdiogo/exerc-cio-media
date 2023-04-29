 #include<stdio.h>
 #include<stdlib.h>
	
	void aloca(float **p, int tam);
	void leitura(float *p);
	void mostra(float *p, int tam);
	void media(float *p, int tam, float **pm, int*qm, float **pM, int *qM);
	
int main()
	{
		float *ptr=NULL, *pmenor=NULL, *pmaior=NULL;
		int cont=0, qmenor=0, qmaior=0;
		char op;
		 
		do {
			aloca(&ptr,cont+1);
			leitura(ptr+cont);
			cont++;
			printf("\nDeseja continuar <S/N>: ");
			scanf("%c",&op);
			fflush(stdin);
		} while(op!='n' && op!='N'); // while(op=='s' || op=='s');
		
		system("cls");
		mostra(ptr, cont);
		media(ptr, cont, &pmenor, &qmenor,&pmaior,&qmaior);
		printf("\nMenores que a media: ");
		mostra(pmenor, qmaior);
	//f	printf("\nMedia = %.2f\n\n", media(media));
		printf("\n\n");
		system("pause");
	}//main
	
	void aloca(float **p, int tam)
	{
		if((*p=(float*)realloc(*p,tam*sizeof(float)))==NULL)
			exit(1);
	}//aloca
	
	void leitura(float *p)
	{
		printf("\nDigite um numero: ");
		scanf("f, p");
		fflush(stdin);
	}//leitura
	
	void mostra(float *p, int tam)
	{
		int i;
		for(i=0; i<tam;i++, p++)
			printf("\n%.2f, *p");
	}//mostra
	
	void media(float *p, int tam, float **pm, int*qm, float **pM, int *qM)
	{
		int i;
		float med=0;
		for(i=0; i<tam; i++)
		med=med+*(p+i); //med+=*(p+i);
		med=med/tam; // med/ = tam;
		printf("\nMedia = %f .2f\n\n");
		for(i=0; i<tam; i++)
		{
			if(*(p+1)<med)
			{
				aloca(pm, *qm+1);
				*(*pm+*qm)=*(p+i);
				(*qm)++;
			}//if
			else
			{
				aloca(pM, *qM+1);
				*(*pM+*qM)=*(p+i);
				(*qM)++;
			}//else
		}//for
	}//media
