# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # calculate number from each list by a+b*10+c*100....
        # add two num, convert val into string
        #loop over string's each digit, create a new list
        def cal_num(node):
            i = 0
            num = 0
            while node:
                num += (node.val)*(10**i)
                i += 1
                node = node.next
            return int(num)
            
        int_1 = cal_num(l1)
        int_2 = cal_num(l2)
        int_ret = reversed(str(int_1+int_2))

        node_list = []
        for dig in int_ret:
            new_node = ListNode(int(dig))
            node_list.append(new_node)
        
        head = node_list[0]
        for j in range(len(node_list)-1):
            node_list[j].next = node_list[j+1]
        
        return head
        