#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
int front = -1;
int rear = -1;

int enqueue(int arr[], int size, int element);
int dequeue(int arr[], int size);
int in(int arr[], int start, int end, int e);

int in(int arr[], int start, int end, int e){
    for(int i=start; i<end; i++){
        if(arr[i]==e){
            return true;
        }
    }
    return false;
}

int enqueue(int arr[], int size, int element){
    rear++;
    if((rear<size)){
        *(arr+rear) = element;
    }
    else{
        rear--;
        return INT_MAX;
    }
}

int dequeue(int arr[], int size){
    int e;
    front++;
    if(front<=rear){
        e = *(arr+front);
        *(arr+front) = -1;
        return e;
    }
    else{
        front--;
        return INT_MAX;
    }
}

struct node{
    int val;
    struct node* link;
};

int main(){
    int v;
    printf("Enter the number of vetices in the graph: ");
    scanf("%d", &v);
    getchar();
    struct node** adj = (struct node**)malloc(v*sizeof(struct node));
    int* visited_arr = (int*)malloc(v*sizeof(int));
    int* pst_lvl_que = (int*)malloc(v*sizeof(int));
    int* node_dist_arr = (int*)malloc(v*sizeof(int));
    int* parents_arr = (int*)malloc(v*sizeof(int));
    int size_child_ent = (2*v);
    char children_ent[size_child_ent];
    for(int i=0; i<v; i++){
        printf("Enter all the adjacent nodes of %d, seperated by Space, when finished click Enter: ", i);
        fgets(children_ent, sizeof(children_ent), stdin);
        int n;
        int a=1;
        char* token = strtok(children_ent, " ");
        struct node* head = (struct node*)malloc(sizeof(struct node));
        struct node* p;
        while(token!=NULL){
            sscanf(token, "%d", &n);
            if(a==1){
                head->val = n;
                head->link = NULL;
                adj[i] = head;
            }
            else if(a==2){
                struct node *temp = (struct node*)malloc(sizeof(struct node));
                temp->val = n;
                temp->link = NULL;
                head->link = temp;
                p = temp;
            }
            else{
                struct node *temp = (struct node*)malloc(sizeof(struct node));
                temp->val = n;
                temp->link = NULL;
                p->link = temp;
                p = p->link;
            }
            a++;
            token = strtok(NULL, " ");
        }
    }
    int source;
    printf("Enter the source node: ");
    scanf("%d", &source);
    node_dist_arr[source] = 0;
    int c_dist = node_dist_arr[source];
    parents_arr[source] = source;
    enqueue(pst_lvl_que, v, source);
    int front_barrier = 0;
    int rear_barrier = 1;
    int temp_rear_barrier = rear_barrier;
    int varr_cnt = 0;
    while(front_barrier<rear_barrier){
        int node = dequeue(pst_lvl_que, v);
        struct node* neighbour = adj[node];
        while(neighbour!=NULL){
            if(!(in(pst_lvl_que, front_barrier, temp_rear_barrier, neighbour->val)) && !(in(visited_arr, 0, varr_cnt, neighbour->val))){
                enqueue(pst_lvl_que, v, neighbour->val);
                parents_arr[neighbour->val] = node;
                neighbour = neighbour->link;
                temp_rear_barrier++;
            }
            else{
                neighbour = neighbour->link;
            }
        }
        visited_arr[varr_cnt] = node;
        varr_cnt++;
        if(front_barrier==rear_barrier-1){
            node_dist_arr[front_barrier] = c_dist;
            front_barrier = rear_barrier;
            rear_barrier = temp_rear_barrier;
            c_dist++;
        }else{
            node_dist_arr[front_barrier] = c_dist;
            front_barrier++;
        }
    }
    printf("The distance of each node from the source node %d is the BST Tree is: \n", source);
    for(int i=0; i<v; i++){
        printf("%d: %d\n", i, node_dist_arr[i]);
    }
    printf("The parent of each node is: \n");
    for(int i=0; i<v; i++){
        printf("%d: %d\n", i, parents_arr[i]);
    }
    printf("The traversal in the BFS tree looks like: ");
    for(int i=0; i<v; i++){
        printf("%d ", visited_arr[i]);
    }
    return 0;
}