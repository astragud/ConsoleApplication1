#include <stdio.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct
{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType* q)
{
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType* q)
{
    return (q->front == q->rear);
}

int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
    if (is_full(q))
    {
        fprintf(stderr, "Queue is full!\n");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
    if (is_empty(q))
    {
        fprintf(stderr, "Queue is empty!\n");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void print_queue(QueueType* q)
{
    int i = (q->front + 1) % MAX_QUEUE_SIZE;
    printf("Queue : ");
    if (!is_empty(q))
    {
        do
        {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d ", q->data[i]);
        } while (i != (q->rear + 1) % MAX_QUEUE_SIZE);
    }
    printf("\n");
}

int main()
{
    QueueType queue;
    int input, choice;

    init_queue(&queue);

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print queue\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to be enqueued : ");
            scanf_s("%d", &input);
            enqueue(&queue, input);
            break;
        case 2:
            input = dequeue(&queue);
            if (input != -1)
            {
                printf("Dequeued element : %d\n", input);
            }
            break;
        case 3:
            print_queue(&queue);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }

        if (queue.rear == 0)
        {
            for (int i = 0; i < MAX_QUEUE_SIZE; i++)
            {
                enqueue(&queue, i);
            }
        }
        else if (queue.rear == MAX_QUEUE_SIZE - 1)
        {
            for (int i = 0; i < MAX_QUEUE_SIZE; i++)
            {
                dequeue(&queue);
            }
        }
    }
}