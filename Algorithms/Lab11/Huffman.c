#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*GREEDY-HUFFMAN-CODE(C)
  prio_queue.build(C)

  while prio_queue.length > 1
    track = new node
    track.left = prio_queue.extract()
    track.right = prio_queue.extract()
    track.freq = track.left.freq + track.right.freq
    prio_queue.insert(track)

  return prio_queue.extract()*/
int codes[100];
static int k=0;
typedef struct node
{
  
  char data;
  int frequency;
  struct node *left;
  struct node *right;
}node;

int heap_array_size = 100; 
int heap_size = 0;
const int INF = 100000;

void swap( node *a, node *b ) {
  node t;
  t = *a;
  *a = *b;
  *b = t;
}
void inorder(struct node *root)
{
  if(root!=NULL) 
  {
    inorder(root->left); 
    printf(" %d", root->frequency); 
    codes[k++]=root->frequency;
    inorder(root->right);
  }
}

node* new_node(char data, int freq) {
  node *p;
  p = malloc(sizeof(struct node));
  p->data = data;
  p->frequency = freq;
  p->left = NULL;
  p->right = NULL;

  return p;
}

int get_right_child(int index) {
  if((((2*index)+1) <= heap_size) && (index >= 1))
    return (2*index)+1;
  return -1;
}

int get_left_child(int index) {
    if(((2*index) <= heap_size) && (index >= 1))
        return 2*index;
    return -1;
}

int get_parent(int index) {
  if ((index > 1) && (index <= heap_size)) {
    return index/2;
  }
  return -1;
}

void insert(node A[], node* a, int key) {
  heap_size++;
  A[heap_size] = *a;
  int index = heap_size;
  while((index>1) && (A[get_parent(index)].frequency > a->frequency)) {
    swap(&A[index], &A[get_parent(index)]);
    index = get_parent(index);
  }
}

node* make_queue(node c[], int size) {
  node* a = malloc(sizeof(node)*heap_array_size); 
  int i;
  for(i=0; i<size; i++) {
    insert(a, &c[i], c[i].frequency); 
  }
  return a;
}

void min_heapify(node A[], int index) {
  int left_child_index = get_left_child(index);
  int right_child_index = get_right_child(index);

  int smallest = index;

  if ((left_child_index <= heap_size) && (left_child_index>0)) {
    if (A[left_child_index].frequency < A[smallest].frequency) {
      smallest = left_child_index;
    }
  }

  if ((right_child_index <= heap_size && (right_child_index>0))) {
    if (A[right_child_index].frequency < A[smallest].frequency) {
      smallest = right_child_index;
    }
  }
  if (smallest != index) {
    swap(&A[index], &A[smallest]);
    min_heapify(A, smallest);
  }
}

node* minChar(node A[]) {
  node minm = A[1];
  A[1] = A[heap_size];
  heap_size--;
  min_heapify(A, 1);
  node *track;
  track = malloc(sizeof(struct node));
  track->data = minm.data;
  track->frequency = minm.frequency;
  track->left = minm.left;
  track->right = minm.right;
  return track;
}

node* huffmancoding(node C[],int V){
  node *prio_queue = make_queue(C, V); 

  while(heap_size > 1) {
    node *h = minChar(prio_queue);
    node *i = minChar(prio_queue);
    node *track;
    track = malloc(sizeof(node));
    track->data = '\0';
    track->left = h;
    track->right = i;
    track->frequency = track->left->frequency + track->right->frequency;
    insert(prio_queue, track, track->frequency);
  }
  return minChar(prio_queue);
}
void printArr(int arr[], int n) { 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d", arr[i]); 
  
    printf("\n"); 
} 
int isLeaf(node* root) { 
  
    return !(root->left) && !(root->right); 
} 
void printCodes(node* root, int arr[], int top) 
  
{ 
  
    if (root->left) { 
  
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1); 
    } 
  
    if (root->right) { 
  
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1); 
    } 
  
  
    if (isLeaf(root)) { 
  
        printf("%c: ", root->data); 
        printArr(arr, top); 
    } 
} 

int main() {
  node *a = new_node('a', 10);
  node *b = new_node('e', 15);
  node *c = new_node('i', 12);
  node *d = new_node('o', 3);
  node *e = new_node('u', 4);
  node *f = new_node('s', 13);
  node *g = new_node('t', 1);
  int V=7;
  node C[] = {*a, *b, *c, *d, *e , *f,*g};

  node* track = huffmancoding(C,V);
  inorder(track); 
  printf("\n");
  printCodes(track,codes,0);
  
  return 0;
}

