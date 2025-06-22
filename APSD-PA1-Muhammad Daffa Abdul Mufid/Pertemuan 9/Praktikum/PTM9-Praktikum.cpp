#include <iostream>
using namespace std;

//definisi struktur node
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	
	//constructor untuk membuat node baru
	TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

int main()
{
	//Membuat simpul - simpul pohon
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	
	//Menampilkan nilai simpul simpul pohon
	cout << "Nilai simpul simpil pohon : " << endl;
	cout << "Akar : " << root->data << endl;
	cout << "Anak kiri dari akar : " << root->left->data << endl;
	cout << "Anak Kanan dari akar : " << root->right->data << endl;
	cout << "Anak kiri dari anak kiri dari akar : " << root->left->left->data << endl;
	cout << "Anal kanan dari anak kiri dari akar : " << root->left->right->data << endl;
	
	//Memberishkan memory
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right;
	delete root;
	
	return 0; 
}
