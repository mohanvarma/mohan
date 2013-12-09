class tree_node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

def tree_inorder(node):
    if node is None:
        return
    tree_inorder(node.left)
    print node.data,
    tree_inorder(node.right)

def mirror_tree(node):
    if node is None:
        return
    # Visit every node and exchange left, right
    node.left, node.right = node.right, node.left
    mirror_tree(node.left)
    mirror_tree(node.right)

# Create a tree
root = tree_node(10)
root.left = tree_node(8)
root.right = tree_node(12)
root.right.left = tree_node(11)
root.right.right = tree_node(13)

tree_inorder(root)
print
mirror_tree(root)

tree_inorder(root)
    
