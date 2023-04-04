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
    typedef AVLTreeNode<K, V> Node;
    public:
        AVLTree()
            :_root(nullptr)
        {}
        Node* _root = AVLTree();

    //左单旋转(右边高需要左旋)
    void RotateL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        //先保存parent的parent
        Node* ppNode = parent->_parent;

        //1.建立parent和subRL之间的关系
        parent->_right = subRL;
        //如果subRL节点不为空，那么要更新它的parent
        if(subRL)
            subRL->_parent = parent;
        
        //2.建立subR和parent之间的关系
        subR->_left = parent;
        parent->_parent = subR;

        //3.建立ppNode和subR之间的关系
        //(分情况讨论parent是整棵树的根，还是局部子树)
        if(parent == _root)//当parent是根节点时
        {
            //subR就变成了新的根节点
            _root = subR;
            //根节点的parent为空
            _root->_parent = nullptr;
        }
        //如果parent在ppNode的右边
        else
        {
            //如果parent在的左边
            if(parent == ppNode->_left)
            {
                //那么subR就是parent的左子树
                ppNode->_left = subR;
            }
            if(parent == ppNode->_left)
            {
                //那么subR就是parent的右子树
                ppNode->_right = subR;
            }
            //subR的parent还要指向ppNode
            subR->_parent = ppNode;
        }
        //更新平衡因子
        parent->_bf = 0;
        subR->_bf = 0;
    }

    //右单旋转(右边高需要左单旋)
    void RotateL(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        Node* ppNode = parent->_parent;

        //1.建立parent和subLR之间的关系
        parent->_left = subLR;
        //如果subLR节点不为空，那么要更新它的parent
        if(subLR)
        {
            subLR->_parent = parent;
        }

        //2.建立subL和parent之间的关系
        subL->_left = parent;
        parent->_parent = subL;

        //3.建立ppNode和subL之间的关系(讨论parent是整棵树的根，还是局部子树)
        if(parent == _root)//当根节点的parent为空
        {
            //subL就变成了新的根节点
            _root = subL;
            //根节点的parent为空
            _root->_parent = nullptr;
        }
        //当parent就是郑哥树的局部子树时
        else
        {
            //如果parent在ppNode的左边
            if(parent == ppNode->_left)
            {
                ppNode->_left = subL;
            }
            //如果parent在ppNode的右边
            else
            {
                ppNode->_right = subL;
            }
            sub->parent = ppNode;
        }
        //更新平衡因子
        parent->_bf = 0;
        subL->_bf = 0; 
    }

    //左右双旋
    void RotateLR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;

        //1.先以subL为旋转点进行左单旋
        RotateL(parent->_left);

        //2.再以parent为旋转点进行左单旋转
        RotateLR(parent);

        //3.更新平衡因子
        //有问题，如果bf=0，说明subLR的高度要么都为h要么都为h-1，
        //不好判断subL和parent的平衡因子值，但是subLR一定为0
        if(bf == 0)
        {
            parent->_bf = 0;
            subL->_bf = 0;
            subLR->_bf = 0;
        }
        else if(bf == 1)
        {
            parent->_bf = 0;
            subL->_bf = -1;
            subLR->_bf = 0;
        }
        else if(bf == -1)
        {
            parent->_bf = 1;
            subL->bf = 0;
            subLR-> = 0;
        }
        else
        {
            //如果走到这里，说明subLR的平衡因子在旋转前就有问题
            assert(false);
        }
    }

    //右左双旋
    void RotateRL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;

        //1.先以subR为旋转点进行右单旋转
        RotateR(parent->_right);

        //2.再以parent为旋转点进行左单旋转
        RotateL(parent)

        //3.更新平衡因子
        if (bf == 0)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 0;
		}
		else if (bf == 1)
		{
			subRL->_bf = 0;
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == -1)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else
		{
			// 如果走到了这里，说明subRL的平衡因子在旋转前就有问题
			assert(false);
		}
    }

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

    //删除函数
    bool Erase(const K& key)
    {
        //用于遍历二叉树
        Node* parent = nullptr;
        Node* cur = _root;
        //用于标记实际的删除节点及其父节点
        Node* delParentPos = nullptr;
        Node* delPos = nullptr;
        while(cur)
        {
            //要删除的key的值小于当前节点的key的值
            if(key < cur->_kv.first)
            {
                //往该节点的左子树走
                parent = cur;
                cur = cur->_left;
            }
            //要删除的key的值大于当前节点的key的值
            else if(key > cur->_kv.first)
            {
                //往该节点的右子树走
                parent = cur;
                cur = cur->_right;
            }
            //找到了待删除的节点
            else
            {
                //待删除节点的左子树为空
                if(cur->_left == nullptr)
                {
                    //待删除节点是根节点
                    if(cur == _root)
                    {
                        //让根节点的右子树作为新的根节点
                        _root = _root->_right;
                        if(_root)
                            _root->_parent = nullptr;
                        //删除原根节点
                        delete cur;
                        //根节点无祖先节点，无需进行平衡因子的更新操作
                        return true;
                    }
                    else
                    {
                        //标记实际删除节点的父节点
                        delParentPos = parent;
                        //标记实际删除的节点
                        delPos = cur;
                    }
                    //删除节点有祖先节点，需要更新平衡因子
                    break;
                }
                //待删除节点的右子树为空
                else if(cur->_right == nullptr)
                {
                    //代删除节点是根节点
                    if(cur == _root)
                    {
                        _root = _root->_left;
                        if(_root)
                            _root->_parent = nullptr;
                        //删除原根节点
                        delete cur;
                        //根节点无祖先节点，无需进行平衡因子的更新操作
                        return true;
                    }
                    else
                    {
                        //标记实际删除节点的父节点
                        delParentPos = parent;
                        //标记实际删除的节点
                        delPos = cur;
                    }
                    //删除节点有祖先节点，需要更新平衡因子
                    break;
                }
                //待删除节点的左右子树均不为空
                else
                {
                    //替换法删除
                    //寻找待删除节点右子树当中key值最小的节点作为实际删除节点
                    Node* minParent = cur;
                    Node* minRight = cur->_right;
                    while(minRight->_left)
                    {
                        minParent = minRight;
                        minRight = minRight->_left;
                    }
                    //将待删除节点的key改为minRinght
                    cur->_kv.first = minRight->_kv.first;
                    //将待删除结点的value改为minRight的value
                    cur->_kv.second = minRight->_kv.second;
                    //标记实际删除结点的父结点
					delParentPos = minParent; 
                    //标记实际删除的节点
                    delPos = minRight;
                    //删除节点有祖先节点,需要更新平衡因子
                    break/
                }
            }
        }
        //delParentPos没有被修改过，说明没有找到待删除节点
        if(delParentPos == nullptr)
        {
            return false;
        }

        //更新平衡因子
        while(delPos != _root)//最坏情况一路更新到根节点
        {
            //delParentPos的右子树高度降低
            if(delPos == delParentPos->_left)
            {
                //delParentPos的平衡因子++
                delParentPos->_bf++;
            }
            //delParentPos的右子树高度降低
            else if(delPos == delParentPos->_right)
            {
                delParentPos->_bf--;
            }

            //判断是否更新结束或需要进行旋转
            if(delParentPos->_bf == 0)//需要继续往上更新平衡因子
            {
                //delParentPos树的高度变化，会影响其父节点的平衡因子需要继续往上更新平衡因子
				delPos = delParentPos;
                delParentPos = delParentPos->_parent;
            }
            //更新结束
            else if(delParentPos->_bf == -1 || delParentPos->_bf == 1)
            {
                //delParentPos树的高度没有发生变化，不会影响其父亲节点及以上节点的平衡
                break;
            }
            //需要进行旋转
            else if(delParentPos->_bf == -2 || delParentPos == 2)
            {
                if(delParentPos->_left->_bf == -1)
                {
                    //记录delParentPos右旋转后新的根节点
                    Node* tmp = delParentPos->_left;
                    //右单旋转
                    RotateLR(delParentPos);
                    //更新根节点
                    delParentPos = tmp;
                }
                else if(delParentPos->_left->_bf == 1)
                {
                    Node* tmp = delParentPos->_left->_right;
                    //左右双旋
                    RotateLR(delParentPos);
                    //更新根节点
                    delParentPos = tmp;
                }
                //delParentPos->_left->_bf == 0
                else
                {
                    //记录delPaarentPos右旋后新的根节点
                    Node* tmp = delParentPos->_left;
                    //右单旋转
                    RotateR(delParentPos);
                    //更新根节点
                    delParentPos = tmp;
                    //平衡因子调整
                    delParentPos->_bf = 1;
                    delParentPos->_right->_bf = -1;
                    //更正
                    break;
                }
            }
            //delParentPos->_right->_bf == 0
            else
            {
                if(delParentPos->_right->_bf == -1)
                {
                    //记录delParentPos右左旋转后新的根结点
                    Node* tmp = delParentPos->_right->_left;
                    //右左双旋
                    RotateRL(delParentPos);
                    //更新根节点
                    delParentPos = tmp;
                }
                else if(delParentPos->_right->_bf == 1)
                {
                    //记录delParentPos左旋转后新的根节点
                    Node* tmp = delParentPos->_right;
                    //左单旋
                    RotateL(delParentPos);
                    //更新根节点
                    delParentPos = tmp;
                }
                //delParentPos->_right->_bf == 0
                {
                    //记录delParentPos左旋转后新的根节点
                    Node* tmp = delParentPos->_right;
                    //左单旋
                    RotateL(delParentPos);
                    //跟新根节点
                    delParentPos = tmp;
                    //调整平衡因子
                    delParentPos->bf = -1;
                    delParentPos->_left->_bf = 1;
                    //更正
                    break;
                }
            }
            //delParentPos树的高度会变化，影响其父节点的平衡因子，需要继续往上更新平衡因子
            delPos = delParentPos;
            delParentPos = delParentPos->_parent;
        }
        else
        {
            //在删除前树的平衡因子有问题
            assert(false);
        }
        
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






























