#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<array>
#include<windows.h>

using namespace std;

class HMnode
{
public:
	char value;
	int frequency;
	HMnode* left;
	HMnode* right;
	HMnode* next;

public:
	HMnode() {};    //default constructor 

	//perameterized constructor 
	HMnode(char element, int pri)
	{
		this->value = element;
		this->frequency = pri;
		this->next = NULL;
		this->left = NULL;
		this->right = NULL;
	}

	void set_value(char v)
	{
		value = v;
	}

	char get_value()
	{
		return value;
	}

	void set_frequency(int free)
	{
		frequency = free;
	}

	int get_freequency()
	{
		return frequency;
	}

	void set_left_node(HMnode* n)
	{
		left = n;
	}

	HMnode* get_left_node()
	{
		return left;
	}

	void set_right_node(HMnode* n)
	{
		right = n;
	}

	HMnode* get_right_node()
	{
		return right;
	}

	void set_next_node(HMnode* nxt)
	{
		next = nxt;
	}

	HMnode* get_next_node()
	{
		return next;
	}

};

class priority_que {
public:
	HMnode* head;
	HMnode* tail;
public:
	priority_que()
	{
		head = NULL;
		tail = NULL;
	}  //Constructor 

	//enque the value in priority que 
	void enque(char data, int priority)
	{
		HMnode* newnode = new HMnode(data, priority);

		//cout << " inserting data " << data << " with priority " << priority << endl;
		if (head == NULL) {
			head = newnode;
			tail = newnode;

			return;
		}
		tail->set_next_node(newnode);
		tail = newnode;
		//headd = head;
	}

	//deque the value from priority que on the bases of priority .
	HMnode* deque()
	{
		HMnode* temp = head;
		HMnode* minf = head;

		if (head == NULL)
		{
			cout << "priority que is empty ";
			//return;
		}


		while (temp != NULL)
		{
			if (minf->frequency > temp->frequency)
			{
				minf = temp;
			}
			temp = temp->next;
		}

		//cout << "Extracting " << maxp->value << " with the " << maxp->frequency << endl;

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			tail = NULL;

			return head;
		}

		if (minf == head)
		{
			head = head->next;
			//delete maxp;
			return minf;

		}

		temp = head;


		while (temp->next != minf)
		{
			temp = temp->next;
		}

		temp->next = minf->next;
		//delete maxp;
		return minf;


	}

	//print priority que 
	void print()
	{
		if (head == NULL)
		{
			cout << "priority que is empty ";
			return;
		}

		HMnode* temp = head;

		while (temp != NULL)
		{
			cout << " the data is " << temp->value << "  with priority " << temp->frequency << endl;
			temp = temp->next;
		}
	}

};

// Huffman Tree builder Class 
class HMtree : public priority_que {

protected:
	HMnode* current;
	HMnode* previous;
	HMnode* root;
	int nov;


public:

	priority_que qu;

	//constructur 
	HMtree()
	{
		root = NULL;
		nov = 0;
	}

	//create simple new node using function 
	HMnode* newnodefun(int value, int freq)
	{
		HMnode* newnode = new HMnode;
		newnode->set_value(value);
		newnode->set_frequency(freq);
		newnode->set_left_node(NULL);
		newnode->set_right_node(NULL);

		return newnode;
	}

	//Huffman node builder  
	HMnode* buildnode(HMnode* node1, HMnode* node2)
	{
		int sum = node1->get_freequency() + node2->get_freequency();
		HMnode* sumnode = newnodefun('$', sum);
		sumnode->set_left_node(node1);
		sumnode->set_right_node(node2);

		return sumnode;
	}
	HMnode* myhead;

	//Huffman Tree builder 
	HMnode* buildmytree(HMnode* node1, HMnode* node2)
	{

		HMnode* newnode = new HMnode;
		newnode = buildnode(node1, node2);
		myhead = newnode;

		return newnode;


	}

