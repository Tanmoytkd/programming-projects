class RangeModule:

    def __init__(self):
        self.ranges = []

    def findStart(self, left, right):
        st = 0
        jumps = [1000, 750, 500, 250, 125, 100, 10, 1]
        
        for d in jumps:
            nxt = st + d - 1
            while nxt < len(self.ranges) and self.ranges[nxt][1] <= left:
                st = nxt+1
        
        return st
    
    def findFinish(self, left, right):
        fn = len(self.ranges) - 1
        jumps = [1000, 750, 500, 250, 125, 100, 10, 1]
        
        for d in jumps:
            while nxt >= 0 and self.ranges[nxt][0] >= right:
                fn = nxt-1
        
        return fn
        
        
    def addRange(self, left: int, right: int) -> None:
        print(f"add {left}, {right}")
        st = self.findStart(left, right)
        fn = self.findFinish(left, right)
        print(f"st {st} fn {fn}")
        
        if st <= fn and st < len(self.ranges) and fn >= 0:
            left = min(left, self.ranges[st][0])
            right = max(right, self.ranges[fn][1])
        
        self.ranges = self.ranges[:st] + [(left, right)] + self.ranges[fn+1:]
        
        print(self.ranges)

    def queryRange(self, left: int, right: int) -> bool:
        print(f"query {left}, {right}")
        st = self.findStart(left, right)
        fn = self.findFinish(left, right)
        print(f"st {st} fn {fn}")
        
        if st == fn and st >=0 and st < len(self.ranges):
            return True
        else:
            return False
        
        

    def removeRange(self, left: int, right: int) -> None:
        print(f"remove {left}, {right}")
        st = self.findStart(left, right)
        fn = self.findFinish(left, right)
        print(f"st {st} fn {fn}")
        
        if st <= fn and st < len(self.ranges) and fn >= 0:
            toAdd = []
            
            if left > self.ranges[st][0]:
                toAdd.append((self.ranges[st][0], left))
            
            if right < self.ranges[fn][1]:
                toAdd.append((right, self.ranges[fn][1]))
            
            print(self.ranges, toAdd)
            self.ranges[st:fn+1] = self.ranges[:st] + toAdd + self.ranges[fn+1:]


# Your RangeModule object will be instantiated and called as such:
obj = RangeModule()

obj.addRange(10, 20)
obj.addRange(20, 30)

# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)