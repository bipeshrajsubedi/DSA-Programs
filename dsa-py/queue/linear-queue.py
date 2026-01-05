SIZE = 5
queue = [None]*SIZE
front = -1
rear = -1

def isEmpty():
    return front == -1 or front > rear

def isFull():
    return rear == SIZE-1

def display():
    if isEmpty():
        print("Queue empty")
        return
    # for i in range(front, rear+1):
    #     print(f"{queue[i]}",end=" ")
    i = front
    while True:
        print(queue[i], end=" ")
        if i == rear:
            break
        i = i+1
    print()

def enqueue(value):
    global front, rear
    if isFull(): 
        print("Queue is full, cannot add")
        return
    if(front == -1):
        front = 0
    rear = rear+1
    queue[rear] = value   
    print("Enqueue: ", value)

def dequeue():
    global front, rear
    if isEmpty(): 
        print("empty, cannot remove")
        return
    data = queue[front]
    print("Dequeue: ", data)
    if front==rear:
        front = rear = -1
    else:
        front = front+1

display()
enqueue(10)
enqueue(20)
enqueue(30)
enqueue(40)
enqueue(50)
enqueue(60)
display()
dequeue()
display()
dequeue()
display()
dequeue() 
dequeue()
display()
enqueue(14)