	//final display function 
	void display()
	{
		cout << endl;
		Sleep(5000);
		cout << "BUILDING HUFFMAN TREE  ";
		for (int i = 0; i < 25; i++)
		{
			cout << "-";
			for (int i = 0; i < 100000000; i++)
			{
			}
		}

		cout << endl;
		cout << endl;
		//display_post_order(myhead);

		Sleep(5000);
		cout << "HERE IS THE HUFFMAN CODE : ";
		cout << endl;
		HuffmanCodes(myhead);
	}

	//display huffman tree in post order 
	void display_post_order(HMnode* n) {

		if (n != NULL) {

			display_post_order(n->get_left_node());
			display_post_order(n->get_right_node());
			cout << n->get_value();
			cout << n->get_freequency();
			cout << endl;
		}


	}


	//generate Huffman Code's
	void printHCodes(HMnode* root, int arr[], int top) {
		if (root->left) {
			arr[top] = 0;
			printHCodes(root->left, arr, top + 1);
		}

		if (root->right) {
			arr[top] = 1;
			printHCodes(root->right, arr, top + 1);
		}
		if (isLeaf(root)) {
			cout << root->value << "  | ";
			printArray(arr, top);
		}
	}

	int isLeaf(HMnode* root) {
		return !(root->left) && !(root->right);
	}


	// Print the codes

	void printArray(int arr[], int n) {
		int i;
		for (i = 0; i < n; ++i)
			cout << arr[i];

		cout << "\n";
	}


	// calling function
	void HuffmanCodes(HMnode* pkhead) {

		int arr[500], top = 0;

		printHCodes(pkhead, arr, top);
	}


};

string getfile()
{
	string filename;
	string text_of_file;

	ifstream file;
	cout << endl;
	cout << "Enter Name of your file with file extension  ";
	cin >> filename;
	file.open(filename, ifstream::in);

	if (!file)
	{
		cout << "file doesnot exist ";
		cout << endl;
		cout << "Enter Name of your file with file extension  ";
		cin >> filename;
		file.open(filename, ifstream::in);
	}
	cout << endl;
	cout << endl;

	cout << "TEXT INSIDE YOUR FILE IS  : ";
	Sleep(5000);
	cout << endl;
	cout << endl;
	while (!file.eof()) {
		getline(file, text_of_file);
		cout << text_of_file;

	}

	int s = text_of_file.length();
	char* array;
	array = new char[s];

	for (int i = 0; i < sizeof(s); i++)
	{
		array[i] = text_of_file[i];
	}

	file.close();
	cout << endl;

	file.close();

	return text_of_file;
}

void create_encrypted_file(string encrypted)
{
	cout << endl;
	cout << "YOUR FILE HAS BEEN SUCCESSFULLY ENCRYPTED ";
	cout << endl;
	ofstream myfile("encrypted_file.txt");
	myfile << encrypted;
	myfile.close();
}

void frequency_calculator(string text_of_file)
{


}

string space_remover(string textof_file)
{
	int i = 0, ji, chk;

	while (textof_file[i] != '\0')
	{
		chk = 0;
		if (textof_file[i] == ' ')
		{
			for (ji = i; textof_file[ji - 1] != '\0'; ji++)
				textof_file[ji] = textof_file[ji + 1];
			chk = 1;
		}
		if (chk == 0)
			i++;
	}

	cout << endl;
	cout << "REMOVING SPACE's FROM THE TEXT OF FILE ";
	for (int i = 0; i < 25; i++)
	{
		cout << "-";
		for (int i = 0; i < 100000000; i++)
		{
		}
	}
	cout << endl;
	//cout << "Text Without Space : ";
	//cout << textof_file;
	cout << endl;

	return textof_file;

}

