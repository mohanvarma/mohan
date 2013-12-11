class tree_node:
    def __init__(self, data):
	self.left = None
	self.right = None
	self.data = data
	self.parent = None

def print_node(node):
	if node == None:
	    return
	print_node(node.left)
	print node.data,
	print_node(node.right)

def inorder(node, lst):
	if node == None:
	    return
	inorder(node.left, lst)
	lst.append(node.data)
	inorder(node.right, lst)
	return lst

def postorder(node, lst):
	if node == None:
	    return
	postorder(node.left, lst)
	postorder(node.right, lst)
	lst.append(node.data)
	return lst

def tree_mirror(node):
    if node is not None:
        # visit every node and exchange left, right
        tmp = node.left
        node.left = node.right
        node.right = tmp
        tree_mirror(node.left)
        tree_mirror(node.right)
	
# nodes appearing in the preorder between given nodes
# among this list, find which node appears first in the reversed list
# of postorder. This is Least common ancestor
def LCA_tree(root, node1, node2):
    lst = []
    lst = inorder(root, lst)
    lst_in = [x for x in lst if x>=node1 and x<=node2]
    print lst_in
    lst_post = []
    lst_post = postorder(root, lst_post)
    print lst_post
    lst_post.reverse()
    print lst_post
    for y in lst_post:
	if y in lst_in:
	    print 'LCA:', y
	    return
# Backtracking to the root node using parent pointers
# 2 paths from 2 nodes intersect at a common node.
# this is Least common ancestor
def path_to_root(node, lst):
    if node is None:
        return
    lst.append(node.data)
    node = node.parent
    path_to_root(node, lst)
    return lst

root = tree_node(15)
root.left = tree_node(10)
root.right = tree_node(16)
root.left.parent = root
root.right.parent = root
root.left.left = tree_node(8)
root.left.right = tree_node(12)
root.left.left.parent = root.left
root.left.right.parent = root.left
root.left.left.left = tree_node(6)
root.left.left.right = tree_node(9)
root.left.left.left.parent = root.left.left
root.left.left.right.parent = root.left.left
root.left.right.left = tree_node(11)
root.left.right.right = tree_node(13)
root.left.right.left.parent = root.left.right
root.left.right.right.parent = root.left.right

print_node(root)
print 
#tree_mirror(root)
#print_node(root)

LCA_tree(root, 6, 16)
path = []
path_to_root(root.left.left.left, path)
print path
path1 = []
path_to_root(root.right, path1)
print path1

lca = [x for x in path if x in path1]
print lca[0]
