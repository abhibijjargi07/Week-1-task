#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
struct product 
{
    int id;
    char name[30];
    int qty;
    double price;
    double total;
};
void main() 
{
    struct product p;
    FILE *fp;
    int i, searchId, found = 0;
    double grandTotal = 0;

    /* STEP 1: Write product details into file */
    fp = fopen("product.txt", "w");
    if (fp == NULL) 
    {
        printf("File cannot be opened!");
       getch() ;
    }

    printf("Enter details of 5 products\n");

    for (i = 0; i < 5; i++) 
    {
        printf("\nProduct %d\n", i + 1);

        printf("Enter Product ID: ");
        scanf("%d", &p.id);

        printf("Enter Product Name: ");
        scanf("%s", p.name);

        printf("Enter Quantity: ");
        scanf("%d", &p.qty);

        printf("Enter Price: ");
        scanf("%lf", &p.price);

        p.total = p.qty * p.price;

        fwrite(&p, sizeof(p), 1, fp);
    }
    fclose(fp);

    /* STEP 2: Read and display product details */
    fp = fopen("product.txt", "r");
    if (fp == NULL) 
    {
        printf("File cannot be opened!");
        getch();
    }
    printf("\n\nProduct Details\n");
    printf("ID\tName\tQty\tPrice\tTotal\n");
    printf("--------------------------------------------\n");

    while (fread(&p, sizeof(p), 1, fp)) 
    {
        printf("%d\t%s\t%d\t%lf\t%lf\n",
               p.id, p.name, p.qty, p.price, p.total);
        grandTotal += p.total;
    }

    printf("--------------------------------------------\n");
    printf("Total Bill = %lf\n", grandTotal);

    fclose(fp);

    /* STEP 3: Search product by ID */
    printf("\nEnter Product ID to search: ");
    scanf("%d", &searchId);

    fp = fopen("product.txt", "r");

    while (fread(&p, sizeof(p), 1, fp)) 
    {
        if (p.id == searchId) 
        {
            printf("\nProduct Found!\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Quantity: %d\n", p.qty);
            printf("Price: %lf\n", p.price);
            printf("Total: %lf\n", p.total);
            found = 1;
            break;
        }
    }
    if (!found) 
    {
        printf("\nProduct Not Found!");
    }
    fclose(fp);
    getch();
    }