#include<iostream>
using namespace std;

//�����ṹ��
template<class K, class V>
struct AVLTreeNode
{
	// �洢�ļ�ֵ��
	pair<K, V> _kv;

	// ������
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	// ƽ������(balance factor)
	int _bf; // �������߶� - �������߶�

	// ���캯��
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

    //����ת(�ұ߸���Ҫ����)
    void RotateL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        //�ȱ���parent��parent
        Node* ppNode = parent->_parent;

        //1.����parent��subRL֮��Ĺ�ϵ
        parent->_right = subRL;
        //���subRL�ڵ㲻Ϊ�գ���ôҪ��������parent
        if(subRL)
            subRL->_parent = parent;
        
        //2.����subR��parent֮��Ĺ�ϵ
        subR->_left = parent;
        parent->_parent = subR;

        //3.����ppNode��subR֮��Ĺ�ϵ
        //(���������parent���������ĸ������Ǿֲ�����)
        if(parent == _root)//��parent�Ǹ��ڵ�ʱ
        {
            //subR�ͱ�����µĸ��ڵ�
            _root = subR;
            //���ڵ��parentΪ��
            _root->_parent = nullptr;
        }
        //���parent��ppNode���ұ�
        else
        {
            //���parent�ڵ����
            if(parent == ppNode->_left)
            {
                //��ôsubR����parent��������
                ppNode->_left = subR;
            }
            if(parent == ppNode->_left)
            {
                //��ôsubR����parent��������
                ppNode->_right = subR;
            }
            //subR��parent��Ҫָ��ppNode
            subR->_parent = ppNode;
        }
        //����ƽ������
        parent->_bf = 0;
        subR->_bf = 0;
    }

    //�ҵ���ת(�ұ߸���Ҫ����)
    void RotateL(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        Node* ppNode = parent->_parent;

        //1.����parent��subLR֮��Ĺ�ϵ
        parent->_left = subLR;
        //���subLR�ڵ㲻Ϊ�գ���ôҪ��������parent
        if(subLR)
        {
            subLR->_parent = parent;
        }

        //2.����subL��parent֮��Ĺ�ϵ
        subL->_left = parent;
        parent->_parent = subL;

        //3.����ppNode��subL֮��Ĺ�ϵ(����parent���������ĸ������Ǿֲ�����)
        if(parent == _root)//�����ڵ��parentΪ��
        {
            //subL�ͱ�����µĸ��ڵ�
            _root = subL;
            //���ڵ��parentΪ��
            _root->_parent = nullptr;
        }
        //��parent����֣�����ľֲ�����ʱ
        else
        {
            //���parent��ppNode�����
            if(parent == ppNode->_left)
            {
                ppNode->_left = subL;
            }
            //���parent��ppNode���ұ�
            else
            {
                ppNode->_right = subL;
            }
            sub->parent = ppNode;
        }
        //����ƽ������
        parent->_bf = 0;
        subL->_bf = 0; 
    }

    //����˫��
    void RotateLR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;

        //1.����subLΪ��ת���������
        RotateL(parent->_left);

        //2.����parentΪ��ת���������ת
        RotateLR(parent);

        //3.����ƽ������
        //�����⣬���bf=0��˵��subLR�ĸ߶�Ҫô��ΪhҪô��Ϊh-1��
        //�����ж�subL��parent��ƽ������ֵ������subLRһ��Ϊ0
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
            //����ߵ����˵��subLR��ƽ����������תǰ��������
            assert(false);
        }
    }

    //����˫��
    void RotateRL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;

        //1.����subRΪ��ת������ҵ���ת
        RotateR(parent->_right);

        //2.����parentΪ��ת���������ת
        RotateL(parent)

        //3.����ƽ������
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
			// ����ߵ������˵��subRL��ƽ����������תǰ��������
			assert(false);
		}
    }

    //���뺯��
    bool Insert(const pair<K, V>&kv)
    {
        //���AVL�ǿ������Ѳ���ڵ�ֱ����Ϊ���ڵ�
        if(_root == nullptr)
        {
            _root = new Node(kv);
            _root->_bf = 0;
            return true;
        }

        //1.�Ȱ��ն����������Ĺ������
        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)
        {
            //Ҫ����ڵ��keyֵ���ڵ�ǰ�ڵ��keyֵ
            if(cur->_kv.first < kv.first)
            {
                //����������
                parent = cur;
                cur = cur->_right;
            }
            //Ҫ�����keyֵС�ڵ�ǰ�ڵ�
            else if(cur->_kv.first > kv.first)
            {
                //����������
                parent = cur;
                cur = cur->_left;
            }
            //Ҫ�����keyֵ�뵱ǰ�ڵ��keyֵ��ͬ
            else
            {
                //����ʧ�ܣ�����false
                return false;
            } 
        }
        //����ƽ�����ӣ�������ֲ�ƽ�⣬����Ҫ������ת
        while(parent)//��Զ���µ����ڵ�ȥ
        {
            //���cur����parent���ұߣ�˵��parent������������
            if(cur == parent->_right)
                parent->_bf++;//��ôparent��ƽ������++
            //���cur����parent����ߣ�˵��parent������������
            else
                parent->_bf--;//��ôparent��ƽ������--
            
            //�жϸ����Ƿ�����������Ƿ���Ҫ��ת���parent��bf����0��˵����
            //�������߶�һ�£��͸��½���(ԭ�����²���Ľڵ��parent��������
            //�а�����һ�߸����),�����ϵ�ƽ������Ҳ�����ܵ�Ӱ��
            if(parent->_bf == 0)
                break;
            //�������ϸ���ƽ������(����ڵ㵼��ĳһ�߱���ˣ�
            //˵��parent���ڵ������߶ȸı���)
            else if(parent->_bf == 1 || parent->_bf == 1)
            {
                //�����ĸ߶ȱ��ˣ���Ҫ�������ϸ�������
                cur = cur->_parent;
                parent = parent->_parent;
            }
            //˵������ڵ㵼�±����ߵ�һ���ֱ���ˣ�������ƽ���ˣ�
            //��ô��ʱ��Ҫ����ת����
            else if(parent->_bf == 2 || parent->_bf == -2)
            {
                //��ת�����ִ���ʽ
                // 1.����
				// 2.�ҵ���
				// 3.����˫��
				// 4.����˫��

                //��ת��ɣ�����
                break;
            }
            else
            {
                // ��������ߵ������˵���ڲ���ڵ�֮ǰAVL���ʹ��ڲ�ƽ���������Ҳ���Ǵ���ƽ������ >= 2�Ľڵ�
				// ���������һ�����Խ��д���
                assert(false);
            }
        }
        //����ɹ�������true
        return true; 
    }

    //ɾ������
    bool Erase(const K& key)
    {
        //���ڱ���������
        Node* parent = nullptr;
        Node* cur = _root;
        //���ڱ��ʵ�ʵ�ɾ���ڵ㼰�丸�ڵ�
        Node* delParentPos = nullptr;
        Node* delPos = nullptr;
        while(cur)
        {
            //Ҫɾ����key��ֵС�ڵ�ǰ�ڵ��key��ֵ
            if(key < cur->_kv.first)
            {
                //���ýڵ����������
                parent = cur;
                cur = cur->_left;
            }
            //Ҫɾ����key��ֵ���ڵ�ǰ�ڵ��key��ֵ
            else if(key > cur->_kv.first)
            {
                //���ýڵ����������
                parent = cur;
                cur = cur->_right;
            }
            //�ҵ��˴�ɾ���Ľڵ�
            else
            {
                //��ɾ���ڵ��������Ϊ��
                if(cur->_left == nullptr)
                {
                    //��ɾ���ڵ��Ǹ��ڵ�
                    if(cur == _root)
                    {
                        //�ø��ڵ����������Ϊ�µĸ��ڵ�
                        _root = _root->_right;
                        if(_root)
                            _root->_parent = nullptr;
                        //ɾ��ԭ���ڵ�
                        delete cur;
                        //���ڵ������Ƚڵ㣬�������ƽ�����ӵĸ��²���
                        return true;
                    }
                    else
                    {
                        //���ʵ��ɾ���ڵ�ĸ��ڵ�
                        delParentPos = parent;
                        //���ʵ��ɾ���Ľڵ�
                        delPos = cur;
                    }
                    //ɾ���ڵ������Ƚڵ㣬��Ҫ����ƽ������
                    break;
                }
                //��ɾ���ڵ��������Ϊ��
                else if(cur->_right == nullptr)
                {
                    //��ɾ���ڵ��Ǹ��ڵ�
                    if(cur == _root)
                    {
                        _root = _root->_left;
                        if(_root)
                            _root->_parent = nullptr;
                        //ɾ��ԭ���ڵ�
                        delete cur;
                        //���ڵ������Ƚڵ㣬�������ƽ�����ӵĸ��²���
                        return true;
                    }
                    else
                    {
                        //���ʵ��ɾ���ڵ�ĸ��ڵ�
                        delParentPos = parent;
                        //���ʵ��ɾ���Ľڵ�
                        delPos = cur;
                    }
                    //ɾ���ڵ������Ƚڵ㣬��Ҫ����ƽ������
                    break;
                }
                //��ɾ���ڵ��������������Ϊ��
                else
                {
                    //�滻��ɾ��
                    //Ѱ�Ҵ�ɾ���ڵ�����������keyֵ��С�Ľڵ���Ϊʵ��ɾ���ڵ�
                    Node* minParent = cur;
                    Node* minRight = cur->_right;
                    while(minRight->_left)
                    {
                        minParent = minRight;
                        minRight = minRight->_left;
                    }
                    //����ɾ���ڵ��key��ΪminRinght
                    cur->_kv.first = minRight->_kv.first;
                    //����ɾ������value��ΪminRight��value
                    cur->_kv.second = minRight->_kv.second;
                    //���ʵ��ɾ�����ĸ����
					delParentPos = minParent; 
                    //���ʵ��ɾ���Ľڵ�
                    delPos = minRight;
                    //ɾ���ڵ������Ƚڵ�,��Ҫ����ƽ������
                    break/
                }
            }
        }
        //delParentPosû�б��޸Ĺ���˵��û���ҵ���ɾ���ڵ�
        if(delParentPos == nullptr)
        {
            return false;
        }

        //����ƽ������
        while(delPos != _root)//����һ·���µ����ڵ�
        {
            //delParentPos���������߶Ƚ���
            if(delPos == delParentPos->_left)
            {
                //delParentPos��ƽ������++
                delParentPos->_bf++;
            }
            //delParentPos���������߶Ƚ���
            else if(delPos == delParentPos->_right)
            {
                delParentPos->_bf--;
            }

            //�ж��Ƿ���½�������Ҫ������ת
            if(delParentPos->_bf == 0)//��Ҫ�������ϸ���ƽ������
            {
                //delParentPos���ĸ߶ȱ仯����Ӱ���丸�ڵ��ƽ��������Ҫ�������ϸ���ƽ������
				delPos = delParentPos;
                delParentPos = delParentPos->_parent;
            }
            //���½���
            else if(delParentPos->_bf == -1 || delParentPos->_bf == 1)
            {
                //delParentPos���ĸ߶�û�з����仯������Ӱ���丸�׽ڵ㼰���Ͻڵ��ƽ��
                break;
            }
            //��Ҫ������ת
            else if(delParentPos->_bf == -2 || delParentPos == 2)
            {
                if(delParentPos->_left->_bf == -1)
                {
                    //��¼delParentPos����ת���µĸ��ڵ�
                    Node* tmp = delParentPos->_left;
                    //�ҵ���ת
                    RotateLR(delParentPos);
                    //���¸��ڵ�
                    delParentPos = tmp;
                }
                else if(delParentPos->_left->_bf == 1)
                {
                    Node* tmp = delParentPos->_left->_right;
                    //����˫��
                    RotateLR(delParentPos);
                    //���¸��ڵ�
                    delParentPos = tmp;
                }
                //delParentPos->_left->_bf == 0
                else
                {
                    //��¼delPaarentPos�������µĸ��ڵ�
                    Node* tmp = delParentPos->_left;
                    //�ҵ���ת
                    RotateR(delParentPos);
                    //���¸��ڵ�
                    delParentPos = tmp;
                    //ƽ�����ӵ���
                    delParentPos->_bf = 1;
                    delParentPos->_right->_bf = -1;
                    //����
                    break;
                }
            }
            //delParentPos->_right->_bf == 0
            else
            {
                if(delParentPos->_right->_bf == -1)
                {
                    //��¼delParentPos������ת���µĸ����
                    Node* tmp = delParentPos->_right->_left;
                    //����˫��
                    RotateRL(delParentPos);
                    //���¸��ڵ�
                    delParentPos = tmp;
                }
                else if(delParentPos->_right->_bf == 1)
                {
                    //��¼delParentPos����ת���µĸ��ڵ�
                    Node* tmp = delParentPos->_right;
                    //����
                    RotateL(delParentPos);
                    //���¸��ڵ�
                    delParentPos = tmp;
                }
                //delParentPos->_right->_bf == 0
                {
                    //��¼delParentPos����ת���µĸ��ڵ�
                    Node* tmp = delParentPos->_right;
                    //����
                    RotateL(delParentPos);
                    //���¸��ڵ�
                    delParentPos = tmp;
                    //����ƽ������
                    delParentPos->bf = -1;
                    delParentPos->_left->_bf = 1;
                    //����
                    break;
                }
            }
            //delParentPos���ĸ߶Ȼ�仯��Ӱ���丸�ڵ��ƽ�����ӣ���Ҫ�������ϸ���ƽ������
            delPos = delParentPos;
            delParentPos = delParentPos->_parent;
        }
        else
        {
            //��ɾ��ǰ����ƽ������������
            assert(false);
        }
        
    }


};

//���뺯��
// template<class K, class V>
// bool Insert(const pair<K, V>& kv)
// {
//     //���AVL���ǿ������Ѳ���ڵ�ֱ����Ϊ���ڵ�
//     if(_root = nullptr)
//     {
//         _root = new Node();
//     }
// }






























