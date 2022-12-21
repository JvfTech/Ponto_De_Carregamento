#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>




#define QUANT 5

float diagonal(float a, float b)
	{
	return sqrt((a*a)+(b*b));
	}

	float case1(int ingles) {
	int i=0, k=0;
	float lat_user, lon_user, lat_pont, lon_pont, menor;
	float dif_lat[QUANT], dif_lon[QUANT], hipo[QUANT]; 
	
	FILE *arq;
	if (ingles == 1) { 
		printf("  Type your latitude:  ");
	}else{
		printf("  Digite sua latitude: ");
	}
	scanf("%f",&lat_user);
	if (ingles == 1) { 
		printf("  Type your longitude:  ");
	}else{
		printf("  Digite sua longitude: ");
	}
	scanf("%f",&lon_user);
	
		printf("\n");
		arq=fopen("latitude.txt","r");
		
		while(fscanf(arq,"%f",&lat_pont)!=EOF)
		{
			dif_lat[i]=lat_user-lat_pont;
			if (ingles == 1) { 
				printf("  > Difference between User Latitude and Point Latitude %i = %.2f\n",i+1,dif_lat[i]);
			}else{
				printf("  > Diferenca entre a Latitude do Usuario com Latitude do Ponto %i = %.2f\n",i+1,dif_lat[i]);
			}
			i++;
			
		}
		i=0;
		printf("\n");
		arq=fopen("longitude.txt","r");
	
		while(fscanf(arq,"%f",&lon_pont)!=EOF)
		{
			dif_lon[i]=lon_user-lon_pont;
			if (ingles == 1) { 
				printf("  > Difference between User Longitude and Point Longitude %i = %.2f\n",i+1,dif_lon[i]);
			}else{
				printf("  > Diferenca entre a Longitude do Usuario com Longitude do Ponto %i = %.2f\n", i+1,dif_lon[i]);
			}
			i++;
			
		}
	
		for(k=0;k<QUANT;k++)
		{
			hipo[k]=diagonal(dif_lat[k], dif_lon[k]);
			
			if (ingles == 1) { 
				printf("\n  >> Diagonal value between User and Point %i = %.2f << ",k+1,hipo[k]);
			}else{
				printf("\n  >> Valor da diagonal entre Usuario e o Ponto %i = %.2f << ",k+1,hipo[k]);
			}
			
			if(k==0)
			{
				menor=hipo[k];
			}
			else 
			{
				if(hipo[k]<menor)
				menor=hipo[k];
			}
		}
		printf("\n");
		printf("\n");
		if (ingles == 1) { 
				printf("  The closest point to the User is distance from: %.2f",menor);
			}else{
				printf("  O ponto mais proximo do Usuario e distancia de: %.2f",menor);
			}
}

	float case2(int ingles) {
			if (ingles == 1) { 
				printf("\n  1 - Shell Station - Av. Saudade, 350/370 - Center. \n");
        		printf("  2 - Orion Park Centro Automotivo Ltda - Av. April twenty-ninth, 629.\n");
       		 	printf("  3 - Andreta - Av. Antonio Frederico Ozanan, 3833.\n");
        		printf("  4 - Super Pay Less - Av. Baden Powell, 2026.\n");
        		printf("  5 - Galleria Corporate - Av. Charles Grimaldi, 1701.\n");
			}else{
				printf("\n  1 - Posto Shell - Av. Saudade, 350/370 - Centro.\n");
      			printf("  2 - Orion Park Centro Automotivo Ltda - Av. Vinte e Nove de Abril, 629.\n");
    			printf("  3 - Andreta -  Av. Antônio Frederico Ozanan, 3833.\n");
  		    	printf("  4 - Super Pague Menos -  Av. Baden Powell, 2026.\n");
        		printf("  5 - Galleria Corporate -  Av. Carlos Grimaldi, 1701.\n");
			}
	}
	float case3(int ingles) {
		if (ingles == 1) { 
				printf("\n -  Do not just leave the electrical system on for a long time as it can shorten battery life.\n");
	    		printf(" -  Change the battery periodically.\n");
				printf(" -  Do not leave burnt out light bulbs in your vehicle.\n");
				printf(" -  Do not start immediately. Start the ignition system. Wait between 5 and 10 seconds. Of departure! \n");
				printf(" -  Do not charge the battery to 100%. This is because full charging increases the core temperature of the battery,\n damaging its capacity and useful life in the long term.\n");
				printf(" -  Perform a full review every 12 months.\n");		
			}else{
				printf("\n -  Não deixe apenas o sistema elétrico ligado por muito tempo pois pode diminuir a vida útil da bateria.\n");
	    		printf(" -  Troque a bateria periodicamente.\n");
				printf(" -  Não deixe lâmpadas queimadas no seu veículo.\n");
				printf(" -  Não dê partida imediatamente. Inicie o sistema de ignição. Espere entre 5 e 10 segundos. Dê partida! \n");
				printf(" -  Não carregue a bateria até 100%. Isso porque o carregamento total aumenta a temperatura do núcleo da bateria, \n prejudicando em longo prazo sua capacidade e vida útil.\n");
				printf(" -  Realize uma revisão completa a cada 12 meses.\n");	
			}
	}
	float case4(int ingles) {
	    float b, c, res;
       	if (ingles == 1) { 
				printf("\n  Enter battery capacity (kWh) =  ");
			}else{
				printf("\n  Digite a capacidade da bateria (kWh) =  ");
			}
       	scanf("%f", &b);
		   if (ingles == 1) { 
				printf("  Enter the charging power (kW) =  ");
			}else{
				printf("  Digite a potência do carregamento (kW) =  ");
			}        	
		scanf("%f", &c);   			
		res = b / c;
		if (ingles == 1) { 
				printf("\n  Charging time is %.2f hours.", res);
			}else{
				printf("\n  O tempo de carregamento é de %.2f horas.", res);
			}
	}
	float case5(int ingles) {
    FILE *arq;

    int op = 1;
    char text[500];

    arq = fopen("melhorias.txt", "w");

    while (op == 1){

        if (ingles == 1) { 
				printf("\n  Enter your suggestions for improvements: ");
			}else{
				printf("\n  Digite suas sugestões de melhorias: ");
			}
        fflush(stdin);
        scanf("%[^\n]s", &text);
        fputs(text, arq);

			if (ingles == 1) { 
				printf("\nContinue? (0-no / 1-yes): ");
			}else{
				printf("\nContinuar? (0-nao / 1-sim): ");
		}
        scanf("%d", &op);

        if(op == 1){
            fputs("\n", arq);
        }

    }
    fclose(arq);

    return 0;
	}
		
	float case6(int ingles) {
	int opcao;	
	
	printf("\n\n");                   

	printf("\n >>> SECONDARY MENU <<<\n \n  1 - Nearest Charging Point. \n  2 - Show Log Of All Gas Stations. \n  3 - Car Electrical System Care. \n  4 - Calculate Loading Time. \n  5 - Leave your suggestions for improvement.\n\n >> ");
	scanf("%i", &opcao);

    switch (opcao) {
        case 1:
        case1(ingles);
        break;
        case 2:
		case2(ingles);
        break;
        case 3:
		case3(ingles);
        break;
        case 4:        
		case4(ingles);
		break;
		case 5:
		case5(ingles);
		break;
        	
        default:
        if (ingles == 1) { 
			printf("\n  Chosen number not present in the menu\n");
			}else{
			printf("\n  Numero escolhido nao presente no menu\n");
		}
        printf("\n------------------------------------------\n");          
    }
    

    return 0;	
}
		
	
void bemvindo() {
	printf("   |~) _  _ _   \\  /. _  _| _ \n");
	printf("   |_)(/_| | |   \\/ || |(_|(_)\n");
	printf("                               \n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int opcao;	
	int ingles = 0;
	
	printf("\n\n");

    bemvindo();                        

	printf("\n >>> MENU PRINCIPAL <<<\n \n  1 - Ponto De Carregamento Mais Próximo. \n  2 - Mostrar Registro De Todos Os Postos. \n  3 - Cuidados Com o Sistema Elétrico do Carro. \n  4 - Calcular Tempo De Carregamento. \n  5 - Deixe sua sugestões de melhoria. \n  6 - english language. \n\n >> ");
	scanf("%i", &opcao);

    switch (opcao) {
        case 1:
        case1(ingles);
        break;
        case 2:
		case2(ingles);
        break;
        case 3:
		case3(ingles);
        break;
        case 4:        
		case4(ingles);
		break;
		case 5:
		case5(ingles);
		break;
		case 6:
		ingles = 1;
		case6(ingles);
		break;
        	
        default:
        printf("\n  Numero escolhido nao presente no menu\n");
        printf("\n------------------------------------------\n");          
    }
    

    return 0;	
}
