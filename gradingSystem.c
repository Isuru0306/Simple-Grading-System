#include<stdio.h>
int rows,columns;

void miniAndMax(float table[rows][columns],int i){
	
	int j;
	float min = table[i][0];
	float max = table[i][0];
	
	for(j=0;j<columns;j++){
		
		if(min > table[i][j])
		min = table[i][j];
		
		if(max < table[i][j])
		max = table[i][j];
	}
	
	printf("\t%.0f",min);
	printf("\t%.0f",max);	
}

void average(float total){
	
	float average = total/columns;
	printf("\t%.2f",average);
	
	if(average>=80 && average<=100)
		printf("\tA");
	else if(average >=60 && average<80)
		printf("\tB");
	else if(average >=40 && average<60)
		printf("\tC");
	else
		printf("\tF");			
}

void totalOfHorizontal(float table[rows][columns],int i){
	
	int j;
	float total;
	for(j=0;j<columns;j++){
		total +=table[i][j];
	}
	printf("\t%.0f",total);
	average(total);
	
}

void printTable(float table[rows][columns]){
	
	int i,j;
	
	for(i=0;i<rows;i++){
		printf("\t%d",i+1);
		for(j=0;j<columns;j++){
			printf("\t%.0f",table[i][j]);
		}
		totalOfHorizontal(table,i);
		miniAndMax(table,i);		
		printf("\n");
	}
	
	
}

float getValue(char scq[] ,int i, char string[]){
	
	float data;
	
	printf("%s%d.%s",scq,i,string);
	scanf("%f",&data);
	return data;
}

void setValue(float table[rows][columns]){
	
	int i,j;
	
	for(i=0;i<rows;i++){
		printf("\nIn the %d row data\n",i+1);
		for(j=0;j<columns;j++){
			table[i][j] = getValue(" ",j+1,"Enter a value :");
		}
	}	
}

void main(){
	
	rows = getValue("\n ", 1, "How many rows do you want to enter? ");
	columns = getValue(" ", 2, "How many columns do you want to enter? ");
	
	float table[rows][columns];
	
	setValue(table);
	
	int i;
	printf("\n\tNo");
	for(i=0;i<columns;i++){
		printf("\t%d",i+1);
	}
	printf("\tTotal\tAverage\tGrade\tMin\tMax\n");
	printTable(table);
}

