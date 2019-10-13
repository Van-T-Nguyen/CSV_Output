/* Author  : Van Nguyen
 * Class   : Data Structures
 * Project : CSV Data
 * Due Date: 2019.02.22
*/

#include <stdio.h>
#include <stdlib.h>

struct item_list
{
	char name[32];
	float price;
	int quantity;
};
	
void csv_reader(void);
void print_struct(struct item_list [], int);

int main(void)
{
	csv_reader();
	getchar();
	getchar();
	return 0;
}

void csv_reader(void)
{
	struct item_list receipt[64];
	FILE * fp;
	char fluff[64];
	int total = 0;
	int size = 0;
	fp = fopen("project_03_data.csv", "r");
	if (fp != NULL)
	{
		fscanf(fp, "%[^,], %s, %s", fluff, fluff, fluff); //Gets rid of title columns
		while (fscanf(fp, "%[^,], %f, %d\n", receipt[size].name, &receipt[size].price, &receipt[size].quantity) == 3)
		{
			size++;
		}
	}
	else
	{
		printf("It didn't work");
	}
	print_struct(receipt, size);
	fclose(fp);
}

void print_struct(struct item_list receipt[], int size)
{
	double total = 0;
	for (int i = 0; i <= size; i++)
	{
		printf("%s: $%.2f\n", receipt[i].name, (receipt[i].price * receipt[i].quantity));
		total += (receipt[i].price * receipt[i].quantity);
	}
	printf("==========\n");
	printf("$%.2f", total);
}
	