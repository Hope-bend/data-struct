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
    void 

    typedef AVLTreeNode<K, V> Node;
    public:
        AVLTree()
            :_root(nullptr)
        {}
    
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






























