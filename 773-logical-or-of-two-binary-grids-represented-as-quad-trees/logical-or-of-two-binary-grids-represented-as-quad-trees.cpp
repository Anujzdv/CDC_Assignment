class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) {
            if (quadTree1->val) return new Node(true, true);
            return clone(quadTree2);
        }

        if (quadTree2->isLeaf) {
            if (quadTree2->val) return new Node(true, true);
            return clone(quadTree1);
        }

        Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
            tl->val == tr->val && tr->val == bl->val && bl->val == br->val) {
            return new Node(tl->val, true);
        }

        return new Node(false, false, tl, tr, bl, br);
    }

private:
    Node* clone(Node* n) {
        if (n->isLeaf)
            return new Node(n->val, true);

        return new Node(false, false,
            clone(n->topLeft),
            clone(n->topRight),
            clone(n->bottomLeft),
            clone(n->bottomRight)
        );
    }
};
