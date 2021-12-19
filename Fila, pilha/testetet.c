#include <stdio.h>
# define SIZEQ 100
# define SIZES 100
void enqueue();
void push();
void show();
int q_arr[SIZEQ];
int s_arr[SIZES]
int Top= -1
int Rear = - 1;
int Front = - 1;
main()
{
    int ch;
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
//            push();
            break;
            case 3:
            show();
            break;
            case 4:
            break;
            default:
            printf("Incorrect choice \n");
        } 
    } 
} 
  
void enqueue()
{
	int x;
	
    int insert_item;
    if (Rear == SIZEQ - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)
       
        Front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        q_arr[Rear] = insert_item;
        
        if(Top==SIZES-1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        
        scanf("%d",&x);
        Top=Top+1;
        s_array[Top]=x;
    }
    }
} 
  
  
void show()
{
    int i;
    
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for ( i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
} 
