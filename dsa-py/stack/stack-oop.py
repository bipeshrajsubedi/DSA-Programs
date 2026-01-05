class Stack:
	def __init__(self,N):
		self.size = N
		self.stack = [None]*N
		self.top = -1
	def isFull(self):
		return self.top == self.size-1
	def isEmpty(self):
		return self.top == -1
	def push(self,value):
		if self.isFull():
			print("Overflow")
		else:
			self.top += 1
			self.stack[self.top] = value
			print("Push: ",value)
	def pop(self):
		if self.isEmpty():
			print("Underflow")
		else:
			print("Pop: ",self.stack[self.top])
			self.stack[self.top] = None
			self.top -= 1
	def peek(self):
		if self.isEmpty():
			print("cannot peek: empty")
		else:
			print(self.stack[self.top])
	def display(self):
		if self.isEmpty():
			print("empty: cannot disply")
		else:
			for i in range(self.top,-1,-1):
				print(self.stack[i])

s = Stack(3)
s.display()
s.pop()
s.push(10)
s.push(12)
s.push(14)
s.push(11)
s.display()
s.pop()
s.peek()
s.pop()
s.pop()
s.pop()
s.display()		
		
