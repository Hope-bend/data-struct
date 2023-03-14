#include<iostream>
using namespace std;

//创建结构体
template<class K, class V>
struct AVLTreeNode
{
	// 存储的键值对
	pair<K, V> _kv;

	// 三叉链
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	// 平衡因子(balance factor)
	int _bf; // 右子树高度 - 左子树高度

	// 构造函数
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template<class K, class V>
struct AVLTree
{
    void 

    typedef AVLTreeNode<K, V> Node;
    public:
        AVLTree()
            :_root(nullptr)
        {}
    
    //插入函数
    bool Insert(const pair<K, V>&kv)
    {
        //如果AVL是空树，把插入节点直接作为根节点
        if(_root == nullptr)
        {
            _root = new Node(kv);
            _root->_bf = 0;
            return true;
        }

        //1.先按照二叉搜索树的规则插入
        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)
        {
            //要插入节点的key值大于当前节点的key值
            if(cur->_kv.first < kv.first)
            {
                //往右子树走
                parent = cur;
                cur = cur->_right;
            }
            //要插入的key值小于当前节点
            else if(cur->_kv.first > kv.first)
            {
                //往左子树走
                parent = cur;
                cur = cur->_left;
            }
            //要插入的key值与当前节点的key值相同
            else
            {
                //插入失败，返回false
                return false;
            } 
        }
        //更新平衡因子，如果出现不平衡，则需要进行旋转
        while(parent)//最远更新到根节点去
        {
            //如果cur插在parent的右边，说明parent的右子树增高
            if(cur == parent->_right)
                parent->_bf++;//那么parent的平衡因子++
            //如果cur插在parent的左边，说明parent的左子树增高
            else
                parent->_bf--;//那么parent的平衡因子--
            
            //判断更新是否结束，或者是否需要旋转如果parent的bf等于0，说明左
            //右子树高度一致，就更新结束(原因是新插入的节点把parent左右子树
            //中矮的那一边给填补了),再往上的平衡因子也不会受到影响
            if(parent->_bf == 0)
                break;
            //继续往上更新平衡因子(插入节点导致某一边变高了，
            //说明parent所在的子树高度改变了)
            else if(parent->_bf == 1 || parent->_bf == 1)
            {
                //子树的高度变了，就要继续往上更新祖先
                cur = cur->_parent;
                parent = parent->_parent;
            }
            //说明插入节点导致本来高的一边又变高了，子树不平衡了，
            //那么此时需要做旋转处理
            else if(parent->_bf == 2 || parent->_bf == -2)
            {
                //旋转的四种处理方式
                // 1.左单旋
				// 2.右单旋
				// 3.左右双旋
				// 4.右左双旋

                //旋转完成，跳出
                break;
            }
            else
            {
                // 如果程序走到了这里，说明在插入节点之前AVL树就存在不平衡的子树，也就是存在平衡因子 >= 2的节点
				// 所以这里加一个断言进行处理
                assert(false);
            }
        }
        //插入成功，返回true
        return true; 
    }
};

//插入函数
// template<class K, class V>
// bool Insert(const pair<K, V>& kv)
// {
//     //如果AVL树是空树，把插入节点直接作为根节点
//     if(_root = nullptr)
//     {
//         _root = new Node();
//     }
// }






























