/*
	The update implemented here takes O(N) which isn't good enough.
	Use only for query.
*/

struct SegmentTreeNode {
    //store the properties here.
    vll nos;

    //assign the leaf with the value.
    void assignLeaf(vll value) {
        nos = value;
    }
    
    //do the merge option here.
    void combine(SegmentTreeNode& left, SegmentTreeNode& right) {
        nos.clear();
        merge(left.nos.begin(), left.nos.end(), right.nos.begin(), right.nos.end(),
              back_inserter(nos), greater<ll>());
    }
    
    //return the output.
    ll getValue() {
        F(i, 0, nos.size()-2) {
            if ((nos[i] >= nos[i+1] + nos[i+2]))
            {
                continue;
            }
            return nos[i] + nos[i+1] + nos[i+2];
        }
        return 0;
    }
};

//T is the input array type and V is the output type.
template<class T, class V>
class SegmentTree {
    SegmentTreeNode* nodes;
    int N; // tree size.
    
public:
    SegmentTree(T arr[], int N) {
        this->N = N;
        nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
        buildTree(arr, 1, 0, N-1);
    }
    
    ~SegmentTree() {
        delete[] nodes;
    }
    
    V getValue(int lo, int hi) {
        SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
        return result.getValue();
    }
    
    void update(int index, T value) {
        update(1, 0, N-1, index, value);
    }
    
private:    
    void buildTree(T arr[], int stIndex, int lo, int hi) {
        if (lo == hi) {
            nodes[stIndex].assignLeaf(vll(1, arr[lo]));
            return;
        }
        
        int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
        buildTree(arr, left, lo, mid);
        buildTree(arr, right, mid + 1, hi);
        nodes[stIndex].combine(nodes[left], nodes[right]);
    }
    
    SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
        if (left == lo && right == hi)
            return nodes[stIndex];
            
        int mid = (left + right) / 2;
        if (lo > mid)
            return getValue(2*stIndex+1, mid+1, right, lo, hi);
        if (hi <= mid)
            return getValue(2*stIndex, left, mid, lo, hi);
            
        SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
        SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
        SegmentTreeNode result;
        result.combine(leftResult, rightResult);
        return result;
    }
    
    int getSegmentTreeSize(int N) {
        return 4*N; 
    }
    
    void update(int stIndex, int lo, int hi, int index, T value) {
        if (lo == hi) {
            nodes[stIndex].assignLeaf(vll(1, value));
            return;
        }
        
        int left = 2 * stIndex, right = left + 1, mid = lo + (hi - lo) / 2;
        if (index <= mid)
            update(left, lo, mid, index, value);
        else
            update(right, mid+1, hi, index, value);
        nodes[stIndex].combine(nodes[left], nodes[right]);
    }
};

