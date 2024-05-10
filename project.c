#include<stdio.h>
#include<math.h>
#include<windows.h>
#include<string.h>
#include<time.h>

typedef struct
{
    char product_name[100];
    float quantity;
    float price;
} product;

typedef struct
{

    char sell_date[100];
    char customer_name[1000];
    char address[100];
    char contact_number[100];

} sell_details;

 int count = 0;
void design();


int main()
{
    design();
    printf("=========================================");
    char arr[]="Welcome to Bechakina Shop";
    int i=0;
    while(arr[i]!='\0')
    {
        printf("%c",arr[i]);
        Sleep(15);
        i++;
    }
    printf("=========================================");

    product shop_product[1000];
    sell_details customer;
    FILE *file;

    while(1)
    {

        file = fopen("product.txt","r");
        if(file == NULL)
        {
            printf("Error!!!");
            exit(1);
        }

        while(!feof(file))
        {
            int status = fscanf(file,"%s\t\t%f\t%f",&shop_product[count].product_name,&shop_product[count].quantity,&shop_product[count].price);
            if(status == -1)
            {
                break;
            }
            count++;
        }
        fclose(file);
        //design();
        printf("\n\nPress 1 for buy something\n\n");
        printf("Press 2 for know available details\n\n");
        printf("Press 3 to add new product\n\n");
        printf("Press 4 for Customer sell details\n\n");
        design();
        int press;
        printf("\nEnter your choice: ");
        scanf("%d",&press);
        fflush(stdin);
        if(press==1)
        {
            int i;
            int total_amount = 0;


            //Working

            file = fopen("sell_details.txt","a");
            if(file == NULL)
            {
                printf("Error!!!");
                exit(1);
            }

//Auto Time Start

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int x= tm.tm_year + 1900;
  int y= tm.tm_mon + 1;
  int z= tm.tm_mday;
  printf("Date: %d-%02d-%02d Time:%02d:%02d:%02d\n",z ,y ,x , tm.tm_hour, tm.tm_min, tm.tm_sec);

  //Auto Time End



            printf("Enter Customer Name : ");
            gets(customer.customer_name);

            printf("Enter Address : ");
            gets(customer.address);

            printf("Enter Contact Number : ");
            gets(customer.contact_number);

            fprintf(file,"%d-%02d-%02d\t\t%s\t\t%s\t\t%s\n",z,y,x,customer.customer_name,customer.address,customer.contact_number);

            fclose(file);

            //Working



            while(1)
            {
                char p_name[100];
                printf("\n\nEnter Product name : ");
                gets(p_name);
                int flag = 0;
                int i;
                for(i = 0 ; i < count ; i++)
                {
                    if(strcmp(strupr(shop_product[i].product_name),strupr(p_name)) == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    printf("Wrong input\n");
                }
                else
                {
                    int q;
                    printf("Enter Quantity : ");
                    scanf("%d",&q);
                    fflush(stdin);
                    if(q < shop_product[i].quantity)
                    {
                        total_amount = total_amount + q * shop_product[i].price;
                        shop_product[i].quantity = shop_product[i].quantity - q;
                        printf("\nName: %s Quantity: %d Price is: %.2fTk.",shop_product[i].product_name,q,(shop_product[i].price*q));
                    }
                    else
                    {
                        printf("Sorry not enough \n");
                        printf("Please buy less than %.2f\n\n",shop_product[i].quantity);
                    }
                }
                printf("\n\nPress C for continue and others for exit\n\n");
                char t;
                scanf("%c",&t);
                fflush(stdin);
                if(t != 'C')
                {
                    break;
                }
            }
            printf("Grand total : Tk.%d\n\n",total_amount);
            file = fopen("product.txt","a");
            if(file == NULL)
            {
                printf("Error!!!");
                exit(1);
            }
            for(i=0; i<count ; i++)
            {
                fprintf(file,"%s\t\t%.2f\t\t%.2f\n", shop_product[i].product_name,shop_product[i].quantity,shop_product[i].price);
            }
        }
        else if(press==2)
        {

            printf("\n\nAll the available product: \n\n");


            design();
            int i;
            for(i=0 ; i<count ; i++)
            {
                printf("%s\t Quantity: %.2f\t Tk: %.2f\n", shop_product[i].product_name,shop_product[i].quantity,shop_product[i].price);
            }
            design();

        }

        //********************************************New Product Add Start**************************************************************
        else if(press==3)

   {
            FILE *file;
            file = fopen("product.txt","a");
            if(file == NULL)
            {
                printf("Error!!!");
                exit(1);
            }
            int pr,i;
            char product_name[100];
            float quantity,price;
            printf("How many product do you want to add? : ");
            scanf("%d",&pr);
            for(i=1; i<=pr; i++)
            {
                printf("Enter Product name : ");
                fflush(stdin);
                gets(product_name);
                fflush(stdin);
                printf("Enter Quantity : ");
                fflush(stdin);
                scanf("%f",&quantity);
                fflush(stdin);
                printf("Enter Price : ");
                scanf("%f", &price);
                fprintf(file,"%s\t\t%.2f\t\t%.2f\n",product_name,quantity,price);
            }

            fclose(file);

        }


        //********************************************New Product Add End**************************************************************


        //********************************************Customer Details Start***********************************************************

        else if(press==4)
        {
            file = fopen("sell_details.txt","r");
            if(file == NULL)
            {
                printf("Error!!!");
                exit(1);
            }

            sell_details customer[1000];
            while(!feof(file))
            {
                int status = fscanf(file,"%s %s %s %s\n",&customer[count].sell_date,&customer[count].customer_name,&customer[count].address,&customer[count].contact_number);
                printf("Date is: %s\nCustomer name: %s\nAddress: %s\nContact number: %s\n\n",customer[count].sell_date,customer[count].customer_name,customer[count].address,customer[count].contact_number);

                if(status == -1)
                {
                    break;
                }
                count++;
            }
            fclose(file);

        }

        //****************************************Customer Details End************************************************


        //For Continue Main Menu
        printf("\n\nPress C for Go Back To Main Menu Other For Exit\n\n");
        char t;
        fflush(stdin);
        scanf("%c",&t);
        fflush(stdin);
        if(t != 'C')
        {
            break;
        }
    }

    return 0;
}

void design()
{
    char arr[]="===========================================================================================================";
    int i=0;
    printf("\n\n");
    while(arr[i]!='\0')
    {
        printf("%c",arr[i]);
        Sleep(2);
        i++;
    }
    printf("\n\n");
}





