# stack using python
SIZE = 3
stack = [None]*SIZE
top = -1

# function to check if stack is full
def isFull():
	return top == SIZE-1
# is empty
def isEmpty():
	return top == -1
#push to stack
def push(value):
	global top
	if isFull():
		print("Stack is full")
	else:
		top = top+1
		stack[top] = value
		print("Pushed: ",value)
# pop from stack
def pop():
	global top
	if isEmpty():
		print("Empty")
	else:
		data = stack[top]
		top = top-1
		print("Popped: ",data)
# peek
def peek():
	if isEmpty():
		print("stack empty")
	else:
		data = stack[top]
		print("Top: ",data)		
# display all elements
def display():
	if isEmpty():
		print("No data to display")
		return
	print("== Data in stack ==")
	for i in range(top,-1,-1):
		print(stack[i])


pop()
display()
push(5)
push(10)
push(12)
push(14)
display()
pop()
display()
pop()
pop()
pop()
display()
