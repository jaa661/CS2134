
//
//  Binary Search Tree Class
//
//  Modified code from Weiss
//
#include <string>
#include <vector>
#include <iostream>
#include <Queue>
using namespace std;

template<class Comparable>
struct BinaryNode
{
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;
    
    BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
    : element{ theElement }, left{ lt }, right{ rt }{ }
    
    BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
    : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
};


// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// bool contains( x )     --> Return true if x is present
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************


template <typename Comparable>
class BinarySearchTree
{
public:
    typedef BinaryNode<Comparable> Node;
    
    BinarySearchTree( ) : root{ nullptr }
    {
    }
    
    /**
     * Copy constructor
     */
    BinarySearchTree( const BinarySearchTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }
    
    /**
     * Move constructor
     */
    BinarySearchTree( BinarySearchTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }
    
    /**
     * Destructor for the tree
     */
    ~BinarySearchTree( )
    {
        makeEmpty( );
    }
    
    /**
     * Copy assignment
     */
    BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        BinarySearchTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    
    /**
     * Move assignment
     */
    BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        std::swap( root, rhs.root );
        return *this;
    }
    
    
    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    /**
     * prints values in range [min, max]
     */
    void range( const Comparable & min, const Comparable & max ) const
    {
        return range( min, max, root );
    }
    
    /**
     * makes tree into single list
     */
    void stringy()
    {
        queue<Node*> Q;
        stringy(Q,root);
        root = Q.front();
        for(int i = 0; i< (Q.size() -1);i++){
            Q[i]->right = Q[i+1];
            Q[i]->left = nullptr;
        }
        Q[Q.size()-1]->right = nullptr;
        Q[Q.size()-1]->left = nullptr;

    }
    
    /**
     * average depth
     */
    void average_node_depth()
    {
        average_node_depth(root);
    }
    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty( ) const
    {
        return root == nullptr;
    }
    
    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }
    
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }
    
    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }
    
    
private:
    
    BinaryNode<Comparable> *root;
    
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( const Comparable & x, Node * & t )
    {
        if( t == nullptr )
            t = new Node{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );
        else
            ;  // Duplicate; do nothing
    }
    //////////////////////////////////////////////////////////////////////////Homework2A
    bool contains(const Comparable& x, BinaryNode<Comparable> node){
        if( node == nullptr)
            return false;
        if( x < node->element )
            contains(x,node->left);
        else if( node->element < x )
            contains(x,node->right);
        else
            return true;
        
    }
    //////////////////////////////////////////////////////////////////////////Homework2B
    
    void range( const Comparable & min, const Comparable & max, BinaryNode<Comparable> node){
        if(node!= nullptr){//check to make sure not null
            if((node->element > min)&&(node->element < max)){//within range
                cout << node->element<<endl;//print
                range(min, max, node->left);//search left
                range(min, max, node->right);//search right
            }
            if((node->element == min)||(node->element == max))//equal to limits
                cout << node->element<<endl;//print
            
            
            if(node->element <= min )//if below range
                range(min, max, node->right);//search right
            if( node->element >= max)//if above
                range(min, max, node->left);// search left
        }
    }
     //////////////////////////////////////////////////////////////////////////Homework2c
    void stringy(queue<Node*>& Q, BinaryNode<Comparable> node)
    {
        if(node->left != nullptr )
            levelOrder(Q,node->left);
        Q.push(node);
        if(node->right != nullptr )
            levelOrder(Q,node->right);
    }
    //////////////////////////////////////////////////////////////////////////Homework2d

    int average_node_depth(BinaryNode<Comparable> node)
    {
        return(depthsum(root,0)/count(root));
    }
    
    int depthSum(BinaryNode<Comparable> node, int depth ) {
        if ( node == nullptr ) {
            return 0;
        }
        else if (( node->left == nullptr) && (node->right == nullptr)) {
            return depth;
        }
        else {
            return (sumOfLeafDepths(node->left, depth + 1) + sumOfLeafDepths(node->right, depth + 1) + depth);
        }
    }
    int count(BinaryNode<Comparable> node) {
        if (node == nullptr)
            return 0;
        else if ((node->left == nullptr) && (node->right == nullptr))
            return 1;
        else
            return (count(node->left) + count(node->right) + 1);
    }
    //////////////////////////////////////////////////////////////////////////Homework3
    void levelOrder(queue<Node*> Q, BinaryNode<Comparable> node){
        int breadthSize=0;
        Q.push(node);
        while(Q.size() > 0){
            breadthSize = Q.size();
            for(int i = 0; i < breadthSize;i++){
                if(Q[i]->left != nullptr)
                    Q.push(Q.push(Q[i]->left));
                if(Q[i]->right != nullptr)
                    Q.push(Q.push(Q[i]->right));
            }
            for(int i = 0; i< breadthSize;i++){
                cout << Q.front() << ", " <<endl;
                Q.pop();
            }
            
        }
    }
    //////////////////////////////////////////////////////////////////////////

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert( Comparable && x, Node * & t )
    {
        if( t == nullptr )
            t = new Node{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );
        else
            ;  // Duplicate; do nothing

    }
    
    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty( Node * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }
    
    
    /**
     * Internal method to clone subtree.
     */
    Node * clone( Node *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new Node{ t->element, clone( t->left ), clone( t->right ) };
    }
    
    
    
};