string encryption(string unencrypted_text, int key)
{

	cout << endl;
	cout << "ENCRYPTING DATA ";
	for (int i = 0; i < 25; i++)
	{
		cout << "-";
		for (int i = 0; i < 100000000; i++)
		{
		}
	}
	Sleep(5000);
	cout << endl;

	char* encrypted_text;
	encrypted_text = new char[unencrypted_text.length()];

	for (int i = 0; i < unencrypted_text.length(); i++)
	{
		encrypted_text[i] = unencrypted_text[i] + key;
	}
	cout << endl;
	//cout << encrypted_text;
	return encrypted_text;
}

string decrption(string encrypted_text,int key)
{
	char* unencrypted_text;
	unencrypted_text = new char[encrypted_text.length()];

	for (int i = 0; i < encrypted_text.length(); i++)
	{
		unencrypted_text[i] = encrypted_text[i] - key;
	}
	cout << endl;
	return unencrypted_text;
}

void header()
{
	cout << "\t \t \t \t \t  HUFFMAN CODING ALGORITHM ";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << " \t \t \t \t DEVELOPER : REHAN AKHTAR ";
	cout << endl;
	cout << " \t \t \t \t \t      MUHAMMAD AASHIR ";
	cout << endl;
	cout << " \t \t \t \t  \t     ZEESHAN ZIA  ";

}

int main()
{
	system("color 80");

	priority_que q;

	HMtree t;

	HMnode* temp12;
	HMnode* temp123;
	string textof_file;
	string encrypted;
	string dencrypted;

	int key;
	char user;

	header();
	textof_file = getfile();

	cout << "Enter the key for Encrypting the data ";
	cin >> key;
	encrypted=encryption(textof_file, key);
	create_encrypted_file(encrypted);

	cout << "Want to decrypt your file ? . press y  ";
	cin >> user;
	if (user == 'y' || user=='Y')
	{
		cout << endl;
		cout << "Enter the key for Decrypting the data ";
		cin >> key;
		dencrypted=decrption(encrypted, key);


		cout << endl;
		cout << "YOUR FILE HAS BEEN SUCCESSFULLY DECRYPTED ";
		cout << endl;
		ofstream myfile("decrypted_file.txt");
		myfile << dencrypted;
		myfile.close();


	}
	textof_file = space_remover(textof_file);

	Sleep(5000);
	cout << "CALCULATING THE FREQUENCY OF EACH ALPHABET's ";
	for (int i = 0; i < 25; i++)
	{
		cout << "-";
		for (int i = 0; i < 100000000; i++)
		{
		}
	}
	cout << endl;

	int* free;
	char* arr;

	int freq[256] = { 0 };

	int size = textof_file.length();
	free = new int[size];
	arr = new char[size];


	for (int i = 0; textof_file[i] != '\0'; i++)
	{
		freq[textof_file[i]]++;
	}
	int j = 0;

	for (int i = 0; i < 256; i++)
	{
		if (freq[i] != 0)
		{
			(arr[j] = char(i)) << (free[j] = freq[i]);
			j++;
		}
	}

	cout << endl;
	Sleep(5000);
	cout << "ENQUE THE DATA IN THE PRIORITY QUE  ";
	for (int i = 0; i < 25; i++)
	{
		cout << "-";
		for (int i = 0; i < 100000000; i++)
		{
		}
	}
	cout << endl;

	for (int i = 0; i < j; i++)
	{
		q.enque(arr[i], free[i]);

	}

	cout << endl;
	Sleep(5000);
	cout << "DEQUE THE DATA FROM PRIORITY QUE";
	for (int i = 0; i < 25; i++)
	{
		cout << "-";
		for (int i = 0; i < 100000000; i++)
		{
		}
	}
	cout << endl;

	temp12 = q.deque();
	temp123 = q.deque();

	for (int i = 2; i < j; i++)
	{
		temp123 = t.buildmytree(temp123, temp12);
		temp12 = q.deque();
	}

	t.display();
	q.print();

	return 0;

}