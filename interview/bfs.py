
from collections import deque
class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

    def add_child(self, child_node):
        self.children.append(child_node)
def bfs(root: Node, target_value) -> list | None:
    queue = deque([(root, [root.value])])
    visited = set([root])
    while queue:
        current_node, path = queue.popleft()
        if current_node.value == target_value:
            return path
        for child in current_node.children:
            if child not in visited:
                visited.add(child)
                queue.append((child, path + [child.value]))
    return None