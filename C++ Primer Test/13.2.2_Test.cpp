/*#include<iostream>  
#include<string>  
#include<vector>
#include<memory>
using namespace std;

class HasPtr   //��ϰ13.27
{
public:
	HasPtr(const string &s=string()):ps(new string(s)),i(0),use(new size_t(1)){}  //Ĭ�Ϲ��캯��
	HasPtr(const HasPtr &temp) :ps(temp.ps), i(temp.i), use(temp.use) { ++*use; }  //�������캯����ÿ������һ�����������1
	HasPtr &operator=(const HasPtr &temp)   //������ֵ��������ȵ����Ҳ���������������캯���Ĺ��������ٵݼ�������������Ҫʱ�ͷ��ڴ棨���������Ĺ��������ٽ����ж�
	{
		++*temp.use;
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
		ps = temp.ps;
		i = temp.i;
		use = temp.use;
		return *this;
	}
	~HasPtr()  //������������Ҫʱ�ͷ��ڴ�
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}
private:
	string *ps;
	int i;
	size_t *use;
};

class TreeNode  //��ϰ13.28
{
public:
	TreeNode(): value(string()), count(new int(1)), left(nullptr), right(nullptr) { cout << "��Ĭ�Ϲ��캯��" << endl; }
	TreeNode(const string &temp) : value(temp), count(new int(1)), left(nullptr), right(nullptr) { cout << "Ĭ�Ϲ��캯��" << endl; }
	TreeNode(const TreeNode& rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; cout << "�������캯��" << endl; }
	TreeNode &operator=(const TreeNode& rhs)  //������ֵ�����
	{
		++*rhs.count;
		if (--*count == 0) 
		{
			if (left) 
			{
				delete left;
				left = nullptr;
			}
			if (right) 
			{
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
		value = rhs.value;
		left = rhs.left;
		right = rhs.right;
		count = rhs.count;
		return *this;
	}
	~TreeNode()  //��������
	{
		if (--*count == 0) {
			if (left) {
				delete left;
				left = nullptr;
			}
			if (right) {
				delete right;
				right = nullptr;
			}
			delete count;
			count = nullptr;
		}
	}
private:
	string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree //��ϰ13.28
{
public:
	BinStrTree() : root(new TreeNode) {}
	BinStrTree(const BinStrTree &temp):root(new TreeNode (*temp.root)){}
	BinStrTree &operator=(const BinStrTree& bst)
	{
		TreeNode *new_root = new TreeNode(*bst.root);
		delete root;
		*root = *new_root;
		return *this;
	}
	~BinStrTree() { delete root; }
private:
	TreeNode *root;
};

int main()
{
	string word("me");
	TreeNode a;
	TreeNode b(word);
	TreeNode c(b);
}*/