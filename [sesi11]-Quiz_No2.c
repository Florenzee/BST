#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *tree = NULL;

//insert node
struct tnode *insert(struct tnode *tree, int val){
	struct tnode *newNode;
	struct tnode *ptr;
	struct tnode *parentPtr;
	
	//membuat node baru
	newNode = (struct tnode*)malloc(sizeof(struct tnode));
	
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	
	//jika tree masih kosong:
	if(tree == NULL){
		tree = newNode;
		return tree;
	}
	
	//jika tree tidak kosong:
	else{
		//1. cari parent-nya dulu
		parentPtr = NULL; 
		ptr = tree;
		
		while(ptr != NULL){
			parentPtr = ptr;
			
			if(val < ptr->data){ 
				ptr = ptr->left; //jika val < data pd parent, maka telusuri left
			}
			else {
				ptr = ptr->right; //jika val > data pd parent, maka telusuri right
			}
		}
	}
	
	//2. insert newnodenya jd child dr parent yg udh di pilih di atas
	if(val < parentPtr->data){
		parentPtr -> left = newNode; // jika val < data pd parent, maka val menjadi anak kiri
	}
	else{
		parentPtr -> right = newNode; // jika val > data pd parent, maka val menjadi anak kanan
	}

	return tree;
	
}

//fungsi u/ mencetak BST secara inorder (urutan: kiri-akar-kanan)
void inorder(struct tnode *tree){
	if (tree!=NULL){
		inorder(tree->left);
		printf("%d ", tree->data);
		inorder(tree->right);
	}
}

//fungsi untuk melakukan searching
struct tnode* search(struct tnode* root, int data)
{
    // Base Cases: root is null or data is present at root
    if (root == NULL || root->data == data)
        return root;
 
    // Key is greater than root's data
    if (root->data < data)
        return search(root->right, data);
 
    // Key is smaller than root's data
    return search(root->left, data);
}

int main(){
	int key;
	int i;
	int data;
	
	//insert
	printf("Silahkan input 5 data!\n");
	for(i=1; i<=5; i++){
		printf("Data ke-%d: ", i);
		scanf("%d", &data);
		
		tree=insert(tree, data);
	}
	
	//transversal
	printf("\nTransversal secara in-order: ");
	inorder(tree);
	puts("");
	
	//searching
    printf("\nMasukan data yag ingin dicari: ");
    scanf("%d", &key);
    // Searching in a BST
    if (search(tree, key) == NULL){
    	printf("Data %d tidak ditemukan\n", key);
	}
    else{
    	printf("Data %d ditemukan\n", key);
	}

	return 0;
}
