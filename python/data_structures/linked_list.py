# Linked lists are good at adding and deleting O(1) and are used when we need to use these operations a lot
# Searching has a time complexity of O(n)
# Single linked lists store a reference to the next node
# Doubly linked lists store a reference to the previous and next nodes

class Node:
    """
    An object for storing a single node of a linked list.
    Models two attributes - data and the link to the next node in the list
    """
    data = None
    next_node = None

    def __init__(self, data):
        self.data = data

    def __repr__(self):
        return "<Node data: %s>" % self.data
# Then, run:
    # python3 i- linked_list.py
    # N1 = Node(10)
    # N1 which will return <Node data: 10>
    # N2 = Node (20)
    # N1.next_node = N2
    # N1.next_node which will return <Node data: 20>

class LinkedList:
    """
    Singly Linked list
    """

    def __init__(self):
        """
        Initializes an empty linked list by setting the head to None.
        """
        self.head = None
    
    def is_empty(self):
        """
        Checks if the linked list is empty. Returns True if empty, False otherwise.
        """
        return self.head == None
    
    def size(self):
        """
        Returns the number of ndoes in the list
        Takes 0(n) time
        """
        current = self.head
        count = 0

        while current:
            count += 1
            current = current.next_node
        
        return count
# Then, run:
    # l = LinkedList()
    # N1 = Node(10)
    # l.head = N1
    # l.size() which should return 1

    def add(self, data):
        """
        Adds new Node containing data at the head of the list
        Takes O(1) times
        """
        new_node = Node(data)
        new_node.next_node = self.head
        self.head = new_node
# Then, run:
    # l = LinkedList()
    # l.add(1)
    # l.add(2)
    # l.size() which should return 2

    def search(self, key):
        """
        Search for the first node containing data that matches the key
        Return the node or None if not found
        Takes O(n) time
        """
        current = self.head

        while current:
            if current.data == key:
                return current
            else:
                current = current.next_node
        return None
# Then, run:
    # l = LinkedList()
    # l.add(1)
    # l.add(2)
    # l.add(45)
    # l.add(1000)
    # l.search(1)    which should return: <Node data: 1>
    # b = l.search(45)
    # b    which should return : <Node data: 45>
    # l    which should return: [Head: 1000]-> [45]-> [2]-> [Tail: 1]

    def insert(self, data, index):
        """
        Inserts a new Node containing data at the index position
        Insertion takes 0(1) time but finding the node at the inseration point takes 0(n)
        Takes an overall 0(n) time
        """

        if index == 0:
            self.add(data)
        if index > 0:
            new = Node(data)

            position = index
            current = self.head
            
            while position > 1:
                current = current.next_node
                position -= 1
            
            prev = current
            next_node = current.next_node

            prev.next_node = new
            new.next_node = next_node
# Then, run:
    # l = LinkedList()
    # l.add(1)
    # l.add(2)
    # l.add(3)
    # l.add(4)
    # l.add(5)
    # l    which should return: [Head: 5]-> [4]-> [3]-> [2]-> [Tail: 1]
    # l.insert(6, 2)
    # l    which should return: [Head: 5]-> [4]-> [6]-> [3]-> [2]-> [Tail: 1]

    def __repr__(self):
        """
        Return a string representation of the list
        Takes 0(n) time
        """

        nodes = []
        current = self.head

        while current:
            if current is self.head:
                nodes.append("[Head: %s]" % current.data)
            elif current.next_node is None:
                nodes.append("[Tail: %s]" % current.data)
            else:
                nodes.append("[%s]" % current.data)
            
            current = current.next_node
        return '-> '.join(nodes)
# Then, run:
    # l = LinkedList()
    # l.add(1)  
    # l.add(2)
    # l.add(3)
    # l  which should print: [Head: 3]-> [2]-> [Tail: 1]