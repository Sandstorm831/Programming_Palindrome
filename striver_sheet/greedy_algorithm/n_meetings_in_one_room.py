# Geeks for Geeks solution
# Link : https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution:

    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,start,end):
        # code here
        x = []
        for i in range(len(end)):
            x.append((start[i], end[i]))
        x.sort(key = lambda x: (x[1], x[0]))
        bot = x[0][1]
        counter = 1
        for i in range(1, len(x)):
            if x[i][0] > bot:
                counter += 1
                bot = x[i][1]
        return counter
