class Node:
    def __init__(self, value):
        self.data = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def traverse(self):
        if self.head == None:
            return
        current = self.head
        while(current != None):
            print(current.data,end=" ")
            current = current.next 
        print()

    def insertBegin(self, value):
        newNode = Node(value)
        newNode.next = self.head
        self.head = newNode
        print("Insert begin: ",value)

    def insertEnd(self,value):
        newNode = Node(value)
        newNode.next = None
        if self.head == None:
            self.head = newNode
            return
        current = self.head
        while(current.next != None):
            current = current.next
        current.next = newNode
        print("Insert end: ",value)
    
    def insertInPosition(self,pos,value):
        if pos < 1:
            print("Invalid position")
            return
        if pos == 1:
            self.insertBegin(value)
            return
        
        newNode = Node(value)
        prev = self.head
        
        for _ in range(pos-2):
            if prev == None:
                return self.head
            prev=prev.next

        newNode.next = prev.next 
        prev.next = newNode
    
    def deleteBegin(self):
        if self.head == None: return
        if self.head.next == None:
            self.head = None
            return
        self.head = self.head.next
        return self.head
    
    def deleteEnd(self):
        if self.head == None: return
        if self.head.next == None:
            self.head = None
            return
        current = self.head
        while(current.next.next != None):
            current = current.next
        current.next = None
    
    def deleteAtPosition(self,pos):
        if pos < 1: return
        if pos  == 1:
            self.deleteBegin()
            return
        prev = self.head
        for _ in range(pos-2):
            if prev == None:
                return
            prev = prev.next
        
        prev.next = prev.next.next



linklist = LinkedList()
linklist.traverse()
linklist.insertBegin(10)
linklist.insertBegin(20)
linklist.traverse()
linklist.insertEnd(30)
linklist.traverse()
linklist.insertInPosition(2,40)
linklist.traverse()
linklist.deleteBegin()
linklist.traverse()
linklist.deleteEnd()
linklist.traverse()
linklist.insertBegin(25)
linklist.insertEnd(45)
linklist.traverse()
linklist.deleteAtPosition(2)
linklist.traverse()



        
        



    

        